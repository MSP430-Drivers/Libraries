/**********************************************************************************************************************
 * \file platform_types.h
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
 *  which are relevant for drivers types
 *********************************************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  e_FREQ1MHZ  = (uint8 const)0u,
  e_FREQ8MHZ  = (uint8 const)1u,
  e_FREQ12MHZ = (uint8 const)2u,
  e_FREQ16MHZ = (uint8 const)3u
} t_Frequency;

typedef enum
{
  e_DIV1 = (uint8 const)0u,
  e_DIV2 = (uint8 const)1u,
  e_DIV4 = (uint8 const)2u,
  e_DIV8 = (uint8 const)3u
} t_Divider;

typedef enum
{
  e_CLK_DCO = (uint8 const)0u,
  e_CLK_XT2 = (uint8 const)1u,
  e_CLK_VLO = (uint8 const)2u
} t_SourceCLK;

#ifdef __cplusplus
}
#endif

#endif
