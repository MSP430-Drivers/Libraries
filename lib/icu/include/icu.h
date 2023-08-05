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
  trapVector        = (uint8)0u,
  port1Vector       = (uint8)1u,
  port2Vector       = (uint8)2u,
  adc10Vector       = (uint8)3u,
  usciab0txVector   = (uint8)4u,
  usciab0rxVector   = (uint8)5u,
  timer0A1Vector    = (uint8)6u,
  timer0A0Vector    = (uint8)7u,
  wdtVector         = (uint8)8u,
  comparatorAVector = (uint8)9u,
  timer1A1Vector    = (uint8)10u,
  timer1A0Vector    = (uint8)11u,
  nmiVector         = (uint8)12u,
  resetVector       = (uint8)13u

} t_VectorIntId;

typedef struct
{
  t_IntHandler  p_callbackFunc;
  void*         p_callbackDataRef;
  t_VectorIntId e_vectorId;
} t_VectorTable;

extern t_VectorTable t_vectorTableEntry[MAX_INT_VECTOR];

static inline void ICU_v_IntEn(uint16 u_intMode)
{
  _BIS_SR(u_intMode);
}

static inline void ICU_v_IntDis(uint16 u_intMode)
{
  _BIC_SR(u_intMode);
}

void ICU_v_Init(void);

void ICU_v_SetupISR(const t_VectorIntId e_vectorId,
                    const t_IntHandler  p_callbackFunc,
                    void* const         p_callbackDataRef);

#ifdef __cplusplus
}
#endif

#endif