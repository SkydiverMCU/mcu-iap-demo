/* Define to prevent recursive inclusion */
#ifndef _CRC32_ALGORITHM_H_
#define _CRC32_ALGORITHM_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* Files include */
#include "hal_conf.h"
#include <stdint.h>
/* Exported types *****************************************************************************************************/

/* Exported constants *************************************************************************************************/

/* Exported macro *****************************************************************************************************/

/**
 * @brief CRC32参数（严格匹配Python：crcmod.mkCrcFun(0x104C11DB7, initCrc=0xFFFFFFFF, rev=False, xorOut=0x00000000)）
 */
// CRC32-MPEG2 标准参数定义
#define CRC32_MPEG2_INIT 0xFFFFFFFFU   // 初始值，匹配Python的initCrc=0xFFFFFFFF
#define CRC32_MPEG2_POLY 0x04C11DB7U   // 多项式（剥离0x104C11DB7的最高位1，标准嵌入式实现方式）
#define CRC32_MPEG2_XOROUT 0x00000000U // 输出异或值，匹配Python的xorOut=0x00000000

    uint32_t crc32_mpeg2_calculate(const uint8_t *addr, uint32_t size, uint32_t init_value);

#ifdef __cplusplus
}
#endif

#endif /* _CRC32_ALGORITHM_H_ */
