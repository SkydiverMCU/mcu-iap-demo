/***********************************************************************************************************************
    @file     hal_rcc.c
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
              MM32 FIRMWARE LIBRARY.
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

/* Define to prevent recursive inclusion -----------------------------------------------------------------------------*/
#define _HAL_RCC_C_

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_rcc.h"

uint8_t AHBPreTable[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
uint8_t APBPreTable[] = {0, 0, 0, 0, 1, 2, 3, 4};

/** @addtogroup MM32_Hardware_Abstract_Layer
  * @{
  */

/** @addtogroup RCC_HAL
  * @{
  */

/** @addtogroup RCC_Exported_Functions
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

    /* Reset SW, HPRE, PPRE1 and MCO bits */
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR &= ~RCC_CFGR_MCO_Msk;

    /* Reset  PLLON bits */
    RCC->CR &= ~RCC_CR_PLLON_Msk;
}


/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    RCC_FLAG_HSIRDY: HSI oscillator clock ready
  * @arg    RCC_FLAG_PLLRDY: PLL clock ready
  * @arg    RCC_FLAG_LSIRDY: LSI oscillator clock ready
  * @arg    RCC_FLAG_PINRST: Pin reset
  * @arg    RCC_FLAG_PORRST: POR/PDR reset
  * @arg    RCC_FLAG_SFTRST: Software reset
  * @arg    RCC_FLAG_IWDGRST: Independent Watchdog reset
  * @arg    RCC_FLAG_WWDGRST: Window Watchdog reset
  * @arg    RCC_FLAG_LPWRRST: Low Power reset
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus RCC_GetFlagStatus(uint8_t flag)
{
    uint32_t tmp = 0;
    uint32_t statusreg = 0;

    tmp = flag >> 5;
    if (tmp == 1)               /* The flag to check is in CR register */
    {
        statusreg = RCC->CR;
    }
    else                       /* The flag to check is in CSR register */
    {
        statusreg = RCC->CSR;
    }

    /* Get the flag position */
    tmp = flag & 0x1F;

    /* Return the flag status */
    return ((statusreg & ((uint32_t)1 << tmp)) ? SET : RESET);
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
  * @brief  Configures the PLL clock source and multiplication factor.
  *   This function must be used only when the PLL is disabled.
  * @param pll_src: 
  *    @arg    RCC_PLLSource_HSI
  * @param pll_pdiv: This parameter can be RCC_PLLCFGR[31:29].
  * @param pll_mul: This parameter can be RCC_PLLCFGR[23:16].
  * @param pll_div: This parameter can be RCC_PLLCFGR[10:8].
  * @retval : None
  */
void RCC_PLLConfig(uint32_t pll_src, uint32_t pll_pdiv, uint32_t pll_mul, uint32_t pll_div)
{
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLPDIV_Msk , pll_pdiv << RCC_PLLCFGR_PLLPDIV_Pos);
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLMUL_Msk , pll_mul << RCC_PLLCFGR_PLLMUL_Pos);        
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLDIV_Msk , pll_div << RCC_PLLCFGR_PLLDIV_Pos ); 
    MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC_Msk , pll_src << RCC_PLLCFGR_PLLSRC_Pos ); 
}

/**
  * @brief  Enables or disables the PLL.
  *   The PLL can not be disabled if it is used as system clock.
  * @param  state: new state of the PLL.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void RCC_PLLCmd(FunctionalState state)
{
    (state) ? \
    (RCC->CR |=  (0x01U << RCC_CR_PLLON_Pos) ) : \
    (RCC->CR &= ~(0x01U << RCC_CR_PLLON_Pos) );
}

/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  sys_clk_source: specifies the clock source used as system
  *         clock. This parameter can be one of the following values:
  *     @arg    RCC_SYSCLKSource_HSI: specifies HSI as system clock
  *     @arg    RCC_SYSCLKSource_PLL: specifies PLL as system clock
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
  *         - 0x00: HSI used as system clock
  *         - 0x04: HSI used as system clock
  *         - 0x08: PLL used as system clock
  *         - 0x0C: LSI used as system clock
  */
uint8_t RCC_GetSYSCLKSource(void)
{
    return ((RCC->CFGR & RCC_CFGR_SWS_Msk));
}

/**
  * @brief  Configures the HSI clock.
  * @param  clk: defines the HSI clock divider.
  *         This parameter can be one of the following values:
  * @arg    RCC_HSI_Div1
  * @arg    RCC_HSI_Div2
  * @arg    RCC_HSI_Div4
  * @arg    RCC_HSI_Div8
  * @arg    RCC_HSI_Div16
  * @arg    RCC_HSI_Div32
  * @arg    RCC_HSI_Div64
  * @arg    RCC_HSI_Div128
  * @retval None.
  */
void RCC_HSIConfig(uint32_t clk)
{
    MODIFY_REG(RCC->CR, RCC_CR_HSIDIV_Msk, clk);
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
    MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1_Msk, clk << RCC_CFGR_PPRE1_Pos );
}


/**
  * @brief  Enables or disables the specified RCC interrupts.
  * @param  it: specifies the RCC interrupt sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  * @arg RCC_IT_LSIRDY: LSI ready interrupt
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
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
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
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
  * @arg RCC_IT_HSIRDY: HSI ready interrupt
  * @arg RCC_IT_PLLRDY: PLL ready interrupt
  * @retval None.
  */
void RCC_ClearITPendingBit(uint8_t it)
{
    RCC->CIR |= (it << RCC_CIR_LSIRDYC_Pos);
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
    (RCC->CSR |=  ((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSIOE_Pos))) : \
    (RCC->CSR &= ~((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSIOE_Pos))) ;
}

/**
  * @brief  Returns the frequency of different on chip clocks.
  * @param  clk: pointer to a RCC_ClocksTypeDef structure which
  *   will hold the clocks frequency.
  * @retval None.
  */
void RCC_GetClocksFreq(RCC_ClocksTypeDef* clk)
{
    uint32_t tmp = 0, pll_pdiv = 0, pll_mul = 0, pll_div = 0;
    uint8_t  divider = 0, pllsource = 0;
   
    /* Get SYSCLK source -------------------------------------------------------*/
    tmp = RCC->CFGR & RCC_CFGR_SWS_Msk; 
    switch (tmp)
    {
        case 0x00:  /* HSI used as system clock */
        case 0x04:  /* HSI used as system clock */
            divider = (uint8_t)((RCC->CR & RCC_CR_HSIDIV_Msk) >> RCC_CR_HSIDIV_Pos);
            clk->SYSCLK_Frequency = HSI_VALUE >> divider;
            break;

        case 0x08:  /* PLL used as system clock */
            pll_pdiv = (RCC->PLLCFGR & RCC_PLLCFGR_PLLPDIV_Msk) >> RCC_PLLCFGR_PLLPDIV_Pos;
            pll_mul  = (RCC->PLLCFGR & RCC_PLLCFGR_PLLMUL_Msk) >> RCC_PLLCFGR_PLLMUL_Pos;
            pll_div  = (RCC->PLLCFGR & RCC_PLLCFGR_PLLDIV_Msk) >> RCC_PLLCFGR_PLLDIV_Pos;

            pllsource =(uint8_t)((RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC_Msk) >> RCC_PLLCFGR_PLLSRC_Pos);    
            if (pllsource == 0x00)/* HSI oscillator clock as PLL clock entry */
            {   
                divider = (uint8_t)((RCC->CR & RCC_CR_HSIDIV_Msk) >> RCC_CR_HSIDIV_Pos);
                clk->SYSCLK_Frequency = (HSI_VALUE >> divider) / (pll_pdiv+1) / (pll_div+1) * (pll_mul+1);
            }
            break;

        case 0x0C:  /* LSI used as system clock */
            clk->SYSCLK_Frequency = LSI_VALUE;
            break;

        default:
            clk->SYSCLK_Frequency = HSI_VALUE;
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
}

/**
  * @brief  Enables or disables the AHB peripheral clock.
  * @param  ahb_periph: specifies the AHB peripheral to gates its clock.
  *   This parameter can be any combination of the following values:
  *   @arg RCC_AHBPeriph_SRAM 
  *   @arg RCC_AHBPeriph_FLASH
  *   @arg RCC_AHBPeriph_CRC  
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
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
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @param  apb1_periph: specifies the APB1 peripheral to gates its clock.
  *   This parameter can be any combination of the following values: 
  *   @arg RCC_APB1Periph_TIM3 
  *   @arg RCC_APB1Periph_TIM16
  *   @arg RCC_APB1Periph_TIM17
  *   @arg RCC_APB1Periph_IWDG 
  *   @arg RCC_APB1Periph_EXTI           
  *   @arg RCC_APB1Periph_ADC       
  *   @arg RCC_APB1Periph_WWDG      
  *   @arg RCC_APB1Periph_SPI       
  *   @arg RCC_APB1Periph_LPTIM     
  *   @arg RCC_APB1Periph_UART1     
  *   @arg RCC_APB1Periph_LPUART    
  *   @arg RCC_APB1Periph_I2C       
  *   @arg RCC_APB1Periph_COMP      
  *   @arg RCC_APB1Periph_OPA1      
  *   @arg RCC_APB1Periph_OPA2      
  *   @arg RCC_APB1Periph_PWR       
  *   @arg RCC_APB1Periph_DBG       
  *   @arg RCC_APB1Periph_SYSCFG     
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
  *   @arg RCC_AHBPeriph_CRC  
  *   @arg RCC_AHBPeriph_GPIOA
  *   @arg RCC_AHBPeriph_GPIOB
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
  * @brief  Forces or releases Low Speed APB (APB1) peripheral reset.
  * @param  apb1_periph: specifies the APB1 peripheral to reset.
  *   This parameter can be any combination of the following values: 
  *   @arg RCC_APB1Periph_TIM3  
  *   @arg RCC_APB1Periph_TIM16
  *   @arg RCC_APB1Periph_TIM17
  *   @arg RCC_APB1Periph_ADC       
  *   @arg RCC_APB1Periph_WWDG      
  *   @arg RCC_APB1Periph_SPI       
  *   @arg RCC_APB1Periph_LPTIM     
  *   @arg RCC_APB1Periph_UART1     
  *   @arg RCC_APB1Periph_LPUART    
  *   @arg RCC_APB1Periph_I2C       
  *   @arg RCC_APB1Periph_COMP      
  *   @arg RCC_APB1Periph_OPA1      
  *   @arg RCC_APB1Periph_OPA2      
  *   @arg RCC_APB1Periph_PWR       
  *   @arg RCC_APB1Periph_DBG  
  *   @arg RCC_APB1Periph_SYSCFG           
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
  * @brief  Selects the clock source to output on MCO pin.
  * @param  mco_src: specifies the clock source to output.
  *   This parameter can be one of the following values:
  * @arg RCC_MCO_NoClock                    
  * @arg RCC_MCO_LSI      
  * @arg RCC_MCO_SYSCLK   
  * @arg RCC_MCO_HSI      
  * @arg RCC_MCO_PLL_Div2            
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
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
