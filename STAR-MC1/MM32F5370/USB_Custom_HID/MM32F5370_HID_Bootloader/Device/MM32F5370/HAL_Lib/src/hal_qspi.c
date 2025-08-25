/***********************************************************************************************************************
    @file     hal_qspi.c
    @author   VV TEAM
    @brief    THIS FILE PROVIDES ALL THE QSPI FIRMWARE FUNCTIONS.
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
  *******************************************************************************************************************  */

/* Files includes ------------------------------------------------------------*/
#include "hal_qspi.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup QSPI
  * @{
  */

/** @defgroup QSPI_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup QSPI_Private_Functions
  * @{
  */

/**
  * @brief  Deinitializes the qspi peripheral registers to their
  *         default reset values.
  * @param  qspi: Select the QSPI peripheral.
  * @retval None.
  */
void QSPI_DeInit(QSPI_TypeDef *qspi)
{
    if (qspi == QSPI)
    {
        RCC_AHBPeriphResetCmd(RCC_AHBPeriph_QSPI, ENABLE);
        RCC_AHBPeriphResetCmd(RCC_AHBPeriph_QSPI, DISABLE);
    }
}

/**
  * @brief  Fills each init_struct member with its default value.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         which will be initialized.
  * @retval None.
  */
void QSPI_StructInit(QSPI_InitTypeDef *init_struct)
{
    init_struct->ClockPrescaler         = QSPI_Prescaler_8;
    init_struct->NssHighLevelHold       = QSPI_CS_HIGH_TIME_AHB_2;
    init_struct->ModeSelection          = QSPI_MODE_3;
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @retval None.
  */
void QSPI_Init(QSPI_TypeDef *qspi, QSPI_InitTypeDef *init_struct)
{
    MODIFY_REG(qspi->CR, QSPI_CR_SCKDIV_Msk, init_struct->ClockPrescaler);
    MODIFY_REG(qspi->CR, QSPI_CR_CSRHT_Msk, init_struct->NssHighLevelHold);
    MODIFY_REG(qspi->CR, QSPI_CR_SCKMODE_Msk, init_struct->ModeSelection);
}

/**
* @brief  Configure QSPI command structure.
* @param  init_struct: QSPI Command structure.
* @retval : None
*/
void QSPI_CommonConfigStructInit(QSPI_CommonConfig_TypeDef *init_struct)
{
    init_struct->InstructionCode        = 0;
    init_struct->InstructPhaseMode      = QSPI_InstructPhaseMode_Single;
    init_struct->AddressPhaseMode       = QSPI_AddressPhaseMode_Single;
    init_struct->AddressPhaseSize       = QSPI_AddressPhaseSize_8Bit;
    init_struct->AltBytesPhaseMode      = QSPI_AltBytePhaseMode_None;
    init_struct->AltBytesPhaseSize      = QSPI_AltBytePhaseSize_8Bit;
    init_struct->DataPhaseMode          = QSPI_DataPhaseMode_Single;
    init_struct->DataPhaseSize          = QSPI_DataPhaseSize_32Bit;
    init_struct->RxSampleDelayCycles    = QSPI_DelayCycles_0;
    init_struct->DummyPhaseCycles       = 0;
    init_struct->AltBytesValue          = 0;
}
    
/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_InitTypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @retval None.
  */
void QSPI_DirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct)
{
    if (QSPI_GetOperationMode(qspi) != QSPI_OperationMode_Inactive)
    {
        QSPI_InactiveInit(qspi);
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }

    MODIFY_REG(qspi->DMCR, 
               (QSPI_DMCR_INST_Msk | QSPI_DMCR_IMODE_Msk | QSPI_DMCR_ADMODE_Msk |          \
                QSPI_DMCR_ADSIZE_Msk | QSPI_DMCR_ABMODE_Msk | QSPI_DMCR_ABSIZE_Msk |       \
                QSPI_DMCR_DMODE_Msk | QSPI_DMCR_DSIZE_Msk | QSPI_DMCR_RXDLY_Msk |          \
                QSPI_DMCR_NUMDC_Msk),                                                      \
               (init_struct->InstructionCode << QSPI_DMCR_INST_Pos | \
                init_struct->InstructPhaseMode |                     \
                init_struct->AddressPhaseMode |                      \
                init_struct->AddressPhaseSize |                      \
                init_struct->AltBytesPhaseMode |                     \
                init_struct->AltBytesPhaseSize |                     \
                init_struct->DataPhaseMode |                         \
                init_struct->DataPhaseSize |                         \
                init_struct->RxSampleDelayCycles |                   \
                init_struct->DummyPhaseCycles << QSPI_DMCR_NUMDC_Pos));
    
    qspi->DABR = init_struct->AltBytesValue;
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Direct);
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @param  init_struct: pointer to a QSPI_CommonConfig_TypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @param  extendconfig: pointer to a QSPI_IndirectExtendConfig_TypeDef structure
  *         that contains the configuration information for the
  *         specified QSPI peripheral.
  * @param  accessmode: QSPI Indirect Mode Access
  * @arg    QSPI_IndirectModeAccess_Read
  * @arg    QSPI_IndirectModeAccess_Write
  * @retval None.
  */
void QSPI_IndirectInit(QSPI_TypeDef *qspi, QSPI_CommonConfig_TypeDef *init_struct, QSPI_IndirectExtendConfig_TypeDef *extendconfig, uint32_t accessmode)
{
    if (QSPI_GetOperationMode(qspi) != QSPI_OperationMode_Inactive)
    {
        QSPI_InactiveInit(qspi);
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
        __NOP();
    }

    MODIFY_REG(qspi->IMCR, 
               (QSPI_IMCR_INST_Msk | QSPI_IMCR_IMODE_Msk | QSPI_IMCR_ADMODE_Msk |          \
                QSPI_IMCR_ADSIZE_Msk | QSPI_IMCR_ABMODE_Msk | QSPI_IMCR_ABSIZE_Msk |       \
                QSPI_IMCR_DMODE_Msk | QSPI_IMCR_DSIZE_Msk | QSPI_IMCR_RXDLY_Msk |          \
                QSPI_IMCR_NUMDC_Msk | QSPI_IMCR_IDMODE_Msk), 
               (init_struct->InstructionCode << QSPI_IMCR_INST_Pos |   \
                init_struct->InstructPhaseMode |                       \
                init_struct->AddressPhaseMode |                        \
                init_struct->AddressPhaseSize |                        \
                init_struct->AltBytesPhaseMode |                       \
                init_struct->AltBytesPhaseSize |                       \
                init_struct->DataPhaseMode |                           \
                init_struct->DataPhaseSize |                           \
                init_struct->RxSampleDelayCycles |                    \
                init_struct->DummyPhaseCycles << QSPI_IMCR_NUMDC_Pos | \
                accessmode));

    qspi->IABR = init_struct->AltBytesValue;
    qspi->IADR = extendconfig->address;
    qspi->IDLR = extendconfig->length;
    qspi->IWCR = extendconfig->count;
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Indirect);
}

/**
  * @brief  Initializes the qspi peripheral according to the specified
  *         parameters in the init_struct .
  * @param  qspi: Select the QSPI peripheral.
  * @retval None.
  */
void QSPI_InactiveInit(QSPI_TypeDef *qspi)
{
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Inactive);
}

/**
  * @brief  Enter or Exit XIP mode direct mode
  * @param  state: state of the enter or exit to the XIP mode for direct mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_DirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                           \
    (qspi->CR |= QSPI_CR_XIPMODE_Msk) : \
    (qspi->CR &= ~QSPI_CR_XIPMODE_Msk);
}

/**
  * @brief  Enter or Exit XIP mode indirect mode
  * @param  state: state of the enter or exit to the XIP mode for indirect mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_IndirectEnterXIPCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                             \
    (qspi->IMCR |= QSPI_IMCR_XIPIM_Msk) : \
    (qspi->IMCR &= ~QSPI_IMCR_XIPIM_Msk);
}

/**
  * @brief  Enter or Exit XIP mode indirect mode
  * @param  state: state of the enter or exit to the XIP mode for indirect mode
  *         registers. This parameter can be: ENABLE or DISABLE.
  * @retval None.
  */
void QSPI_XIPFromIndirectCmd(QSPI_TypeDef *qspi, FunctionalState state)
{
    (state) ?                             \
    (qspi->IMCR |= QSPI_IMCR_XIPIM_Pos) : \
    (qspi->IMCR &= ~QSPI_IMCR_XIPIM_Pos);
}

/**
  * @brief  Set QSPI Operation Mode.
  * @param  qspi: Select the QSPI peripheral.
  * @param  mode: Select the QSPI Operation Mode.
  *         This parameter can be one of the following values:
  * @arg    QSPI_OperationMode_Direct
  * @arg    QSPI_OperationMode_Reserved
  * @arg    QSPI_OperationMode_Indirect
  * @arg    QSPI_OperationMode_Inactive
  * @retval None.
  */
void QSPI_SetOperationMode(QSPI_TypeDef *qspi, uint32_t mode)
{
    MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, mode);
}

/**
  * @brief  Get QSPI Current Operation Mode.
  * @param  qspi: Select the QSPI peripheral.
  * @retval 0:QSPI_OperationMode_Direct 1:QSPI_OperationMode_Reserved 2:QSPI_OperationMode_Indirect 3:QSPI_OperationMode_Inactive
  */
uint32_t QSPI_GetOperationMode(QSPI_TypeDef *qspi)
{
    return (qspi->SR & QSPI_SR_CUROP_Msk);
}

/**
  * @brief  Get FIFO level.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetFifoLevel(QSPI_TypeDef *qspi)
{
    return ((qspi->SR & QSPI_SR_LEVEL_Msk) >> QSPI_SR_LEVEL_Pos);
}

/**
  * @brief  Get FIFO depth.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetFifoDepth(QSPI_TypeDef *qspi)
{
    return ((qspi->SR & QSPI_SR_DEPTH_Msk) >> QSPI_SR_DEPTH_Pos);
}

/**
  * @brief  Set direct mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetDirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->DABR = data;
}

/**
  * @brief  Get direct mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetDirectAlternateBytes(QSPI_TypeDef *qspi)
{
    return (qspi->DABR);
}

/**
  * @brief  Set indirect mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectAlternateBytes(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IABR = data;
}

/**
  * @brief  Get indirect mode alternate bytes.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectAlternateBytes(QSPI_TypeDef *qspi)
{
    return (qspi->IABR);
}

/**
  * @brief  Set indirect mode address.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectAddress(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IADR = data;
}

/**
  * @brief  Get indirect mode address.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectAddress(QSPI_TypeDef *qspi)
{
    return (qspi->IADR);
}

/**
  * @brief  Set indirect mode data length.
  * @param  qspi: Select the QSPI peripheral.
  * @param  length : Data to be transmitted.
  * @retval None.
  */
void QSPI_SetIndirectDataLength(QSPI_TypeDef *qspi, uint32_t length)
{
    qspi->IDLR = length;
}

/**
  * @brief  Get indirect mode data length.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_GetIndirectDataLength(QSPI_TypeDef *qspi)
{
    return (qspi->IDLR);
}

/**
  * @brief  Set indirect mode wait count.
  * @param  qspi: Select the QSPI peripheral.
  * @param  count : wait count.
  * @retval None.
  */
void QSPI_SetIndirectWaitCount(QSPI_TypeDef *qspi, uint32_t count)
{
    qspi->IWCR = count;
}

/**
  * @brief  Get indirect mode wait count.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the wait count.
  */
uint32_t QSPI_GetIndirectWaitCount(QSPI_TypeDef *qspi)
{
    return (qspi->IWCR);
}

/**
  * @brief  Transmits a Data through the qspi fifo indirectly.
  * @param  qspi: Select the QSPI peripheral.
  * @param  data : Data to be transmitted.
  * @retval None.
  */
void QSPI_SendIndirectDataFifo(QSPI_TypeDef *qspi, uint32_t data)
{
    qspi->IDFR = data;
}

/**
  * @brief  Returns received data by the qspi fifo indirectly.
  * @param  qspi: Select the QSPI peripheral.
  * @retval The value of the received data.
  */
uint32_t QSPI_ReceiveIndirectDataFifo(QSPI_TypeDef *qspi)
{
    return (qspi->IDFR);
}

/**
  * @brief  Checks whether the specified QSPI flag is set or not.
  * @param  qspi: Select the QSPI peripheral.
  * @param  flag: specifies the QSPI flag to check.
  *         This parameter can be one of the following values:
  * @arg    QSPI_FLAG_TCF
  * @arg    QSPI_FLAG_EMPTY
  * @arg    QSPI_FLAG_FULL
  * @arg    QSPI_FLAG_BUSY
  * @arg    QSPI_FLAG_XIP
  * @arg    QSPI_FLAG_MODECHANGE
  * @retval The new state of flag (SET or RESET).
  */
FlagStatus QSPI_GetFlagStatus(QSPI_TypeDef *qspi, uint32_t flag)
{
    return ((qspi->SR & flag) ? SET : RESET);
}

/**
  * @brief  Clears the QSPI flag.
  * @param  qspi: Select the QSPI peripheral.
  * @param  flag: specifies the QSPI flag to clear.
  *         This parameter can be one of the following values:
  * @arg    QSPI_FLAG_TCF
  * @arg    QSPI_FLAG_EMPTY
  * @retval None
  */
void QSPI_ClearFlag(QSPI_TypeDef *qspi, uint32_t flag)
{
    qspi->SR = flag;
}

/**
  * @brief  Enables or disables the specified QSPI interrupts.
  * @param  qspi: Select the QSPI peripheral.
  * @param  it: specifies the QSPI interrupt source to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    QSPI_IT_TCF
  * @arg    QSPI_IT_EMPTY
  * @arg    QSPI_IT_FULL
  * @param  state: new state of the specified QSPI interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_ITConfig(QSPI_TypeDef *qspi, uint32_t it, FunctionalState state)
{
    (state) ?             \
    (qspi->IDER |=  it) : \
    (qspi->IDER &= ~it) ;
}

/**
  * @brief  Enables or disables the specified QSPI DMA request.
  * @param  qspi: Select the QSPI peripheral.
  * @param  dmaconfig: specifies the QSPI interrupt source to be enabled or disabled.
  *         This parameter can be one of the following values:
  * @arg    QSPI_DMA_TCF
  * @arg    QSPI_DMA_EMPTY
  * @arg    QSPI_DMA_FULL
  * @param  state: new state of the specified QSPI interrupt.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void QSPI_DMAConfig(QSPI_TypeDef *qspi, uint32_t dmaconfig, FunctionalState state)
{
    (state) ?                   \
    (qspi->IDER |= dmaconfig) : \
    (qspi->IDER &= ~dmaconfig);
}

/**
* @brief  Set Indirect Trans Mode, if QSPI is in indirect mode, do not configure.
* @param  qspi: Select the QSPI peripheral.
* @param  direction: Select indirect mode access mode.
*   @arg QSPI_IndirectMode_Read 
*   @arg QSPI_IndirectMode_Write
* @retval : None
*/
void QSPI_SetIndirectTransMode(QSPI_TypeDef *qspi, uint32_t direction)
{
    if(QSPI_GetOperationMode(qspi) != QSPI_OperationMode_Indirect)
    {
        MODIFY_REG(qspi->IMCR, QSPI_IMCR_IDMODE_Msk, direction);
        
        if(direction == QSPI_IndirectMode_Read)
        {
            qspi->SR |= 0x100;
        }

        MODIFY_REG(qspi->CR, QSPI_CR_OPMODE_Msk, QSPI_OperationMode_Indirect);
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
