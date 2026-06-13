/***********************************************************************************************************************
    @file     hal_hwsqrt.c
    @author   FD TEAM
    @brief    THIS FILE PROVIDES ALL THE SYSCFG FIRMWARE FUNCTIONS.
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

/* Includes ------------------------------------------------------------------*/
#include "hal_hwsqrt.h"

/** @addtogroup MM32_StdPeriph_Driver
  * @{
  */

/** @addtogroup HWSQRT
  * @{
  */

/** @defgroup HWSQRT_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup HWSQRT_Private_Functions
  * @{
  */
/**
  * @brief  Write data to square data register.
  * @param  square: Set the value of square.
  * @retval None
  */
void HWSQRT_SetSquare(uint32_t square)
{
    HWSQRT->SQR = square;
}

/**
  * @brief  Get square result.
  * @param  None
  * @retval HWSQRT root value
  */
uint16_t HWSQRT_GetRoot(void)
{
    return (HWSQRT->RDR & HWSQRT_RDR_ROOT_Msk);
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

