/*
 *******************************************************************************
    @file     system_mm32f0160.c
    @author   AE TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE ADC
              FIRMWARE LIBRARY.
 *******************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its
       contributors may be used to endorse or promote products derived from this
       software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES,INCLUDING, BUT NOT LIMITED TO,
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */

/** @addtogroup CMSIS
  * @{
  */
#include "mm32_device.h"

/**
  * @}
  */

/*
 *  Only one of SYSCLK_HSI_XXMHz and SYSCLK_HSE_XXMHz can be defined at a time.
 *  When HSI(HSI_VALUE =  8MHz) is used as the clock source, SYSCLK_HSI_XXMHz is used.
 *  When HSE(HSE_VALUE = 12MHz) is used as the clock source, SYSCLK_HSE_XXMHz is used.
 */

// #define SYSCLK_HSI_XXMHz                96000000   /* default:96MHz, can be set as 48000000 or others */
// #define SYSCLK_HSI_XXMHz               48000000
// #define SYSCLK_HSI_XXMHz               36000000
// #define SYSCLK_HSI_XXMHz               24000000
                                          
 #define SYSCLK_HSE_XXMHz               96000000 /* default:96MHz, can be set as 48000000 or others */
// #define SYSCLK_HSE_XXMHz               48000000
// #define SYSCLK_HSE_XXMHz               36000000
// #define SYSCLK_HSE_XXMHz               24000000

#if defined SYSCLK_HSE_XXMHz
uint32_t    SystemCoreClock      = SYSCLK_HSE_XXMHz;
#elif defined SYSCLK_HSI_XXMHz
uint32_t    SystemCoreClock      = SYSCLK_HSI_XXMHz;
#else /*!< HSI Selected as System Clock source */
uint32_t    SystemCoreClock      = HSI_VALUE; /*!< System Clock Frequency (Core Clock) */
#endif

/**
  * @brief  use to return the pll_div & pll_mul.
  * @param  pllclkSourceFrq : PLL1 source clock frquency;
  *         pllclkFrq : Target PLL1 clock frquency;
  *         pll_mul : PLL1 factor PLL1  Multiplication Factor
  *         pll_div : PLL1 factor PLL1 Divide Factor
  * @retval amount of error
  */
uint32_t AutoCalPllFactor(uint32_t pllclkSourceFrq, uint32_t pllclkFrq, uint8_t *pll_mul, uint8_t *pll_div)
{
    uint32_t mul_temp, div_temp, mul_max, div_max;
    uint32_t tempFrq = 0;
    uint32_t minDiff = pllclkFrq;
    uint8_t  flag    = 0;

    mul_max = RCC_PLL1CFGR_PLL1MUL >> RCC_PLL1CFGR_PLL1MUL_Pos;
    div_max = RCC_PLL1CFGR_PLL1DIV >> RCC_PLL1CFGR_PLL1DIV_Pos;

    for (div_temp = 1; div_temp <= div_max; div_temp += 2)
    {
        for (mul_temp = 0; mul_temp <= mul_max; mul_temp++)
        {
            tempFrq = pllclkSourceFrq / (div_temp + 1) * (mul_temp + 1);
            tempFrq = (tempFrq > pllclkFrq) ? (tempFrq - pllclkFrq) : (pllclkFrq - tempFrq);

            if (minDiff > tempFrq)
            {
                minDiff    = tempFrq;
                *pll_mul   = mul_temp;
                *pll_div   = div_temp;
            }

            if (minDiff == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag != 0)
        {
            break;
        }
    }

    return (minDiff);
}

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
void SetSysClockToDefine(void)
{
    __IO uint32_t  tn, tm, StartUpCounter = 0, ClkSrcStatus = 1;
    uint8_t pll_mul, pll_div;
    uint32_t temp = 0, i = 0;
    
#ifdef SYSCLK_HSE_XXMHz
    
    /* Enable HSE */
    RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);
    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY;
        StartUpCounter++;
    }
    while ((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));
    
    if ((RCC->CR & RCC_CR_HSERDY) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }
    
    SystemCoreClock = SYSCLK_HSE_XXMHz;
    
    /* Config HSE as PLL clock source*/
    RCC->PLL1CFGR |= (0x01U << RCC_PLL1CFGR_PLL1SRC_Pos);

    /* calculate PLL1 factor*/
    AutoCalPllFactor(HSE_VALUE, SystemCoreClock, &pll_mul, &pll_div);
    
    /* set PLL1 CP Current Control Signals */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1_ICTRL;

    if (HSE_VALUE >= 8000000)
    {
        RCC->PLL1CFGR |= (0x03 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
    else
    {
        RCC->PLL1CFGR |= (0x01 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
#else
    /* Enable HSI */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);
    
    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSIRDY) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSI_XXMHz;

    /* Config HSI as PLL clock source*/
    RCC->PLL1CFGR &= ~(0x01U << RCC_PLL1CFGR_PLL1SRC_Pos);

    /* calculate PLL1 factor*/
    AutoCalPllFactor(HSI_VALUE, SystemCoreClock, &pll_mul, &pll_div);
    
    if (HSI_VALUE >= 8000000)
    {
        RCC->PLL1CFGR |= (0x03 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
    else
    {
        RCC->PLL1CFGR |= (0x01 << RCC_PLL1CFGR_PLL1_ICTRL_Pos);
    }
#endif

    if (ClkSrcStatus == (uint32_t)0x01)
    {
        /* Config FLASH latency */
        FLASH->ACR &= ~FLASH_ACR_LATENCY;
        temp = (SystemCoreClock - 1) / 24000000;
        
        if (temp > 3)
        {
            temp = 3;
        }

        FLASH->ACR |= temp;

        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        /* PCLK2 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE2;
        temp     |= RCC_CFGR_PPRE2_DIV1;
        RCC->CFGR = temp;

        /* PCLK1 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE1;
        temp     |= RCC_CFGR_PPRE1_DIV1;
        RCC->CFGR = temp;
        
        /* configuration PLL1 */
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1PDIV;
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1MUL;
        RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1DIV;
        
        RCC->PLL1CFGR |= ((pll_mul << RCC_PLL1CFGR_PLL1MUL_Pos) | (pll_div << RCC_PLL1CFGR_PLL1DIV_Pos));
        
        /* Enable PLL1 */
        RCC->CR |= (0x01U << RCC_CR_PLL1ON_Pos);
        
        /* Wait till PLL1 is ready */
        while ((RCC->CR & RCC_CR_PLL1RDY) == 0)
        {
            __ASM("nop");              /* __NOP(); */
        }
        
        /* Select PLL1 as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW;
        RCC->CFGR |= RCC_CFGR_SW_PLL1;

        /* Wait till PLL1 is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL1)
        {
            __ASM("nop");              /* __NOP(); */
        }
        
        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
        
        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

         /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

         /* HCLK = SYSCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE;
        temp     |= RCC_CFGR_HPRE_DIV1;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
    }
    else
    {
        /* If HSE not ready within the given time, the program will stop here.
           User can add here some code to deal with this error */
        while (1)
        {
            /* please check Whether the crystal oscillator starts*/
        }
    }
}

/**
  * @brief  Setup the microcontroller system
  *         Initialize the Embedded Flash Interface, the PLL and update the
  *         SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
    /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
    /* Set HSION bit */
    RCC->CR |= RCC_CR_HSION;

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR &= ~RCC_CFGR_PPRE1;
    RCC->CFGR &= ~RCC_CFGR_PPRE2;
    RCC->CFGR &= ~RCC_CFGR_MCO;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= ~RCC_CR_HSEON;
    RCC->CR &= ~RCC_CR_CSSON;
    RCC->CR &= ~RCC_CR_PLL1ON;

    /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP;

    /* Reset PLLSRC, PLLXTPRE, PLLMUL */
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1SRC;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1PDIV;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1MUL;
    RCC->PLL1CFGR &= ~RCC_PLL1CFGR_PLL1DIV;

    /* Disable all interrupts and clear pending bits  */
    RCC->CIR = 0xFFFFFFFF;
    RCC->CIR = 0;

    /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClockToDefine();
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/*-------------------------(C) COPYRIGHT 2021 MindMotion ----------------------*/

