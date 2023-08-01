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

#include <bcm.h>
#include <msp430g2553_registers.h>
#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

volatile uint16* const pu_CALDCO_XMHZ_ADDR[4] = { u_CALDCO_1MHZ_ADDR, u_CALDCO_8MHZ_ADDR,
                                                  u_CALDCO_12MHZ_ADDR, u_CALDCO_16MHZ_ADDR };

// Bits 7-6 Select MCLK. These bits select the MCLK source.
// [0] -> 00 DCOCLK & 01 DCOCLK = 0u
// [1] -> 10 XT2CLK = 0b10000000
// [2] -> 11 LFXT1CLK or VLOCLK = 0b11000000
static const uint8 au_SRC_CLK_MCLK[3] = { 0u, 128u, 192u };

// Bits 5-4 Divider for MCLK
// [0] -> 00 /1 = 0b000000 0u
// [1] -> 01 /2 = 0b010000 16u
// [2] -> 10 /4 = 0b100000 32u
// [3] -> 11 /8 = 0b110000 48u
static const uint8 au_DIV_MCLK[4] = { 0u, 16u, 32u, 48u };

// Bit 3 Select SMCLK. This bit selects the SMCLK source.
// [0] -> 0 DCOCLK = 0u
// [1] -> 1 XT2CLK = 0b1000
static const uint8 au_SRC_CLK_SMCLK[2] = { 0u, 8u };

// Bits 2-1 Divider for SMCLK
// [0] -> 00 /1 = 0b000 0u
// [1] -> 01 /2 = 0b010 2u
// [2] -> 10 /4 = 0b100 4u
// [3] -> 11 /8 = 0b110 6u
static const uint8 au_DIV_SMCLK[4] = { 0u, 2u, 4u, 6u };

// Bits 5-4 Divider for ACLK
// [0] -> 00 /1 = 0b000000 0u
// [1] -> 01 /2 = 0b010000 16u
// [2] -> 10 /4 = 0b100000 32u
// [3] -> 11 /8 = 0b110000 48u
static const uint8 au_DIV_ACLK[4] = { 0u, 16u, 32u, 48u };

void BCM_v_DCOConf(t_Frequency e_freq)
{
  REG_v_WriteToReg(u_DCOCTL_ADDR, REG_u_ReadFromReg(pu_CALDCO_XMHZ_ADDR[e_freq]));
}

void BCM_v_MCLKConf(t_SourceCLK e_srcClk, t_Divider e_div)
{
  uint8 u_mclkConf = au_SRC_CLK_MCLK[e_srcClk] | au_DIV_MCLK[e_div];
  REG_v_WriteOrReg(u_BCSCTL2_ADDR, u_mclkConf);
}

void BCM_v_SMCLKConf(t_SourceCLK e_srcClk, t_Divider e_div)
{
  uint8 u_smclkConf = au_SRC_CLK_SMCLK[e_srcClk] | au_DIV_SMCLK[e_div];
  REG_v_WriteOrReg(u_BCSCTL2_ADDR, u_smclkConf);
}

void BCM_v_ACLKConf(t_Divider e_div)
{
  REG_v_WriteOrReg(u_BCSCTL1_ADDR, au_DIV_ACLK[e_div]);
}

#ifdef __cplusplus
}
#endif
