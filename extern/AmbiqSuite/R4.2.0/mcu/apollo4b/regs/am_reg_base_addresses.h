//*****************************************************************************
//
//  am_reg_base_addresses.h
//! @file
//!
//! @brief Register defines for all module base addresses
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2022, Ambiq Micro, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// Third party software included in this distribution is subject to the
// additional license terms as defined in the /docs/licenses directory.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision release_sdk_4_2_0-0a31245a64 of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_REG_BASE_ADDRESSES_H
#define AM_REG_BASE_ADDRESSES_H

#include "stdint.h"

//
// ARM standard register space (needed for macros)
//
#define REG_ITM_BASEADDR                        (0x00000000UL)
#define REG_JEDEC_BASEADDR                      (0x00000000UL)
#define REG_NVIC_BASEADDR                       (0x00000000UL)
#define REG_SYSCTRL_BASEADDR                    (0x00000000UL)
#define REG_SYSTICK_BASEADDR                    (0x00000000UL)
#define REG_TPIU_BASEADDR                       (0x00000000UL)

//
// Peripheral register space
//
#define REG_ADC_BASEADDR                        (0x40038000UL)
#define REG_APBDMA_BASEADDR                     (0x51000000UL)
#define REG_AUDADC_BASEADDR                     (0x40210000UL)
#define REG_CLKGEN_BASEADDR                     (0x40004000UL)
#define REG_CPU_BASEADDR                        (0x48000000UL)
#define REG_DC_BASEADDR                         (0x400A0000UL)
#define REG_DSI_BASEADDR                        (0x400A8000UL)
#define REG_DSP_BASEADDR                        (0x40100000UL)
#define REG_DSPI2S_BASEADDR                     (0x50428000UL)
#define REG_DSPTIMER_BASEADDR                   (0x40087000UL)
#define REG_FPIO_BASEADDR                       (0x40010800UL)
#define REG_GPIO_BASEADDR                       (0x40010000UL)
#define REG_GPU_BASEADDR                        (0x40090000UL)
#define REG_IOM_BASEADDR                        (0x40005000UL)
#define REG_IOSLAVE_BASEADDR                    (0x40034000UL)
#define REG_MCUCTRL_BASEADDR                    (0x40020000UL)
#define REG_MRAM_BASEADDR                       (0x40014000UL)
#define REG_MSPI_BASEADDR                       (0x40060000UL)
#define REG_PDM_BASEADDR                        (0x50401000UL)
#define REG_PWRCTRL_BASEADDR                    (0x40021000UL)
#define REG_RSTGEN_BASEADDR                     (0x40000000UL)
#define REG_RTC_BASEADDR                        (0x40004800UL)
#define REG_SECURITY_BASEADDR                   (0x40030000UL)
#define REG_STIMER_BASEADDR                     (0x40008800UL)
#define REG_TIMER_BASEADDR                      (0x40008000UL)
#define REG_UART_BASEADDR                       (0x4001C000UL)
#define REG_VCOMP_BASEADDR                      (0x4000C000UL)
#define REG_WDT_BASEADDR                        (0x40024000UL)

// ****************************************************************************
// RAM Memory Map:
//  TCM:                             384KB      0x10000000 - 0x1005FFFF
//  System SRAM (SRAM):             1024KB      0x10060000 - 0x1015FFFF
//  Extended RAM:                    480KB      0x10160000 - 0x101D7FFF
// ****************************************************************************
//
// SRAM address space
//
#define SRAM_BASEADDR                           (0x10000000UL)
#define TCM_MAX_SIZE                            (0x60000UL)

//
// SSRAM address space
//
#define SSRAM_BASEADDR                          (0x10060000UL)
#define SSRAM0_BASEADDR                         SSRAM_BASEADDR
#define SSRAM0_MAX_SIZE                         (0x80000UL)
#define SSRAM1_BASEADDR                         (SSRAM_BASEADDR + SSRAM0_MAX_SIZE)
#define SSRAM1_MAX_SIZE                         (0x80000UL)
#define SSRAM_MAX_SIZE                          (SSRAM0_MAX_SIZE + SSRAM1_MAX_SIZE)

//
// Extended RAM address space
//
#define EXRAM_BASEADDR                          (0x10160000UL)
#define DSP0IRAM_BASEADDR                       EXRAM_BASEADDR
#define DSP0IRAM_MAX_SIZE                       (0x20000UL)
#define DSP0DRAM_BASEADDR                       (0x10180000UL)
#define DSP0DRAM_MAX_SIZE                       (0x40000UL)
#define DSP1DRAM_BASEADDR                       (0x101C0000UL)
#define DSP1DRAM_MAX_SIZE                       (0x10000UL)
#define DSP1IRAM_BASEADDR                       (0x101D0000UL)
#define DSP1IRAM_MAX_SIZE                       (0x8000UL)
#define EXRAM_MAX_SIZE                          (0x78000UL)

// ****************************************************************************
// MRAM Address Space
// ****************************************************************************
#define MRAM_BASEADDR                           (0x00000000UL)
#define MRAM_MAX_SIZE                           (0x200000UL)

//
// MSPI Aperature address ranges
//
#define MSPI0_APERTURE_START_ADDR               (0x14000000UL)
#define MSPI0_APERTURE_END_ADDR                 (0x18000000UL)
#define MSPI1_APERTURE_START_ADDR               (0x18000000UL)
#define MSPI1_APERTURE_END_ADDR                 (0x1C000000UL)
#define MSPI2_APERTURE_START_ADDR               (0x1C000000UL)
#define MSPI2_APERTURE_END_ADDR                 (0x20000000UL)



#endif // AM_REG_BASE_ADDRESSES_H

