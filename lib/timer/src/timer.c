/**********************************************************************************************************************
 * \file timer.c
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

#include <msp430g2553_registers.h>
#include <timer.h>

#ifdef __cplusplus
extern "C" {
#endif

volatile uint16* const pu_TAxCTL_ADDR[2] = { TA0CTL_ADDR, TA1CTL_ADDR };
volatile uint16* const pu_TAxR_ADDR[2]   = { TA0R_ADDR, TA1R_ADDR };

void TIMER_v_Init(void)
{
  timersChannels[0].timer   = TimerNC;
  timersChannels[0].slot[0] = NC;
  timersChannels[0].slot[1] = NC;
  timersChannels[0].slot[2] = NC;
  timersChannels[1].timer   = TimerNC;
  timersChannels[1].slot[0] = NC;
  timersChannels[1].slot[1] = NC;
  timersChannels[1].slot[2] = NC;
}

void TIMER_v_Configure(t_TimerChannel e_timer, t_TimerMode e_mode)
{
  if(timersChannels[e_timer].timer != TimerNC)
  {
    timersChannels[e_timer].timer = e_timer;
    timersChannels[e_timer].mode  = e_mode;
  }
  else
  {
    // IED Implementation Error Detection
    // Timer is already configured
  }
}

void TIMER_v_SetInstance(t_TimerChannel e_timer, t_TimerType e_type, t_TimerSlot e_slot)
{
  if(timersChannels[e_timer].slot[e_slot] != NC)
  {
  }
  else
  {
    // IED Implementation Error Detection
    // Timer Slot is already configured
  }
}

#ifdef __cplusplus
}
#endif
