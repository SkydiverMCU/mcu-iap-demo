/***********************************************************************************************************************
    @file     SYSTEM_MM32SPIN0260.C
    @author   FD TEAM
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
#define SYSCLK_HSI_XXMHz  96000000     /* default:96MHz, can be set as 48000000 or others */
//#define SYSCLK_HSI_XXMHz  48000000     


//#define SYSCLK_HSE_XXMHz  8000000     /* Input frequency range: 4 to 24MHz */ 


/** @defgroup SYSTERM_Private_Defines
  * @{
  */
#define RCC_CFGR_HPRE_DIV1              (0x00U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV2              (0x08U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV4              (0x09U << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV8              (0x0AU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV16             (0x0BU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV64             (0x0CU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV128            (0x0DU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV256            (0x0EU << RCC_CFGR_HPRE_Pos)
#define RCC_CFGR_HPRE_DIV512            (0x0FU << RCC_CFGR_HPRE_Pos)

#define RCC_CFGR_PPRE1_DIV1             (0x00U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV2             (0x04U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV4             (0x05U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV8             (0x06U << RCC_CFGR_PPRE1_Pos)
#define RCC_CFGR_PPRE1_DIV16            (0x07U << RCC_CFGR_PPRE1_Pos)

#define RCC_CFGR_PPRE2_DIV1             (0x00U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV2             (0x04U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV4             (0x05U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV8             (0x06U << RCC_CFGR_PPRE2_Pos)
#define RCC_CFGR_PPRE2_DIV16            (0x07U << RCC_CFGR_PPRE2_Pos)

#define RCC_CFGR_SW_HSI_DIV24           (0x00U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSE                 (0x01U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_HSI                 (0x02U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_LSI                 (0x03U << RCC_CFGR_SW_Pos)

#define RCC_CFGR_SWS_HSI_DIV24          (0x00U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSE                (0x01U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_HSI                (0x02U << RCC_CFGR_SWS_Pos)
#define RCC_CFGR_SWS_LSI                (0x03U << RCC_CFGR_SWS_Pos)

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
    __IO uint32_t  tn, tm, StartUpCounter = 0, ClkSrcStatus = 0;
    uint32_t temp = 0, i = 0;

#ifdef SYSCLK_HSE_XXMHz
    /* Enable HSE */
    RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);
    
    /* Wait till HSE is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSERDY_Msk;
        StartUpCounter++;
    } while ((ClkSrcStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    if ((RCC->CR & RCC_CR_HSERDY_Msk) != RESET)
    {
        ClkSrcStatus = (uint32_t)0x01;
    }
    else
    {
        ClkSrcStatus = (uint32_t)0x00;
    }

    SystemCoreClock = SYSCLK_HSE_XXMHz;

#elif defined SYSCLK_HSI_XXMHz
    /* Enable HSI */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);
    
    /* Wait till HSI is ready and if Time out is reached exit */
    do
    {
        ClkSrcStatus = RCC->CR & RCC_CR_HSIRDY_Msk;
        StartUpCounter++;
    } while ((ClkSrcStatus == 0) && (StartUpCounter != HSI_STARTUP_TIMEOUT));

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
        FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
        
        /* Enable Prefetch Buffer */
        FLASH->ACR |=  (0x01U << FLASH_ACR_PRFTBE_Pos);  
        
        temp = (SystemCoreClock-1) / 24000000;
        if(temp > 3)
        {
            temp = 3;
        }
        FLASH->ACR |= temp;

        /* HCLK = SYSCLK/8 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV8;
        RCC->CFGR = temp;

        /* PCLK1 = HCLK  */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE1_Msk;
        temp     |= RCC_CFGR_PPRE1_DIV1;
        RCC->CFGR = temp;
        
        /* PCLK2 = HCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_PPRE2_Msk;
        temp     |= RCC_CFGR_PPRE2_DIV1;
        RCC->CFGR = temp;

#if defined (SYSCLK_HSE_XXMHz)
        /* Select HSE_as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSE; 
        
        /* Wait till HSE is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSE)
        {
            __ASM("nop");                  /* __NOP(); */
        }
        
        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV1;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }           
#elif defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 96000000U)
        /* Select HSI_as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSI;     
        
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
        
        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }

        /* HCLK = SYSCLK/2 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV2;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
#elif defined (SYSCLK_HSI_XXMHz) && (SYSCLK_HSI_XXMHz == 48000000U)
        /* Select HSI_as system clock source */
        RCC->CFGR &= ~RCC_CFGR_SW_Msk;
        RCC->CFGR |= RCC_CFGR_SW_HSI;     
        
        /* Wait till HSI is used as system clock source */
        while ((RCC->CFGR & RCC_CFGR_SWS_Msk) != RCC_CFGR_SWS_HSI)
        {
            __ASM("nop");                  /* __NOP(); */
        }
        
        /* HCLK = SYSCLK/4 */
        temp      = RCC->CFGR;
        temp     &= ~RCC_CFGR_HPRE_Msk;
        temp     |= RCC_CFGR_HPRE_DIV4;
        RCC->CFGR = temp;

        for (i = 0; i < 1000; i++)
        {
            __ASM("nop");
        }
#endif
    }
    else
    {
        /* If HSE or HSI not ready within the given time, the program will stop here.
           User can add here some code to deal with this error */
        while (1)
        {
            /* please check Whether the crystal oscillator starts*/
        }
    }
}

/**
  * @brief  Setup the microcontroller system Initialize the Embedded Flash Interface, 
  *         update the SystemCoreClock variable.
  * @note   This function should be used only after reset.
  * @param  None
  * @retval None
  */
void SystemInit(void)
{
    /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON and CSSON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSON_Msk;

    /* Disable all interrupts and clear pending bits */
    RCC->CIR = 0xFFFFFFFF;
    RCC->CIR = 0;

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
