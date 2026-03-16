////////////////////////////////////////////////////////////////////////////////
/// @file     hal_usb.h
/// @author   AE TEAM
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE EXTI
///           FIRMWARE LIBRARY.
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
#ifndef __HAL_USB_H
#define __HAL_USB_H

// Files includes
#include "types.h"
#include "reg_common.h"
#include "reg_usb.h"

/*!
 * @addtogroup USB
 * @{
 */

/*!
 * @brief USB support max end point number.
 */
#define USB_EP_NUM    5u

/*!
 * @brief USB support max packet size.
 */
#define USB_MAX_PACKET_SIZE     64u

/*!
 * @addtogroup USB_INT
 * @{
 */
#define USB_INT_EPINT           USB_INT_STATE_EPINTF        /*!< USB Interrupt: end point interrupt. */
#define USB_INT_SOFTOK          USB_INT_STATE_SOFF 	        /*!< USB Interrupt: recv a SOF_Tok.      */
#define USB_INT_RESUME          USB_INT_STATE_RESUMF        /*!< USB Interrupt: resume.              */
#define USB_INT_SLEEP           USB_INT_STATE_SUSPENDF      /*!< USB Interrupt: sleep.               */
#define USB_INT_RESET           USB_INT_STATE_RSTF          /*!< USB Interrupt: reset.               */
/*!
 * @}
 */

/*!
 * @addtogroup USB_INT_EP
 * @{
 */
#define USB_INT_EP_OUTSTALL      EPn_INT_STATE_OUTSTALL  /*!< USB EP Interrupt: out stall.  */
#define USB_INT_EP_OUTACK        EPn_INT_STATE_OUTACK    /*!< USB EP Interrupt: out ack.    */
#define USB_INT_EP_OUTNACK       EPn_INT_STATE_OUTNACK   /*!< USB EP Interrupt: out nack.   */
#define USB_INT_EP_INSTALL       EPn_INT_STATE_INSTALL   /*!< USB EP Interrupt: in stall.   */
#define USB_INT_EP_INACK         EPn_INT_STATE_INACK 	 /*!< USB EP Interrupt: in ack.     */
#define USB_INT_EP_INNACK        EPn_INT_STATE_INNACK    /*!< USB EP Interrupt: in nack.    */
#define USB_INT_EP_END           EPn_INT_STATE_END       /*!< USB EP Interrupt: end xfer.   */
#define USB_INT_EP_SETUP         EPn_INT_EN_SETUPIE      /*!< USB EP Interrupt: setup.      */
/*!
 * @}
 */

/*!
 * @addtogroup USB_EP
 * @brief USB EndPoint mask codes
 * @{
 */
#define USB_EP_0     (1u << 0u ) /*!< EndPoint 0. */
#define USB_EP_1     (1u << 1u ) /*!< EndPoint 1. */
#define USB_EP_2     (1u << 2u ) /*!< EndPoint 2. */
#define USB_EP_3     (1u << 3u ) /*!< EndPoint 3. */
#define USB_EP_4     (1u << 4u ) /*!< EndPoint 4. */
/*!
 * @}
 */

/*!
 * @brief USB Speed type.
 */
typedef enum
{
    USB_Speed_Full = 1,        /*< USB Full Speed (FS). */
    USB_Speed_Low,
} USB_Speed_Type;

/*!
 * @brief USB Init type.
 */
typedef struct
{
    USB_Speed_Type Speed;           /*< USB Speed Choose. */
} USB_Init_Type;

/*!
 * @brief Initialize the USB module.
 *
 * @param USBx USB instance.
 * @param init Pointer to the initialization structure. See to @ref USB_Init_Type.
 * @return None.
 */
bool USB_Init(USB_TypeDef * USBx, USB_Init_Type * init);

/*!
 * @brief Enable USB.
 *
 * @param USBx USB instance.
 * @param enable 'true' to enable the USB connect, 'false' to disable the USB connect (USB disconnect).
 * @return None.
 */
void USB_Enable(USB_TypeDef * USBx, bool enable);

/*!
 * @brief Reset USB Controller & FIFO.
 *
 * @param USBx USB instance.
 * @return None.
 */
void USB_Reset(USB_TypeDef * USBx);

/*!
 * @brief Enable the EndPoint.
 *
 * @param USBx USB instance.
 * @param index EndPoint index.
 * @param enable 'true' to enable the EndPoint, 'false' to disable the EndPoint.
 * @return None.
 */
bool USB_EnableEndPoint(USB_TypeDef * USBx, uint32_t ep_index, bool enable);

/*!
 * @brief Enable interrupts of the USB module.
 *
 * @param USBx USB instance.
 * @param interrupts Interrupt code masks. See to @ref USB_INT.
 * @param enable 'true' to enable the indicated interrupts, 'false' to disable the indicated interrupts.
 * @return None.
 */
void USB_EnableInterrupts(USB_TypeDef * USBx, uint32_t interrupts, bool enable);

/*!
 * @brief Get the enabled interrupts status flags of the USB module.
 *
 * @param USBx USB instance.
 * @return Interrupt status flags. See to @ref USB_INT.
 */
uint32_t USB_GetEnabledInterrupts(USB_TypeDef * USBx);

/*!
 * @brief Get the interrupts status flags of the USB module.
 *
 * @param USBx USB instance.
 * @return Interrupt status flags. See to @ref USB_INT.
 */
uint32_t USB_GetInterruptStatus(USB_TypeDef * USBx);

/*!
 * @brief Clear the interrupts status flags of the USB module.

 * @param USBx USB instance.
 * @param interrupts Interrupt status flags. See to @ref USB_INT.
 * @return None.
 */
void USB_ClearInterruptStatus(USB_TypeDef * USBx, uint32_t interrupts);

/*!
 * @brief Enable interrupts of the USB EndPoint.
 *
 * @param USBx USB instance.
 * @param ep_index EndPoint index.
 * @param interrupts Interrupt code masks. See to @ref USB_INT_EP.
 * @param enable 'true' to enable the indicated interrupts, 'false' to disable the indicated interrupts.
 * @return None.
 */
void USB_EnableEndPointInterrupts(USB_TypeDef * USBx, uint32_t ep_index, uint32_t interrupts, bool enable);

/*!
 * @brief Get the enabled interrupts status flags of the USB EndPoint.
 *
 * @param USBx USB instance.
 * @param ep_index EndPoint index.
 * @return Interrupt status flags. See to @ref USB_INT_EP.
 */
uint32_t USB_GetEnabledEndPointInterrupts(USB_TypeDef * USBx, uint32_t ep_index);

/*!
 * @brief Get the interrupts status flags of the USB EndPoint.
 *
 * @param USBx USB instance.
 * @return Interrupt status flags. See to @ref USB_INT_EP.
 */
uint32_t USB_GetEndPointInterruptStatus(USB_TypeDef * USBx, uint32_t ep_index);

/*!
 * @brief Clear the interrupts status flags of the USB EndPoint.

 * @param USBx USB instance.
 * @param interrupts Interrupt status flags. See to @ref USB_INT_EP.
 * @return None.
 */
void USB_ClearEndPointInterruptStatus(USB_TypeDef * USBx, uint32_t ep_index, uint32_t interrupts);

/*!
 * @brief Set Device address, This address is distribute by host.
 *
 * @param USBx USB instance.
 * @param addr The Device address.
 * @return None.
 */
void USB_SetDeviceAddr(USB_TypeDef * USBx, uint8_t addr);

/*!
 * @brief Get Device address.
 *
 * @param USBx USB instance.
 * @return The Device address.
 */
uint8_t USB_GetDeviceAddr(USB_TypeDef * USBx);

/*!
 * @brief Put packet to host.
 *
 * @param USBx USB instance.
 * @param ep_index EndPoint index.
 * @param data the address of data.
 * @param len Data length.
 * @return 'true': EndPoint can be xfer data, 'false': EndPoint is busy.
 */
bool USB_EndPoint_PutPacket(USB_TypeDef * USBx, uint32_t ep_index, uint8_t * data, uint32_t len);

/*!
 * @brief Get packet from host.
 *
 * @param USBx USB instance.
 * @param ep_index EndPoint index.
 * @param data the address of data.
 * @return Data length.
 */
uint32_t USB_EndPoint_GetPacket(USB_TypeDef * USBx, uint32_t ep_index, uint8_t * data);

/*!
 * @brief Get setup packet from host.
 *
 * @param USBx USB instance.
 * @param data the address of data.
 * @return None.
 */
void USB_EndPoint0_GetSetupPacket(USB_TypeDef * USBx, uint8_t * data);

/*!
 * @brief Check whether EndPoint is busy.
 *
 * @param USBx USB instance.
 * @return 'true': EndPoint is busy, 'false': EndPoint is not busy.
 */
bool USB_EndPoint_Busy(USB_TypeDef * USBx, uint32_t ep_index);

/*!
 * @brief Stall EndPoint n.
 *
 * @param USBx USB instance.
 * @param ep_mask EndPoint mask, see to @ref USB EndPointStall mask codes.
 * @return None.
 */
void USB_EnableEndPointStall(USB_TypeDef * USBx, uint32_t ep_mask, bool enable);

/*!
 * @brief Get EndPoint stall status.
 *
 * @param USBx USB instance.
 * @return stall status, see to @ref USB EndPointStall mask codes.
 */
uint32_t USB_GetEnabledEndPointStall(USB_TypeDef * USBx);

/*!
 * @brief Enable USB Resume signal.
 *
 * @param USBx USB instance.
 * @param enable 'true' to enable the resume signal, 'false' to disable the resume signal.
 * @return None.
 */
void USB_EnableResumeSignal(USB_TypeDef * USBx, bool enable);

/*!
 * @brief Enable USB Resume signal.
 *
 * @param USBx USB instance.
 * @param enable 'true' to enable suspend, 'false' to disable suspend.
 * @return None.
 */
void USB_EnableSuspend(USB_TypeDef * USBx, bool enable);

/*!
 *@}
 */

#endif /* __HAL_USB_H__ */
