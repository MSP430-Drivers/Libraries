/**********************************************************************************************************************
 * \file timer.h
 *
 * \author  Marco Aguilar
 *
 * \date Aug-17-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the Timer Driver
 *********************************************************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  timerA0 = (uint8)0u,
  timerA1 = (uint8)1u,
  TimerNC = (uint8)2u
} t_TimerChannel;

typedef enum
{
  stop       = (uint8)0u,
  up         = (uint8)1u,
  continuous = (uint8)2u,
  updown     = (uint8)3u,
} t_TimerMode;

typedef enum
{
  capture = (uint8)0u,
  compare = (uint8)1u,
  NC      = (uint8)3u
} t_TimerType;

typedef enum
{
  slot0 = (uint8)0u,
  slot1 = (uint8)1u,
  slot2 = (uint8)2u
} t_TimerSlot;

typedef struct

{
  t_TimerChannel timer;
  t_TimerMode    mode;
  t_TimerType    slot[3];
} t_Timers;

static t_Timers timersChannels[2];

#ifdef __cplusplus
}
#endif

#endif