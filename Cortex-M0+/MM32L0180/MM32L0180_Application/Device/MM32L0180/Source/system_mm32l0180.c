/***********************************************************************************************************************
    @file     SYSTEM_MM32L0180.C
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSTEM FUNCTIONS.
  **********************************************************************************************************************
    @attention

    <h2><center>&copy; Copyright(c) <2023> <MindMotion></center></h2>

      Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
    following conditions are met:
    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
       the following disclaimer in the documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or
       promote products derived from this software without specific prior written permission.

      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *********************************************************************************************************************/

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSTERM
  * @{
  */

/** You can use the following frequency values as a test, 
  * more detailed clock configuration please see the manual. 
  * Note that only one macro definition can be used at a time.
  */
#define SYSCLK_HSI_XXMHz  48000000     //The value not modification allowed
//#define SYSCLK_HSI_XXMHz  24000000     //The value not modification allowed
//#define SYSCLK_HSI_XXMHz  16000000     //The value not modification allowed
//#define SYSCLK_HSI_XXMHz  12000000     //The value not modification allowed
//#define SYSCLK_HSI_XXMHz  8000000      //The value not modification allowed
//#define SYSCLK_HSE_XXMHz  8000000      //Modify the value according to the actual crystal 



/** @defgroup SYSTERM_Private_Defines
  * @{
  */
#define RCC_CFGR_SW_HSI                 (0x00U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE                 (0x01U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_LSCLK               (0x02U << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SWS_HSI                (0x00U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE                (0x01U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_LSCLK              (0x02U << RCC_CFGR_SWS_Pos)

#if defined SYSCLK_HSI_XXMHz 
uint32_t SystemCoreClock = SYSCLK_HSI_XXMHz;

#elif defined SYSCLK_HSE_XXMHz
uint32_t SystemCoreClock = SYSCLK_HSE_XXMHz;

#endif
/**
  * @}
  */

/** @defgroup CRC_Private_Functions
  * @{
  */

/**
  * @brief  Configures the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers.
  * @param  None
  * @retval None
  */
static void SetSysClockToDefine(void)
{
    __IO uint32_t  StartUpCounter = 0, ClkSrcStatus = 1;
    uint32_t temp = 0;

#ifdef SYSCLK_HSE_XXMHz
	/* Enable HSE */
    RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);

     /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY_Msk;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSE_XXMHz;

#else
     /* Enable HSI */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

     /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY_Msk;
        StartUpCounter++;
    }
    while((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSIRDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSI_XXMHz;

#endif

    if (ClkSrcStatus == (uint32_t)0x01)
    {
        /* Enable Prefetch Buffer */
        FLASH->ACR |=  (0x01U << FLASH_ACR_PRFTBE_Pos);

        FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
        temp = (SystemCoreClock-1) / 16000000;
        if(temp > 2)
        {
            temp = 2;
        }

        FLASH->ACR |= temp;

        /* Select system clock source */
#if defined SYSCLK_HSE_XXMHz
        /* Select HSE as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSE;
		RCC->CFGR  = temp;
		
        /* Wait till HSE is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSE)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#elif defined  (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 48000000) 
        /* HSI frequency division selection */
        RCC->CR &= ~RCC_CR_HSIDIV_Msk;

        /* Select HSI as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSI;
		RCC->CFGR  = temp;
		
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#elif defined  (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 24000000)
        /* HSI frequency division selection */
		temp     = RCC->CR;
        temp    &= ~RCC_CR_HSIDIV_Msk;
        temp    |= (0x01U << RCC_CR_HSIDIV_Pos);
		RCC->CR  = temp;

        /* Select HSI as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSI;
        CC->CFGR  = temp;
		
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#elif defined  (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 16000000) 
        /* HSI frequency division selection */
		temp     = RCC->CR;
        temp    &= ~RCC_CR_HSIDIV_Msk;
        temp    |= (0x02U << RCC_CR_HSIDIV_Pos);
		RCC->CR  = temp;

        /* Select HSI as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSI;
        CC->CFGR  = temp;
		
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#elif defined  (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 12000000) 
        /* HSI frequency division selection */
		temp     = RCC->CR;
        temp    &= ~RCC_CR_HSIDIV_Msk;
        temp    |= (0x03U << RCC_CR_HSIDIV_Pos);
		RCC->CR  = temp;

        /* Select HSI as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSI;
        CC->CFGR  = temp;
		
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#else
        /* HSI frequency division selection */
		temp     = RCC->CR;
        temp    &= ~RCC_CR_HSIDIV_Msk;
        temp    |= (0x05U << RCC_CR_HSIDIV_Pos);
		RCC->CR  = temp;

        /* Select HSI as system clock source */
		temp       = RCC->CFGR;
        temp      &= ~RCC_CFGR_SW_Msk;
        temp      |=  RCC_CFGR_SW_HSI;
        CC->CFGR  = temp;
		

        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
#endif
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
  * @brief  Setup the microcontroller system Initialize the Embedded Flash Interface,
  *         the PLL and update the SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON, CSSON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSHSON_Msk;
    RCC->CR &= ~RCC_CR_CSSLSON_Msk;

    /* Reset HSEBYP bit */
    RCC->CR &= ~RCC_CR_HSEBYP_Msk;

    /* Disable all interrupts and clear pending bits */
    RCC->CIR = 0xFFFFFFFF;
    RCC->CIR = 0;

    /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
    /* Configure the Flash Latency cycles and enable prefetch buffer */
    SetSysClockToDefine();
}

