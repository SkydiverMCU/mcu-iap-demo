/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#include "tusb_option.h"
#include "Queue.h"

#if (TUSB_OPT_DEVICE_ENABLED && CFG_TUD_PRINTER)

#include "common/tusb_common.h"
#include "printer_device.h"
#include "device/usbd_pvt.h"
#include "device/dcd.h"         // for faking dcd_event_xfer_complete
//#include "tusb_compiler.h"

#include "Queue.h"

//--------------------------------------------------------------------+
// MACRO CONSTANT TYPEDEF
//--------------------------------------------------------------------+
enum {
    BULK_PACKET_SIZE = (TUD_OPT_HIGH_SPEED ? 512 : 64)
};

typedef struct {
    uint8_t itf_num;
    uint8_t ep_notif;
    uint8_t ep_in;
    uint8_t ep_out;

    // FIFO
    //tu_fifo_t rx_ff;
    tu_fifo_t tx_ff;
    
    

    //uint8_t rx_ff_buf[CFG_TUD_PRINTER_EP_BUFSIZE*10];
    uint8_t tx_ff_buf[CFG_TUD_PRINTER_EP_BUFSIZE*10];

#if CFG_FIFO_MUTEX
    osal_mutex_def_t rx_ff_mutex;
    osal_mutex_def_t tx_ff_mutex;
#endif

    // Endpoint Transfer buffer
    CFG_TUSB_MEM_ALIGN uint8_t epout_buf[CFG_TUD_PRINTER_EP_BUFSIZE];
    CFG_TUSB_MEM_ALIGN uint8_t epin_buf[CFG_TUD_PRINTER_EP_BUFSIZE];

} printer_interface_t;



CFG_TUSB_MEM_ALIGN static printer_interface_t _printer_itf[1];
//CFG_TUSB_MEM_ALIGN static uint8_t _printer_buf[CFG_TUD_PRINTER_EP_BUFSIZE];


//--------------------------------------------------------------------+
// Debug
//--------------------------------------------------------------------+
#if CFG_TUSB_DEBUG >= 2


#endif


//--------------------------------------------------------------------+
QUEUE8_t m_QueueUsbRx         = {0};

uint8_t  m_UsbRxBuf[USB_RX_BUF_SIZE]      = {0};  

volatile uint8_t Flag_free_EP = 0;  

uint8_t usb_release_Buffer[CFG_TUD_PRINTER_EP_BUFSIZE*12];
//--------------------------------------------------------------------+
// APPLICATION API
//--------------------------------------------------------------------+
static void _prep_printer_out_transaction (printer_interface_t* p_printer)
{
    uint8_t const rhport = TUD_OPT_RHPORT;
    uint16_t buff_Remaining = 0;
    uint16_t   data_len = QUEUE_PacketLengthGet(&m_QueueUsbRx);
    buff_Remaining = USB_RX_BUF_SIZE - data_len;
    
    // Prepare for incoming data but only allow what we can store in the ring buffer.
    // TODO Actually we can still carry out the transfer, keeping count of received bytes
    // and slowly move it to the FIFO when read().
    // This pre-check reduces endpoint claiming
    TU_VERIFY(buff_Remaining >= sizeof(p_printer->epout_buf), );
    // claim endpoint
    TU_VERIFY(usbd_edpt_claim(rhport, p_printer->ep_out), );

    // fifo can be changed before endpoint is claimed
   // data_len = tu_fifo_remaining(&p_printer->rx_ff);    

    if ( buff_Remaining >= sizeof(p_printer->epout_buf) ) 
    {
        usbd_edpt_xfer(rhport, p_printer->ep_out, p_printer->epout_buf, sizeof(p_printer->epout_buf));
    }
    else {
        // Release endpoint since we don't make any transfer
        //usbd_edpt_release(rhport, p_printer->ep_out);
        Flag_free_EP = 1; 
        TU_LOG1("Queue full................\r\n");
    }
}


uint32_t tud_priter_n_write_flush (uint8_t itf)
{
    printer_interface_t* p_printer = &_printer_itf[itf];

    // Skip if usb is not ready yet
    TU_VERIFY( tud_ready(), 0 );

    // No data to send
    if ( !tu_fifo_count(&p_printer->tx_ff) ) return 0;

    uint8_t const rhport = TUD_OPT_RHPORT;

    // Claim the endpoint
    TU_VERIFY( usbd_edpt_claim(rhport, p_printer->ep_in), 0 );

    // Pull data from FIFO
    uint16_t const count = tu_fifo_read_n(&p_printer->tx_ff, p_printer->epin_buf, sizeof(p_printer->epin_buf));

    if ( count ) {
        TU_ASSERT( usbd_edpt_xfer(rhport, p_printer->ep_in, p_printer->epin_buf, count), 0 );
        return count;
    }
    else {
        // Release endpoint since we don't make any transfer
        // Note: data is dropped if terminal is not connected
        usbd_edpt_release(rhport, p_printer->ep_in);
        return 0;
    }
}


uint32_t tud_printer_n_write(uint8_t itf, void const* buffer, uint32_t bufsize)
{
//    cdcd_interface_t* p_cdc = &_cdcd_itf[itf];
    printer_interface_t* p_printer = &_printer_itf[itf];
    
    uint16_t ret = tu_fifo_write_n(&p_printer->tx_ff, buffer, bufsize);

    // flush if queue more than packet size
    if ( tu_fifo_count(&p_printer->tx_ff) ) 
    {
        tud_priter_n_write_flush(itf);
    }

    return ret;
}

//--------------------------------------------------------------------+
// USBD Driver API
//--------------------------------------------------------------------+
void printer_init(void)
{
    tu_memclr(&_printer_itf, sizeof(_printer_itf));
    
    for(uint8_t i = 0; i < CFG_TUD_PRINTER; i++) {
        printer_interface_t* p_printer = &_printer_itf[i];


        // Config RX fifo
        //tu_fifo_config(&p_printer->rx_ff, p_printer->rx_ff_buf, TU_ARRAY_SIZE(p_printer->rx_ff_buf), 1, false);

        // Config TX fifo as overwritable at initialization and will be changed to non-overwritable
        // if terminal supports DTR bit. Without DTR we do not know if data is actually polled by terminal.
        // In this way, the most current data is prioritized.
        tu_fifo_config(&p_printer->tx_ff, p_printer->tx_ff_buf, TU_ARRAY_SIZE(p_printer->tx_ff_buf), 1, true);

#if CFG_FIFO_MUTEX
        tu_fifo_config_mutex(&p_cdc->rx_ff, NULL, osal_mutex_create(&p_cdc->rx_ff_mutex));
        tu_fifo_config_mutex(&p_cdc->tx_ff, osal_mutex_create(&p_cdc->tx_ff_mutex), NULL);
#endif
    }    
}

void printer_reset(uint8_t rhport)
{
    (void) rhport;
    for(uint8_t i = 0; i < CFG_TUD_PRINTER; i++) {
        printer_interface_t* p_printer = &_printer_itf[i];
        tu_memclr(p_printer, offsetof(printer_interface_t, tx_ff));
        //tu_fifo_clear(&p_printer->rx_ff);
        tu_fifo_clear(&p_printer->tx_ff);
        tu_fifo_set_overwritable(&p_printer->tx_ff, true);
    }
}

uint16_t printer_open(uint8_t rhport, tusb_desc_interface_t const* itf_desc, uint16_t max_len)
{
    // Find available interface
    printer_interface_t* p_printer = NULL;
    for(uint8_t id = 0; id < CFG_TUD_CDC; id++) {
        if ( _printer_itf[id].ep_in == 0 ) {
            p_printer = &_printer_itf[id];
            break;
        }
    }
    TU_ASSERT(p_printer, 0);

    //------------- Control Interface -------------//
    p_printer->itf_num = itf_desc->bInterfaceNumber;

    uint16_t drv_len = sizeof(tusb_desc_interface_t);
    uint8_t const* p_desc = tu_desc_next( itf_desc );


    // Communication Functional Descriptors
    while ( TUSB_DESC_CS_INTERFACE == tu_desc_type(p_desc) && drv_len <= max_len ) {
        drv_len += tu_desc_len(p_desc);
        p_desc   = tu_desc_next(p_desc);
    }

    if ( TUSB_DESC_ENDPOINT == tu_desc_type(p_desc) ) {
        // notification endpoint if any
        //TU_ASSERT( usbd_edpt_open(rhport, (tusb_desc_endpoint_t const*) p_desc), 0 );

        p_printer->ep_notif = ((tusb_desc_endpoint_t const*) p_desc)->bEndpointAddress;
        TU_ASSERT( usbd_open_edpt_pair(rhport, p_desc, 2, TUSB_XFER_BULK, &p_printer->ep_out, &p_printer->ep_in), 0 );

        drv_len += 2 * sizeof(tusb_desc_endpoint_t);
        p_desc   = tu_desc_next(p_desc);
    }



    // Prepare for incoming data
    _prep_printer_out_transaction(p_printer);

    return drv_len;
}
// Invoked when a control transfer occurred on an interface of this class
// Driver response accordingly to the request and the transfer stage (setup/data/ack)
// return false to stall control endpoint (e.g unsupported request)
bool printer_control_xfer_cb(uint8_t rhport, uint8_t stage, tusb_control_request_t const* p_request)
{
    uint8_t  * devicedesc;
    // nothing to do with DATA & ACK stage
    if (stage != CONTROL_STAGE_SETUP) return true;
        // Handle class request only
    TU_VERIFY(p_request->bmRequestType_bit.type == TUSB_REQ_TYPE_CLASS);
    
    switch ( p_request->bRequest ) {
        case 0x00:
             devicedesc = tud_printer_device_id_cb();
             tud_control_xfer(rhport, p_request, (void*) devicedesc, devicedesc[1]);
        
            break;
        case 0x01:
             devicedesc = tud_printer_device_id_cb();
             tud_control_xfer(rhport, p_request, (void*) devicedesc, devicedesc[1]);
            break;
        default:
            return false; // stall unsupported request
    }

    return true;
}


bool printer_xfer_cb(uint8_t rhport, uint8_t ep_addr, xfer_result_t event, uint32_t xferred_bytes)
{
    //(void) result;

    uint8_t itf;
    printer_interface_t* p_printer;

    // Identify which interface to use
    for (itf = 0; itf < CFG_TUD_PRINTER; itf++) {
        p_printer = &_printer_itf[itf];
        if ( ( ep_addr == p_printer->ep_out ) || ( ep_addr == p_printer->ep_in ) ) break;
    }
    TU_ASSERT(itf < CFG_TUD_PRINTER);

    // Received new data
    if ( ep_addr == p_printer->ep_out ) {
        
        //tu_fifo_write_n(&p_printer->rx_ff, &p_printer->epout_buf, xferred_bytes);
        
        //TU_LOG1("EP read = %d\r\n",xferred_bytes);
        
        USB_RxWrite(p_printer->epout_buf,xferred_bytes);

        _prep_printer_out_transaction(p_printer);
        //usbd_edpt_xfer(rhport, p_printer->ep_out, p_printer->epout_buf, sizeof(p_printer->epout_buf));
    }

    // Data sent to host, we continue to fetch from tx fifo to send.
    // Note: This will cause incorrect baudrate set in line coding.
    //       Though maybe the baudrate is not really important !!!
    if ( ep_addr == p_printer->ep_in ) {
        // invoke transmit callback to possibly refill tx fifo
        //if ( tud_cdc_tx_complete_cb ) tud_cdc_tx_complete_cb(itf);
        if ( 0 == tud_priter_n_write_flush(itf) ) {
            // If there is no data left, a ZLP should be sent if
            // xferred_bytes is multiple of EP Packet size and not zero
            if ( !tu_fifo_count(&p_printer->tx_ff) && xferred_bytes && (0 == (xferred_bytes & (BULK_PACKET_SIZE - 1))) ) 
            {
                if ( usbd_edpt_claim(rhport, p_printer->ep_in) ) {
                    usbd_edpt_xfer(rhport, p_printer->ep_in, NULL, 0);
                }
            }
        }
    }
    
    return true;
}

//--------------------------------------------------------------------+
// User process API
//--------------------------------------------------------------------+

void New_queue_create(void)
{
    QUEUE_PacketCreate(&m_QueueUsbRx, m_UsbRxBuf, sizeof(m_UsbRxBuf));
    TU_LOG1("User Queue create success\r\n");
}    


/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
uint32_t USB_RxRead(uint8_t *buffter, uint32_t buffterSize)
{
    return QUEUE_PacketOut(&m_QueueUsbRx, buffter, buffterSize);
}


/***********************************************************************************************************************
  * @brief
  * @note   none
  * @param  none
  * @retval none
  *********************************************************************************************************************/
uint32_t USB_RxWrite(uint8_t *buffter, uint32_t writeLen)
{
    return QUEUE_PacketIn(&m_QueueUsbRx, buffter, writeLen);
}

/*******************************************************************************
* Function Name  : 
* Description    : 
*                  routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
volatile uint32_t total_len;
uint8_t Test_tx_data[64]={0xA0,0xA1,0xA2,0xA3,0xA4};

void tud_printer_task(void)
{
    uint16_t data_len = 0;
    uint8_t tmp_index;
    uint8_t Tx_buff[64]={0};
    uint8_t index = 0;
    
    printer_interface_t* p_printer = &_printer_itf[0];
    uint8_t const rhport = TUD_OPT_RHPORT;   
    
    __disable_irq();
    data_len = QUEUE_PacketLengthGet(&m_QueueUsbRx);
    __enable_irq();
    

    if(data_len < (USB_RX_BUF_SIZE - 128))			
    {
        
        if(Flag_free_EP) 
        {		
                usbd_edpt_xfer(rhport, p_printer->ep_out, p_printer->epout_buf, sizeof(p_printer->epout_buf));                
                //usbd_edpt_xfer(rhport, p_printer->ep_out, p_printer->epout_buf, sizeof(p_printer->epout_buf));
                Flag_free_EP = 0;
                TU_LOG1("Queue release.................\r\n");
        }

    }                            

    if(data_len)
    {

        if(data_len <=64)
        {
          tmp_index = data_len;

        }
        else
        {
          tmp_index = 64;
        }
        
        __disable_irq();
        USB_RxRead(Tx_buff,tmp_index);
        __enable_irq();
        
        for(index=0;index<tmp_index;index++)
        {
          printf("%02x ",Tx_buff[index]);
            total_len++;
            
        }
        printf("\r\n");
        printf("%06d ",total_len);
        printf("\r\n");
        
//        if(total_len == 83750)
//        {
//           tud_printer_n_write(0, Test_tx_data,6);   //IN data
//           printf("tud_printer_n_write success\r\n");
//        }
        
        memset(Tx_buff,0,64);			
        data_len = 0;
        
    }    
    
}

#endif
