/**********************************************************************************************************************
 * \file wdt.h
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
#ifndef WDT_H
#define WDT_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const uint16 u_WDT_PSWR;

void WDT_v_Stop(void);

#ifdef __cplusplus
}
#endif

#endif
