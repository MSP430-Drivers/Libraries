/**********************************************************************************************************************
 * \file bcm.h
 *
 * \author  Marco Aguilar
 *
 * \date Jul-25-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the BCM Driver
 *********************************************************************************************************************/

#ifndef BCM_H
#define BCM_H

#include <std_types.h>
#include <platform_types.h>

#ifdef __cplusplus
extern "C" {
#endif

void BCM_v_DCOConf(t_Frequency e_freq);

void BCM_v_MCLKConf(t_SourceCLK e_srcClk, t_Divider e_div);

void BCM_v_SMCLKConf(t_SourceCLK e_srcClk, t_Divider e_div);

void BCM_v_ACLKConf(t_Divider e_div);

#ifdef __cplusplus
}
#endif

#endif