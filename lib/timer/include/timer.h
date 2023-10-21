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
#include <platform_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
  e_TIMERA0 = (uint8)0u,
  e_TIMERA1 = (uint8)1u,
  e_TIMERNC = (uint8)2u
} t_TimerChannel;

typedef enum
{
  e_STOP       = (uint8)0u,
  e_UP         = (uint8)1u,
  e_CONTINUOUS = (uint8)2u,
  e_UPMODE     = (uint8)3u,
} t_TimerMode;

typedef enum
{
  e_COMPARE = (uint8)0u,
  e_CAPTURE = (uint8)1u,
  e_NC      = (uint8)3u
} t_TimerType;

typedef enum
{
  e_SLOT0 = (uint8)0u,
  e_SLOT1 = (uint8)1u,
  e_SLOT2 = (uint8)2u
} t_TimerSlot;

typedef struct
{
  t_TimerChannel timer;
  t_TimerMode    mode;
  t_TimerType    slot[3];
} t_Timers;

static t_Timers timersChannels[2];

void TIMER_v_Configure(t_TimerChannel e_timer, t_TimerMode e_mode, t_Clk e_clk, t_Divider e_div);

void TIMER_v_Init(void);

void TIMER_v_Configure(t_TimerChannel e_timer, t_TimerMode e_mode, t_Clk e_clk, t_Divider e_div);

void TIMER_v_SetInstance(t_TimerChannel e_timer, t_TimerType e_type, t_TimerSlot e_slot);

void TIMER_v_EnableInterruptCC(t_TimerChannel e_timer, t_TimerSlot e_slot);

#ifdef __cplusplus
}
#endif

#endif