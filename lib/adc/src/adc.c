/**********************************************************************************************************************
 * \file adc.c
 *
 * \author  Marco Aguilar
 *
 * \date Dec-05-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the ADC Driver
 *********************************************************************************************************************/

#include <adc.h>
#include <msp430g2553_registers.h>
#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

void ADC_v_Init(void)
{
  REG_v_Set16BitReg(u_ADC10CTL0, 0u);
}

void ADC_v_Config(t_SelectRef e_selRef, t_SampleHoldTime e_sht, t_SampleRate e_samRate,
                  t_DataFormat e_df, t_AdcDivClk e_div, t_AdcClkSrc e_src, t_ConversionSeq e_con)
{
  REG_v_SetBitsIn16BitReg(u_ADC10CTL0, 15u, 13u, e_selRef);  // Select reference
  REG_v_SetBitsIn16BitReg(u_ADC10CTL0, 11u, 12u, e_sht);     // ADC10 sample-and-hold time
  REG_v_SetBitsIn16BitReg(u_ADC10CTL0, 10u, 10u, e_samRate); // Select the reference buffer drive capability for the maximum sampling rate
  REG_v_SetBitsIn16BitReg(u_ADC10CTL1, 9u, 9u, e_df);        // ADC10 data format (Straight binary or 2s complement)
  REG_v_SetBitsIn16BitReg(u_ADC10CTL1, 7u, 5u, e_div);       // ADC10 clock divider
  REG_v_SetBitsIn16BitReg(u_ADC10CTL1, 4u, 3u, e_src);       // clock source select
  REG_v_SetBitsIn16BitReg(u_ADC10CTL1, 2u, 1u, e_con);       // Conversion sequence mode
}

void ADC_v_EnableInterrupt()
{
  REG_v_SetBitIn16BitReg(u_ADC10CTL0, 3u);
}

void ADC_v_SetChannel(t_AdcChannel e_inputCh)
{
  REG_v_SetBitsIn16BitReg(u_ADC10CTL1, 15u, 12u, e_inputCh);
  REG_v_SetBitIn8BitReg(u_ADC10AE0, e_inputCh);
}

void ADC_v_StartConversion(void)
{
  REG_v_SetBitIn16BitReg(u_ADC10CTL0, 4u);
  REG_v_SetBitsIn16BitReg(u_ADC10CTL0, 1u, 0u, 3u);
}

#ifdef __cplusplus
}
#endif
