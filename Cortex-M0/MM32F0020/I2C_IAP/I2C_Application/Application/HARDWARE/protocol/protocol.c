#include "protocol.h"
#include "uart.h"
#include "delay.h"

u8 Send_Size;

// #define UartSendGroup(txrxCmd, Send_Size)    UART1_DMA_Sends(txrxCmd,Send_Size)

/*************Check calculation********************************/

unsigned short CheckSum(uint8_t *addr, uint8_t count)
{
	register int sum = 0;

	while (count > 0)
	{
		sum = sum + *addr;
		addr++;
		count--;
	}

	while (sum >> 16) // 当和的高16位不为0，把高16位作为校验和的一部分求和，
		sum = (sum & 0xffff) + (sum >> 16);

	return (short)~sum;
}
/**********校验Checksum*******************/

uint8_t Check_data(u8 *txrxCmd)
{
	// uint8_t Flag_check = 0;
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

static void memset(u8 *str, u8 dat, u16 len)
{
	while (len--)
	{
		*str = dat;
		str++;
	}
}

void Setting_flags(void)
{

	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASH_ErasePage(BootJumpFlagAddress);
	FLASH_ProgramHalfWord(BootJumpFlagAddress, 0x0000);
	FLASH_Lock();
}

void Reply_version_number(u8 *txrxCmd) // 返回版本号
{
	//    uint8_t Checkstate;

	//	Checkstate = Check_data(txrxCmd);

	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size); // UART1_DMA_Sends(txrxCmd,Send_Size);
		return;
	}

	if ((txrxCmd[2] == 0x52) && (txrxCmd[3] == 0x45) && (txrxCmd[4] == 0x56) && (txrxCmd[5] == 0x45))
	{

		txrxCmd[0] = txrxCmd[0] | 0xc0;
		txrxCmd[1] = txrxCmd[1];
		txrxCmd[2] = 0x00;
		txrxCmd[3] = 0x01; // Bootloader  默认Ver:00.01 版本号
		txrxCmd[4] = 0;
		txrxCmd[5] = 0;
		txrxCmd[6] = APP_SIZE;
		txrxCmd[7] = 0;
		txrxCmd[8] = 0;
		txrxCmd[9] = 0;

		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
}

void Boot_Firmware(u8 *txrxCmd) // 擦除标志位并复位
{

	//	uint8_t Checkstate = 0;

	//	Checkstate = Check_data(txrxCmd);
	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{

		if ((txrxCmd[2] == 0x42) && (txrxCmd[3] == 0x4F) && (txrxCmd[4] == 0x4F)	//
			&& (txrxCmd[5] == 0x54) && (txrxCmd[6] == 0x52) && (txrxCmd[7] == 0x45) //
			&& (txrxCmd[8] == 0x53) && (txrxCmd[9] == 0x45) && (txrxCmd[10] == 0x54))
		{

			txrxCmd[0] = txrxCmd[0] | 0xc0;
			txrxCmd[1] = txrxCmd[1];
			UartSendGroup(txrxCmd, Send_Size);

			FLASH_Unlock();
			FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);

			FLASH_ErasePage(BootJumpFlagAddress);

			FLASH_Lock();

			NVIC_SystemReset(); // 软件复位
		}
		else
		{
			memset(txrxCmd, 0, 0x40);
			UartSendGroup(txrxCmd, Send_Size);
		}
	}
}

void Boot_MAL_Erase_app(u8 *txrxCmd) // Boot模式下擦除APP程序区数据
{
	uint32_t Address;
	uint16_t index;

	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{

		Address = ApplicationAddress; // APP flash   0x08002000 -- 0x0801FFFF  0x1E000
		FLASH_Unlock();
		FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
		for (index = 0; index < APP_SIZE; index++)
		{
			FLASH_ErasePage(Address);
			Address = Address + 0x400;
		}
		FLASH_Lock();
		txrxCmd[0] = txrxCmd[0] | 0xC0;
		UartSendGroup(txrxCmd, Send_Size);
	}
}

void Reset_Boot_Firmware(u8 *txrxCmd) // APP校验正确写好Boot标志位并复位系统
{

	//	uint8_t Checkstate = 0;

	//	Checkstate = Check_data(txrxCmd);
	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{

		txrxCmd[0] = txrxCmd[0] | 0xc0;
		UartSendGroup(txrxCmd, Send_Size);
		Setting_flags();

		NVIC_SystemReset(); // 系统复位
	}
}

void DFU_MAL_Write_onebulk(u8 *txrxCmd)
{
	uint32_t HalfWord;
	//  uint8_t  *writeBuff=NULL;
	uint16_t temp, writeNumber;
	uint32_t WriteAddress;

	writeNumber = txrxCmd[1];
	writeNumber = writeNumber - 8;
	writeNumber = writeNumber / 2;
	WriteAddress = ApplicationAddress + ((txrxCmd[5] << 24) + (txrxCmd[4] << 16) + (txrxCmd[3] << 8) + txrxCmd[2]); // 上位机传下来的地址是相对于ApplicationAddress的偏移地址

	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	for (temp = 0; temp < writeNumber; temp++)
	{
		HalfWord = txrxCmd[(2 * temp) + 6];
		HalfWord = HalfWord | (txrxCmd[(2 * temp) + 7] << 8);
		FLASH_ProgramHalfWord(WriteAddress, HalfWord);
		WriteAddress = WriteAddress + 2;
	}

	FLASH_Lock();
	txrxCmd[0] = txrxCmd[0] | 0xc0;
	txrxCmd[1] = txrxCmd[1];
	UartSendGroup(txrxCmd, Send_Size);
}
void Write_APP_Data(u8 *txrxCmd)
{
	//	uint8_t Checkstate = 0;

	//	Checkstate = Check_data(txrxCmd);
	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{
		DFU_MAL_Write_onebulk(txrxCmd);
	}
}
uint8_t *MAL_Read(uint32_t SectorAddress, uint32_t DataLength) // 读取FLASH数据
{
	return (uint8_t *)SectorAddress;
}
void DFU_MAL_Read(u8 *txrxCmd)
{
	uint8_t *readBuff = NULL;
	uint32_t temp, ReadNumber;
	uint32_t ReadAddress;

	txrxCmd[0] = txrxCmd[0] | 0xc0;
	//	txrxCmd[1] = txrxCmd[1];
	//	txrxCmd[2] = txrxCmd[2];
	//	txrxCmd[3] = txrxCmd[3];
	//	txrxCmd[4] = txrxCmd[4];
	//	txrxCmd[5] = txrxCmd[5];

	ReadNumber = txrxCmd[1];
	ReadNumber = ReadNumber - 8;
	ReadAddress = ApplicationAddress + ((txrxCmd[5] << 24) + (txrxCmd[4] << 16) + (txrxCmd[3] << 8) + txrxCmd[2]); // 上位机传下来的地址是相对于ApplicationAddress的偏移地址
	readBuff = MAL_Read(ReadAddress, ReadNumber);

	for (temp = 0; temp < ReadNumber; temp++)
	{
		txrxCmd[6 + temp] = (*(readBuff + temp)) & 0xff;
	}

	UartSendGroup(txrxCmd, Send_Size);
}
void Verify_APP_Firmware(u8 *txrxCmd)
{

	//	uint8_t Checkstate = 0;

	//	Checkstate = Check_data(txrxCmd);
	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{
		DFU_MAL_Read(txrxCmd);
	}
}

void Clear_DFU_State(u8 *txrxCmd)
{

	//	uint8_t Checkstate = 0;

	//	Checkstate = Check_data(txrxCmd);
	if (Check_data(txrxCmd))
	{
		memset(txrxCmd, 0, 0x40);
		UartSendGroup(txrxCmd, Send_Size);
	}
	else
	{

		FLASH_Unlock();
		FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
		FLASH_ErasePage(BootJumpFlagAddress);
		//							 FLASH_ProgramHalfWord(BootJumpFlagAddress, 0xFFFF);
		FLASH_Lock();
		txrxCmd[0] = txrxCmd[0] | 0xc0;
		txrxCmd[1] = txrxCmd[1];
		UartSendGroup(txrxCmd, Send_Size);
	}
}

void DFU_read_state_UP(u8 *txrxCmd)
{

	uint8_t *Buff = NULL;
	uint32_t temp;

	txrxCmd[0] = txrxCmd[0] | 0xc0;

	Buff = (uint8_t *)BootJumpFlagAddress; // MAL_Read(BootJumpFlagAddress, 2);

	for (temp = 0; temp < 2; temp++)
	{
		txrxCmd[1 + temp] = (*(Buff + temp)) & 0xff;
	}

	UartSendGroup(txrxCmd, Send_Size);
}

void DFU_writeoneword_state(u8 *txrxCmd)
{
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASH_ErasePage(BootJumpFlagAddress);
	FLASH_ProgramHalfWord(BootJumpFlagAddress, 0x0000);
	FLASH_Lock();
	txrxCmd[0] = txrxCmd[0] | 0xc0;
	UartSendGroup(txrxCmd, Send_Size);
}

void Reset_Firmware(u8 *txrxCmd)
{
	txrxCmd[0] = txrxCmd[0] | 0xc0;
	UartSendGroup(txrxCmd, Send_Size);

	NVIC_SystemReset(); // 系统复位
}

uint16_t DFU_read_state(void)
{
	uint8_t *Buff = NULL;

	uint16_t ReadDATA = 0;

	Buff = (uint8_t *)BootJumpFlagAddress; // MAL_Read(BootJumpFlagAddress, 2); //DFU Flag  0x08001C00

	ReadDATA = (Buff[1] << 8) + Buff[0];

	return ReadDATA;
}

void Uart_protocol(u8 *txrxCmd)
{
	u8 host_cmd;

	host_cmd = txrxCmd[0];
	Send_Size = txrxCmd[1];

	switch (host_cmd)
	{
	case 0x00:
		Reply_version_number(txrxCmd); // 回复当前software 版本号
		break;

	case 0x20:
		Boot_Firmware(txrxCmd); // 擦除标志位并复位  //和APP程序同一条指令
		break;

	case 0x21:
		Boot_MAL_Erase_app(txrxCmd); // Boot模式下擦除APP程序区数据
		break;

	case 0x22:
		Reset_Boot_Firmware(txrxCmd); // APP校验正确写好Boot标志位并复位系统
		break;

	case 0x23:
		Write_APP_Data(txrxCmd); // Boot模式下写APP程序
		break;

	case 0x24:
		Verify_APP_Firmware(txrxCmd); // 校验APP程序数据
		break;

	case 0x25:
		Clear_DFU_State(txrxCmd); // 清除Boot标志位
		break;

	case 0x31:
		DFU_read_state_UP(txrxCmd); // 读Boot标志位
		break;

	case 0x32:
		DFU_writeoneword_state(txrxCmd); // 写标志位
		break;

	case 0x33:
		Reset_Firmware(txrxCmd); // 在Boot升级模式下复位系统
		break;

	default:
		break;
	}
}

// 把str2向str1复制real_len个数据，后面的全部补0
void mem_copy(u8 *str1, u8 *str2, u16 real_len, u16 total_len)
{
	u16 i;

	for (i = 0; i < real_len; i++)
	{
		str1[i] = str2[i];
	}
	for (; i < total_len; i++)
	{
		str1[i] = 0;
	}
}
