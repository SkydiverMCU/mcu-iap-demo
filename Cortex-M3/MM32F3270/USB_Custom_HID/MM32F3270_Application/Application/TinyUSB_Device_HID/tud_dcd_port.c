/***********************************************************************************************************************
    @file    tud_dcd_port.c
    @author  FD Team
    @date    13-March-2024
    @brief   THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2024> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Files include */
#include "tusb_config.h"
#ifdef BOARD_TUD_RHPORT

#include "device/dcd.h"
#include "hal_usbfs.h"
#include "mm32_device.h"
#include "tusb_config.h"
#include "hal_gpio.h"

extern uint32_t SystemCoreClock;

/* Private macro ******************************************************************************************************/
#define BOARD_USB_PORT          USB_FS
#define BOARD_USB_IRQn          USB_OTGFS_IRQn
#define BOARD_USB_IRQHandler    USB_OTGFS_IRQHandler
#define CLOCK_SYS_FREQ          SystemCoreClock

/* Private variables **************************************************************************************************/
/* OTG_FS BufferDescriptorTable Buffer. */
static __ALIGNED(512u) USBFS_BufDespTable_Type usb_bd_tbl = {0u}; /* usb_bufdesp_table */
static uint8_t usb_ep0_buffer[CFG_TUD_ENDPOINT0_SIZE] = {0u};     /* usb_recv_buff. */
static uint8_t usb_setup_buff[8u] = {0u};       /* usb_setup_buff. */
static uint8_t usb_device_addr = 0u;            /* usb_device_addr. */

typedef struct
{
    uint8_t * xfer_buf;
    uint32_t max_packet_size;   /* EndPoint max packet size.      */
    uint32_t length;            /* EndPoint xfer data length.     */
    uint32_t remaining;         /* EndPoint xfer data remaining.  */
    bool  odd_even;             /* EndPoint BD OddEven status.    */
    bool  data_n;               /* next packet is DATA0 or DATA1. */
    bool  xfer_done;
} USBFS_EndPointManage_Type;

static USBFS_EndPointManage_Type usb_epmng_tbl[16u][2u] = {0u}; /* EndPoint Manage Table. */

void USBFS_BusResetHandler(void)
{
    USBFS_OddEvenResetCmd(BOARD_USB_PORT, ENABLE);
    USBFS_OddEvenResetCmd(BOARD_USB_PORT, DISABLE);  /* OddEven Reset. */
    USBFS_SetDeviceAddr(BOARD_USB_PORT, 0x00u);       /* Set USB device addr equal 0x00. */
    USBFS_EndPointManage_Type epm = {0u};

    for (uint32_t i = 0u; i < USBFS_BDT_EP_NUM; i++) /* disable all EndPoint. */
    {
        USBFS_EndPointCmd(BOARD_USB_PORT, i, USBFS_EndPointMode_NULL, DISABLE);
        usb_epmng_tbl[i][USBFS_Direction_IN] = epm;
        usb_epmng_tbl[i][USBFS_Direction_OUT] = epm;
    }

    USBFS_EndPointCmd(BOARD_USB_PORT, 0u, USBFS_EndPointMode_Control, ENABLE); /* enable EP0. */
    epm.max_packet_size = CFG_TUD_ENDPOINT0_SIZE;
    epm.length          = CFG_TUD_ENDPOINT0_SIZE;
    epm.remaining       = CFG_TUD_ENDPOINT0_SIZE;
    usb_epmng_tbl[0u][USBFS_Direction_IN ] = epm;
    usb_epmng_tbl[0u][USBFS_Direction_OUT] = epm; /* set EP0 ep manage. */

    /* start recv setup data. */
    USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USBFS_Direction_OUT][USBFS_BufDesp_OddEven_Even], 1u, usb_ep0_buffer, sizeof(usb_setup_buff));
    usb_epmng_tbl[0u][USBFS_Direction_IN].data_n = true; /* the first Tx data's data_n is 1. */
}

void USB_TokenDoneHandler(uint8_t rhport) /* roothub port. */
{
    USBFS_BufDesp_Type             * bd = USBFS_GetBufDesp(BOARD_USB_PORT); /* get bd. */
    USBFS_TokenPid_Type           token = USBFS_BufDesp_GetTokenPid(bd); /* get token pid. */
    uint32_t                       size = USBFS_BufDesp_GetPacketSize(bd); /* get packet size. */
    uint8_t                      * addr = (uint8_t *)USBFS_BufDesp_GetPacketAddr(bd); /* get packet addr. */
    uint32_t                   ep_index = USBFS_GetEndPointIndex(BOARD_USB_PORT); /* which EP Xfer data. */
    USBFS_Direction_Type         ep_dir = USBFS_GetXferDirection(BOARD_USB_PORT); /* EP direction. */
    USBFS_BufDesp_OddEven_Type      odd = USBFS_GetBufDespOddEven(BOARD_USB_PORT); /* ODD_EVEN. */
    USBFS_BufDesp_Reset(bd);
    usb_epmng_tbl[ep_index][ep_dir].odd_even = !odd; /* toggle the bd odd_even flag. */
    USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_TOKENDONE);/* clear interrupt status. */

    if (0u == ep_index && USBFS_Direction_OUT == ep_dir ) /* ep0_out include setup packet & out_packet, need to special treatment */
    {
        if (USBFS_TokenPid_SETUP == token) /* setup packet. */
        {
            for (uint32_t i = 0; i < 8u; i++)
            {
                usb_setup_buff[i] = usb_ep0_buffer[i];
            }
            
            usb_ep0_buffer[0] = usb_setup_buff[0];/* usb_ep0_buffer not used, avoid warming.*/
            
            dcd_event_setup_received(rhport, addr, true);
            USBFS_SuspendCmd(BOARD_USB_PORT, DISABLE);
            usb_epmng_tbl[0u][USBFS_Direction_IN].data_n = true; /* next in packet is DATA1 packet. */
            usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_done = false;
            USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USBFS_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
        }
        else /* out packet. */
        {
            if (0 < size && NULL == usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_buf)
            {   /* received data, but tinyusb not prepared. */
                usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_done = true;
                USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USBFS_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
                return;
            }
            for (uint32_t i = 0; i < size; i++)
            {
                usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_buf[i] = usb_ep0_buffer[i];
            }
            dcd_event_xfer_complete(rhport, 0u, size, XFER_RESULT_SUCCESS, true);
            USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USBFS_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
        }

        /* Continue to receive out packets. */

        return;
    }

    /* xfer next packet if data length more than max_packet_size when start xfer data. */
    uint16_t max_packet_size = usb_epmng_tbl[ep_index][ep_dir].max_packet_size;
    uint16_t          length = usb_epmng_tbl[ep_index][ep_dir].length;
    uint16_t       remaining = usb_epmng_tbl[ep_index][ep_dir].remaining - size;
    if ( (remaining > 0u) && (size == usb_epmng_tbl[ep_index][ep_dir].max_packet_size) )
    {
        usb_epmng_tbl[ep_index][ep_dir].remaining = remaining;
        if(remaining > max_packet_size)
        {
            uint8_t *next_packet_addr    = addr + 2u * max_packet_size;
            uint16_t next_packet_size    = remaining - max_packet_size;
            if(next_packet_size > max_packet_size)
            {
                next_packet_size = max_packet_size;
            }
            USBFS_BufDesp_Xfer(bd,usb_epmng_tbl[ep_index][ep_dir].data_n, next_packet_addr, next_packet_size);
            usb_epmng_tbl[ep_index][ep_dir].data_n = !usb_epmng_tbl[ep_index][ep_dir].data_n;
        }
        return;
    }

    /* set addr. */
    if(size == 0u && 0u != usb_device_addr)/* ZLP, if usb_device_addr not equal 0, need to set addr to USB. */
    {
        USBFS_SetDeviceAddr(BOARD_USB_PORT, usb_device_addr);
        usb_device_addr = 0u;
    }

    /* report to tusb. */
    uint8_t ep_addr = ep_index;
    if (USBFS_Direction_IN == ep_dir)
    {
        ep_addr |= TUSB_DIR_IN_MASK;
    }
    dcd_event_xfer_complete(rhport,  ep_addr, length - remaining, XFER_RESULT_SUCCESS, true);
}

//--------------------------------------------------------------------+
// Controller API
//--------------------------------------------------------------------+

// Initialize controller to device mode
void dcd_init       (uint8_t rhport)
{
    (void) rhport;
    USBFS_Device_Init_Type init = {0u};
    init.BufDespTable_Addr = (uint32_t)&usb_bd_tbl;
    USBFS_InitDevice(BOARD_USB_PORT, &init);
    USBFS_Cmd(BOARD_USB_PORT, ENABLE);
    NVIC_ClearPendingIRQ(BOARD_USB_IRQn);
}

// Interrupt Handler
void dcd_int_handler(uint8_t rhport)
{
    uint32_t flag = USBFS_GetEnabledITStatus(BOARD_USB_PORT);

    if (flag & USBFS_IT_TOKENDONE)
    {
        USB_TokenDoneHandler(rhport);
        return;
    }

    if (flag & USBFS_IT_RESET)
    {
        USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_RESET);
        USBFS_BusResetHandler();

        dcd_event_bus_reset(rhport, TUSB_SPEED_FULL, true);
    }

    if (flag & USBFS_IT_SLEEP)
    {
        USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_SLEEP);

        dcd_event_bus_signal(rhport, DCD_EVENT_SUSPEND, true);
    }
    if (flag & USBFS_IT_RESUME)
    {
        USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_RESUME);

        dcd_event_bus_signal(rhport, DCD_EVENT_RESUME, true);
    }
    if (flag & USBFS_IT_STALL)
    {
        USBFS_EndPointStallCmd(BOARD_USB_PORT, DISABLE);  /* NOT RUN.!*/
        dcd_edpt_clear_stall(rhport, 0);
        USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USBFS_Direction_OUT][usb_epmng_tbl[0u][USBFS_Direction_OUT].odd_even], 1, usb_ep0_buffer, 64);
        USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_STALL);
    }
    if (flag & USBFS_IT_SOFTOK)
    {
        USBFS_ClearITPendingBit(BOARD_USB_PORT, USBFS_IT_SOFTOK);
    }
}

// Enable device interrupt
void dcd_int_enable (uint8_t rhport)
{
    (void) rhport;
    USBFS_ITConfig(BOARD_USB_PORT, USBFS_IT_RESET | USBFS_IT_TOKENDONE
                                            | USBFS_IT_SLEEP
                                            | USBFS_IT_RESUME
                                            | USBFS_IT_STALL
                                            | USBFS_IT_SOFTOK, ENABLE); /* enable interrupts*/
    NVIC_SetPriority(BOARD_USB_IRQn, 3u);
    NVIC_EnableIRQ(BOARD_USB_IRQn);
}

// Disable device interrupt
void dcd_int_disable(uint8_t rhport)
{
    (void) rhport;
    NVIC_DisableIRQ(BOARD_USB_IRQn);
    USBFS_ITConfig(BOARD_USB_PORT, USBFS_IT_RESET | USBFS_IT_TOKENDONE
                                            | USBFS_IT_SLEEP
                                            | USBFS_IT_RESUME
                                            | USBFS_IT_STALL
                                            | USBFS_IT_SOFTOK, DISABLE); /* disable interrupts*/
}

// Receive Set Address request, mcu port must also include status IN response
void dcd_set_address(uint8_t rhport, uint8_t dev_addr)
{
    usb_device_addr = dev_addr;
    /* get addr, Tx ZLP, then set addr to USB. */
    dcd_edpt_xfer(rhport, tu_edpt_addr(0, TUSB_DIR_IN), NULL, 0);
}

// Wake up host
void dcd_remote_wakeup(uint8_t rhport)
{
    (void) rhport;
    USBFS_ResumeSignalCmd(BOARD_USB_PORT, ENABLE);
    uint32_t i = CLOCK_SYS_FREQ / 100; /* 10ms. */
    while(i--)
    {
        __NOP();
    }
    USBFS_ResumeSignalCmd(BOARD_USB_PORT, DISABLE);
}

// Enable/Disable Start-of-frame interrupt. Default is disabled
void dcd_sof_enable(uint8_t rhport, bool en)
{
    (void) rhport;
    if (true == en)
    {
        USBFS_ITConfig(BOARD_USB_PORT, USBFS_IT_SOFTOK, ENABLE); /* enable interrupts*/
    }
    else
    {
        USBFS_ITConfig(BOARD_USB_PORT, USBFS_IT_SOFTOK, DISABLE); /* disable interrupts*/
    }
}

//--------------------------------------------------------------------+
// Endpoint API
//--------------------------------------------------------------------+

// Configure endpoint's registers according to descriptor
bool dcd_edpt_open            (uint8_t rhport, tusb_desc_endpoint_t const * desc_ep)
{
    (void) rhport;
    uint8_t ep_index = desc_ep->bEndpointAddress & 0x0fu;
    USBFS_Direction_Type ep_dir = USBFS_Direction_OUT;

    /* get direction. */
    if ((desc_ep->bEndpointAddress & TUSB_DIR_IN_MASK) == TUSB_DIR_IN_MASK)
    {
        ep_dir = USBFS_Direction_IN;
    }

    /* according to usb role, choose the EP mode. */
    USBFS_EndPointMode_Type ep_mode = USBFS_EndPointMode_Control;
    if     (TUSB_XFER_ISOCHRONOUS == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USBFS_EndPointMode_Isochronous;
    }
    else if(TUSB_XFER_BULK == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USBFS_EndPointMode_Bulk;
    }
    else if(TUSB_XFER_INTERRUPT == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USBFS_EndPointMode_Interrupt;
    }

    usb_epmng_tbl[ep_index][ep_dir].max_packet_size = desc_ep->wMaxPacketSize;

    USBFS_EndPointCmd(BOARD_USB_PORT, ep_index, ep_mode, ENABLE);/* enable EPx. */
    return true;
}

// Close all non-control endpoints, cancel all pending transfers if any.
// Invoked when switching from a non-zero Configuration by SET_CONFIGURE therefore
// required for multiple configuration support.
void dcd_edpt_close_all       (uint8_t rhport)
{
    for (uint32_t i = 0u; i < USBFS_BDT_EP_NUM; i++)
    {
        USBFS_EndPointCmd(BOARD_USB_PORT, i, USBFS_EndPointMode_NULL, DISABLE); /* disable all EndPoint. */
        usb_epmng_tbl[i][USBFS_Direction_IN ].max_packet_size = 0;
        usb_epmng_tbl[i][USBFS_Direction_IN ].remaining       = 0;
        usb_epmng_tbl[i][USBFS_Direction_OUT].max_packet_size = 0;
        usb_epmng_tbl[i][USBFS_Direction_OUT].remaining       = 0;
    }
}

// Close an endpoint.
// Since it is weak, caller must TU_ASSERT this function's existence before calling it.
void dcd_edpt_close           (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    usb_epmng_tbl[ep_addr & 0x0fu][USBFS_Direction_IN ].max_packet_size = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USBFS_Direction_IN ].remaining       = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USBFS_Direction_OUT].max_packet_size = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USBFS_Direction_OUT].remaining       = 0;
    USBFS_EndPointCmd(BOARD_USB_PORT, ep_addr & 0x0fu, USBFS_EndPointMode_NULL, DISABLE);
}

// Submit a transfer, When complete dcd_event_xfer_complete() is invoked to notify the stack
bool dcd_edpt_xfer            (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes)
{
    (void) rhport;
    uint32_t           ep_index = ep_addr & 0x0fu;
    USBFS_Direction_Type   ep_dir = (ep_addr & TUSB_DIR_IN_MASK) ? USBFS_Direction_IN : USBFS_Direction_OUT;
    uint32_t                odd = usb_epmng_tbl[ep_index][ep_dir].odd_even;
    uint32_t    max_packet_size = usb_epmng_tbl[ep_index][ep_dir].max_packet_size;
    uint32_t             data_n = usb_epmng_tbl[ep_index][ep_dir].data_n;

    if (0u == ep_index && ep_dir == USBFS_Direction_OUT)
    {
        if (true == usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_done)
        {
            for (uint32_t i = 0; i < total_bytes; i++)
            {
                buffer[i] = usb_ep0_buffer[i];
            }
            dcd_event_xfer_complete(rhport, 0u, total_bytes, XFER_RESULT_SUCCESS, ENABLE);
            usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_done = false;
        }
        else
        {
            usb_epmng_tbl[0u][USBFS_Direction_OUT].xfer_buf = buffer;
        }
        return true;
    }

    if ( USBFS_BufDesp_IsBusy(&usb_bd_tbl.Table[ep_index][ep_dir][odd]) ) /* BD.OWN not equal 0, mean BD owner is SIE, BD is busy. */
    {
        return false;
    }
    usb_epmng_tbl[ep_index][ep_dir].length    = total_bytes;
    usb_epmng_tbl[ep_index][ep_dir].remaining = total_bytes;
    if (total_bytes > max_packet_size) /* if xfer data length more than EP max_packet_size, divide data. */
    {
        /* more than double max_packet_size, xfer first two packet first. */
        uint32_t len2 = (total_bytes > 2u * max_packet_size) ? max_packet_size : (total_bytes - max_packet_size);
        USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd ^ 1u], data_n ^ 1u, buffer + max_packet_size, len2);
        USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd     ], data_n     , buffer                  , max_packet_size);
    }
    else
    {
        USBFS_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd], data_n, buffer, total_bytes);
        usb_epmng_tbl[ep_index][ep_dir].data_n ^= 1;
    }
    return true;
}

// Stall endpoint
void dcd_edpt_stall           (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    //uint32_t ep_index = ep_addr & 0x0fu;
    USBFS_EndPointStallCmd(BOARD_USB_PORT, ENABLE);
}

// clear stall, data toggle is also reset to DATA0
// This API never calls with control endpoints, since it is auto cleared when receiving setup packet
void dcd_edpt_clear_stall     (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    //uint32_t ep_index = ep_addr & 0x0fu;
    USBFS_EndPointStallCmd(BOARD_USB_PORT, DISABLE);
}

/* USB IRQ. */
void BOARD_USB_IRQHandler(void)
{
    dcd_int_handler(BOARD_TUD_RHPORT);
}

void USB_DeviceClockInit(void)
{
//    GPIO_InitTypeDef GPIO_InitStruct;
    /* Select USBCLK source */
    if(RCC_GetHCLKFreq() == 96000000){
        RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_Div2);
    }
    else if(RCC_GetHCLKFreq() == 48000000){
        RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_Div1);
    }
    else{
        //HCLK is not fit of USB Clock
        while(1){
            __NOP();
        };
    }

    /* Enable USB clock */
    RCC_AHB2PeriphClockCmd(RCC_AHB2ENR_USBFS, ENABLE);
    // sys time init;


//    // PD7-KEY1
//    GPIO_StructInit(&GPIO_InitStruct);
//    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_7;
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_IPU;
//    GPIO_Init(GPIOD, &GPIO_InitStruct);
//    
//    RCC_AHBPeriphClockCmd(RCC_AHBENR_GPIOD,ENABLE);
}

// Control led pattern using phase duration in ms.
// For each phase, LED is toggle then repeated, board_led_task() is required to be called
//void board_led_pattern(uint32_t const phase_ms[], uint8_t count);

// Get the current state of button
// a '1' means active (pressed), a '0' means inactive.
uint32_t board_button_read(void)
{
  if (GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_7) == RESET)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// Get characters from UART. Return number of read bytes
int board_uart_read(uint8_t *buf, int len)
{
  if (UART1->CSR & UART_FLAG_RXAVL)
  {
    buf[0] = UART1->RDR;
    return 1;
  }
  else
  {
    return 0;
  }
}

// Send characters to UART. Return number of sent bytes
int board_uart_write(void const *buf, int len)
{
  for (int i = 0; i < len; i++)
  {
    putchar(((char*)(buf))[i]);
  }
  return len;
}

void board_led_write(bool state)
{
  if (state)
  {
      GPIO_SetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_15);
  }
  else
  {
      GPIO_ResetBits(GPIOA, GPIO_Pin_0|GPIO_Pin_15);
  };
}

#if CFG_TUSB_OS == OPT_OS_NONE
volatile static uint32_t systime = 0;
// Get current milliseconds, must be implemented when no RTOS is used
uint32_t board_millis(void)
{
  return systime;
}

//void SysTick_Handler(void)
//{
//  systime++;
//}
#endif

// stdio getchar() is blocking, this is non-blocking version
int board_getchar(void)
{
  if (UART1->CSR & UART_FLAG_RXAVL)
  {
    return UART1->RDR;
  }
  else
  {
    return 0;
  }
}

#endif /* BOARD_TUD_RHPORT */
