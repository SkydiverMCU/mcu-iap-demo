////////////////////////////////////////////////////////////////////////////////
/// @file     reg_bkp.h
/// @author   AE TEAM
/// @brief    THIS FILE CONTAINS ALL THE FUNCTIONS PROTOTYPES FOR THE SERIES OF
///           MM32 FIRMWARE LIBRARY.
////////////////////////////////////////////////////////////////////////////////
/// @attention
///
/// THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
/// CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
/// TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
/// CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
/// HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
/// CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
///
/// <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2>
////////////////////////////////////////////////////////////////////////////////

// Define to prevent recursive inclusion

#ifndef __REG_BKP_H
#define __REG_BKP_H

// Files includes

#include <stdint.h>
#include <stdbool.h>
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__CC_ARM)
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic ignored "-Wc11-extensions"
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined(__GNUC__)
// anonymous unions are enabled by default
#else
#warning Not supported compiler type
#endif

////////////////////////////////////////////////////////////////////////////////
/// @brief BKP Base Address Definition
////////////////////////////////////////////////////////////////////////////////

#define BKP_BASE                        (APB1PERIPH_BASE + 0x2800)              ///< Base Address: 0x40002800

////////////////////////////////////////////////////////////////////////////////
/// @brief BKP Register Structure Definition
////////////////////////////////////////////////////////////////////////////////

#define BKP_NUMBER  20

typedef struct {
    __IO uint32_t RESERVED;                   
    __IO uint32_t CR;                             /*!<                                               offset: 0x04       */
    __IO uint32_t CSR;                            /*!<                                               offset: 0x08       */
} BKP_TypeDef;

////////////////////////////////////////////////////////////////////////////////
/// @brief BKP type pointer Definition
////////////////////////////////////////////////////////////////////////////////
#define BKP                             ((BKP_TypeDef*) BKP_BASE)

////////////////////////////////////////////////////////////////////////////////
/// @brief BKP_DRn Register Bit Definition
////////////////////////////////////////////////////////////////////////////////
#define BKP_DR_DATA_Pos                 (0)
#define BKP_DR_DATA                     (0xFFFFU << BKP_DR_DATA)                ///< Backup data

/// @}

/// @}

/// @}

#ifdef __cplusplus
}
#endif

////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////
