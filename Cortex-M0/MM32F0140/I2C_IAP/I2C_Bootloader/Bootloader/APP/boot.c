#define _BOOT_C_

#include "boot.h"
#include "string.h"
#include "main.h"
#include "i2c.h"
// #include "platform.h"

const u8 USB_Return_Err[64] =
    {
        0xD5, 0x04, 0x00, 0x00, 0x59};
const u8 Valid_buf[4] =
    {
        0x55, 0xAA, 0xAA, 0x55};

#define BURN_VER "0.0.1"

FileData_Block appdata_block[BLOCK_NUM];

u8 code_buff[512];
u8 currentSegment = 0;
u16 code_CurrentLength;
u32 code_TotalLength;

#define code_buff_size sizeof(code_buff)

void Boot_SendGroup(u8 *buffer, u16 bufsize)
{
    I2C_Status_t status = I2C_STATUS_SUCCESS;

    out_len = bufsize;
    in_len = 0;

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

uint32_t App_CheckSum(uint32_t FlashStartAddr, uint32_t length)
{
    uint32_t i;
    uint32_t sum;
    uint32_t Address;
    uint16_t u16FlashData;

    sum = 0;
    Address = FlashStartAddr;
    for (i = 0; i < length; i += 2)
    {
        u16FlashData = *((vu16 *)Address);

        sum += u16FlashData;

        Address += 2;
    }

    return sum;
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

void FLASH_Read(u8 *buff, u32 addr, u32 readNumber)
{
    u32 temp;
    u32 Address;
    u16 halfword;

    Address = addr;

    for (temp = 0; temp < readNumber; temp += 2)
    {
        halfword = *((vu16 *)Address) & 0xFFFF;
        buff[temp] = halfword & 0xFF;
        buff[temp + 1] = (halfword >> 8) & 0xFF;
        Address += 2;
    }
}

void appVerify(u8 *buff)
{
    u8 j;
    u16 i, idx;
    u16 page_num;
    u16 page_mud;
    u32 addr;
    u32 DatWord = 0;
    u32 check_sum = 0;

    for (j = 0; j < 4; j++)
    {
        if (appdata_block[j].BlockLength == 0)
        {
            break;
        }

        check_sum = 0;
        page_num = appdata_block[j].BlockLength / code_buff_size;
        page_mud = appdata_block[j].BlockLength % code_buff_size;

        addr = appdata_block[j].BlockStartAddr;

        for (i = 0; i < page_num; i++)
        {
            FLASH_Read(code_buff, addr, code_buff_size);
            addr += code_buff_size;

            for (idx = 0; idx < code_buff_size; idx++)
            {
                if (idx & 0x01)
                {
                    DatWord = ((code_buff[idx] << 8) + DatWord);
                    check_sum += DatWord;
                }
                else
                {
                    DatWord = code_buff[idx];
                }
            }
        }

        if (page_mud)
        {
            FLASH_Read(code_buff, addr, page_mud);

            for (idx = 0; idx < page_mud; idx++)
            {
                if (idx & 0x01)
                {
                    DatWord = ((code_buff[idx] << 8) + DatWord);
                    check_sum += DatWord;
                }
                else
                {
                    DatWord = code_buff[idx];
                }
            }
        }

        if (check_sum != appdata_block[j].BlockCheckSum)
        {
            memcpy(buff, USB_Return_Err, 0x40);
            Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
            return;
        }
    }

    memset(buff, 0, 0x40);
    buff[0] = 0xC0 | VERIFY_APP;
    buff[1] = 5;
    buff[2] = 1;
    buff[3] = ((buff[0] + buff[1] + buff[2]) >> 8) & 0xFF;
    buff[4] = (buff[0] + buff[1] + buff[2]) & 0xFF;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

void segmentInfo(u8 *buff)
{
    u8 i;
    u32 segmentLen;

    code_CurrentLength = 0;
    code_TotalLength = 0;
    currentSegment = 0;

    for (i = 0; i < BLOCK_NUM; i++)
    {
        appdata_block[i].BlockLength = 0;
        appdata_block[i].BlockStartAddr = 0;
        appdata_block[i].BlockCheckSum = 0;
    }

    for (i = 0; i < BLOCK_NUM; i++)
    {
        segmentLen = (buff[i * 12 + 2] << 24) | (buff[i * 12 + 3] << 16) | (buff[i * 12 + 4] << 8) | buff[i * 12 + 5];

        if (segmentLen == 0)
        {
            break;
        }

        appdata_block[i].BlockLength = segmentLen;
        appdata_block[i].BlockStartAddr = (buff[i * 12 + 6] << 24) | (buff[i * 12 + 7] << 16) |
                                          (buff[i * 12 + 8] << 8) | buff[i * 12 + 9];
        appdata_block[i].BlockCheckSum = (buff[i * 12 + 10] << 24) | (buff[i * 12 + 11] << 16) |
                                         (buff[i * 12 + 12] << 8) | buff[i * 12 + 13];
    }

    buff[0] = SEG_STARTADDR | 0xC0;
    buff[1] = 4;
    buff[2] = ((buff[0] + buff[1]) >> 8) & 0xFF;
    buff[3] = (buff[0] + buff[1]) & 0xFF;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

static void Data_Recive(u8 *buff, u32 StartAddr, u32 SegmentLength)
{
    if (code_CurrentLength + 60 <= code_buff_size)
    {
        memcpy(&code_buff[code_CurrentLength], &buff[2], buff[1] - 4);
        code_CurrentLength += buff[1] - 4;
    }
    else
    {
        FLASH_Write(code_buff, StartAddr + code_TotalLength, code_CurrentLength);
        code_TotalLength += code_CurrentLength;

        memcpy(&code_buff, &buff[2], buff[1] - 4);
        code_CurrentLength = buff[1] - 4;
    }

    if ((code_TotalLength + code_CurrentLength) == SegmentLength)
    {
        FLASH_Write(code_buff, StartAddr + code_TotalLength, code_CurrentLength);

        code_CurrentLength = 0;
        code_TotalLength = 0;

        if (currentSegment < 3)
        {
            currentSegment++;
        }
    }
}

void appCodeDownload(u8 *buff)
{
    Data_Recive(buff, appdata_block[currentSegment].BlockStartAddr, appdata_block[currentSegment].BlockLength);

    memset(buff, 0, 0x40);
    buff[0] = WRITE_APP | 0xC0;
    buff[1] = 4;
    buff[2] = ((buff[0] + buff[1]) >> 8) & 0xFF;
    buff[3] = (buff[0] + buff[1]) & 0xFF;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

void resetMCU(u8 *buff)
{
    u16 sum;

    buff[0] = buff[0] | 0xc0;
    sum = CheckSum(buff, buff[1] - 2);
    buff[2] = (sum >> 8) & 0xFF;
    buff[3] = sum & 0xFF;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
    __disable_irq();
    NVIC_SystemReset(); // 系统复位
}

void eraseAppSpace(u8 *buff)
{
    uint32_t Address;
    uint16_t index;
    u16 sum;
    u16 page_erase = (buff[2] << 8) | buff[3];

    Address = ApplicationAddress; // APP flash   0x08002000 -- 0x0801FFFF  0x1E000
    FLASH_Unlock();
    FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

    for (index = 0; index < page_erase; index++)
    {
        FLASH_ErasePage(Address);
        Address = Address + 0x400;
    }

    FLASH_Lock();
    buff[0] = buff[0] | 0xC0;
    sum = CheckSum(buff, buff[1] - 2);
    buff[4] = (sum >> 8) & 0xFF;
    buff[5] = sum & 0xff;
    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

void getVersion(u8 *buff)
{
    u16 sum = 0;

    memset(buff, 0, 0x40);
    buff[0] = 0xC9;
    buff[1] = 9;
    strncpy((char *)(buff + 2), BURN_VER, 5);
    sum = CheckSum(buff, buff[1] - 2);
    buff[7] = (sum >> 8) & 0xFF;
    buff[8] = sum & 0xFF;

    Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
}

void clearAppFlag(u8 *buff)
{
    code_CurrentLength = 0;
    code_TotalLength = 0;
    currentSegment = 0;

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

void writeAppFlag(u8 *buff)
{
    u8 buf[4];

    FLASH_Write(Valid_buf, AppInfoAreaAddress, sizeof(Valid_buf));
    FLASH_Read(buf, AppInfoAreaAddress, 4);

    if (memcmp(buf, Valid_buf, 4) != 0)
    {
        memcpy(buff, USB_Return_Err, 0x40);
        Boot_SendGroup(buff, I2C_MAX_RECV_LEN);
        return;
    }

    memset(buff, 0, 0x40);
    buff[0] = WRITE_FLAG | 0xC0;
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

void boot_protocol(void)
{
    u8 cmd;
    //    uint16_t update_number;
    I2C_Status_t status = I2C_STATUS_SUCCESS;

    while (1)
    {

        status = I2C_Slave_Transfer(I2C1, NULL, 0, NULL, 0, &actual_transmitted, &actual_received, TIMEOUT_RECEIVE);
        if (status != I2C_STATUS_ERR_RX_PENDING)
        {
            while (status == I2C_STATUS_ERR_TX_PENDING)
            {
                out_buff[0] = 0xFF;
                out_len = 1;
                status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, TIMEOUT_TRANSMIT);
            }
        }

        out_len = 0;
        in_len = I2C_MAX_RECV_LEN;

        status = I2C_Slave_Transfer(I2C1, out_buff, out_len, in_buff, in_len, &actual_transmitted, &actual_received, TIMEOUT_RECEIVE); // 总超时时间
        if ((actual_received == 0) || (status != I2C_STATUS_SUCCESS))
        {
            continue;
        }

        if (Check_data(in_buff)) // 校验错误
        {
            memcpy(out_buff, USB_Return_Err, 0x40);

            Boot_SendGroup(out_buff, I2C_MAX_RECV_LEN);

            continue;
        }

        cmd = in_buff[0];

        switch (cmd)
        {
        case GET_VERSION:
            getVersion(in_buff);
            break;

        case ERASE_APP:
            eraseAppSpace(in_buff);
            break;

        case SYSTEM_RESET:
            resetMCU(in_buff);
            break;

        case WRITE_APP:
            appCodeDownload(in_buff);
            break;

        case VERIFY_APP:
            appVerify(in_buff);
            break;

        case CLEAR_FLAG:
            clearAppFlag(in_buff);
            break;

        case WRITE_FLAG:
            writeAppFlag(in_buff);
            break;

        case SEG_STARTADDR:
            segmentInfo(in_buff);
            break;

        case MCU_INFO:
            mcuInfo(in_buff);
            break;

        default:
            break;
        }
    }
}
