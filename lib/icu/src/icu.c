/**********************************************************************************************************************
 * \file icu.c
 *
 * \author  Marco Aguilar
 *
 * \date Jul-13-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the ICU Driver
 *********************************************************************************************************************/

#include <icu.h>
#include <msp430g2553_registers.h>
#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

static void ICU_v_Timer0A0_ISR(void);

static void ICU_v_Timer0A1_ISR(void);

static void ICU_v_Timer1A0_ISR(void);

static void ICU_v_Timer1A1_ISR(void);

t_VectorTable t_vectorTableEntry[MAX_INT_VECTOR] = {
  {NULL, NULL,        trapVector}, //  TRAPINT
  {NULL, NULL,       port1Vector}, //  Port 1
  {NULL, NULL,       port2Vector}, //  Port 2
  {NULL, NULL,       adc10Vector}, //  ADC10
  {NULL, NULL,   usciab0txVector}, //  USCI A0/B0 Transmit
  {NULL, NULL,   usciab0rxVector}, //  USCI A0/B0 Receive
  {NULL, NULL,    timer0A1Vector}, //  Timer0_A CC0
  {NULL, NULL,    timer0A0Vector}, //  Timer0_A CC1, TA0
  {NULL, NULL,         wdtVector}, //  Watchdog Timer
  {NULL, NULL, comparatorAVector}, //  Comparator A
  {NULL, NULL,    timer1A1Vector}, //  Timer1_A CC1-4, TA1
  {NULL, NULL,    timer1A0Vector}, //  Timer1_A CC0
  {NULL, NULL,         nmiVector}, //  Non-maskable
  {NULL, NULL,       resetVector}  //  Reset [Highest Priority]
};

volatile uint8* const pu_PXIFG_ADDR[2] = { u_P1IFG_ADDR, u_P1IFG_ADDR };

void ICU_v_Init(void)
{
  REG_v_Set8BitReg(u_P1IFG_ADDR, 0u);
  REG_v_Set8BitReg(u_P2IFG_ADDR, 0u);
}

void ICU_v_SetupISR(const t_VectorIntId e_vectorId,
                    const t_IntHandler  p_callbackFunc,
                    void* const         p_callbackDataRef)
{
  // Check if the callback function is valid (not NULL)...CallbackDataRef is not checked,
  // because in some cases maybe there are no data needed in the interrupt handler
  // than the CallbackDataRef = NULL
  if(p_callbackFunc != NULL)
  {
    t_vectorTableEntry[e_vectorId].p_callbackFunc    = p_callbackFunc;
    t_vectorTableEntry[e_vectorId].p_callbackDataRef = p_callbackDataRef;
  }
  else
  {
    // report error, wrong calling parameter:
    // callback function or CallbackDataRef are a NULL pointer
  }
}

void __attribute__((interrupt(PORT1_VECTOR))) ICU_v_Port1(void)
{
  (*(t_vectorTableEntry[port1Vector].p_callbackFunc))(t_vectorTableEntry[port1Vector].p_callbackDataRef);
}

void __attribute__((interrupt(PORT2_VECTOR))) ICU_v_Port2(void)
{
  (*(t_vectorTableEntry[port2Vector].p_callbackFunc))(t_vectorTableEntry[port2Vector].p_callbackDataRef);
}

__attribute__((interrupt(TIMER0_A0_VECTOR))) void ICU_v_Timer0A0_ISR(void)
{
  (*(t_vectorTableEntry[timer0A0Vector].p_callbackFunc))(t_vectorTableEntry[timer0A0Vector].p_callbackDataRef);
}

__attribute__((interrupt(TIMER0_A1_VECTOR))) void ICU_v_Timer0A1_ISR(void)
{
  (*(t_vectorTableEntry[timer0A1Vector].p_callbackFunc))(t_vectorTableEntry[timer0A1Vector].p_callbackDataRef);
}

__attribute__((interrupt(TIMER1_A0_VECTOR))) void ICU_v_Timer1A0_ISR(void)
{
  (*(t_vectorTableEntry[timer1A0Vector].p_callbackFunc))(t_vectorTableEntry[timer1A0Vector].p_callbackDataRef);
}

__attribute__((interrupt(TIMER1_A1_VECTOR))) void ICU_v_Timer1A1_ISR(void)
{
  (*(t_vectorTableEntry[timer1A1Vector].p_callbackFunc))(t_vectorTableEntry[timer1A1Vector].p_callbackDataRef);
}

#ifdef __cplusplus
}
#endif
