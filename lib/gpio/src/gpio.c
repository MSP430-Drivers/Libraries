/**********************************************************************************************************************
 * \file gpio.c
 *
 * \author  Marco Aguilar
 *
 * \date Jun-19-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the DIO Driver
 *********************************************************************************************************************/

#include <gpio.h>
#include <msp430g2553_registers.h>
#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

static uint8 u_DioIsInitialized;


uint8 DIO_u_Init(void)
{
    uint8 u_retVal = 0u;
    if(!u_DioIsInitialized)
    {
        // Low consumption for unused pins
        REG_v_WriteToReg(u_P1DIR_ADDR,input);
        REG_v_WriteToReg(u_P2DIR_ADDR,input);
        REG_v_WriteToReg(u_P1OUT_ADDR,input);
        REG_v_WriteToReg(u_P2OUT_ADDR,input);

        // Datashet recomend enable Internal resistor
        REG_v_WriteToReg(u_P1REN_ADDR,0xFFu);
        REG_v_WriteToReg(u_P2REN_ADDR,0xFFu);

        u_DioIsInitialized = u_True;
    }
    else
    {
        u_retVal = u_dioDeinitialized;
    }
  
  return u_retVal;  
}


#ifdef __cplusplus
}
#endif
