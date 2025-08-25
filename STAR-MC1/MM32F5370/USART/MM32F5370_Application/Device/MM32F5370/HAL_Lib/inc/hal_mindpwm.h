/***********************************************************************************************************************
    @file     hal_mindpwm.h
    @author   VV TEAM
    @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE MindPWM FIRMWARE LIBRARY.
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
#ifndef __HAL_MINDPWM_H
#define __HAL_MINDPWM_H

/* Files includes ----------------------------------------------------------------------------------------------------*/
#include "mm32_device.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @defgroup MINDPWM
  * @{
  */

/** @defgroup MINDPWM_Exported_Types
  * @{
  */


/*! Number of submodule */
#define PWM_SUBMODULE_NUM        4
/*! Because setting the pwm duty cycle doesn't support PWMX, getting the pwm duty cycle also doesn't support PWMX. */
#define PWM_SUBMODULE_CHANNEL            2

/*! @brief List of PWM submodules */
typedef enum
{
    PWM_Module_0 = 0U, /*!< Submodule 0 */
    PWM_Module_1,      /*!< Submodule 1 */
    PWM_Module_2,      /*!< Submodule 2 */
    PWM_Module_3       /*!< Submodule 3 */
} pwm_submodule_t;

/*! @brief List of PWM channels in each module */
typedef enum
{
    PWM_PwmX = 0U,
    PWM_PwmA,
    PWM_PwmB
} pwm_channels_t;

/*! @brief List of PWM value registers */
typedef enum
{
    PWM_ValueRegister_0 = 0U, /*!< PWM Value0 register */
    PWM_ValueRegister_1,      /*!< PWM Value1 register */
    PWM_ValueRegister_2,      /*!< PWM Value2 register */
    PWM_ValueRegister_3,      /*!< PWM Value3 register */
    PWM_ValueRegister_4,      /*!< PWM Value4 register */
    PWM_ValueRegister_5       /*!< PWM Value5 register */
} pwm_value_register_t;

/*! @brief PWM clock source selection.*/
typedef enum
{
    PWM_BusClock = 0U,  /*!< The IPBus clock is used as the clock */
    PWM_ExternalClock,  /*!< EXT_CLK is used as the clock */
    PWM_Submodule0Clock /*!< Clock of the submodule 0 (AUX_CLK) is used as the source clock */
} pwm_clock_source_t;

/*! @brief PWM prescaler factor selection for clock source*/
typedef enum
{
    PWM_Prescale_Divide_1 = 0U, /*!< PWM clock frequency = fclk/1 */
    PWM_Prescale_Divide_2,      /*!< PWM clock frequency = fclk/2 */
    PWM_Prescale_Divide_4,      /*!< PWM clock frequency = fclk/4 */
    PWM_Prescale_Divide_8,      /*!< PWM clock frequency = fclk/8 */
    PWM_Prescale_Divide_16,     /*!< PWM clock frequency = fclk/16 */
    PWM_Prescale_Divide_32,     /*!< PWM clock frequency = fclk/32 */
    PWM_Prescale_Divide_64,     /*!< PWM clock frequency = fclk/64 */
    PWM_Prescale_Divide_128     /*!< PWM clock frequency = fclk/128 */
}pwm_clock_prescale_t;

/*! @brief Options that can trigger a PWM FORCE_OUT */
typedef enum
{
    PWM_Force_Local = 0U,   /*!< The local force signal, CTRL2[FORCE], from the submodule is used to force updates */
    PWM_Force_Master,       /*!< The master force signal from submodule 0 is used to force updates */
    PWM_Force_LocalReload,  /*!< The local reload signal from this submodule is used to force updates without regard to
                               the state of LDOK */
    PWM_Force_MasterReload, /*!< The master reload signal from submodule 0 is used to force updates if LDOK is set */
    PWM_Force_LocalSync,    /*!< The local sync signal from this submodule is used to force updates */
    PWM_Force_MasterSync,   /*!< The master sync signal from submodule0 is used to force updates */
    PWM_Force_External,     /*!< The external force signal, EXT_FORCE, from outside the PWM module causes updates */
    PWM_Force_ExternalSync  /*!< The external sync signal, EXT_SYNC, from outside the PWM module causes updates */
}pwm_force_output_trigger_t;


/*! @brief PWM counter initialization options */
typedef enum
{
    PWM_Initialize_LocalSync = 1U,      /*!< Local sync causes initialization */
    PWM_Initialize_MasterReload = 2U,   /*!< Master reload from submodule 0 causes initialization */
    PWM_Initialize_MasterSync = 4U,     /*!< Master sync from submodule 0 causes initialization */
    PWM_Initialize_ExtSync = 8U,         /*!< EXT_SYNC causes initialization */
} pwm_init_source_t;

/*! @brief PWM load frequency selection */
typedef enum
{
    PWM_LoadEveryOportunity = 0U, /*!< Every PWM opportunity */
    PWM_LoadEvery2Oportunity,     /*!< Every 2 PWM opportunities */
    PWM_LoadEvery3Oportunity,     /*!< Every 3 PWM opportunities */
    PWM_LoadEvery4Oportunity,     /*!< Every 4 PWM opportunities */
    PWM_LoadEvery5Oportunity,     /*!< Every 5 PWM opportunities */
    PWM_LoadEvery6Oportunity,     /*!< Every 6 PWM opportunities */
    PWM_LoadEvery7Oportunity,     /*!< Every 7 PWM opportunities */
    PWM_LoadEvery8Oportunity,     /*!< Every 8 PWM opportunities */
    PWM_LoadEvery9Oportunity,     /*!< Every 9 PWM opportunities */
    PWM_LoadEvery10Oportunity,    /*!< Every 10 PWM opportunities */
    PWM_LoadEvery11Oportunity,    /*!< Every 11 PWM opportunities */
    PWM_LoadEvery12Oportunity,    /*!< Every 12 PWM opportunities */
    PWM_LoadEvery13Oportunity,    /*!< Every 13 PWM opportunities */
    PWM_LoadEvery14Oportunity,    /*!< Every 14 PWM opportunities */
    PWM_LoadEvery15Oportunity,    /*!< Every 15 PWM opportunities */
    PWM_LoadEvery16Oportunity     /*!< Every 16 PWM opportunities */
} pwm_load_frequency_t;

/*! @brief List of PWM fault selections */
typedef enum
{
    PWM_Fault_0 = 0U, 
    PWM_Fault_1,      
    PWM_Fault_2,      
    PWM_Fault_3,  
    PWM_Fault_4,
    PWM_Fault_5,
    PWM_Fault_6,
    PWM_Fault_7,
    PWM_Fault_8,
    PWM_Fault_9,
    PWM_Fault_10,
    PWM_Fault_11,
    PWM_Fault_12,
    PWM_Fault_13,
    PWM_Fault_14,
    PWM_Fault_15    
} pwm_fault_input_t;

/*! @brief List of PWM fault disable mapping selections */
typedef enum
{
    PWM_FaultDisable_0 = (1U << 0), /*!< Fault 0 disable mapping */
    PWM_FaultDisable_1 = (1U << 1), /*!< Fault 1 disable mapping */
    PWM_FaultDisable_2 = (1U << 2), /*!< Fault 2 disable mapping */
    PWM_FaultDisable_3 = (1U << 3)  /*!< Fault 3 disable mapping */
} pwm_fault_disable_t;

/*! @brief List of PWM fault channels */
typedef enum
{
    PWM_faultchannel_0 = 0U,
    PWM_faultchannel_1,
    PWM_faultchannel_2,
    PWM_faultchannel_4
} pwm_fault_channels_t;

/*! @brief PWM output options when a FORCE_OUT signal is asserted */
typedef enum
{
    PWM_UsePwm = 0U,     /*!< Generated PWM signal is used by the deadtime logic.*/
    PWM_InvertedPwm,     /*!< Inverted PWM signal is used by the deadtime logic.*/
    PWM_SoftwareControl, /*!< Software controlled value is used by the deadtime logic. */
    PWM_UseExternal      /*!< PWM_EXTA signal is used by the deadtime logic. */
} pwm_force_signal_t;

typedef enum
{
    PWM_Logic_0 = 0U,     
    PWM_Logic_1    
} pwm_force_signal_logic_t;

/*! @brief Options available for the PWM A & B pair operation */
typedef enum
{
    PWM_Independent = 0U,  /*!< PWM A & PWM B operate as 2 independent channels */
    PWM_ComplementaryPwmA, /*!< PWM A & PWM B are complementary channels, PWM A generates the signal */
    PWM_ComplementaryPwmB  /*!< PWM A & PWM B are complementary channels, PWM B generates the signal */
} pwm_chnl_pair_operation_t;

/*! @brief Options available on how to load the buffered-registers with new values */
typedef enum
{
    PWM_ReloadImmediate = 0U,     /*!< Buffered-registers get loaded with new values as soon as LDOK bit is set */
    PWM_ReloadPwmHalfCycle,       /*!< Registers loaded on a PWM half cycle */
    PWM_ReloadPwmFullCycle,       /*!< Registers loaded on a PWM full cycle */
    PWM_ReloadPwmHalfAndFullCycle /*!< Registers loaded on a PWM half & full cycle */
}pwm_register_reload_t;

/*! @brief Options available on how to re-enable the PWM output when recovering from a fault */
typedef enum
{
    PWM_NoRecovery = 0U,        /*!< PWM output will stay inactive */
    PWM_RecoverHalfCycle,       /*!< PWM output re-enabled at the first half cycle */
    PWM_RecoverFullCycle,       /*!< PWM output re-enabled at the first full cycle */
    PWM_RecoverHalfAndFullCycle /*!< PWM output re-enabled at the first half or full cycle */
} pwm_fault_recovery_mode_t;

/*! @brief List of PWM interrupt options */
typedef enum
{
    PWM_CompareVal0InterruptEnable = (1U << 0),  /*!< PWM VAL0 compare interrupt */
    PWM_CompareVal1InterruptEnable = (1U << 1),  /*!< PWM VAL1 compare interrupt */
    PWM_CompareVal2InterruptEnable = (1U << 2),  /*!< PWM VAL2 compare interrupt */
    PWM_CompareVal3InterruptEnable = (1U << 3),  /*!< PWM VAL3 compare interrupt */
    PWM_CompareVal4InterruptEnable = (1U << 4),  /*!< PWM VAL4 compare interrupt */
    PWM_CompareVal5InterruptEnable = (1U << 5),  /*!< PWM VAL5 compare interrupt */
    PWM_ReloadInterruptEnable      = (1U << 12), /*!< PWM reload interrupt */
    PWM_ReloadErrorInterruptEnable = (1U << 13), /*!< PWM reload error interrupt */
} pwm_interrupt_enable_t;

/*! @brief PWM operation mode */
typedef enum
{
    PWM_UpwardCenterAligned = 0U, 
    PWM_UpdownCenterAligned,           
    PWM_EdgeAligned                   
} pwm_mode_t;

/*! @brief PWM output pulse mode, high-true or low-true */
typedef enum
{
    PWM_HighTrue = 0U, /*!< High level represents "on" or "active" state */
    PWM_LowTrue        /*!< Low level represents "on" or "active" state */
} pwm_level_select_t;

/*! @brief PWM output fault status */
typedef enum
{
    PWM_PwmFaultState0 = 0U, /*!< Output is forced to logic 0 state */
    PWM_PwmFaultState1,      /*!< Output is forced to logic 1 state */
    PWM_PwmFaultState2,      /*!< Output is tristated. */
    PWM_PwmFaultState3       /*!< Output is tristated. */
} pwm_fault_state_t;

/*! @brief PWM reload source select */
typedef enum
{
    PWM_LocalReload = 0U, /*!< The local reload signal is used to reload registers */
    PWM_MasterReload      /*!< The master reload signal (from submodule 0) is used to reload */
} pwm_reload_source_select_t;

/*! @brief PWM fault clearing options */
typedef enum
{
    PWM_Automatic = 0U, /*!< Automatic fault clearing  */
    PWM_ManualNormal,   /*!< Manual fault clearing with no fault safety mode */
    PWM_ManualSafety    /*!< Manual fault clearing with fault safety mode */
} pwm_fault_clear_t;

/*! @brief Options for submodule master control operation */
typedef enum
{
    PWM_Control_Module_0 = (1U << 0), /*!< Control submodule 0's start/stop,buffer reload operation */
    PWM_Control_Module_1 = (1U << 1), /*!< Control submodule 1's start/stop,buffer reload operation */
    PWM_Control_Module_2 = (1U << 2), /*!< Control submodule 2's start/stop,buffer reload operation */
    PWM_Control_Module_3 = (1U << 3)  /*!< Control submodule 3's start/stop,buffer reload operation */
} pwm_module_control_t;

/*! @brief Structure for the user to define the PWM signal characteristics */
typedef struct
{
    pwm_channels_t pwmChannel;    /*!< PWM channel being configured; PWM A or PWM B */
    float dutyCyclePercent;       /*!< PWM pulse width, value should be between 0 to 100 */
    pwm_level_select_t level;     /*!< PWM output active level select */
    uint16_t deadtimeValue;       /*!< The deadtime value; only used if channel pair is operating in complementary mode */
    pwm_fault_state_t faultState; /*!< PWM output fault status */
    bool pwmchannelenable;        /*!< Enable PWM output */
} pwm_signal_param_t;

/*!
 * @brief PWM config structure
 *
 * This structure holds the configuration settings for the PWM peripheral. To initialize this
 * structure to reasonable defaults, call the PWM_GetDefaultConfig() function and pass a
 * pointer to your config structure instance.
 *
 * The config struct can be made const so it resides in flash
 */
typedef struct
{
    bool enableDebugMode; /*!< true: PWM continues to run in debug mode;
                               false: PWM is paused in debug mode */
    pwm_init_source_t initializationControl; /*!< Option to initialize the counter */
    pwm_clock_source_t clockSource;          /*!< Clock source for the counter */
    pwm_clock_prescale_t prescale;           /*!< Pre-scaler to divide down the clock */
    pwm_chnl_pair_operation_t pairOperation; /*!< Channel pair in indepedent or complementary mode */
    pwm_register_reload_t reloadLogic;       /*!< PWM Reload logic setup */
    pwm_reload_source_select_t reloadSelect; /*!< Reload source select */
    pwm_load_frequency_t reloadFrequency;    /*!< Specifies when to reload, used when user's choice
                                                  is not immediate reload */
    pwm_force_output_trigger_t forceTrigger; /*!< Specify which signal will trigger a FORCE_OUT */
} PWM_InitTypeDef;

/*! @brief Structure for the user to configure the fault input filter. */
typedef struct
{
    uint8_t faultFilterCount;  /*!< Fault filter count */
    uint8_t faultFilterPeriod; /*!< Fault filter period;value of 0 will bypass the filter */
    bool faultGlitchStretch;   /*!< Fault Glitch Stretch Enable: A logic 1 means that input
                                    fault signals will be stretched to at least 2 IPBus clock cycles */
} pwm_fault_input_filter_param_t;

/*! @brief Structure is used to hold the parameters to configure a PWM fault */
typedef struct
{
    pwm_fault_clear_t faultClearingMode;   /*!< Fault clearing mode to use */
    bool faultLevel;                       /*!< true: Logic 1 indicates fault;
                                                false: Logic 0 indicates fault */
    bool enableCombinationalPath;          /*!< true: Combinational Path from fault input is enabled;
                                                false: No combination path is available */
    pwm_fault_recovery_mode_t recoverMode; /*!< Specify when to re-enable the PWM output */
} PWM_Fault_InitTypeDef;




int32_t PWM_Init(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, const PWM_InitTypeDef *config);
void PWM_Deinit(MindPWM_TypeDef *mindpwm);
void PWM_GetDefaultConfig(PWM_InitTypeDef *config);
int32_t PWM_SetupPwm(MindPWM_TypeDef *mindpwm,
                      pwm_submodule_t subModule,
                      const pwm_signal_param_t *chnlParams,
                      uint8_t numOfChnls,
                      pwm_mode_t mode,
                      float pwmFreq_Hz,
                      uint32_t srcClock_Hz);
int32_t PWM_SetupPwmPhaseShift(MindPWM_TypeDef *mindpwm,
                                pwm_submodule_t subModule,
                                pwm_channels_t pwmChannel,
                                uint32_t pwmFreq_Hz,
                                uint32_t srcClock_Hz,
                                uint8_t shiftvalue,
                                bool doSync);
void PWM_SetupFaultInputFilter(MindPWM_TypeDef *mindpwm, pwm_fault_input_t faultNum, const pwm_fault_input_filter_param_t *faultInputFilterParams);
void PWM_SetupFaults(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel, pwm_fault_input_t faultNum, const PWM_Fault_InitTypeDef *faultParams);
void PWM_FaultDefaultConfig(PWM_Fault_InitTypeDef *config);
void PWM_SetupForceSignal(MindPWM_TypeDef *mindpwm,
                          pwm_submodule_t subModule,
                          pwm_channels_t pwmChannel,
                          pwm_force_signal_t mode,
                          pwm_force_signal_logic_t logic);
void PWM_ITConfig(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t mask, FunctionalState state);

/*!
 * @brief Enables or disables the PWM DMA write request.
 *
 * @param base      PWM peripheral base address
 * @param subModule PWM submodule to configure
 * @param state     ENABLE: Enable DMA write request; DISABLE: Disable DMA write request
 */
__STATIC_INLINE void PWM_DMAWriteCmd(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, FunctionalState state)
{
    uint32_t reg = mindpwm->SM[subModule].DMAE;
    if (state)
    {
        reg |= MindPWM_SMDMAE_VALDE_Msk;
    }
    else
    {
        reg &= ~MindPWM_SMDMAE_VALDE_Msk;
    }
    mindpwm->SM[subModule].DMAE = reg;
}

uint32_t PWM_GetStatusFlags(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule);
void PWM_ClearStatusFlags(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t mask);

/*!
 * @brief Starts the PWM counter for a single or multiple submodules.
 *
 * Sets the Run bit which enables the clocks to the PWM submodule. This function can start multiple
 * submodules at the same time.
 *
 * @param base              PWM peripheral base address
 * @param subModulesToStart PWM submodules to start. This is a logical OR of members of the
 *                          enumeration ::pwm_module_control_t
 */
__STATIC_INLINE void PWM_StartTimer(MindPWM_TypeDef *mindpwm, uint8_t subModulesToStart)
{
    mindpwm->GCR0 |= (subModulesToStart << MindPWM_GCR0_RUN_Pos);
}

/*!
 * @brief Stops the PWM counter for a single or multiple submodules.
 *
 * Clears the Run bit which resets the submodule's counter. This function can stop multiple
 * submodules at the same time.
 *
 * @param base             PWM peripheral base address
 * @param subModulesToStop PWM submodules to stop. This is a logical OR of members of the
 *                         enumeration ::pwm_module_control_t
 */
__STATIC_INLINE void PWM_StopTimer(MindPWM_TypeDef *mindpwm, uint8_t subModulesToStop)
{
    mindpwm->GCR0 &= ~(subModulesToStop << MindPWM_GCR0_RUN_Pos);
}

/*!
 * @brief Set the PWM VALx registers.
 *
 * This function allows the user to write value into VAL registers directly. And it will destroying the PWM clock period
 * set by the PWM_SetupPwm()/PWM_SetupPwmPhaseShift() functions.
 * Due to VALx registers are bufferd, the new value will not active uless call PWM_SetPwmLdok() and the reload point is
 * reached.
 *
 * @param base          PWM peripheral base address
 * @param subModule     PWM submodule to configure
 * @param valueRegister VALx register that will be writen new value
 * @param value         Value that will been write into VALx register
 */
__STATIC_INLINE void PWM_SetVALxValue(MindPWM_TypeDef *mindpwm,
                                    pwm_submodule_t subModule,
                                    pwm_value_register_t valueRegister,
                                    uint16_t value)
{
    switch (valueRegister)
    {
        case PWM_ValueRegister_0:
            mindpwm->SM[subModule].VAL0 = value;
            break;
        case PWM_ValueRegister_1:
            mindpwm->SM[subModule].VAL1 = value;
            break;
        case PWM_ValueRegister_2:
            mindpwm->SM[subModule].VAL2 = value;
            break;
        case PWM_ValueRegister_3:
            mindpwm->SM[subModule].VAL3 = value;
            break;
        case PWM_ValueRegister_4:
            mindpwm->SM[subModule].VAL4 = value;
            break;
        case PWM_ValueRegister_5:
            mindpwm->SM[subModule].VAL5 = value;
            break;
        default:
            break;
    }
}

/*!
 * @brief Get the PWM VALx registers.
 * @param base          PWM peripheral base address
 * @param subModule     PWM submodule to configure
 * @param valueRegister VALx register that will be read value
 * @return The VALx register value
 */
__STATIC_INLINE uint16_t PWM_GetVALxValue(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_value_register_t valueRegister)
{
    uint16_t temp = 0U;

    switch (valueRegister)
    {
        case PWM_ValueRegister_0:
            temp = mindpwm->SM[subModule].VAL0;
            break;
        case PWM_ValueRegister_1:
            temp = mindpwm->SM[subModule].VAL1;
            break;
        case PWM_ValueRegister_2:
            temp = mindpwm->SM[subModule].VAL2;
            break;
        case PWM_ValueRegister_3:
            temp = mindpwm->SM[subModule].VAL3;
            break;
        case PWM_ValueRegister_4:
            temp = mindpwm->SM[subModule].VAL4;
            break;
        case PWM_ValueRegister_5:
            temp = mindpwm->SM[subModule].VAL5;
            break;
        default:
            break;
    }

    return temp;
}


/*!
 * @brief Enables the PWM output trigger.
 *
 * This function allows the user to enable one or more (VAL0-5) PWM trigger.
 *
 * @param base              PWM peripheral base address
 * @param subModule         PWM submodule to configure
 * @param valueRegisterMask Value register mask that will activate one or more (VAL0-5) trigger
 *                          enumeration ::_pwm_value_register_mask
 */
__STATIC_INLINE void PWM_ActivateOutputTrigger(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t valueRegisterMask)
{
    mindpwm->SM[subModule].TRGCR |= (MindPWM_SMTRGCR_OUT_TRIG_EN_Msk & (valueRegisterMask));
}

/*!
 * @brief Disables the PWM output trigger.
 *
 * This function allows the user to disables one or more (VAL0-5) PWM trigger.
 *
 * @param base              PWM peripheral base address
 * @param subModule         PWM submodule to configure
 * @param valueRegisterMask Value register mask that will Deactivate one or more (VAL0-5) trigger
 *                          enumeration ::_pwm_value_register_mask
 */
__STATIC_INLINE void PWM_DeactivateOutputTrigger(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, uint32_t valueRegisterMask)
{
    mindpwm->SM[subModule].TRGCR &= ~(MindPWM_SMTRGCR_OUT_TRIG_EN_Msk & (valueRegisterMask));
}


/*!
 * @brief Sets or clears the PWM LDOK bit on a single or multiple submodules
 *
 * Set LDOK bit to load buffered values . The
 * values are loaded immediately if kPWM_ReloadImmediate option was choosen during config. Else the
 * values are loaded at the next PWM reload point.
 * This function can issue the load command to multiple submodules at the same time.
 *
 * @param base               PWM peripheral base address
 * @param subModulesToUpdate PWM submodules to update with buffered values. This is a logical OR of
 *                           members of the enumeration ::pwm_module_control_t
 * @param value              true: Set LDOK bit for the submodule list; false: Clear LDOK bit
 */
__STATIC_INLINE void PWM_SetPwmLdok(MindPWM_TypeDef *mindpwm, uint8_t subModulesToUpdate, bool value)
{
    if (value)
    {
        mindpwm->GCR0 |= (subModulesToUpdate << MindPWM_GCR0_LDOK_Pos);
    }
    else
    {
        mindpwm->GCR0 |= (subModulesToUpdate << MindPWM_GCR0_CLDOK_Pos);
    }
}
/*!
 * @brief Set PWM output fault status
 *
 * These bits determine the fault state for the PWM_A output in fault conditions
 * and STOP mode. It may also define the output state in WAIT and DEBUG modes
 * depending on the settings of CTRL2[WAITEN] and CTRL2[DBGEN].
 * This function can update PWM output fault status.
 *
 * @param base       PWM peripheral base address
 * @param subModule  PWM submodule to configure
 * @param pwmChannel Channel to configure
 * @param faultState PWM output fault status
 */
__STATIC_INLINE void PWM_SetPwmFaultState(MindPWM_TypeDef *mindpwm,
                                        pwm_submodule_t subModule,
                                        pwm_channels_t pwmChannel,
                                        pwm_fault_state_t faultState)
{
    uint32_t reg = mindpwm->SM[subModule].OCR;
    switch (pwmChannel)
    {
        case PWM_PwmA:
            reg &= ~((uint32_t)MindPWM_SMOCR_PWMA_FS_Msk);
            reg |= (((uint32_t)faultState << (uint32_t)MindPWM_SMOCR_PWMA_FS_Pos) & (uint32_t)MindPWM_SMOCR_PWMA_FS_Msk);
            break;
        case PWM_PwmB:
            reg &= ~((uint32_t)MindPWM_SMOCR_PWMB_FS_Msk);
            reg |= (((uint32_t)faultState << (uint32_t)MindPWM_SMOCR_PWMB_FS_Pos) & (uint32_t)MindPWM_SMOCR_PWMB_FS_Msk);
            break;
        case PWM_PwmX:
            reg &= ~((uint32_t)MindPWM_SMOCR_PWMX_FS_Msk);
            reg |= (((uint32_t)faultState << (uint32_t)MindPWM_SMOCR_PWMX_FS_Pos) & (uint32_t)MindPWM_SMOCR_PWMX_FS_Msk);
            break;
        default:
            break;
    }
    mindpwm->SM[subModule].OCR = reg;
}

/*!
 * @brief Set PWM output enable
 *
 * This feature allows the user to enable the PWM Output.
 *
 * @param base               PWM peripheral base address
 * @param pwmChannel         PWM channel to configure
 * @param subModule          PWM submodule to configure
 */
__STATIC_INLINE void PWM_OutputEnable(MindPWM_TypeDef *mindpwm, pwm_channels_t pwmChannel, pwm_submodule_t subModule)
{
    /* Set PWM output */
    switch (pwmChannel)
    {
        case PWM_PwmA:
            mindpwm->GCR0 |= ((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMA_EN_Pos + (uint32_t)subModule));
            break;
        case PWM_PwmB:
            mindpwm->GCR0 |= ((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMB_EN_Pos + (uint32_t)subModule));
            break;
        case PWM_PwmX:
            mindpwm->GCR0 |= ((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMX_EN_Pos + (uint32_t)subModule));
            break;
        default:
            break;
    }
}

/*!
 * @brief Set PWM output disable
 *
 *This feature allows the user to disable the PWM output.
 *
 * @param base               PWM peripheral base address
 * @param pwmChannel         PWM channel to configure
 * @param subModule          PWM submodule to configure
 */
__STATIC_INLINE void PWM_OutputDisable(MindPWM_TypeDef *mindpwm, pwm_channels_t pwmChannel, pwm_submodule_t subModule)
{
    switch (pwmChannel)
    {
        case PWM_PwmA:
            mindpwm->GCR0 &= ~((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMA_EN_Pos + (uint32_t)subModule));
            break;
        case PWM_PwmB:
            mindpwm->GCR0 &= ~((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMB_EN_Pos + (uint32_t)subModule));
            break;
        case PWM_PwmX:
            mindpwm->GCR0 &= ~((uint32_t)1U << ((uint32_t)MindPWM_GCR0_PWMX_EN_Pos + (uint32_t)subModule));
            break;
        default:
            break;
    }
}

float PWM_GetPwmChannelState(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_channels_t pwmChannel);
int32_t PWM_SetOutputToIdle(MindPWM_TypeDef *mindpwm, pwm_channels_t pwmChannel, pwm_submodule_t subModule, bool idleStatus);
void PWM_SetClockMode(MindPWM_TypeDef *mindpwm, pwm_submodule_t subModule, pwm_clock_prescale_t prescaler);
void PWM_SetPwmForceOutputToZero(MindPWM_TypeDef *mindpwm,
                                 pwm_submodule_t subModule,
                                 pwm_channels_t pwmChannel,
                                 bool forcetozero);

#endif 

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
