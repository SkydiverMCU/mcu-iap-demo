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


/* Define to prevent recursive inclusion -------------------------------------*/
#define __HAL_PWR_C_

/* Files includes ------------------------------------------------------------*/
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

    for (i = 0; i < 30000; i++)
    {
        __NOP();
    }

    (state) ?                                 \
    (tmpreg |= (0x01U << RCC_BDCR_DBP_Pos)) : \
    (tmpreg &= ~(0x01U << RCC_BDCR_DBP_Pos));

    RCC->BDCR = tmpreg;

    for (i = 0; i < 10000; i++)
    {
        __NOP();
    }
}

/**
  * @brief  Enables or disables the Power Voltage Detector(PVD).
  * @param  state: new state of the PVD.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void PWR_PVDCmd(FunctionalState state)
{
    (state) ? \
    (PWR->CR |=  (0x01U << PWR_CR_PVDE_Pos)) : \
    (PWR->CR &= ~(0x01U << PWR_CR_PVDE_Pos));
}

/**
  * @brief  Configures the voltage threshold detected by the Power Voltage
  *         Detector(PVD).
  * @param  pvd_level: specifies the PVD detection level
  *         This parameter can be one of the following values:
  * @arg    PWR_PVDLevel_1V8: PVD detection level set to 1.8V
  * @arg    PWR_PVDLevel_2V1: PVD detection level set to 2.1V
  * @arg    PWR_PVDLevel_2V4: PVD detection level set to 2.4V
  * @arg    PWR_PVDLevel_2V7: PVD detection level set to 2.7V
  * @arg    PWR_PVDLevel_3V0: PVD detection level set to 3.0V
  * @arg    PWR_PVDLevel_3V3: PVD detection level set to 3.3V
  * @arg    PWR_PVDLevel_3V6: PVD detection level set to 3.6V
  * @arg    PWR_PVDLevel_3V9: PVD detection level set to 3.9V
  * @arg    PWR_PVDLevel_4V2: PVD detection level set to 4.2V
  * @arg    PWR_PVDLevel_4V5: PVD detection level set to 4.5V
  * @arg    PWR_PVDLevel_4V8: PVD detection level set to 4.8V
  * @retval None.
  */
void PWR_PVDLevelConfig(uint32_t pvd_level)
{
    MODIFY_REG(PWR->CR, PWR_CR_PLS_Msk, pvd_level);
}

/**
  * @brief  Enters SLEEP mode.
  * @param  sleep_entry: Select Enter mode of SLEEP to execute related instructions
  *         This parameter can be one of the following values:
  * @arg    PWR_SLEEPNOW_WFI: enter SLEEPNOW mode with WFI instruction
  * @arg    PWR_SLEEPNOW_WFE: enter SLEEPNOW mode with WFE instruction
  * @arg    PWR_SLEEPONEXIT : enter SLEEPONEXIT mode with WFI instruction
  * @retval None.
  */
void PWR_EnterSLEEPMode(uint32_t sleep_entry)
{
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    if((sleep_entry == PWR_SLEEPNOW_WFE) || (sleep_entry == PWR_SLEEPNOW_WFI))
    {
        SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;
        if(sleep_entry == PWR_SLEEPNOW_WFI)
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
        SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
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
    uint32_t systickreg = 0;
    uint32_t nvicReg = 0;
    uint32_t wrIcerReg = 0;
    uint32_t exti16Reg = 0;
    uint32_t adcReg = ADC1->ADCFG;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC, ENABLE);
	
    systickreg = SysTick->CTRL & 0x01;
    
    MODIFY_REG(PWR->CR, PWR_CR_LPDS, stop_mode);
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;	
	
    /* By default, clear the enablement of all interrupts except EXTI0 - EXTI15. The interrupt lines with enablement above EXTI16 will maintain their original enabled states */
    nvicReg = NVIC->ISER[0];
    exti16Reg = EXTI->IMR;
    wrIcerReg = nvicReg;
    wrIcerReg &= ~((1 << EXTI0_1_IRQn)|(1 << EXTI2_3_IRQn)|(1 << EXTI4_15_IRQn));
    
    if(exti16Reg & (1 << 16))
    {
        wrIcerReg &= ~(1 << PVD_IRQn);
    }
    if(exti16Reg & (1 << 17))
    {
        wrIcerReg &= ~(1 << RTC_BKP_IRQn);
    }
    if(exti16Reg & (1 << 19))
    {
        wrIcerReg &= ~(1 << ADC_COMP_IRQn);
        ADC1->ADCFG &= ~ADC_ADCFG_ADEN_Msk;
    }
    if(exti16Reg & (1 << 24))
    {
        wrIcerReg &= ~(1 << IWDG_IRQn);
    }
    NVIC->ICER[0] = wrIcerReg;
    
    
    /* Enable HSI */
    RCC->CR |= 0x1;
    while((RCC->CR & 0x2) == 0);
	
    /* To ensure that the instruction is deterministic after awakening, turn off the prefetch function before stop. */
    RCC->CFGR  &= ~(RCC_CFGR_HPRE_Msk | RCC_CFGR_SW_Msk);
    while((RCC->CFGR & RCC_CFGR_SWS_Msk) != 0);
	
    /* Before turning off prefetch, you need to clear the latency configuration */
    FLASH->ACR &= ~FLASH_ACR_LATENCY_Msk;
    FLASH->ACR &= ~FLASH_ACR_PRFTBE_Msk;
    while ((FLASH->ACR & FLASH_ACR_PRFTBS_Msk) != 0)
    {
    }
    
    SysTick->CTRL &= 0xFFFFFFFE;

    /* RCC_HSIDLY register */
    *(__IO uint32_t *)(RCC_BASE + 0x44) = 0xFF;	
	
	
    if (stop_entry == PWR_STOPEntry_WFI)
    {
        __WFI();
    }
    else
    {
        __SEV();
        __WFE();
        __WFE();
    }
    NVIC->ISER[0] = nvicReg;
    SysTick->CTRL |= systickreg ;
	
    ADC1->ADCFG = adcReg;
    
    SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
}

/**
  * @brief  Checks whether the specified PWR flag is set or not.
  * @param  flag: specifies the flag to check.
  *         This parameter can be one of the following values:
  * @arg    PWR_FLAG_PVDO: PVD Output
  * @retval The new state of PWR_FLAG (SET or RESET).
  */
FlagStatus PWR_GetPVDOFlagStatus(uint32_t flag)
{
    return (FlagStatus)(PWR->CSR & flag);
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
