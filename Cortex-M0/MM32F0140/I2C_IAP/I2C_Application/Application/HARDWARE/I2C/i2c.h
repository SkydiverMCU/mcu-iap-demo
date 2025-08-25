////////////////////////////////////////////////////////////////////////////////
/// @file    i2c.h
/// @author  AE TEAM
/// @brief   THIS FILE PROVIDES ALL THE SYSTEM FIRMWARE FUNCTIONS.
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
#ifndef __I2C_H
#define __I2C_H

// Files includes

#include "hal_device.h"
#include "hal_conf.h"
#include "stdio.h"


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Example_Layer
/// @brief MM32 Example Layer
/// @{
//#define BOOT_UPDATE_DATA_NUM    64
#define I2C_MAX_RECV_LEN		64					//最大接收缓存字节数


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_RESOURCE
/// @brief MM32 Examples resource modules
/// @{

#define DEVICE_ADDR             0x50


//#define  REG_GRAYSCALE          0x00    //亮度调节
//#define  REG_CONTROL            0x02    //显示指令
//#define  REG_RUNSTA             0x0A    //运行状态
//#define  REG_FLAG               0x0B    //标志

//#define  REG_FLASHSIZE_7_0      0x0C    //FLASH 容量低8位 单位Kb
//#define  REG_FLASHSIZE_15_8     0x0D    //FLASH 容量高8位 单位Kb

//#define  REG_RAMSIZE_7_0        0x0E    //RAM 容量低8位 单位Kb
//#define  REG_RAMSIZE_15_8       0x0F    //RAM 容量高8位 单位Kb

//#define  REG_BADPIXEL_7_0       0x10    //坏点的7:0位
//#define  REG_BADPIXEL_15_8      0x11    //坏点的15:8位
//#define  REG_BADPIXEL_23_16     0x12    //坏点的23:16位
//#define  REG_BADPIXEL_31_24     0x13    //坏点的31:24位

//#define  REG_MCU_RESET          0x20  //MCU重启

//#define  REG_VERSION_FIRST      0xA0
//#define  REG_VERSION_SECOND     0xA1
//#define  REG_VERSION_THIRD      0xA2
//#define  REG_VERSION_FOURTH     0xA3

////升级相关指令
//#define  REG_UPDATE_READY       0xA8
//#define  REG_UPDATE_DATA        0xAA
//#define  REG_UPDATE_FINISH      0xAF

//#define  REG_NONE               0xFF


////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Constants
/// @{




#define I2C1_SCL_PORT                   GPIOA
#define I2C1_SCL_PIN                    GPIO_Pin_5
#define I2C1_SCL_BUSCLK                 RCC_AHBENR_GPIOA
#define I2C1_SCL_AFSOURCE               GPIO_PinSource5
#define I2C1_SCL_AFMODE                 GPIO_AF_5


#define I2C1_SDA_PORT                   GPIOA
#define I2C1_SDA_PIN                    GPIO_Pin_4
#define I2C1_SDA_BUSCLK                 RCC_AHBENR_GPIOA
#define I2C1_SDA_AFSOURCE               GPIO_PinSource4
#define I2C1_SDA_AFMODE                 GPIO_AF_5




#define RX_STA_START                    (1<<0)
#define RX_STA_BUFF_NOFULL              (1<<1)
#define RX_STA_BUFF_OVER                (1<<2)
#define RX_STA_STOP                     (1<<7)
                                        
#define TX_STA_START                    (1<<0)
#define TX_STA_BUFF_EPMT                (1<<2)
#define TX_STA_ABRT                     (1<<3)
#define TX_STA_RX_DONE                  (1<<4)
#define TX_STA_STOP                     (1<<7)
                                        
#define TIMEOUT_INFINITY                (0xFFFFFFFF)
#define TIMEOUT_TRANSMIT                (500000) /*(TIMEOUT_INFINITY)*/
#define TIMEOUT_RECEIVE                 (500000) /*(TIMEOUT_INFINITY)*/

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Enumeration
/// @{

////////////////////////////////////////////////////////////////////////////////
/// @brief XXXX enumerate definition.
/// @anchor XXXX
////////////////////////////////////////////////////////////////////////////////
#define I2C_STATUS_BASE		(1<<16)
typedef enum I2C_Status_e
{
    I2C_STATUS_SUCCESS          = I2C_STATUS_BASE,
    I2C_STATUS_ERR_BAD_PARAMS   = I2C_STATUS_BASE + 1,
    I2C_STATUS_ERR_ADDR_NACK    = I2C_STATUS_BASE + 2,
    I2C_STATUS_ERR_TX_NACK      = I2C_STATUS_BASE + 3,
    I2C_STATUS_ERR_TX_ABRT      = I2C_STATUS_BASE + 4,
    I2C_STATUS_ERR_TIMEOUT      = I2C_STATUS_BASE + 5,
    I2C_STATUS_ERR_BUS_STALL    = I2C_STATUS_BASE + 6,
    I2C_STATUS_ERR_TX_PENDING   = I2C_STATUS_BASE + 7,
    I2C_STATUS_ERR_RX_PENDING   = I2C_STATUS_BASE + 8,
    I2C_STATUS_ERR_UNKNOWN      = I2C_STATUS_BASE + 255,
} I2C_Status_t;
/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Variables
/// @{
#ifdef _I2C_C_
#define GLOBAL







#else
#define GLOBAL extern






#endif

GLOBAL uint8_t  out_buff[I2C_MAX_RECV_LEN]; 	
GLOBAL uint8_t  in_buff[I2C_MAX_RECV_LEN]; 
GLOBAL uint32_t in_len;
GLOBAL uint32_t out_len;

//GLOBAL u8  Current_Offset;

GLOBAL uint32_t actual_received, actual_transmitted;
//GLOBAL volatile uint16_t rx_idx, tx_idx;
//GLOBAL volatile uint8_t rx_status, tx_status;
//GLOBAL volatile uint16_t rx_data_size, tx_data_size;

//GLOBAL REGISTER_Structure offset_reg;



#undef GLOBAL

/// @}

////////////////////////////////////////////////////////////////////////////////
/// @defgroup MM32_Exported_Functions
/// @{

uint16_t I2C_Slave_GetRxAvailable(void);
uint16_t I2C_Slave_GetTxFinish(void);
//void I2C_Slave_Init(uint8_t dev_addr, uint8_t *rx_buff, uint16_t rx_buff_size, uint8_t *tx_buff, uint16_t tx_buff_size);
void I2C_Slave_Init(uint8_t dev_addr, uint32_t i2c_speed);
void I2C_Master_Write(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size);
void I2C_Master_Read(I2C_TypeDef *I2Cx, uint16_t dev_address, uint8_t *data_p, uint16_t size);
void I2C_Master_Init(void);
I2C_Status_t I2C_Slave_Transfer(I2C_TypeDef *i2c_device,
                                uint8_t *transmit_buff, uint32_t transmit_len,
                                uint8_t *receive_buff, uint32_t receive_len,
                                uint32_t *actual_transmitted_p,
                                uint32_t *actual_received_p,
                                uint32_t timeout);

/// @}


/// @}

/// @}


////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
