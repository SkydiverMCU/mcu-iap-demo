#include "crc32_algorithm.h"

/**
 * @brief 计算CRC32-MPEG2（支持Flash/内存字节访问）
 * @param addr: 数据起始地址（Flash/内存地址）
 * @param size: 数据字节长度
 * @return 计算后的CRC32-MPEG2值
 */
uint32_t crc32_mpeg2_calculate(const uint8_t *addr, uint32_t size, uint32_t init_value)
{
    const volatile uint8_t *ptr = (const volatile uint8_t *)addr;
    uint32_t crc = init_value;
    uint8_t byte;

    for (uint32_t i = 0; i < size; i++)
    {
        byte = ptr[i];
        crc ^= (uint32_t)byte << 24;
        for (int bit = 0; bit < 8; bit++)
        {
            if (crc & 0x80000000U)
            {
                crc = (crc << 1) ^ CRC32_MPEG2_POLY;
            }
            else
            {
                crc = crc << 1;
            }
        }
    }

    // 输出不反转、不异或（匹配标准）
    return crc ^ CRC32_MPEG2_XOROUT;
}
