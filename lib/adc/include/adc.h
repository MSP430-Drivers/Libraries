/**********************************************************************************************************************
 * \file adc.h
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

#ifndef ADC_H
#define ADC_H

#include <platform_types.h>
#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  e_VCC  = (uint8 const)0u,
  e_EREF = (uint8 const)2u
} t_SelectRef;

typedef enum
{
  e_4ADC10CLKS  = (uint8 const)0u,
  e_8ADC10CLKS  = (uint8 const)1u,
  e_16ADC10CLKS = (uint8 const)2u,
  e_64ADC10CLKS = (uint8 const)3u
} t_SampleHoldTime;

typedef enum
{
  e_200KSPS = (uint8 const)0u,
  e_50KSPS  = (uint8 const)1u
} t_SampleRate;

typedef enum
{
  e_STRAIGHT   = (uint8 const)0u,
  e_COMPLEMENT = (uint8 const)1u
} t_DataFormat;

typedef enum
{
  e_ADC_DIV1 = (uint8 const)0u,
  e_ADC_DIV2 = (uint8 const)1u,
  e_ADC_DIV3 = (uint8 const)2u,
  e_ADC_DIV4 = (uint8 const)3u,
  e_ADC_DIV5 = (uint8 const)4u,
  e_ADC_DIV6 = (uint8 const)5u,
  e_ADC_DIV7 = (uint8 const)6u,
  e_ADC_DIV8 = (uint8 const)7u
} t_AdcDivClk;

typedef enum
{
  e_ADC_CLK   = (uint8 const)0u,
  e_ADC_ACLK  = (uint8 const)1u,
  e_ADC_MCLK  = (uint8 const)2u,
  e_ADC_SMCLK = (uint8 const)3u
} t_AdcClkSrc;

typedef enum
{
  e_SINGLE      = (uint8 const)0u,
  e_SEQUENCE    = (uint8 const)1u,
  e_REPSINGLE   = (uint8 const)2u,
  e_REPSEQUENCE = (uint8 const)3u
} t_ConversionSeq;

typedef enum
{
  e_CHA0 = (uint8 const)0u,
  e_CHA1 = (uint8 const)1u,
  e_CHA2 = (uint8 const)2u,
  e_CHA3 = (uint8 const)3u,
  e_CHA4 = (uint8 const)4u,
  e_CHA5 = (uint8 const)5u,
  e_CHA6 = (uint8 const)6u,
  e_CHA7 = (uint8 const)7u
} t_AdcChannel;

void ADC_v_Init(void);

void ADC_v_Config(t_SelectRef e_selRef, t_SampleHoldTime e_sht, t_SampleRate e_samRate,
                  t_DataFormat e_df, t_AdcDivClk e_div, t_AdcClkSrc e_src, t_ConversionSeq e_con);

void ADC_v_EnableInterrupt();

void ADC_v_SetChannel(t_AdcChannel e_inputCh);

#ifdef __cplusplus
}
#endif

#endif
