////////////////////////////////////////////////////////////////////////////////
/// @file     hal_usb.c
/// @author   AE TEAM
/// @brief    THIS FILE PROVIDES ALL THE EXTI FIRMWARE FUNCTIONS.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion
#define _HAL_USB_C_

// Files includes
#include "hal_usb.h"

volatile static uint32_t * USB_GetEPINTEN(USB_TypeDef * USBx, uint32_t ep_index)
{
    volatile uint32_t * inten_index[] =
    {
        &USBx->EP0_INT_EN,
        &USBx->EPx_INT_EN[0],
        &USBx->EPx_INT_EN[1],
        &USBx->EPx_INT_EN[2],
        &USBx->EPx_INT_EN[3],
    };
    return inten_index[ep_index];
}

volatile static uint32_t * USB_GetEPINTSTATE(USB_TypeDef * USBx, uint32_t ep_index)
{
    volatile uint32_t * inten_index[] =
    {
        &USBx->EP0_INT_STATE,
        &USBx->EPx_INT_STATE[0],
        &USBx->EPx_INT_STATE[1],
        &USBx->EPx_INT_STATE[2],
        &USBx->EPx_INT_STATE[3],
    };
    return inten_index[ep_index];
}

bool USB_Init(USB_TypeDef * USBx, USB_Init_Type * init)
{
    USB_Reset(USBx);
    
    if(USB_Speed_Full == init->Speed)
    {   /* full speed. */
        USBx->TOP &= ~USB_TOP_SPEED;
    }
    else
    {   
        USBx->TOP |= USB_TOP_SPEED;
    }
    
    /* make usb module work. */
    USBx->POWER = USB_POWER_SUSPEN | USB_POWER_SUSP;
    return true;
}

void USB_Enable(USB_TypeDef * USBx, bool enable)
{
    if(enable)
    {   /* connect usb. */
        USBx->TOP |=  USB_TOP_CONNECT;
    }
    else
    {   /* disconnect usb. */
        USBx->TOP &= ~USB_TOP_CONNECT;
    }
}

void USB_Reset(USB_TypeDef * USBx)
{
    /* reset usb. */
    USBx->TOP |=  USB_TOP_RESET;
    USBx->TOP &= ~USB_TOP_RESET;

    USB_SetDeviceAddr(USB, 0x00u);
}

bool USB_EnableEndPoint(USB_TypeDef * USBx, uint32_t index, bool enable)
{
    if(USB_EP_NUM > index)
    {   /* enable end point. */
        if(enable)
        {
            USBx->EP_EN |=  (1 << index);
        }
        else
        {
            USBx->EP_EN &= ~(1 << index);
        }
        
        USBx->EPx_CTRL[index] = 0;
        return true;
    }
    else
    { /* if index more than max end point num, return false. */
        return false;
    }
}

void USB_EnableInterrupts(USB_TypeDef * USBx, uint32_t interrupts, bool enable)
{
    if(enable)
    {
        USBx->INT_EN |=  interrupts;
    }
    else
    {
        USBx->INT_EN &= ~interrupts;
    }
}

uint32_t USB_GetEnabledInterrupts(USB_TypeDef * USBx)
{
    return USBx->INT_EN;
}

uint32_t USB_GetInterruptStatus(USB_TypeDef * USBx)
{
    uint32_t en   = USBx->INT_EN;
    uint32_t stat = USBx->INT_STATE;
    return stat & en;
}

void USB_ClearInterruptStatus(USB_TypeDef * USBx, uint32_t interrupts)
{
    USBx->INT_STATE = interrupts;
}

void USB_EnableEndPointInterrupts(USB_TypeDef * USBx, uint32_t ep_index, uint32_t interrupts, bool enable)
{
    if(enable)
    {
        USBx->EP_INT_EN |=  (1u << ep_index);
        *USB_GetEPINTEN(USBx, ep_index) |=  interrupts;
    }
    else
    {
        *USB_GetEPINTEN(USBx, ep_index) &= ~interrupts;
        if(0 == *USB_GetEPINTEN(USBx, ep_index))
        {
            USBx->EP_INT_EN &= ~(1u << ep_index);
        }
    }
}

uint32_t USB_GetEnabledEndPointInterrupts(USB_TypeDef * USBx, uint32_t ep_index)
{
    return *USB_GetEPINTEN(USBx, ep_index);
}

uint32_t USB_GetEndPointInterruptStatus(USB_TypeDef * USBx, uint32_t ep_index)
{
    uint32_t ep_flag = USBx->EP_INT_STATE;
    if(0 == (ep_flag & (1u << ep_index)))
    {
        return 0;
    }

    if(0 == ep_index)
    {
        uint32_t en   = USBx->EP0_INT_EN;
        uint32_t stat = USBx->EP0_INT_STATE;
        return stat & en;
    }
    else if(USB_EP_NUM > ep_index)
    {
        uint32_t en   = USBx->EPx_INT_EN[ep_index - 1];
        uint32_t stat = USBx->EPx_INT_STATE[ep_index - 1];
        return stat & en;
    }
    return 0;
}

void USB_ClearEndPointInterruptStatus(USB_TypeDef * USBx, uint32_t ep_index, uint32_t interrupts)
{
    * USB_GetEPINTSTATE(USBx, ep_index) = interrupts;
}

void USB_SetDeviceAddr(USB_TypeDef * USBx, uint8_t addr)
{
    USBx->ADDR = addr;
}

uint8_t USB_GetDeviceAddr(USB_TypeDef * USBx)
{
    return USBx->ADDR;
}

bool USB_EndPoint_PutPacket(USB_TypeDef * USBx, uint32_t ep_index, uint8_t * data, uint32_t len)
{
    uint32_t i;
    
    if(USB_EndPoint_Busy(USBx, ep_index) || len > 64)
    {
        return false;
    }
    
    for (i = 0; i < len; i++)
    {
        USBx->EPx_FIFO[ep_index] = data[i];
    }
    
    USBx->EPx_CTRL[ep_index] = EPn_CTRL_TRANEN | len;
    return true;
}

uint32_t USB_EndPoint_GetPacket(USB_TypeDef * USBx, uint32_t ep_index, uint8_t * data)
{
    if(USB_EndPoint_Busy(USBx, ep_index))
    {
        return 0;
    }
    
    uint32_t len = USBx->EPx_AVAIL[ep_index];
    
    for(uint32_t i = 0; i < len; i++)
    {
        data[i] = USBx->EPx_FIFO[ep_index];
    }
    return len;
}

void USB_EndPoint0_GetSetupPacket(USB_TypeDef * USBx, uint8_t * data)
{
    for (uint32_t i = 0; i < 8; i++)
    {
        data[i] = USBx->SETUPx[i];
    }
}

bool USB_EndPoint_Busy(USB_TypeDef * USBx, uint32_t ep_index)
{
    if(USB_EP_NUM > ep_index)
    {
        if (USBx->EPx_CTRL[ep_index] & 0x80)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return true; /* An endpoint that does not exist is considered a busy endpoint. */
}

void USB_EnableEndPointStall(USB_TypeDef * USBx, uint32_t ep_stall, bool enable)
{
    if(enable)
    {
        USBx->EP_HALT |=  ep_stall;
    }
    else
    {
        USBx->EP_HALT &= ~ep_stall;
    }
}

uint32_t USB_GetEnabledEndPointStall(USB_TypeDef * USBx)
{
    return USBx->EP_HALT;
}


void USB_EnableResumeSignal(USB_TypeDef * USBx, bool enable)
{
    if(enable)
    {
        USBx->POWER |=  USB_POWER_WKUP;
    }
    else
    {
        USBx->POWER &= ~USB_POWER_WKUP;
    }
}

void USB_EnableSuspend(USB_TypeDef * USBx, bool enable)
{
    USBx->POWER |= USB_POWER_SUSPEN;
    
    if(enable)
    {
        USBx->POWER &= ~USB_POWER_SUSP;
    }
    else
    {
        USBx->POWER |=  USB_POWER_SUSP;
    }
}

/* EOF. */
