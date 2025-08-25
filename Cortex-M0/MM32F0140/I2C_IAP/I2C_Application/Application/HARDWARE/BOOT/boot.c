#define _I2C_PROTOCOL_C_

#include "boot.h"
#include "string.h"
#include "main.h"
#include "i2c.h"

const u8 USB_Return_Err[64] =
{
    0xD5, 0x04, 0x00, 0x00, 0x59
};

void Boot_SendGroup(u8 *buffer, u16 bufsize)
{
    I2C_Status_t status = I2C_STATUS_SUCCESS;
    
    out_len = bufsize;
    in_len  = 0;
    
    status = I2C_Slave_Transfer(I2C1, buffer, out_len, in_buff, in_len, &actual_transmitted, &actual_received, TIMEOUT_RECEIVE);
}

/*************Check calculation********************************/

static u16 CheckSum(uint8_t *pdat, uint8_t count)
{
    register int sum = 0;

    while (count > 0)
    {
        sum = sum + *pdat;
        pdat++;
        count--;
    }
    
    return sum;
}

/**********校验Checksum*******************/

static uint8_t Check_data(u8 *txrxCmd)
{
    uint16_t tmp_Checksum = 0;
    uint8_t temp1, temp2;

    tmp_Checksum = CheckSum(txrxCmd, txrxCmd[1] - 2);

    temp1 = tmp_Checksum & 0x00FF;
    temp2 = (tmp_Checksum >> 8) & 0x00FF;

    if ((temp2 != txrxCmd[txrxCmd[1] - 2]) || (temp1 != txrxCmd[txrxCmd[1] - 1]))
    {
        return 1;
    }

    return 0;
}

void resetMCU(void)
{
    __disable_irq();
    NVIC_SystemReset();     //系统复位
}

void clearAppFlag(u8 *buff)
{

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    FLASH_ErasePage(AppInfoAreaAddress);

    FLASH_Lock();

    memset(buff, 0, 0x40);
    buff[0] = CLEAR_FLAG | 0xC0;
    buff[1] = 4;
    buff[2] = ((buff[0] + buff[1]) >> 8) & 0xFF;
    buff[3] = (buff[0] + buff[1]) & 0xFF;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
    
    
}

void mcuInfo(u8 *buff)
{
    u16 sum;

    buff[0] = MCU_INFO | 0xC0;
    buff[1] = 12;
    buff[2] = (ApplicationAddress >> 24) & 0xFF;
    buff[3] = (ApplicationAddress >> 16) & 0xFF;
    buff[4] = (ApplicationAddress >> 8) & 0xFF;
    buff[5] = ApplicationAddress & 0xFF;

    buff[6] = ((APP_SIZE * 1024) >> 24) & 0xFF;
    buff[7] = ((APP_SIZE * 1024) >> 16) & 0xFF;
    buff[8] = ((APP_SIZE * 1024) >> 8) & 0xFF;
    buff[9] = (APP_SIZE * 1024) & 0xFF;

    sum = CheckSum(buff, buff[1] - 2);
    buff[10] = (sum >> 8) & 0xFF;
    buff[11] = sum & 0xFF;

    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

static void FLASH_Write(const u8 *buff, u32 addr, u32 writeNumber)
{
    u32 temp;
    u32 WriteAddress;
    u16 HalfWord;

    WriteAddress = addr;

    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (temp = 0; temp < writeNumber; temp += 2)
    {
        HalfWord = buff[temp];
        HalfWord = HalfWord | (buff[temp + 1] << 8);
        FLASH_ProgramHalfWord(WriteAddress, HalfWord);
        WriteAddress = WriteAddress + 2;
    }

    FLASH_Lock();
}

void i2c_protocol(void)
{
    uint8_t cmd;
    I2C_Status_t status = I2C_STATUS_SUCCESS;
    
    if(!I2C_GetFlagStatus(I2C1, I2C_ISR_RX_REQ) && !I2C_GetFlagStatus(I2C1, I2C_ISR_RX_FULL))
    {
        return;
    }
#if 0  
    status = I2C_Slave_Transfer(I2C1, NULL, 0, NULL, 0, &actual_transmitted, &actual_received, TIMEOUT_RECEIVE);
    if(status != I2C_STATUS_ERR_RX_PENDING)
    {
        
        while(status == I2C_STATUS_ERR_TX_PENDING)
        {
            out_buff[0] = REG_NONE;
            out_len = 1;
            status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, TIMEOUT_TRANSMIT);
        }
        
        return;
        
    }

    out_len = 0;
    in_len  = 1;
    status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, 50000);//总超时时间
    if((actual_received != 1) || (status != I2C_STATUS_SUCCESS))
    {
        return;
    }
    
    Current_Offset = in_buff[0];
    
#else    
    
    status = I2C_Slave_Transfer(I2C1, NULL, 0, NULL, 0, &actual_transmitted, &actual_received, TIMEOUT_RECEIVE);
    
    if(status != I2C_STATUS_ERR_TX_PENDING)
    {

        if(status == I2C_STATUS_ERR_RX_PENDING)
        {
            out_len = 0;
            in_len  = I2C_MAX_RECV_LEN;
            status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, 50000);//总超时时间
            if((actual_received == 0) || (status != I2C_STATUS_SUCCESS))
            {
                return;
            }
            
            if (Check_data(in_buff)) //校验错误
            {
                memcpy(out_buff, USB_Return_Err, 0x40);
                
                Boot_SendGroup(out_buff,I2C_MAX_RECV_LEN);
                                  
                return;
            }
            
            cmd = in_buff[0];
            
            switch (cmd)
            {

                case CLEAR_FLAG:
                    clearAppFlag(in_buff);
                    resetMCU();
                    break;

                case MCU_INFO:
                    mcuInfo(in_buff);
                    break;

                default:
                    break;
            } 
        }
    }
#endif
    
    
    while(status == I2C_STATUS_ERR_TX_PENDING)
    {
        out_buff[0] = 0xFF;
        out_len = 1;
        status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, TIMEOUT_TRANSMIT);
    }
}

