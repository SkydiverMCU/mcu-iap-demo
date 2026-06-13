/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016, 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _HOST_MSD_FATFS_H_
#define _HOST_MSD_FATFS_H_

#include "platform.h"
/*******************************************************************************
 * IAP Definitions
 ******************************************************************************/

extern uint32_t Packet_Total_lenth;
extern uint16_t Updatepacketsize;
extern uint32_t Remaining_size;
extern uint32_t Operation_address;

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief 0 - execute normal fatfs test code; 1 - execute throughput test code */
#define MSD_FATFS_THROUGHPUT_TEST_ENABLE (0U)

/*! @brief host app run status */
typedef enum _usb_host_msd_run_state
{
    kUSB_HostMsdRunIdle = 0,         /*!< idle */
    kUSB_HostMsdRunSetInterface,     /*!< execute set interface code */
    kUSB_HostMsdRunWaitSetInterface, /*!< wait set interface done */
    kUSB_HostMsdRunMassStorageTest   /*!< execute mass storage test code */
} usb_host_msd_run_state_t;


/*******************************************************************************
 * API
 ******************************************************************************/

/*!
 * @brief host msd fatfs task function.
 *
 * This function implements the host msd fatfs action, it is used to create task.
 *
 * @param arg   the host msd fatfs instance pointer.
 */
extern void USB_HostMsdFatfsUserReadWrite(void);

#endif /* _HOST_MSD_FATFS_H_ */
