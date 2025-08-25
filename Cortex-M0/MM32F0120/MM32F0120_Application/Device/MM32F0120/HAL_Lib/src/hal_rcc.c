/***********************************************************************************************************************
    @file     hal_rcc.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE RCC FIRMWARE FUNCTIONS.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#define _HAL_RCC_C_

/* Files includes ------------------------------------------------------------*/
#include "hal_rcc.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/** @defgroup RCC_Private_Defines
  * @{
  */
uint8_t AHBPreTable[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
uint8_t APBPreTable[] = {0, 0, 0, 0, 1, 2, 3, 4};

/**
  * @}
  */

/** @defgroup RCC_Private_Functions
  * @{
  */

/**
  * @brief  Resets the RCC clock configuration to default state.
  * @param  None.
  * @retval None.
  */
void RCC_DeInit(void)
{
    /* Set HSION bit */
    RCC->CR |= (0x01U << RCC_CR_HSION_Pos);

    /* Reset SW, HPRE, PPRE1, PPRE2 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset HSEON, CSSON and PLLON bits */
    RCC->CR &= ~RCC_CR_HSEON_Msk;
    RCC->CR &= ~RCC_CR_CSSON_Msk;

}

/**
  * @brief  Configures the External High Speed oscillator (HSE).
  * @param  hsesource: specifies the new config of HSE.
  *         This parameter can be one of the following values:
  * @arg    RCC_HSE_OFF: HSE oscillator OFF
  * @arg    RCC_HSE_ON: HSE oscillator ON
  * @retval None.
  */
void RCC_HSEConfig(uint32_t hsesource)
{
    RCC->CR &= ~RCC_CR_HSEON_Msk;

    if(RCC_HSE_ON == hsesource) 
    {
        RCC->CR |= (0x01U << RCC_CR_HSEON_Pos);
    }
}
/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    RCC_FLAG_HSIRDY: HSI oscillator clock ready
  * @arg    RCC_FLAG_HSERDY: HSE oscillator clock ready
  * @arg    RCC_FLAG_LSERDY: LSE oscillator clock ready
  * @arg    RCC_FLAG_LSIRDY: LSI oscillator clock ready
  * @arg    RCC_FLAG_PINRST: Pin reset
  * @arg    RCC_FLAG_PORRST: POR/PDR reset
  * @arg    RCC_FLAG_SFTRST: Software reset
  * @arg    RCC_FLAG_IWDGRST: Independent Watchdog reset
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus RCC_GetFlagStatus(uint8_t flag)
{
    uint32_t tmp = 0, i = 0;
    uint32_t statusreg = 0;

    tmp = flag >> 5;
    if (tmp == 1)               /* The flag to check is in CR register */
    {
        statusreg = RCC->CR;
    }
    else if (tmp == 2)                 /* The flag to check is in BDCR register */
    {
        statusreg = RCC->BDCR;

        for (i = 0; i < 30000; i++)
        {
            __NOP();
        }
    }
    else if (tmp == 3)                      /* The flag to check is in CSR register */
    {
        statusreg = RCC->CSR;
    }

    /* Get the flag position */
    tmp = flag & 0x1F;

    /* Return the flag status */
    return ((statusreg & ((uint32_t)1 << tmp)) ? SET : RESET);
}

/**
  * @brief  Waits for HSE start-up.
  * @param  None.
  * @retval An ErrorStatus enumuration value:
  *         - SUCCESS: HSE oscillator is stable and ready to use
  *         - ERROR: HSE oscillator not yet ready
  */
ErrorStatus RCC_WaitForHSEStartUp(void)
{
    uint32_t StartUpCounter = 0;
    FlagStatus HSEStatus = RESET;

    do 
    {
        HSEStatus = RCC_GetFlagStatus(RCC_FLAG_HSERDY);
        StartUpCounter++;
    } while ((HSEStatus == RESET) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

    return (RCC_GetFlagStatus(RCC_FLAG_HSERDY) != RESET) ? SUCCESS : ERROR;
}


/**
  * @brief  Enables or disables the Internal High Speed oscillator (HSI).
  * @param  state: new state of the HSI.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_HSICmd(FunctionalState state)
{
    (state) ? \
    (RCC->CR |=  (0x01U << RCC_CR_HSION_Pos)) : \
    (RCC->CR &= ~(0x01U << RCC_CR_HSION_Pos));
}


/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  sys_clk_source: specifies the clock source used as system
  *         clock. This parameter can be one of the following values:
  *     @arg    RCC_SYSCLKSource_HSI8: specifies HSI8 as system clock
  *     @arg    RCC_SYSCLKSource_HSE: specifies HSE as system clock
  *     @arg    RCC_SYSCLKSource_HSI144: specifies HSI144 as system clock
  *     @arg    RCC_SYSCLKSource_LSI: specifies LSI as system clock
  * @retval None.
  */
void RCC_SYSCLKConfig(uint32_t sys_clk_source)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_SW_Msk, sys_clk_source );
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None.
  * @retval The clock source used as system clock. The returned value can
  *         be one of the following:
  *         - 0x00: HSI8 used as system clock
  *         - 0x04: HSE used as system clock
  *         - 0x08: HSI144 used as system clock
  *         - 0x0C: LSI used as system clock
  */
uint8_t RCC_GetSYSCLKSource(void)
{
    return ((RCC->CFGR & RCC_CFGR_SWS_Msk));
}

/**
  * @brief  Configures the AHB clock (hclk).
  * @param  sys_clk: defines the AHB clock divider. This clock is derived
  *                    from the system clock (SYSCLK).
  *         This parameter can be one of the following values:
  * @arg    RCC_SYSCLK_Div1: AHB clock = SYSCLK
  * @arg    RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
  * @arg    RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
  * @arg    RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
  * @arg    RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
  * @arg    RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
  * @arg    RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  * @arg    RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  * @arg    RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval None.
  */
void RCC_HCLKConfig(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE_Msk, clk);
}

/**
  * @brief  Configures the Low Speed APB clock (pclk1).
  * @param  hclk: defines the APB1 clock divider. This clock is derived from
  *                  the AHB clock (hclk).
  *         This parameter can be one of the following values:
  * @arg    RCC_HCLK_Div1: APB1 clock = hclk
  * @arg    RCC_HCLK_Div2: APB1 clock = hclk/2
  * @arg    RCC_HCLK_Div4: APB1 clock = hclk/4
  * @arg    RCC_HCLK_Div8: APB1 clock = hclk/8
  * @arg    RCC_HCLK_Div16: APB1 clock = hclk/16
  * @retval None.
  */
void RCC_PCLK1Config(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1_Msk, clk << RCC_CFGR_PPRE1_Pos);
}

/**
  * @brief  Configures the High Speed APB clock (pclk2).
  * @param  hclk: defines the APB2 clock divider. This clock is derived from
  *                  the AHB clock (hclk).
  *         This parameter can be one of the following values:
  * @arg    RCC_HCLK_Div1: APB2 clock = hclk
  * @arg    RCC_HCLK_Div2: APB2 clock = hclk/2
  * @arg    RCC_HCLK_Div4: APB2 clock = hclk/4
  * @arg    RCC_HCLK_Div8: APB2 clock = hclk/8
  * @arg    RCC_HCLK_Div16: APB2 clock = hclk/16
  * @retval None.
  */
void RCC_PCLK2Config(uint32_t clk)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2_Msk, clk << RCC_CFGR_PPRE2_Pos);
}

/**
  * @brief  Enables or disables the specified RCC interrupts.
  * @param  it: specifies the RCC interrupt sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @param  state: new state of the specified RCC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_ITConfig(uint8_t it, FunctionalState state)
{
    (state) ? \
    (RCC->CIR |=  (it << RCC_CIR_LSIRDYIE_Pos)) : \
    (RCC->CIR &= ~(it << RCC_CIR_LSIRDYIE_Pos)) ;
}

/**
  * @brief  Checks whether the specified RCC interrupt has occurred or not.
  * @param  it: specifies the RCC interrupt source to check.
  *   This parameter can be one of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_CSSF: Clock Security System interrupt
  * @retval The new state of it (SET or RESET).
  */
ITStatus RCC_GetITStatus(uint8_t it)
{
    return (ITStatus)(RCC->CIR & (it << RCC_CIR_LSIRDYF_Pos));
}

/**
  * @brief  Clears the RCC interrupt pending bits.
  * @param  it: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_LSERDY: LSE ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_HSERDY: HSE ready interrupt
  * @arg RCC_IT_CSSF: Clock Security System interrupt
  * @retval None.
  */
void RCC_ClearITPendingBit(uint8_t it)
{
    RCC->CIR |= (it << RCC_CIR_LSIRDYC_Pos);
}

/**
  * @brief  Configures the External Low Speed oscillator (LSE).
  * @param  rcc_lse: specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  * @arg    RCC_LSE_OFF: LSE oscillator OFF
  * @arg    RCC_LSE_ON: LSE oscillator ON
  * @arg    RCC_LSE_Bypass: LSE oscillator bypassed with external clock
  * @retval None.
  */
void RCC_LSEConfig(uint32_t rcc_lse)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    tmpreg &= ~RCC_BDCR_LSEON_Msk;

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }    

    tmpreg &= ~RCC_BDCR_LSEBYP_Msk;

    if (rcc_lse == RCC_LSE_Bypass)
    {
        tmpreg |= RCC_LSE_Bypass;
        tmpreg |= RCC_LSE_ON;
    }
    else
    {
        tmpreg |= rcc_lse;
    }

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}


/**
  * @brief  Enables or disables the Internal Low Speed oscillator (LSI).
  *         LSI can not be disabled if the IWDG is running.
  * @param  state: new state of the LSI.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_LSICmd(FunctionalState state)
{
    (state) ? \
    (RCC->CSR |=  (0x01U << RCC_CSR_LSION_Pos)) : \
    (RCC->CSR &= ~(0x01U << RCC_CSR_LSION_Pos)) ;
}

/**
  * @brief  Configures the RTC clock (RTCCLK).
  *         Once the RTC clock is selected it can be changed unless the
  *         Backup domain is reset.
  * @param  rtc_clk_src: specifies the RTC clock source.
  *         This parameter can be one of the following values:
  * @arg    RCC_RTCCLKSource_LSE: LSE selected as RTC clock
  * @arg    RCC_RTCCLKSource_LSI: LSI selected as RTC clock
  * @arg    RCC_RTCCLKSource_HSE_Div128: HSE clock divided by 128
  *         selected as RTC clock
  * @retval None.
  */
void RCC_RTCCLKConfig(uint32_t rtc_clk_src)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    tmpreg |= rtc_clk_src;

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the RTC clock.
  *         This function must be used only after the RTC clock was
  *         selected using the RCC_RTCCLKConfig function.
  * @param  state: new state of the RTC clock.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_RTCCLKCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    (state) ?                                   \
    (tmpreg |= (0x01U << RCC_BDCR_RTCEN_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_RTCEN_Pos));

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Returns the frequency of different on chip clocks.
  * @param  clk: pointer to a RCC_ClocksTypeDef structure which
  *   will hold the clocks frequency.
  * @retval None.
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef* clk)
{
    uint32_t tmp = 0;
    uint8_t  divider = 0;
   
    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CFGR & RCC_CFGR_SWS_Msk; 
    switch (tmp)
    {
        case 0x00:  /* HSI8 used as system clock */
            clk->SYSCLK_Frequency = HSI8_VALUE;
            break;

        case 0x04:  /* HSE used as system clock */
            clk->SYSCLK_Frequency = HSE_VALUE;
            break;

        case 0x08:  /* HSI144 used as system clock */
            divider = (uint8_t)((RCC->CR & RCC_CR_HSI144DIV_Msk) >> RCC_CR_HSI144DIV_Pos);
            if(divider == 0x01)
            {
                clk->SYSCLK_Frequency = HSI144_VALUE_Div_1_5;
            }
            else 
            {
                clk->SYSCLK_Frequency = HSI144_VALUE;
            }
            break;

        case 0x0C:  /* LSI used as system clock */
            clk->SYSCLK_Frequency = LSI_VALUE;
            break;
        default:
            clk->SYSCLK_Frequency = HSI8_VALUE;
            break;
    }

    /* Compute HCLK, PCLK1, PCLK2 and ADCCLK clocks frequencies ----------------*/

    /* Get HCLK prescaler */
    tmp = (RCC->CFGR & RCC_CFGR_HPRE_Msk) >> RCC_CFGR_HPRE_Pos;
    divider = AHBPreTable[tmp];
    /* HCLK clock frequency */
    clk->HCLK_Frequency = clk->SYSCLK_Frequency >> divider;

    /* Get PCLK1 prescaler */
    tmp = (RCC->CFGR & RCC_CFGR_PPRE1_Msk) >> RCC_CFGR_PPRE1_Pos;
    divider = APBPreTable[tmp];
    /* PCLK1 clock frequency */
    clk->PCLK1_Frequency = clk->HCLK_Frequency >> divider;

    /* Get PCLK2 prescaler */
    tmp = (RCC->CFGR & RCC_CFGR_PPRE2_Msk) >> RCC_CFGR_PPRE2_Pos;
    divider = APBPreTable[tmp];
    /* PCLK2 clock frequency */
    clk->PCLK2_Frequency = clk->HCLK_Frequency >> divider;
}

/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @param  ahb_periph: specifies the AHB peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_AHBPeriph_DMA
  *   @arg RCC_AHBPeriph_SRAM
  *   @arg RCC_AHBPeriph_FLASH
  *   @arg RCC_AHBPeriph_CRC
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
  *   @arg RCC_AHBPeriph_GPIOC
  *   @arg RCC_AHBPeriph_GPIOD
  *   @arg RCC_AHBPeriph_HWDIV
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_AHBPeriphClockCmd(uint32_t ahb_periph, FunctionalState state)
{
    (state) ? \
    (RCC->AHBENR |=  ahb_periph) : \
    (RCC->AHBENR &= ~ahb_periph);
}

/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @param  apb2_periph: specifies the APB2 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB2Periph_SYSCFG
  *   @arg RCC_APB2Periph_ADC
  *   @arg RCC_APB2Periph_TIM1
  *   @arg RCC_APB2Periph_SPI1
  *   @arg RCC_APB2Periph_USART1
  *   @arg RCC_APB2Periph_COMP
  *   @arg RCC_APB2Periph_TIM14
  *   @arg RCC_APB2Periph_TIM16
  *   @arg RCC_APB2Periph_TIM17
  *   @arg RCC_APB2Periph_DBG
  *   @arg RCC_APB2Periph_EXTI
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB2PeriphClockCmd(uint32_t apb2_periph, FunctionalState state)
{
    (state) ? \
    (RCC->APB2ENR |=  apb2_periph) : \
    (RCC->APB2ENR &= ~apb2_periph);
}

/**
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @param  apb1_periph: specifies the APB1 peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB1Periph_TIM3
  *   @arg RCC_APB1Periph_USART2
  *   @arg RCC_APB1Periph_USART3
  *   @arg RCC_APB1Periph_I2C1
  *   @arg RCC_APB1Periph_CSM
  *   @arg RCC_APB1Periph_PWR
  *   @arg RCC_APB1Periph_IWDG
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB1PeriphClockCmd(uint32_t apb1_periph, FunctionalState state)
{
    (state) ? \
    (RCC->APB1ENR |=  apb1_periph) : \
    (RCC->APB1ENR &= ~apb1_periph);
}

/**
  * @brief  Forces or releases the AHB peripheral  peripheral reset.
  * @param  ahb_periph: specifies the AHB peripheral
  *   This parameter can be any combination of the following values:
  *   @arg RCC_AHBPeriph_DMA
  *   @arg RCC_AHBPeriph_CRC
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
  *   @arg RCC_AHBPeriph_GPIOC
  *   @arg RCC_AHBPeriph_GPIOD
  *   @arg RCC_AHBPeriph_HWDIV
  * @param  state: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_AHBPeriphResetCmd(uint32_t ahb_periph, FunctionalState state)
{
    (state) ? \
    (RCC->AHBRSTR |=  ahb_periph) : \
    (RCC->AHBRSTR &= ~ahb_periph);
}
/**
  * @brief  Forces or releases High Speed APB (APB2) peripheral reset.
  * @param  apb2_periph: specifies the APB2 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB2Periph_SYSCFG
  *   @arg RCC_APB2Periph_ADC
  *   @arg RCC_APB2Periph_TIM1
  *   @arg RCC_APB2Periph_SPI1
  *   @arg RCC_APB2Periph_USART1
  *   @arg RCC_APB2Periph_COMP
  *   @arg RCC_APB2Periph_TIM14
  *   @arg RCC_APB2Periph_TIM16
  *   @arg RCC_APB2Periph_TIM17
  *   @arg RCC_APB2Periph_DBG
  * @param  state: new state of the specified peripheral reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB2PeriphResetCmd(uint32_t apb2_periph, FunctionalState state)
{
    (state) ? \
    (RCC->APB2RSTR |= apb2_periph) : \
    (RCC->APB2RSTR &= ~apb2_periph);
}

/**
  * @brief  Forces or releases Low Speed APB (APB1) peripheral reset.
  * @param  apb1_periph: specifies the APB1 peripheral to reset.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_APB1Periph_TIM3   
  *   @arg RCC_APB1Periph_USART2  
  *   @arg RCC_APB1Periph_USART3  
  *   @arg RCC_APB1Periph_I2C1  
  *   @arg RCC_APB1Periph_CSM  
  *   @arg RCC_APB1Periph_PWR    
  * @param  state: new state of the specified peripheral clock.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_APB1PeriphResetCmd(uint32_t apb1_periph, FunctionalState state)
{
    (state) ? \
    (RCC->APB1RSTR |= apb1_periph) : \
    (RCC->APB1RSTR &= ~apb1_periph);
}

/**
  * @brief  Enables or disables the Clock Security System.
  * @param  state: new state of the Clock Security System..
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_ClockSecuritySystemCmd(FunctionalState state)
{
    (state) ? \
    (RCC->CR |=  (0x1U << RCC_CR_CSSON_Pos)) : \
    (RCC->CR &= ~(0x1U << RCC_CR_CSSON_Pos));
}

/**
  * @brief  Selects the clock source to output on MCO pin.
  * @param  mco_src: specifies the clock source to output.
  *   This parameter can be one of the following values:
  * @arg RCC_MCO_NoClock
  * @arg RCC_MCO_LSI
  * @arg RCC_MCO_LSE
  * @arg RCC_MCO_SYSCLK
  * @arg RCC_MCO_HSI_Div8
  * @arg RCC_MCO_HSE
  * @retval None.
  */
void RCC_MCOConfig(uint32_t mco_src)
{
    MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO_Msk, mco_src);
}

/**
  * @brief  Clears the RCC reset flags.
  * @param  None.
  * @retval None.
  */
void RCC_ClearFlag(void)
{
    RCC->CSR |= (1 << RCC_CSR_RMVF_Pos);
}

/**
  * @brief  Forces or releases the Backup domain reset.
  * @param  state: new state of the Backup domain reset.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void RCC_BackupResetCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0;

    tmpreg = RCC->BDCR;

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    (state) ?                                   \
    (tmpreg |= (0x01U << RCC_BDCR_BDRST_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_BDRST_Pos));

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Configure HSI144 frequency division.
  * @param  hsi144_div: HSI144 frequency division factor.
  *   This parameter can be one of the following values:
  * @arg RCC_HSI144_Div_None              
  * @arg RCC_HSI144_Div_1_5                                
  * @retval None.
  */
void RCC_HSI144DIVConfig(uint32_t hsi144_div)
{
    MODIFY_REG(RCC->CR, RCC_CR_HSI144DIV_Msk, hsi144_div);
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
