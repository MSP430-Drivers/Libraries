/**********************************************************************************************************************
 * \file icu.h
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

#ifndef ICU_H
#define ICU_H

#include <in430.h>
#include <msp430g2553_registers.h>
#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*t_IntHandler)(void* p_data);

typedef enum
{
  trap        = (uint8)0u,
  port1       = (uint8)1u,
  port2       = (uint8)2u,
  adc10       = (uint8)3u,
  usciab0tx   = (uint8)4u,
  usciab0rx   = (uint8)5u,
  timer0A1    = (uint8)6u,
  timer0A0    = (uint8)7u,
  wdt         = (uint8)8u,
  comparatorA = (uint8)9u,
  timer1A1    = (uint8)10u,
  timer1A0    = (uint8)11u,
  nmi         = (uint8)12u,
  reset       = (uint8)13u

} t_VectorIntId;

typedef struct
{
  t_IntHandler  p_callbackFunc;
  void*         p_callbackDataRef;
  t_VectorIntId e_vectorId;
} t_VectorTable;

t_VectorTable t_vectorTableEntry[MAX_INT_VECTOR] = {
  {NULL, NULL,     TRAPINT_VECTOR}, //  TRAPINT
  {NULL, NULL,       PORT1_VECTOR}, //  Port 1
  {NULL, NULL,       PORT2_VECTOR}, //  Port 2
  {NULL, NULL,       ADC10_VECTOR}, //  ADC10
  {NULL, NULL,   USCIAB0TX_VECTOR}, //  USCI A0/B0 Transmit
  {NULL, NULL,   USCIAB0RX_VECTOR}, //  USCI A0/B0 Receive
  {NULL, NULL,   TIMER0_A1_VECTOR}, //  Timer0_A CC0
  {NULL, NULL,   TIMER0_A0_VECTOR}, //  Timer0_A CC1, TA0
  {NULL, NULL,         WDT_VECTOR}, //  Watchdog Timer
  {NULL, NULL, COMPARATORA_VECTOR}, //  Comparator A
  {NULL, NULL,   TIMER1_A1_VECTOR}, //  Timer1_A CC1-4, TA1
  {NULL, NULL,   TIMER1_A0_VECTOR}, //  Timer1_A CC0
  {NULL, NULL,         NMI_VECTOR}, //  Non-maskable
  {NULL, NULL,       RESET_VECTOR}  //  Reset [Highest Priority]
};

static inline void ICU_v_IntEn(uint16 u_intMode)
{
  _BIS_SR(u_intMode);
}

static inline void ICU_v_IntDis(uint16 u_intMode)
{
  _BIC_SR(u_intMode);
}

#ifdef __cplusplus
}
#endif

#endif