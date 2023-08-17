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

volatile uint8* const pu_CALDCO_XMHZ_ADDR[4] = { u_CALDCO_1MHZ_ADDR, u_CALDCO_8MHZ_ADDR,
                                                 u_CALDCO_12MHZ_ADDR, u_CALDCO_16MHZ_ADDR };

volatile uint8* const pu_CALBC1_XMHZ_ADDR[4] = { u_CALBC1_1MHZ_ADDR, u_CALBC1_8MHZ_ADDR,
                                                 u_CALBC1_12MHZ_ADDR, u_CALBC1_16MHZ_ADDR };

// DCO is configured using the following:
// DCOCTL Register, DCO Control Register
// DCOx Bits 7-5 -> DCO frequency select.
// MODx Bits 4-0 -> Modulator selection.
// BCSCTL1 Register, Basic Clock System Control Register 1
// RSELxBits 3-0 -> Range select. Sixteen different frequency ranges are available.
void BCM_v_DCOConf(t_Frequency e_freq)
{
  REG_v_Set8BitReg(u_DCOCTL_ADDR, REG_u_Get8BitReg(pu_CALDCO_XMHZ_ADDR[e_freq]));  // DCOCTL -> DCO and MOD
  REG_v_Set8BitReg(u_BCSCTL1_ADDR, REG_u_Get8BitReg(pu_CALBC1_XMHZ_ADDR[e_freq])); // BCSCTL1 -> RSEL
}

// Bits 7-6 Select MCLK. These bits select the MCLK source.
// [0] -> 00 DCOCLK & 01 DCOCLK = 0u
// [1] -> 10 XT2CLK = 0b10000000
// [2] -> 11 LFXT1CLK or VLOCLK = 0b11000000
// Bits 5-4 Divider for MCLK
// [0] -> 00 /1 = 0b000000 0u
// [1] -> 01 /2 = 0b010000 16u
// [2] -> 10 /4 = 0b100000 32u
// [3] -> 11 /8 = 0b110000 48u
void BCM_v_MCLKConf(t_SourceCLK e_srcClk, t_Divider e_div)
{
  REG_v_SetBitsIn8BitReg(u_BCSCTL2_ADDR, 7u, 6u, e_srcClk);
  REG_v_SetBitsIn8BitReg(u_BCSCTL2_ADDR, 5u, 4u, e_div);
}

// Bit 3 Select SMCLK. This bit selects the SMCLK source.
// [0] -> 0 DCOCLK = 0u
// [1] -> 1 XT2CLK = 0b1000
// Bits 2-1 Divider for SMCLK
// [0] -> 00 /1 = 0b000 0u
// [1] -> 01 /2 = 0b010 2u
// [2] -> 10 /4 = 0b100 4u
// [3] -> 11 /8 = 0b110 6u
void BCM_v_SMCLKConf(t_SourceCLK e_srcClk, t_Divider e_div)
{
  REG_v_SetBitsIn8BitReg(u_BCSCTL2_ADDR, 3u, 3u, e_srcClk);
  REG_v_SetBitsIn8BitReg(u_BCSCTL2_ADDR, 2u, 1u, e_div);
}

// Only support internal CLK provided by VLO
// Bits 5-4 Divider for ACLK
// [0] -> 00 /1 = 0b000000 0u
// [1] -> 01 /2 = 0b010000 16u
// [2] -> 10 /4 = 0b100000 32u
// [3] -> 11 /8 = 0b110000 48u
void BCM_v_ACLKConf(t_Divider e_div)
{
  // XT2 is off (bit 7)
  REG_v_SetBitIn8BitReg(u_BCSCTL1_ADDR, 7u);
  // LFXT1 Low frequency (bit6)
  REG_v_ClearBitIn8BitReg(u_BCSCTL1_ADDR, 6u);
  // Select VLO as clk source (bit 5-4)
  // 10 VLOCLK = 2u
  REG_v_SetBitsIn8BitReg(u_BCSCTL3_ADDR, 5u, 4u, 2u);
  REG_v_SetBitsIn8BitReg(u_BCSCTL1_ADDR, 5u, 4u, e_div);
}

#ifdef __cplusplus
}
#endif
