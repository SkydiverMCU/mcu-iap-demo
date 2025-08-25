#ifndef __PROTOCOL_H_
#define __PROTOCOL_H_

#include "hal_conf.h" 

//#define Send_Size 0x40


#define APP_SIZE 10                  //10K flash
#define ApplicationAddress    0x08002400 //APP Address
#define BootJumpFlagAddress   (ApplicationAddress-0x400)



void Uart_sendbyte(u8 data);
void Uart_protocol(u8 *txrxCmd);
uint16_t DFU_read_state(void);//判断用户程序区是否有效




#endif


