/**********************************************************************************************************************
 * \file gpio_types.h
 *
 * \author  Marco Aguilar
 *
 * \date Jun-26-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the MSP's project
 *********************************************************************************************************************/

#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  pinNotInit = (uint8)0u,
  pinInit    = (uint8)1u,
  pinConf    = (uint8)2u
} t_PortPinStat;

typedef enum
{
  input  = (uint8)0u,
  output = (uint8)1u
} t_PinDir;

typedef enum
{
  dio       = (uint8)0u,
  primary   = (uint8)1u,
  secondary = (uint8)2u
} t_FunctionSelect;

typedef enum
{
  disabled = (uint8)0u,
  enable   = (uint8)1u
} t_Ren;

typedef enum
{
  pullDown = (uint8)0u,
  pullUp   = (uint8)1u
} t_ResType;

typedef enum
{
  pin0   = (uint8)0u,
  pin1   = (uint8)1u,
  pin2   = (uint8)2u,
  pin3   = (uint8)3u,
  pin4   = (uint8)4u,
  pin5   = (uint8)5u,
  pin6   = (uint8)6u,
  pin7   = (uint8)7u,
  pinMax = (uint8)8u
} t_Pin;

typedef enum
{
  port1   = (uint8)0u,
  port2   = (uint8)1u,
  portMax = (uint8)2u
} t_Port;

typedef enum
{
  low  = (uint8)0u,
  high = (uint8)1u
} t_PinState;

typedef enum
{
  risingEdge  = (uint8)0u, ///< low-to-high transition
  fallingEdge = (uint8)1u  ///< high-to-low transition
} t_EdgeSelect;

#ifdef __cplusplus
}
#endif

#endif
