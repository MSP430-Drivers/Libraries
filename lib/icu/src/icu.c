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

#ifdef __cplusplus
extern "C" {
#endif

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

void __attribute__((interrupt(PORT1_VECTOR))) ICU_v_port1(void)
{
  t_vectorTableEntry[port1].p_callbackFunc;
}

#ifdef __cplusplus
}
#endif
