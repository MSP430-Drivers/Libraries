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
#include <register_utils.h>
#include <timer.h>

#ifdef __cplusplus
extern "C" {
#endif

volatile uint16* const pu_TAxCTL_ADDR[2] = { TA0CTL_ADDR, TA1CTL_ADDR };
volatile uint16* const pu_TAxR_ADDR[2]   = { TA0R_ADDR, TA1R_ADDR };
volatile uint16* const pu_TAxCCTLx_ADDR[2][3] = {{TA0CCTL0_ADDR, TA0CCTL1_ADDR, TA0CCTL2_ADDR}, \
                                                 {TA1CCTL0_ADDR, TA1CCTL1_ADDR, TA1CCTL2_ADDR}};

void TIMER_v_Init(void)
{
  timersChannels[0].timer   = e_TIMERNC;
  timersChannels[0].slot[0] = e_NC;
  timersChannels[0].slot[1] = e_NC;
  timersChannels[0].slot[2] = e_NC;
  timersChannels[1].timer   = e_TIMERNC;
  timersChannels[1].slot[0] = e_NC;
  timersChannels[1].slot[1] = e_NC;
  timersChannels[1].slot[2] = e_NC;
}

void TIMER_v_Configure(t_TimerChannel e_timer, t_TimerMode e_mode, t_Clk e_clk, t_Divider e_div)
{
  if(timersChannels[e_timer].timer == e_TIMERNC)
  {
    timersChannels[e_timer].timer = e_timer;
    timersChannels[e_timer].mode  = e_mode;
    REG_v_SetBitsIn16BitReg(pu_TAxCTL_ADDR[e_timer], 9u, 8u, e_clk);
    REG_v_SetBitsIn16BitReg(pu_TAxCTL_ADDR[e_timer], 7u, 6u, e_div);
    REG_v_SetBitsIn16BitReg(pu_TAxCTL_ADDR[e_timer], 5u, 4u, e_mode);
    REG_v_SetBitsIn16BitReg(pu_TAxCTL_ADDR[e_timer], 1u, 0u, 0u);
  }
  else
  {
    // IED Implementation Error Detection
    // Timer is already configured
  }
}

void TIMER_v_SetInstance(t_TimerChannel e_timer, t_TimerType e_type, t_TimerSlot e_slot)
{
  if(timersChannels[e_timer].slot[e_slot] == e_NC)
  {
    timersChannels[e_timer].slot[e_slot] = e_type;
    (e_type == e_COMPARE) ? REG_v_ClearBitIn16BitReg(pu_TAxCCTLx_ADDR[e_timer][e_slot], 8u) : REG_v_SetBitIn16BitReg(pu_TAxCCTLx_ADDR[e_timer][e_slot], 8u);
  }
  else
  {
    // IED Implementation Error Detection
    // Timer Slot is already configured
  }
}

void TIMER_v_EnableInterruptCC(t_TimerChannel e_timer, t_TimerSlot e_slot)
{
  if(timersChannels[e_timer].slot[e_slot] != e_NC)
  {
    REG_v_SetBitIn16BitReg(pu_TAxCCTLx_ADDR[e_timer][e_slot], 4u);
  }
  else
  {
    // IED Implementation Error Detection
    // Timer Slot is not configured
  }
}

#ifdef __cplusplus
}
#endif
