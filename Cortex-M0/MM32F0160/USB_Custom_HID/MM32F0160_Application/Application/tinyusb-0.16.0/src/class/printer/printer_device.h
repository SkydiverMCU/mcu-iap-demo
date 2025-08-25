/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ha Thach (tinyusb.org)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * This file is part of the TinyUSB stack.
 */

#ifndef _TUSB_MSC_DEVICE_H_
#define _TUSB_MSC_DEVICE_H_

#include "common/tusb_common.h"
#include "device/usbd.h"
#include "printer_device.h"

#ifdef __cplusplus
extern "C" {
#endif

#define USB_RX_BUF_SIZE             (1024 * 2)  //

//--------------------------------------------------------------------+
// Class Driver Configuration
//--------------------------------------------------------------------+

#if !defined(CFG_TUD_PRINTER_EP_BUFSIZE) & defined(CFG_TUD_MSC_BUFSIZE)
// TODO warn user to use new name later on
// #warning CFG_TUD_MSC_BUFSIZE is renamed to CFG_TUD_MSC_EP_BUFSIZE, please update to use the new name
#define CFG_TUD_MSC_EP_BUFSIZE  CFG_TUD_MSC_BUFSIZE
#endif

#ifndef CFG_TUD_PRINTER_EP_BUFSIZE
#error CFG_TUD_PRINTER_EP_BUFSIZE must be defined, value of a block size should work well, the more the better
#endif

TU_VERIFY_STATIC(CFG_TUD_PRINTER_EP_BUFSIZE < UINT16_MAX, "Size is not correct");

/** \addtogroup ClassDriver_MSC
 *  @{
 * \defgroup MSC_Device Device
 *  @{ */


// Invoked when received SCSI_CMD_READ_CAPACITY_10 and SCSI_CMD_READ_FORMAT_CAPACITY to determine the disk size
// Application update block count and block size
void tud_msc_capacity_cb(uint8_t lun, uint32_t* block_count, uint16_t* block_size);

/**
 * Invoked when received an SCSI command not in built-in list below.
 * - READ_CAPACITY10, READ_FORMAT_CAPACITY, INQUIRY, TEST_UNIT_READY, START_STOP_UNIT, MODE_SENSE6, REQUEST_SENSE
 * - READ10 and WRITE10 has their own callbacks
 *
 * \param[in]   lun         Logical unit number
 * \param[in]   scsi_cmd    SCSI command contents which application must examine to response accordingly
 * \param[out]  buffer      Buffer for SCSI Data Stage.
 *                            - For INPUT: application must fill this with response.
 *                            - For OUTPUT it holds the Data from host
 * \param[in]   bufsize     Buffer's length.
 *
 * \return      Actual bytes processed, can be zero for no-data command.
 * \retval      negative    Indicate error e.g unsupported command, tinyusb will \b STALL the corresponding
 *                          endpoint and return failed status in command status wrapper phase.
 */

/** @} */
/** @} */

//--------------------------------------------------------------------+
// Internal Class Driver API
//--------------------------------------------------------------------+
void     printer_init            (void);
void     printer_reset           (uint8_t rhport);
uint16_t printer_open            (uint8_t rhport, tusb_desc_interface_t const* itf_desc, uint16_t max_len);
bool     printer_control_xfer_cb (uint8_t rhport, uint8_t stage, tusb_control_request_t const* p_request);
bool     printer_xfer_cb         (uint8_t rhport, uint8_t ep_addr, xfer_result_t event, uint32_t xferred_bytes);
uint8_t * tud_printer_device_id_cb(void);
//--------------------------------------------------------------------+
//user API
uint32_t tud_printer_n_write(uint8_t itf, void const* buffer, uint32_t bufsize);
void tud_printer_task(void);



void New_queue_create(void);
uint32_t USB_RxRead(uint8_t *buffter, uint32_t buffterSize);
uint32_t USB_RxWrite(uint8_t *buffter, uint32_t writeLen);
#ifdef __cplusplus
}
#endif

#endif /* _TUSB_MSC_DEVICE_H_ */
