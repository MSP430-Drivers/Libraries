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

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    freq_1Mhz = (uint8)0u,
    freq_8Mhz = (uint8)1u,
    freq_12Mhz = (uint8)2u,
    freq_16Mhz = (uint8)3u

}t_Frequency;

typedef enum
{
    div_1 = (uint8)0u,
    div_2 = (uint8)1u,
    div_3 = (uint8)2u,
    div_4 = (uint8)3u
}t_Divider;

void BCM_v_DCOConf(t_Frequency e_freq);
void BCM_v_MCLKConf();
void BCM_v_SMCLKConf();
void BCM_v_ACLKConf(t_Frequency e_freq, t_Divider e_div);

#ifdef __cplusplus
}
#endif

#endif