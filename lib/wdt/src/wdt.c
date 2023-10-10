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

// pasword that needs to be include every write transaction
const uint16 u_WDT_PSWR = 0x5A00u;

void WDT_v_Stop(void)
{
  // Set bit 7
  // Watchdog timer+ hold. This bit stops the watchdog timer+
  REG_v_Set16BitReg(u_WDTCTL_ADDR, (u_WDT_PSWR | 0x0080));
}

#ifdef __cplusplus
}
#endif
