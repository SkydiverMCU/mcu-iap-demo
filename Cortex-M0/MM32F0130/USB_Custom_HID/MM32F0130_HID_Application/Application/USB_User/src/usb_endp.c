////////////////////////////////////////////////////////////////////////////////
/// @file     usb_endp.C
/// @author   AE TEAM
/// @brief    THIS FILE PROVIDES ALL THE ADC FIRMWARE FUNCTIONS.
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
#define _USB_ENDP_C_

// Files includes
#include "platform_config.h"
#include "mm32_device.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "hal_exti.h"
#include "hal_gpio.h"
#include "hal_adc.h"
#include "hal_uart.h"

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup MM32_Hardware_Abstract_Layer
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup USB_HAL
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup USB_Exported_Functions
/// @{
uint8_t Receive_Buffer[BUFF_SIZE];
__IO uint8_t gTxDataCnt = 0;
////////////////////////////////////////////////////////////////////////////////
/// @brief  EP1 OUT Callback Routine.
/// @param  None.
/// @retval None.
////////////////////////////////////////////////////////////////////////////////
void EP3_OUT_Callback(void)
{
    gTxDataCnt = _GetUSB_AVILn(ENDP3);
    PMAToUserBufferCopy(Receive_Buffer, ENDP3, gTxDataCnt);

}

/// @}

/// @}

/// @}

