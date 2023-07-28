/**********************************************************************************************************************
 * \file bcm.c
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

#include <msp430g2553_registers.h>
#include <register_utils.h>
#include <bcm.h>

#ifdef __cplusplus
extern "C" {
#endif

volatile uint16* const pu_CALDCO_XMHZ_ADDR[4]  = { u_CALDCO_1MHZ_ADDR, u_CALDCO_8MHZ_ADDR, \
                                                  u_CALDCO_12MHZ_ADDR, u_CALDCO_16MHZ_ADDR };

void BCM_v_DCOConf(t_Frequency e_freq)
{
    REG_v_WriteToReg(u_DCOCTL_ADDR,REG_u_ReadFromReg(pu_CALDCO_XMHZ_ADDR[e_freq]));
}

void BCM_v_ACLKConf(t_Frequency e_freq, t_Divider e_div)
{
}


#ifdef __cplusplus
}
#endif
