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

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
 * CLK Types
 ************************************************************/
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

/************************************************************
 * GPIO Types
 ************************************************************/
typedef enum
{
  e_INPUT  = (uint8 const)0u,
  e_OUTPUT = (uint8 const)1u
} t_PinDir;

typedef enum
{
  e_PIN_DIO       = (uint8 const)0u,
  e_PIN_PRIMARY   = (uint8 const)1u,
  e_PIN_SECONDARY = (uint8 const)2u
} t_FunctionSelect;

typedef enum
{
  e_RES_DIS = (uint8 const)0u,
  e_RES_EN  = (uint8 const)1u
} t_Ren;

typedef enum
{
  e_PULL_DOWN = (uint8 const)0u,
  e_PULL_UP   = (uint8 const)1u
} t_ResType;

typedef enum
{
  e_PIN0   = (uint8 const)0u,
  e_PIN1   = (uint8 const)1u,
  e_PIN2   = (uint8 const)2u,
  e_PIN3   = (uint8 const)3u,
  e_PIN4   = (uint8 const)4u,
  e_PIN5   = (uint8 const)5u,
  e_PIN6   = (uint8 const)6u,
  e_PIN7   = (uint8 const)7u,
  pinMax   = (uint8)8u
} t_Pin;

typedef enum
{
  e_PORT1   = (uint8 const)0u,
  e_PORT2   = (uint8 const)1u,
  portMax   = (uint8)2u
} t_Port;

typedef enum
{
  e_LOW  = (uint8 const)0u,
  e_HIGH = (uint8 const)1u
} t_PinState;

typedef enum
{
  e_RISING_EDGE  = (uint8 const)0u, ///< low-to-high transition
  e_FALLING_EDGE = (uint8 const)1u  ///< high-to-low transition
} t_EdgeSelect;

#ifdef __cplusplus
}
#endif

#endif
