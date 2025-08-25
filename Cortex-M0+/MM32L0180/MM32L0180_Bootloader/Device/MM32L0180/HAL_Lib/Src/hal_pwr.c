/***********************************************************************************************************************
    @file     hal_pwr.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE PWR FIRMWARE FUNCTIONS.
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
#define __HAL_PWR_C_

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_pwr.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup PWR
  * @{
  */

/** @defgroup PWR_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup PWR_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the PWR peripheral registers to their default reset
  * values.
  * @param  None.
  * @retval None.
  */
void PWR_DeInit(void)
{
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_PWR, DISABLE);
}

/**
  * @brief  Enables or disables access to the RTC and backup registers.
  * @param  state: new state of the access to the RTC and backup
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_BackupAccessCmd(FunctionalState state)
{
    uint32_t i = 0;
    uint32_t tmpreg = 0; 

    tmpreg = RCC->BDCR;
    for(i=0; i<30000; i++)
    {
        __NOP();
    }

    (state) ?                                  \
    (tmpreg |=  (0x01U << RCC_BDCR_DBP_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_DBP_Pos)) ;

    RCC->BDCR = tmpreg;
    for(i=0; i<10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the WakeUp Pin functionality.
  * @param  pinx: slect wakeup pin
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @arg    WAKEUP_PIN6
  * @param  state: new state of the WakeUp Pin functionality.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_WakeUpPinXCmd(uint8_t pin, FunctionalState state)
{
    PWR->CR2 = 0;

    (state) ?            \
    (PWR->CR2 |=  pin) : \
    (PWR->CR2 &= ~pin);
}

/**
  * @brief  Configure the edge detection polarity of the wakeup pin.
  * @param  pin: slect wakeup pin
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN0
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @param  edge: The edge detection configuration of the wakeup pin.
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_EDGE_RISE
  * @arg    WAKEUP_EDGE_FALL
  * @retval None.
  */
void PWR_WakeUpPinXEdgeConfig(uint8_t pin, uint8_t edge)
{
    PWR->CR3 = 0;

    switch (pin)
    {
        case WAKEUP_PIN0:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP0_Msk, (edge << PWR_CR3_WP0_Pos));
            break;
        case WAKEUP_PIN1:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP1_Msk, (edge << PWR_CR3_WP1_Pos));
            break;

        case WAKEUP_PIN2:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP2_Msk, (edge << PWR_CR3_WP2_Pos));
            break;

        case WAKEUP_PIN3:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP3_Msk, (edge << PWR_CR3_WP3_Pos));
            break;

        case WAKEUP_PIN4:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP4_Msk, (edge << PWR_CR3_WP4_Pos));
            break;

        case WAKEUP_PIN5:
            MODIFY_REG(PWR->CR3, PWR_CR3_WP5_Msk, (edge << PWR_CR3_WP5_Pos));
            break;

        default:
            break;
    }
}

/**
  * @brief  Checks whether the wakeup pinx flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @arg    WAKEUP_PIN6
  * @retval The new state of wakeup pinx flag (SET or RESET).
  */
FlagStatus PWR_GetWakeUpPinXFlagStatus(uint32_t flag)
{
    return ((FlagStatus)(PWR->SR & flag));
}

/**
  * @brief  Clears the wakeup pinx pending flag.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    WAKEUP_PIN1
  * @arg    WAKEUP_PIN2
  * @arg    WAKEUP_PIN3
  * @arg    WAKEUP_PIN4
  * @arg    WAKEUP_PIN5
  * @arg    WAKEUP_PIN6
  * @retval None.
  */
void PWR_ClearWakeUpPinXFlag(uint32_t flag)
{
    PWR->SCR = flag;
}

/**
  * @brief  Configure the fast wake up period in STANDBY mode.
  * @param  cycle: slect the fast wake up cycles.
  *         This parameter can be one of the following values:
  * @arg    PWR_STANDBY_FS_WK_9_Cycles
  * @arg    PWR_STANDBY_FS_WK_7_Cycles
  * @arg    PWR_STANDBY_FS_WK_5_Cycles
  * @arg    PWR_STANDBY_FS_WK_2_Cycles
  * @retval None.
  */
void PWR_StandbyFastWakeUpConfig(uint8_t cycle)
{
    RCC->CSR |= ((0x01U << RCC_CSR_LSION_Pos) | (0x01U << RCC_CSR_LSI_OEN_LV_Pos));
    MODIFY_REG(PWR->CR6, PWR_CR6_STDBY_FS_WK_Msk, cycle);
    PWR->CR6 |= (1 << PWR_CR6_PWR_SYNC_REQ_Pos);
    while(PWR->CR6 & PWR_CR6_PWR_SYNC_REQ_Msk);
}

/**
  * @brief  Enters SLEEP mode.
  * @param  regulator: specifies the regulator state in STOP mode.
  *         This parameter can be one of the following values:
  * @arg    PWR_Regulator_ON:  with regulator ON
  * @arg    PWR_Regulator_LowPower:  with regulator in low power mode.
  * @param  sleep_entry: Select Enter mode of SLEEP to execute related instructions
  *         This parameter can be one of the following values:
  * @arg    PWR_SLEEPNOW_WFI: enter SLEEPNOW mode with WFI instruction
  * @arg    PWR_SLEEPNOW_WFE: enter SLEEPNOW mode with WFE instruction
  * @arg    PWR_SLEEPONEXIT : enter SLEEPONEXIT mode with WFI instruction
  * @retval None.
  */
void PWR_EnterSLEEPMode(uint32_t regulator, uint32_t sleep_entry)
{
    MODIFY_REG(PWR->CR1, PWR_CR1_LPR_Msk, regulator);
    SCB->SCR &= ~(0x01U << SCB_SCR_SLEEPDEEP_Pos);

    if ((sleep_entry == PWR_SLEEPNOW_WFE) || (sleep_entry == PWR_SLEEPNOW_WFI))
    {
        SCB->SCR &= ~(0x01U << SCB_SCR_SLEEPONEXIT_Pos);

        if (sleep_entry == PWR_SLEEPNOW_WFI)
        {
            __WFI();
        }
        else
        {
            __SEV();
            __WFE();
            __WFE();
        }
    }
    else if (sleep_entry == PWR_SLEEPONEXIT)
    {
        SCB->SCR |= (0x01U << SCB_SCR_SLEEPONEXIT_Pos);
        __WFI();
    }
}

/**
  * @brief  Enters STOP mode.
  * @param  stop_mode:
  *         This parameter can be one of the following values:
  * @arg    PWR_MODE_STOP:
  * @arg    PWR_MODE_DEEPSTOP:
  * @param  stop_entry: specifies if STOP mode in entered with WFI or  WFE instruction.
  *         This parameter can be one of the following values:
  * @arg    PWR_STOPEntry_WFI: enter STOP mode with WFI instruction
  * @arg    PWR_STOPEntry_WFE: enter STOP mode with WFE instruction
  * @retval None.
  */
void PWR_EnterSTOPMode(uint32_t stop_mode, uint32_t stop_entry)
{
    uint8_t i = 0;
    uint32_t systickreg = 0;
    uint32_t nvicReg = 0;
    uint32_t wrIcerReg = 0;
    uint32_t compcsrReg[2] = {0};
    uint32_t exti16Reg = 0;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_COMP, ENABLE);

    compcsrReg[0] = COMP->COMP1CSR;
    compcsrReg[1] = COMP->COMP2CSR;
    
    systickreg = SysTick->CTRL & 0x01;

    MODIFY_REG(PWR->CR1, PWR_CR1_LPDS | PWR_CR1_PDDS, stop_mode);
    /* Set SLEEPDEEP bit of Cortex System Control Register */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* By default, clear the enablement of all interrupts except EXTI0 - EXTI15. The interrupt lines with enablement above EXTI16 will maintain their original enabled states */
    nvicReg = NVIC->ISER[0];
    exti16Reg = EXTI->IMR;
    wrIcerReg = nvicReg;
    wrIcerReg &= ~((1UL << EXTI0_1_IRQn)|(1UL << EXTI2_3_IRQn)|(1UL << EXTI4_15_IRQn));
    
    if(exti16Reg & (1UL << 16))
    {
        wrIcerReg &= ~(1UL << PVD_IRQn);
    }
    if(exti16Reg & (1UL << 17))
    {
        wrIcerReg &= ~(1UL << RTC_BKP_IRQn);
    } 
    if(exti16Reg & (0x3UL << 19))
    {
        wrIcerReg &= ~(1UL << ADC_COMP_IRQn);
                
        for(i=19; i<20; i++)
        {
            if(!(exti16Reg & (1UL << i)))
            {
                compcsrReg[i-19] &= ~0x1;
            }
        }
        COMP->COMP1CSR = compcsrReg[0];
        COMP->COMP2CSR = compcsrReg[1];
    }  
    if(exti16Reg & (1UL << 21))
    {
        wrIcerReg &= ~(1UL << IWDG_IRQn);
    }      
    if((exti16Reg & (1UL << 22)) || (exti16Reg & (1UL << 25)))
    {
        wrIcerReg &= ~(1UL << LPUART1_LPUART2_IRQn);
    }
    if((exti16Reg & (1UL << 26)) || (exti16Reg & (1UL << 27)))
    {
        wrIcerReg &= ~(1UL << LPUART3_LPUART4_IRQn);
    }
    if(exti16Reg & (1UL << 28))
    {
        wrIcerReg &= ~(1UL << LPUART5_IRQn);
    }
    if((exti16Reg & (1UL << 23)) || (exti16Reg & (1UL << 29)))
    {
        wrIcerReg &= ~(1UL << LPTIM1_LPTIM2_IRQn);
    }
    if((exti16Reg & (1UL << 30)) || (exti16Reg & (1UL << 31)))
    {
        wrIcerReg &= ~(1UL << LPTIM3_LPTIM4_IRQn);
    }    
    NVIC->ICER[0] = wrIcerReg;
    
    /* Enable HSI */
    RCC->CR |= 0x1;
    while((RCC->CR & 0x2) == 0);
	
    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR  &= ~(RCC_CFGR_HPRE | RCC_CFGR_SW);
    while((RCC->CFGR & RCC_CFGR_SWS) != 0);
	
    /* Before turning off prefetch, you need to clear the latency configuration */
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR &= ~FLASH_ACR_PRFTBE;
    while ((FLASH->ACR & FLASH_ACR_PRFTBS) != 0)
    {
    }
    
    SysTick->CTRL &= 0xFFFFFFFE;

    /* RCC_HSIDLY register */
    *(__IO uint32_t *)(RCC_BASE + 0x44) = 0xFF;	
    
    if(stop_entry == PWR_STOPEntry_WFI)
    {
        /* Request Wait For Interrupt */
        __WFI();
    }
    else
    {
        /* Request Wait For Event */
        __SEV();
        __WFE();
        __WFE();
    }
    NVIC->ISER[0] = nvicReg;
    SysTick->CTRL |= systickreg ;
    
    for(i=19; i<20; i++)
    {
        if((exti16Reg & (1UL << i)))
        {
            compcsrReg[i-19] |= 0x1;
        }
    }
    COMP->COMP1CSR = compcsrReg[0];
    COMP->COMP2CSR = compcsrReg[1];
    
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk; 
}

/**
  * @brief  Enters STANDBY mode.
  * @param  None.
  * @retval None.
  */
void PWR_EnterSTANDBYMode(void)
{
    uint8_t i = 0;
    uint32_t nvicReg = 0;
    uint32_t wrIcerReg = 0;
    uint32_t compcsrReg[2] = {0};
    uint32_t exti16Reg = 0;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_COMP, ENABLE);
	
    compcsrReg[0] = COMP->COMP1CSR;
    compcsrReg[1] = COMP->COMP2CSR;
    
    /* By default, clear the enablement of all interrupts except EXTI0 - EXTI15. The interrupt lines with enablement above EXTI16 will maintain their original enabled states */
    nvicReg = NVIC->ISER[0];
    exti16Reg = EXTI->IMR;
    wrIcerReg = nvicReg;
    wrIcerReg &= ~((1UL << EXTI0_1_IRQn)|(1UL << EXTI2_3_IRQn)|(1UL << EXTI4_15_IRQn));
      
    if(exti16Reg & (1UL << 16))
    {
        wrIcerReg &= ~(1UL << PVD_IRQn);
    }
    if(exti16Reg & (1UL << 17))
    {
        wrIcerReg &= ~(1UL << RTC_BKP_IRQn);
    } 
    if(exti16Reg & (0x3UL << 19))
    {
        wrIcerReg &= ~(1UL << ADC_COMP_IRQn);
                
        for(i=19; i<20; i++)
        {
            if(!(exti16Reg & (1UL << i)))
            {
                compcsrReg[i-19] &= ~0x1;
            }
        }
        COMP->COMP1CSR = compcsrReg[0];
        COMP->COMP2CSR = compcsrReg[1];
    }  
    if(exti16Reg & (1UL << 21))
    {
        wrIcerReg &= ~(1UL << IWDG_IRQn);
    }      
    if((exti16Reg & (1UL << 22)) || (exti16Reg & (1UL << 25)))
    {
        wrIcerReg &= ~(1UL << LPUART1_LPUART2_IRQn);
    }
    if((exti16Reg & (1UL << 26)) || (exti16Reg & (1UL << 27)))
    {
        wrIcerReg &= ~(1UL << LPUART3_LPUART4_IRQn);
    }
    if(exti16Reg & (1UL << 28))
    {
        wrIcerReg &= ~(1UL << LPUART5_IRQn);
    }
    if((exti16Reg & (1UL << 23)) || (exti16Reg & (1UL << 29)))
    {
        wrIcerReg &= ~(1UL << LPTIM1_LPTIM2_IRQn);
    }
    if((exti16Reg & (1UL << 30)) || (exti16Reg & (1UL << 31)))
    {
        wrIcerReg &= ~(1UL << LPTIM3_LPTIM4_IRQn);
    }    
    NVIC->ICER[0] = wrIcerReg;
    
    /* Enable HSI */
    RCC->CR |= 0x1;
    while((RCC->CR & 0x2) == 0);
	
    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR  &= ~(RCC_CFGR_HPRE | RCC_CFGR_SW);
    while((RCC->CFGR & RCC_CFGR_SWS) != 0);
	
    /* Before turning off prefetch, you need to clear the latency configuration */
    FLASH->ACR &= ~FLASH_ACR_LATENCY;
    FLASH->ACR &= ~FLASH_ACR_PRFTBE;
    while ((FLASH->ACR & FLASH_ACR_PRFTBS) != 0)
    {
    }
    
    SysTick->CTRL &= 0xFFFFFFFE;
	
    /* RCC_HSIDLY register */
    *(__IO uint32_t *)(RCC_BASE + 0x44) = 0xFF;
    
    PWR->CR1 |= PWR_CR1_PDDS;
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
#if defined(__CC_ARM)
    __force_stores();
#endif
    __WFI();
    
    for(i=19; i<20; i++)
    {
        if((exti16Reg & (1UL << i)))
        {
            compcsrReg[i-19] |= 0x1;
        }
    }
    COMP->COMP1CSR = compcsrReg[0];
    COMP->COMP2CSR = compcsrReg[1];
}

/**
  * @brief  Enables or disables enter low power run mode.
  *         Before entering this mode, ensure the system frequency
  *         does not exceed 2MHZ. After you exit this mode, you can
  *         increase the system clock frequency.
  * @param  state: new state of the low power run mode.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_LowPowerRunModeCmd(FunctionalState state)
{
    (state) ?                                  \
    (PWR->CR1 |= (0x01U << PWR_CR1_LPR_Pos)) : \
    (PWR->CR1 &= ~(0x01U << PWR_CR1_LPR_Pos));
}

/**
  * @brief  Checks whether the specified PWR flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_STANDBY: StandBy flag
  * @arg    PWR_FLAG_WAKEUP: wakeup flag
  * @retval The new state of PWR_FLAG (SET or RESET).
  */
FlagStatus PWR_GetFlagStatus(uint32_t flag)
{
    return ((FlagStatus)(PWR->CSR & flag));
}

/**
  * @brief  Clears the PWR's pending flags.
  * @param  flag: specifies the flag to clear.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_STANDBY: StandBy flag
  * @arg    PWR_FLAG_WAKEUP: wakeup flag
  * @retval None.
  */
void PWR_ClearFlag(uint32_t flag)
{
    PWR->CR1 |= flag << 2;
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
