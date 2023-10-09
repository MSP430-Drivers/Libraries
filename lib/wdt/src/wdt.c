/**********************************************************************************************************************
 * \file wdt.c
 *
 * \author  Marco Aguilar
 *
 * \date Oct-08-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the WatchDog Timer Driver
 *********************************************************************************************************************/

#include <msp430g2553_registers.h>
#include <register_utils.h>
#include <wdt.h>

#ifdef __cplusplus
extern "C" {
#endif

void WDT_v_Stop(void)
{
  REG_v_SetBitsIn8BitReg(u_WDTCTL_ADDR, 15u, 8u, u_WDT_PSWR);
  REG_v_SetBitsIn8BitReg(u_WDTCTL_ADDR, 7u, 7u, 1u);
}

#ifdef __cplusplus
}
#endif
