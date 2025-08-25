#ifndef __SIMBKP_H__
#define __SIMBKP_H__

//#include "types.h" 

#define SIMBPK_BASE   0x200007F0  //将RAM最后20字节作为备份寄存器


/// @brief Sim Bkp Register Structure Definition

typedef struct {
    union {
        volatile uint8_t DR[16];       
        struct {
            volatile uint8_t DR0;
            volatile uint8_t DR1;
            volatile uint8_t DR2;
            volatile uint8_t DR3;
            volatile uint8_t DR4;
            volatile uint8_t DR5;
            volatile uint8_t DR6;
            volatile uint8_t DR7;
            volatile uint8_t DR8;
            volatile uint8_t DR9;
            volatile uint8_t DR10;
            volatile uint8_t DR11;
            volatile uint8_t DR12;
            volatile uint8_t DR13;
            volatile uint8_t DR14;
            volatile uint8_t DR15;
        };   

    };

} SIMBKP_TypeDef;

#define SIMBKP      ((SIMBKP_TypeDef*) SIMBPK_BASE)

#endif
