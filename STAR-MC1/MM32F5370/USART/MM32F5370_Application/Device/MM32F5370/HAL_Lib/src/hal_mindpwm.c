/***********************************************************************************************************************
    @file     hal_mindpwm.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE MindPWM FIRMWARE FUNCTIONS.
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
#define _HAL_MINDPWM_C_

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "hal_mindpwm.h"
#include "string.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup MINDPWM
  * @{
  */

/** @defgroup MINDPWM_Private_Defines
  * @{
  */
  
/*! @brief Temporary PWM duty cycle. */
static float s_pwmGetPwmDutyCycle[PWM_SUBMODULE_NUM][PWM_SUBMODULE_CHANNEL] = {{0}};

/**
  * @}
  */

/** @defgroup MINDPWM_Private_Functions
  * @{
  */

/*!
 * brief Complement the variable of type uint16_t as needed
 *
 * This function can complement the variable of type uint16_t as needed.For example,
 * need to ask for the opposite of a positive integer.
 *
 * param value    Parameters of type uint16_t
 */
__STATIC_INLINE int16_t PWM_GetComplementU16(uint16_t value)
{
    return (~value + 1U);
}

/*!
 * brief Ungates the PWM submodule clock and configures the peripheral for basic operation.
 *
 * note This API should be called at the beginning of the application using the PWM driver.
 *
 * param base      PWM peripheral base address
 * param subModule PWM submodule to configure
 * param config    Pointer to user's PWM config structure.
 *
 * return (0) means success; else failed.
 */
int32_t PWM_Init(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, const PWM_InitTypeDef *config)
{
    /* Source clock for submodule 0 cannot be itself */
    if ((config->clockSource == PWM_Submodule0Clock) && (subModule == PWM_Module_0))
    {
        return (1);
    }

    /* Reload source select clock for submodule 0 cannot be master reload */
    if ((config->reloadSelect == PWM_MasterReload) && (subModule == PWM_Module_0))
    {
        return (1);
    }

    MODIFY_REG(mindpwm->SM[subModule].CR0, 
               (MindPWM_SMCR0_CLK_SEL_Msk | MindPWM_SMCR0_PRSC_Msk | MindPWM_SMCR0_FORCE_SEL_Msk | \
                MindPWM_SMCR0_INIT_SEL_Msk | MindPWM_SMCR0_RELOAD_SEL_Msk | MindPWM_SMCR0_LDFQ_Msk), 
               ((config->clockSource << MindPWM_SMCR0_CLK_SEL_Pos) | \
                (config->prescale << MindPWM_SMCR0_PRSC_Pos) | \
                (config->forceTrigger << MindPWM_SMCR0_FORCE_SEL_Pos) | \
                (config->initializationControl << MindPWM_SMCR0_INIT_SEL_Pos) | \
                (config->reloadSelect << MindPWM_SMCR0_INIT_SEL_Pos) | \
                (config->reloadFrequency << MindPWM_SMCR0_LDFQ_Pos) ));
    
    if(config->enableDebugMode)
    {
        mindpwm->SM[subModule].OCR |= MindPWM_SMOCR_DBGEN_Msk;
    }
    else
    {
        mindpwm->SM[subModule].OCR &= ~MindPWM_SMOCR_DBGEN_Msk;
    }
            
    /* Setup PWM A & B to be independent or a complementary-pair */
    switch (config->pairOperation)
    {
        case PWM_Independent:
            mindpwm->SM[subModule].CR1 |= MindPWM_SMCR1_INDEP_Msk;
            break;
        case PWM_ComplementaryPwmA:
            mindpwm->SM[subModule].CR1 &= ~MindPWM_SMCR1_INDEP_Msk;
            mindpwm->GCR0 &= ~((uint32_t)1U << (MindPWM_GCR0_IPOL_Pos + (uint32_t)subModule));
            break;
        case PWM_ComplementaryPwmB:
            mindpwm->SM[subModule].CR1 &= ~MindPWM_SMCR1_INDEP_Msk;
            mindpwm->GCR0 |= ((uint32_t)1U << (MindPWM_GCR0_IPOL_Pos + (uint32_t)subModule));
            break;
        default:
            break;
    }

    /* Setup register reload logic */
    switch (config->reloadLogic)
    {
        case PWM_ReloadImmediate:
            mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_LDMOD_Msk;
            break;
        case PWM_ReloadPwmHalfCycle:
            mindpwm->SM[subModule].CR0 &= ~MindPWM_SMCR0_LDMOD_Msk;
            mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_HALF_Msk;
            mindpwm->SM[subModule].CR0 &= ~MindPWM_SMCR0_FULL_Msk;
            break;
        case PWM_ReloadPwmFullCycle:
            mindpwm->SM[subModule].CR0 &= ~MindPWM_SMCR0_LDMOD_Msk;
            mindpwm->SM[subModule].CR0 &= ~MindPWM_SMCR0_HALF_Msk;
            mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_FULL_Msk;
            break;
        case PWM_ReloadPwmHalfAndFullCycle:
            mindpwm->SM[subModule].CR0 &= ~MindPWM_SMCR0_LDMOD_Msk;
            mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_HALF_Msk;
            mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_FULL_Msk;
            break;
        default:
            break;
    }

    /* Issue a Force trigger event when configured to trigger locally */
    if (config->forceTrigger == PWM_Force_Local)
    {
        mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_FORCE_LOCAL_Msk;
    }

    return (0);
}

/*!
 * brief Gate the PWM submodule clock
 *
 * param base      PWM peripheral base address
 */
void PWM_Deinit(MindPWM_TypeDef *mindpwm)
{
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_MDPWM, ENABLE);
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_MDPWM, DISABLE);
}

/*!
 * brief  Fill in the PWM config struct with the default settings
 *
 * The default values are:
 *   config->enableDebugMode = false;
 *   config->reloadSelect = PWM_LocalReload;
 *   config->clockSource = PWM_BusClock;
 *   config->prescale = PWM_Prescale_Divide_1;
 *   config->initializationControl = PWM_Initialize_LocalSync;
 *   config->forceTrigger = kPWM_Force_Local;
 *   config->reloadFrequency = kPWM_LoadEveryOportunity;
 *   config->reloadLogic = PWM_ReloadImmediate;
 *   config->pairOperation = PWM_Independent;
 * param config Pointer to user's PWM config structure.
 */
void PWM_GetDefaultConfig(PWM_InitTypeDef *config)
{
    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* PWM is paused in debug mode */
    config->enableDebugMode = false;
    /* PWM module uses the local reload signal to reload registers */
    config->reloadSelect = PWM_LocalReload;
    /* Use the IP Bus clock as source clock for the PWM submodule */
    config->clockSource = PWM_BusClock;
    /* Clock source prescale is set to divide by 1*/
    config->prescale = PWM_Prescale_Divide_1;
    /* Local sync causes initialization */
    config->initializationControl = PWM_Initialize_LocalSync;
    /* The local force signal, CTRL2[FORCE], from the submodule is used to force updates */
    config->forceTrigger = PWM_Force_Local;
    /* PWM reload frequency, reload opportunity is PWM half cycle or full cycle.
     * This field is not used in Immediate reload mode
     */
    config->reloadFrequency = PWM_LoadEveryOportunity;
    /* Buffered-registers get loaded with new values as soon as LDOK bit is set */
    config->reloadLogic = PWM_ReloadImmediate;
    /* PWM A & PWM B operate as 2 independent channels */
    config->pairOperation = PWM_Independent;
}

/*!
 * brief Sets up the PWM signals for a PWM submodule.
 *
 * The function initializes the submodule according to the parameters passed in by the user. The function
 * also sets up the value compare registers to match the PWM signal requirements.
 * If the dead time insertion logic is enabled, the pulse period is reduced by the
 * dead time period specified by the user.
 *
 * param base        PWM peripheral base address
 * param subModule   PWM submodule to configure
 * param chnlParams  Array of PWM channel parameters to configure the channel(s), PWMX submodule is not supported.
 * param numOfChnls  Number of channels to configure, this should be the size of the array passed in.
 *                    Array size should not be more than 2 as each submodule has 2 pins to output PWM
 * param mode        PWM operation mode, options available in enumeration ::pwm_mode_t
 * param pwmFreq_Hz  PWM signal frequency in Hz
 * param srcClock_Hz PWM main counter clock in Hz.
 *
 * return Returns kStatusFail if there was error setting up the signal; kStatusSuccess otherwise
 */
int32_t PWM_SetupPwm(MindPWM_TypeDef *mindpwm,
                      pwm_submodule_t subModule,
                      const pwm_signal_param_t *chnlParams,
                      uint8_t numOfChnls,
                      pwm_mode_t mode,
                      float pwmFreq_Hz,
                      uint32_t srcClock_Hz)
{ 
    uint32_t integerClock = 0;
    uint64_t fractionalClock = 0;
    uint32_t frequencyRatio = 0;
    float pulseCnt = 0, pwmHighPulse = 0;
    uint16_t pulseCntInt = 0, pulseCntFrac = 0; 
    uint16_t pwmHighPulseInt = 0, pwmHighPulseFrac = 0; 
    uint16_t modulo = 0;
    uint8_t i;
    
    mindpwm->GCR1 |= MindPWM_GCR1_HRPWM_LDO_EN_Msk;
    mindpwm->SM[subModule].FRCR0 |= (MindPWM_SMFRCR0_FRAC_PU_Msk | MindPWM_SMFRCR0_FRAC1_EN_Msk | MindPWM_SMFRCR0_FRAC23_EN_Msk | MindPWM_SMFRCR0_FRAC45_EN_Msk);

    for (i = 0; i < numOfChnls; i++)
    {
        if (chnlParams[i].pwmChannel == PWM_PwmX)
        {
            /* PWMX configuration is not supported yet */
            return (1);
        }
    }

    /* Divide the clock by the prescale value */
    integerClock = (srcClock_Hz / (1UL << ((mindpwm->SM[subModule].CR0 & MindPWM_SMCR0_PRSC_Msk) >> MindPWM_SMCR0_PRSC_Pos)));
    fractionalClock  = SystemCoreClock * (uint64_t)32;
    frequencyRatio = (uint32_t)(fractionalClock / integerClock);  
    
    pulseCnt     = integerClock / pwmFreq_Hz;
    pulseCntInt  = (uint16_t) pulseCnt;
    pulseCntFrac = (uint16_t)((pulseCnt - pulseCntInt) * frequencyRatio);

    /* Setup each PWM channel */
    for (i = 0; i < numOfChnls; i++)
    {
        /* Calculate pulse width */
        pwmHighPulse     = (pulseCnt * chnlParams->dutyCyclePercent) / 100;
        pwmHighPulseInt  = (uint16_t) pwmHighPulse;
        pwmHighPulseFrac = (uint16_t)((pwmHighPulse - pwmHighPulseInt) * frequencyRatio);

        /* Setup the different match registers to generate the PWM signal */
        switch (mode)
        {
            case PWM_UpwardCenterAligned:
                /* Setup the PWM period for a signed center aligned signal */
                if (i == 0U)
                {
                    modulo = (pulseCntInt >> 1U);

                    mindpwm->SM[subModule].INIT   = PWM_GetComplementU16(modulo);
                    mindpwm->SM[subModule].VAL0   = 0;
                    mindpwm->SM[subModule].VAL1   = modulo - 1U;  
                    mindpwm->SM[subModule].FRCR0 |= (pulseCntFrac << MindPWM_SMFRCR0_FRACVAL1_Pos);
                }

                /* Setup the PWM dutycycle */
                if (chnlParams->pwmChannel == PWM_PwmA)
                {
                    mindpwm->SM[subModule].VAL2 = PWM_GetComplementU16(pwmHighPulseInt / 2U);
                    mindpwm->SM[subModule].VAL3 = (pwmHighPulseInt / 2U);
                    mindpwm->SM[subModule].FRCR1 |= (pwmHighPulseFrac << MindPWM_SMFRCR1_FRACVAL3_Pos);
                }
                else
                {
                    mindpwm->SM[subModule].VAL4 = PWM_GetComplementU16(pwmHighPulseInt / 2U);
                    mindpwm->SM[subModule].VAL5 = (pwmHighPulseInt / 2U);
                    mindpwm->SM[subModule].FRCR1 |= (pwmHighPulseFrac << MindPWM_SMFRCR1_FRACVAL5_Pos);
                }
                break;
            case PWM_UpdownCenterAligned:
                break;
            case PWM_EdgeAligned:
                break;
            default:
                break;
        }
        /* Setup register shift values based on the channel being configured.
         * Also setup the deadtime value
         */
        if (chnlParams->pwmChannel == PWM_PwmA)
        {
            /* Setup signal active level */
            if ((bool)chnlParams->level == PWM_HighTrue)
            {
                mindpwm->SM[subModule].OCR &= ~MindPWM_SMOCR_POLA_Msk;
            }
            else
            {
                mindpwm->SM[subModule].OCR |= MindPWM_SMOCR_POLA_Msk;
            }
            
            if (chnlParams->pwmchannelenable)
            {
                mindpwm->GCR0 |= ((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMA_EN_Pos + (uint32_t)subModule));
            }
            else
            {
                mindpwm->GCR0 &= ~((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMA_EN_Pos + (uint32_t)subModule));
            }    
            
            MODIFY_REG(mindpwm->SM[subModule].DTCNT, MindPWM_SMDTCNT_DTCNTA_Msk, chnlParams->deadtimeValue << MindPWM_SMDTCNT_DTCNTA_Pos);
            /* Set PWM output fault status */
            MODIFY_REG(mindpwm->SM[subModule].OCR, MindPWM_SMOCR_PWMA_FS_Msk, chnlParams->faultState << MindPWM_SMOCR_PWMA_FS_Pos);
        }
        else
        {
            /* Setup signal active level */
            if ((bool)chnlParams->level == PWM_HighTrue)
            {
                mindpwm->SM[subModule].OCR &= ~MindPWM_SMOCR_POLB_Msk;
            }
            else
            {
                mindpwm->SM[subModule].OCR |= MindPWM_SMOCR_POLB_Msk;
            }
            
            if (chnlParams->pwmchannelenable)
            {
                mindpwm->GCR0 |= ((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMB_EN_Pos + (uint32_t)subModule));
            }
            else
            {
                mindpwm->GCR0 &= ~((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMB_EN_Pos + (uint32_t)subModule));
            }    

            MODIFY_REG(mindpwm->SM[subModule].DTCNT, MindPWM_SMDTCNT_DTCNTB_Msk, chnlParams->deadtimeValue << MindPWM_SMDTCNT_DTCNTB_Pos);
            /* Set PWM output fault status */
            MODIFY_REG(mindpwm->SM[subModule].OCR, MindPWM_SMOCR_PWMB_FS_Msk, chnlParams->faultState << MindPWM_SMOCR_PWMB_FS_Pos);
        }

        /* Get the pwm duty cycle */
        s_pwmGetPwmDutyCycle[subModule][chnlParams->pwmChannel] = chnlParams->dutyCyclePercent;

        /* Get the next channel parameters */
        chnlParams++;
    }

    return (0);
}

/*!
 * brief Set PWM phase shift for PWM channel running on channel PWM_A, PWM_B which with 50% duty cycle.
 *
 * param base        PWM peripheral base address
 * param subModule   PWM submodule to configure
 * param pwmChannel  PWM channel to configure
 * param pwmFreq_Hz  PWM signal frequency in Hz
 * param srcClock_Hz PWM main counter clock in Hz.
 * param shiftvalue  Phase shift value, range in 0 ~ 50
 * param doSync      true: Set LDOK bit for the submodule list;
 *                   false: LDOK bit don't set, need to call PWM_SetPwmLdok to sync update.
 *
 * return Returns (1) if there was error setting up the signal; (0) otherwise
 */
int32_t PWM_SetupPwmPhaseShift(MindPWM_TypeDef *mindpwm,
                                pwm_submodule_t subModule,
                                pwm_channels_t pwmChannel,
                                uint32_t pwmFreq_Hz,
                                uint32_t srcClock_Hz,
                                uint8_t shiftvalue,
                                bool doSync)
{
    uint32_t pwmClock;
    uint16_t pulseCnt = 0, pwmHighPulse = 0;
    uint16_t modulo = 0;
    uint16_t shift  = 0;

    if (pwmChannel != PWM_PwmX)
    {
        /* Divide the clock by the prescale value */
        pwmClock = (srcClock_Hz / (1UL << ((mindpwm->SM[subModule].CR0 & MindPWM_SMCR0_PRSC_Msk) >> MindPWM_SMCR0_PRSC_Pos)));
        pulseCnt = (uint16_t)(pwmClock / pwmFreq_Hz);

        /* Clear LDOK bit if it is set */
        if (0U != (mindpwm->GCR0 & (1UL << (MindPWM_GCR0_LDOK_Pos + subModule))))
        {
            mindpwm->GCR0 |= (1UL << (MindPWM_GCR0_CLDOK_Pos + subModule));
        }

        modulo = (pulseCnt >> 1U);
        /* Indicates the start of the PWM period */
        mindpwm->SM[subModule].INIT = PWM_GetComplementU16(modulo);
        /* Indicates the center value */
        mindpwm->SM[subModule].VAL0 = 0;
        /* Indicates the end of the PWM period */
        /* The change during the end to start of the PWM period requires a count time */
        mindpwm->SM[subModule].VAL1 = modulo - 1U;

        /* Immediately upon when GCR0[LDOK] being set */
        mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_LDMOD_Msk;

        /* phase shift value */
        shift = (pulseCnt * shiftvalue) / 100U;

        /* duty cycle 50% */
        pwmHighPulse = pulseCnt / 2U;

        if (pwmChannel == PWM_PwmA)
        {
            mindpwm->SM[subModule].VAL2 = PWM_GetComplementU16(modulo) + shift;
            mindpwm->SM[subModule].VAL3 = PWM_GetComplementU16(modulo) + pwmHighPulse + shift - 1U;
        }
        else if (pwmChannel == PWM_PwmB)
        {
            mindpwm->SM[subModule].VAL4 = PWM_GetComplementU16(modulo) + shift;
            mindpwm->SM[subModule].VAL5 = PWM_GetComplementU16(modulo) + pwmHighPulse + shift - 1U;
        }
        else
        {
            return (1);
        }

        if (doSync)
        {
            /* Set LDOK bit to load VALx bit */
            mindpwm->GCR0 |= (1UL << (MindPWM_GCR0_CLDOK_Pos + subModule));
        }
    }
    else
    {
        return (1);
    }

    return (0);
}


/*!
 * @brief Sets up the PWM fault input filter.
 *
 * @param base                   PWM peripheral base address
 * @param faultNum               PWM_Fault_0 ... PWM_Fault_15
 * @param faultInputFilterParams Parameters passed in to set up the fault input filter.
 */
void PWM_SetupFaultInputFilter(MindPWM_TypeDef *mindpwm, pwm_fault_input_t faultNum, const pwm_fault_input_filter_param_t *faultInputFilterParams)
{
    uint32_t channel = 0;
    __IO uint32_t *reg = NULL;
    
    channel    = faultNum / 4;
    
    if(channel == 0)
    {
        reg = &(mindpwm->FC0CR1); 
    }
    else if(channel == 1)
    {
        reg = &(mindpwm->FC1CR1); 
    }
    else if(channel == 2)
    {
        reg = &(mindpwm->FC2CR1); 
    }
    else if(channel == 3)
    {
        reg = &(mindpwm->FC3CR1); 
    }

    /* When changing values for fault period from a non-zero value, first write a value of 0 to clear the filter. */
    if (0U != (*reg & MindPWM_FCCR1_FILT_PER_Msk))
    {
        *reg &= ~MindPWM_FCCR1_FILT_PER_Msk;
    }

    MODIFY_REG(*reg, 
               (MindPWM_FCCR1_FILT_PER_Msk | MindPWM_FCCR1_FILT_CNT_Msk | MindPWM_FCCR1_GSTR_Msk), 
               ((faultInputFilterParams->faultFilterPeriod << MindPWM_FCCR1_FILT_PER_Pos)  | \
                (faultInputFilterParams->faultFilterCount << MindPWM_FCCR1_FILT_CNT_Pos) | \
                ((faultInputFilterParams->faultGlitchStretch ? 1U : 0U) << MindPWM_FCCR1_GSTR_Pos)));           
}

/*!
 * brief Sets up the PWM fault protection.
 *
 * PWM has 16 fault inputs.
 *
 * param base        PWM peripheral base address
 * param subModule   PWM submodule to configure
 * param pwmChannel  Channel to configure
 * param faultNum    PWM_Fault_0 ... PWM_Fault_15
 * param faultParams Pointer to the PWM fault config structure
 */
void PWM_SetupFaults(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel, pwm_fault_input_t faultNum, const PWM_Fault_InitTypeDef *faultParams)
{
    uint32_t channel = 0, subchannel = 0;
    __IO uint32_t *reg0 = NULL;
    __IO uint32_t *reg1 = NULL;
    uint32_t tmp = 0;
    
    channel    = faultNum / 4;
    subchannel = faultNum % 4;
    
    if(channel == 0)
    {
        reg0 = &(mindpwm->FC0CR0);
        reg1 = &(mindpwm->FC0CR1); 
        
        MindPWM->SM[subModule].FDIS0 |= (1UL << (subchannel + (pwmChannel * 4)));     
    }
    else if(channel == 1)
    {
        reg0 = &(mindpwm->FC1CR0);
        reg1 = &(mindpwm->FC1CR1); 
        
        MindPWM->SM[subModule].FDIS0 |= (1UL << (subchannel + (pwmChannel * 4) + 8)); 
    }
    else if(channel == 2)
    {
        reg0 = &(mindpwm->FC2CR0); 
        reg1 = &(mindpwm->FC2CR1); 
        
        MindPWM->SM[subModule].FDIS1 |= (1UL << (subchannel + (pwmChannel * 4))); 
    }
    else if(channel == 3)
    {
        reg0 = &(mindpwm->FC3CR0);         
        reg1 = &(mindpwm->FC3CR1); 
        
        MindPWM->SM[subModule].FDIS1 |= (1UL << (subchannel + (pwmChannel * 4) + 8)); 
    }
    
    /* The fault input function is enabled */
    *reg1 |= MindPWM_FCCR1_FEN_Msk;

    /* Set the faults level-settting */
    if (faultParams->faultLevel)
    {
        *reg0 |= ((uint32_t)1U << (MindPWM_FCCR0_FLVL_Pos + subchannel));
    }
    else
    {
        *reg0 &= ~((uint32_t)1U << (MindPWM_FCCR0_FLVL_Pos + subchannel));
    }
    
    /* Set the fault clearing mode */
    if (faultParams->faultClearingMode != 0U)
    {
        /* Use manual fault clearing */
        *reg0 &= ~((uint32_t)1U << (MindPWM_FCCR0_FAUTO_Pos + subchannel));
        if (faultParams->faultClearingMode == PWM_ManualSafety)
        {
            /* Use manual fault clearing with safety mode enabled */
            *reg0 |= ((uint32_t)1U << (MindPWM_FCCR0_FSAFE_Pos + subchannel));
        }
        else
        {
            /* Use manual fault clearing with safety mode disabled */
            *reg0 &= ~((uint32_t)1U << (MindPWM_FCCR0_FSAFE_Pos + subchannel));
        }
    }
    else
    {
        /* Use automatic fault clearing */
        *reg0 |= ((uint32_t)1U << (MindPWM_FCCR0_FAUTO_Pos + subchannel));
    } 

    /* Set the combinational path option */
    if (faultParams->enableCombinationalPath)
    {
        /* Combinational path from the fault input to the PWM output is available */
        *reg1 &= ~((uint32_t)1U << (MindPWM_FCCR1_NOCOMB_Pos + subchannel));
    }
    else
    {
        /* No combinational path available, only fault filter & latch signal can disable PWM output */
        *reg1 |= ((uint32_t)1U << (MindPWM_FCCR1_NOCOMB_Pos + subchannel));
    }

    /* Initially clear both recovery modes */
    tmp = *reg0;
    tmp &= ~(((uint32_t)1U << (MindPWM_FCCR0_FFULL_Pos + subchannel)) |
             ((uint32_t)1U << (MindPWM_FCCR0_FHALF_Pos + subchannel)));
    /* Setup fault recovery */
    switch (faultParams->recoverMode)
    {
        case PWM_NoRecovery:
            break;
        case PWM_RecoverHalfCycle:
            tmp |= ((uint32_t)1U << (MindPWM_FCCR0_FHALF_Pos + subchannel));
            break;
        case PWM_RecoverFullCycle:
            tmp |= ((uint32_t)1U << (MindPWM_FCCR0_FFULL_Pos + subchannel));
            break;
        case PWM_RecoverHalfAndFullCycle:
            tmp |= ((uint32_t)1U << (MindPWM_FCCR0_FHALF_Pos + subchannel));
            tmp |= ((uint32_t)1U << (MindPWM_FCCR0_FFULL_Pos + subchannel));
            break;
        default:
            break;
    }
    *reg0 = tmp;
}

/*!
 * brief  Fill in the PWM fault config struct with the default settings
 *
 * The default values are:
 *   config->faultClearingMode = PWM_Automatic;
 *   config->faultLevel = false;
 *   config->enableCombinationalPath = true;
 *   config->recoverMode = PWM_NoRecovery;
 * param config Pointer to user's PWM fault config structure.
 */
void PWM_FaultDefaultConfig(PWM_Fault_InitTypeDef *config)
{
    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* PWM uses automatic fault clear mode */
    config->faultClearingMode = PWM_Automatic;
    /* PWM fault level is set to logic 0 */
    config->faultLevel = false;
    /* Combinational Path from fault input is enabled */
    config->enableCombinationalPath = true;
    /* PWM output will stay inactive when recovering from a fault */
    config->recoverMode = PWM_NoRecovery;
}

/*!
 * brief Selects the signal to output on a PWM pin when a FORCE_OUT signal is asserted.
 *
 * The user specifies which channel to configure by supplying the submodule number and whether
 * to modify PWM A or PWM B within that submodule.
 *
 * param base       PWM peripheral base address
 * param subModule  PWM submodule to configure
 * param pwmChannel Channel to configure
 * param mode       Signal to output when a FORCE_OUT is triggered
 * param logic      0 or 1 use as  dead zone generator
 */
void PWM_SetupForceSignal(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel, pwm_force_signal_t mode, pwm_force_signal_logic_t logic)
{
    if(pwmChannel == PWM_PwmA)
    {
        MODIFY_REG(mindpwm->DTCR, MindPWM_DTCR_SMnPWMA_DTSEL_Msk, mode << (MindPWM_DTCR_SMnPWMA_DTSEL_Pos + subModule*2));
        if(mode == PWM_SoftwareControl)
        {
            MODIFY_REG(mindpwm->DTCR, MindPWM_DTCR_SMnPWMA_DTSW_Msk, logic << (MindPWM_DTCR_SMnPWMA_DTSW_Pos + subModule));
        }
    }
    else if(pwmChannel == PWM_PwmB)
    {
        MODIFY_REG(mindpwm->DTCR, MindPWM_DTCR_SMnPWMB_DTSEL_Msk, mode << (MindPWM_DTCR_SMnPWMB_DTSEL_Pos + subModule*2));
        if(mode == PWM_SoftwareControl)
        {
            MODIFY_REG(mindpwm->DTCR, MindPWM_DTCR_SMnPWMB_DTSW_Msk, logic << (MindPWM_DTCR_SMnPWMB_DTSW_Pos + subModule));
        }
    }
}

/*!
 * brief Enables the selected PWM interrupts
 *
 * param base      PWM peripheral base address
 * param subModule PWM submodule to configure
 * param mask      The interrupts to enable. This is a logical OR of members of the enumeration ::pwm_interrupt_enable_t
 * state           New state of the specified ADC interrupts.        
 */
void PWM_ITConfig(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t mask, FunctionalState state)
{
    __IO uint32_t *reg = NULL;
    
    if(subModule == PWM_Module_0)
    {
        reg = &(mindpwm->FC0CR0); 
    }
    else if(subModule == PWM_Module_1)
    {
        reg = &(mindpwm->FC1CR0); 
    }
    else if(subModule == PWM_Module_2)
    {
        reg = &(mindpwm->FC2CR0); 
    }
    else if(subModule == PWM_Module_3)
    {
        reg = &(mindpwm->FC3CR0); 
    }
    
    if (state)
    {
        mindpwm->SM[subModule].INTE |= ((uint32_t)mask & 0xFFFFU);
        /* Fault related interrupts */
        *reg |= ((uint32_t)(mask >> 16U) & 0xFFFFU);    
    }
    else 
    {
        mindpwm->SM[subModule].INTE &= ~((uint32_t)mask & 0xFFFFU);
        /* Fault related interrupts */
        *reg &= ~((uint32_t)(mask >> 16U) & 0xFFFFU); 
    }
}

/*!
 * brief Gets the PWM status flags
 *
 * param base      PWM peripheral base address
 * param subModule PWM submodule to configure
 *
 * return The status flags. This is the logical OR of members of the
 *         enumeration ::pwm_status_flags_t
 */
uint32_t PWM_GetStatusFlags(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule)
{
    uint32_t statusFlags = 0;
    __IO uint32_t *reg = NULL;
    
    if(subModule == PWM_Module_0)
    {
        reg = &(mindpwm->FC0CR0); 
    }
    else if(subModule == PWM_Module_1)
    {
        reg = &(mindpwm->FC1CR0); 
    }
    else if(subModule == PWM_Module_2)
    {
        reg = &(mindpwm->FC2CR0); 
    }
    else if(subModule == PWM_Module_3)
    {
        reg = &(mindpwm->FC3CR0); 
    }  

    statusFlags = mindpwm->SM[subModule].SR;
    statusFlags |= (((*reg & MindPWM_FCCR0_FFLAG_Msk) >> MindPWM_FCCR0_FFLAG_Pos) << 16UL);

    return statusFlags;
}

/*!
 * brief Clears the PWM status flags
 *
 * param base      PWM peripheral base address
 * param subModule PWM submodule to configure
 * param mask      The status flags to clear. This is a logical OR of members of the
 *                  enumeration ::pwm_status_flags_t
 */
void PWM_ClearStatusFlags(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t mask)
{
    __IO uint32_t *reg = NULL;
    
    if(subModule == PWM_Module_0)
    {
        reg = &(mindpwm->FC0CR0); 
    }
    else if(subModule == PWM_Module_1)
    {
        reg = &(mindpwm->FC1CR0); 
    }
    else if(subModule == PWM_Module_2)
    {
        reg = &(mindpwm->FC2CR0); 
    }
    else if(subModule == PWM_Module_3)
    {
        reg = &(mindpwm->FC3CR0); 
    }  
    
    mindpwm->SM[subModule].SR = ((uint32_t)mask & 0xFFFFU);
    MODIFY_REG(*reg, MindPWM_FCCR0_FFLAG_Msk, ((mask >> 16UL) << MindPWM_FCCR0_FFLAG_Pos));
}

/*!
 * brief Set PWM output in idle status (high or low).
 *
 * note This API should call after PWM_SetupPwm() APIs, and PWMX submodule is not supported.
 *
 * param base               PWM peripheral base address
 * param pwmChannel         PWM channel to configure
 * param subModule          PWM submodule to configure
 * param idleStatus         True: PWM output is high in idle status; false: PWM output is low in idle status.
 *
 * return (1) if there was error setting up the signal; (0) if set output idle success
 */
int32_t PWM_SetOutputToIdle(MindPWM_TypeDef *mindpwm, pwm_channels_t pwmChannel, pwm_submodule_t subModule, bool idleStatus)
{
    uint32_t valOn = 0, valOff = 0;
    uint32_t ldmod;

    /* Clear LDOK bit if it is set */
    if (0U != (mindpwm->GCR0 & (1UL << (subModule + MindPWM_GCR0_LDOK_Pos))))
    {
        mindpwm->GCR0 |= (1UL << (subModule + MindPWM_GCR0_CLDOK_Pos));
    }

    valOff = mindpwm->SM[subModule].INIT;
    valOn  = mindpwm->SM[subModule].VAL1 + 0x1U;

    if ((valOff + 1U) == valOn)
    {
        return (1);
    }

    /* Should not PWM_X channel */
    if (PWM_PwmA == pwmChannel)
    {
        if (0U != (mindpwm->SM[subModule].OCR & MindPWM_SMOCR_POLA_Msk))
        {
            if (!idleStatus)
            {
                valOn  = mindpwm->SM[subModule].INIT;
                valOff = mindpwm->SM[subModule].VAL1 + 0x1U;
            }
        }
        else
        {
            if (idleStatus)
            {
                valOn  = mindpwm->SM[subModule].INIT;
                valOff = mindpwm->SM[subModule].VAL1 + 0x1U;
            }
        }
        mindpwm->SM[subModule].VAL2 = valOn;
        mindpwm->SM[subModule].VAL3 = valOff;
    }
    else if (PWM_PwmB == pwmChannel)
    {
        if (0U != (mindpwm->SM[subModule].OCR & MindPWM_SMOCR_POLB_Msk))
        {
            if (!idleStatus)
            {
                valOn  = mindpwm->SM[subModule].INIT;
                valOff = mindpwm->SM[subModule].VAL1 + 0x1U;
            }
        }
        else
        {
            if (idleStatus)
            {
                valOn  = mindpwm->SM[subModule].INIT;
                valOff = mindpwm->SM[subModule].VAL1 + 0x1U;
            }
        }
        mindpwm->SM[subModule].VAL4 = valOn;
        mindpwm->SM[subModule].VAL5 = valOff;
    }
    else
    {
        return (1);
    }

    /* Record Load mode */
    ldmod = mindpwm->SM[subModule].CR0;
    /* Set Load mode to make Buffered registers take effect immediately when LDOK bit set */
    mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_LDMOD_Msk;
    /* Set LDOK bit to load buffer registers */
    mindpwm->GCR0 |= (1UL << (MindPWM_GCR0_LDOK_Pos + subModule));
    /* Restore Load mode */
    mindpwm->SM[subModule].CR0 = ldmod;

    /* Get pwm duty cycle */
    s_pwmGetPwmDutyCycle[subModule][pwmChannel] = 0x0U;

    return (0);
}

/*!
 * brief Get the dutycycle value.
 *
 * param base        PWM peripheral base address
 * param subModule   PWM submodule to configure
 * param pwmChannel  PWM channel to configure
 *
 * return Current channel dutycycle value.
 */
float PWM_GetPwmChannelState(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel)
{
    return s_pwmGetPwmDutyCycle[subModule][pwmChannel];
}

/*!
 * brief Set the pwm submodule prescaler.
 *
 * param base               PWM peripheral base address
 * param subModule          PWM submodule to configure
 * param prescaler          Set prescaler value
 */
void PWM_SetClockMode(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_clock_prescale_t prescaler)
{
    uint32_t reg = mindpwm->SM[subModule].CR0;

    /* Clear LDOK bit if it is set */
    if (0U != (mindpwm->GCR0 & (1UL << (subModule + MindPWM_GCR0_LDOK_Pos))))
    {
        mindpwm->GCR0 |= (1UL << (subModule + MindPWM_GCR0_CLDOK_Pos));
    }

    /* Set submodule prescaler. */
    reg &= ~MindPWM_SMCR0_PRSC_Msk;
    reg |= (prescaler << MindPWM_SMCR0_PRSC_Pos);
    mindpwm->SM[subModule].CR0 = reg;
    /* Set Load mode to make Buffered registers take effect immediately when LDOK bit set */
    mindpwm->SM[subModule].CR0 |= MindPWM_SMCR0_LDMOD_Msk;
    /* Set LDOK bit to load buffer registers */
    mindpwm->GCR0 |= (1UL << (MindPWM_GCR0_LDOK_Pos + subModule));
    /* Restore Load mode */
    mindpwm->SM[subModule].CR0 = reg;
}

/*!
 * brief This function enables-disables the forcing of the output of a given MindPWM channel to logic 0.
 *
 * param base               PWM peripheral base address
 * param pwmChannel         PWM channel to configure
 * param subModule          PWM submodule to configure
 * param forcetozero        True: Enable the pwm force output to zero; False: Disable the pwm output resumes normal
 *                          function.
 */
void PWM_SetPwmForceOutputToZero(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel, bool forcetozero)
{
    uint32_t reg = mindpwm->GCR1;

    if (PWM_PwmA == pwmChannel)
    {
        MODIFY_REG(mindpwm->GCR1, 
                   (MindPWM_GCR1_MASKA_Msk | MindPWM_GCR1_MASK_UP_Msk), 
                   ((forcetozero << (MindPWM_GCR1_MASKA_Pos + subModule)) | \
                    (0x01UL << (MindPWM_GCR1_MASK_UP_Pos + subModule))));
    }
    else if (PWM_PwmB == pwmChannel)
    {
        MODIFY_REG(mindpwm->GCR1, 
                   (MindPWM_GCR1_MASKB_Msk | MindPWM_GCR1_MASK_UP_Msk), 
                   ((forcetozero << (MindPWM_GCR1_MASKB_Pos + subModule)) | \
                    (0x01UL << (MindPWM_GCR1_MASK_UP_Pos + subModule))));
    }
    else
    {
        MODIFY_REG(mindpwm->GCR1, 
                   (MindPWM_GCR1_MASKX_Msk | MindPWM_GCR1_MASK_UP_Msk), 
                   ((forcetozero << (MindPWM_GCR1_MASKX_Pos + subModule)) | \
                    (0x01UL << (MindPWM_GCR1_MASK_UP_Pos + subModule))));
    }
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


