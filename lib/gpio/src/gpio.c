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

static uint8           u_DioIsInitialized;
volatile uint16* const pu_PXDIR_ADDR[2]  = { u_P1DIR_ADDR, u_P2DIR_ADDR };
volatile uint16* const pu_PXREN_ADDR[2]  = { u_P1REN_ADDR, u_P2REN_ADDR };
volatile uint16* const pu_PXOUT_ADDR[2]  = { u_P1OUT_ADDR, u_P2OUT_ADDR };
volatile uint16* const pu_PXIN_ADDR[2]   = { u_P1IN_ADDR, u_P1IN_ADDR };
volatile uint16* const pu_PXSEL_ADDR[2]  = { u_P1SEL_ADDR, u_P2SEL_ADDR };
volatile uint16* const pu_PXSEL2_ADDR[2] = { u_P1SEL2_ADDR, u_P2SEL2_ADDR };

void GPIO_v_Init(void)
{
  if(!u_DioIsInitialized)
  {
    uint8 u_indexPin;
    uint8 u_indexPort;
    // Low consumption for unused pins
    REG_v_WriteToReg(u_P1DIR_ADDR, input);
    REG_v_WriteToReg(u_P2DIR_ADDR, input);
    REG_v_WriteToReg(u_P1OUT_ADDR, input);
    REG_v_WriteToReg(u_P2OUT_ADDR, input);

    // Datashet recomend enable Internal resistor
    REG_v_WriteToReg(u_P1REN_ADDR, 0xFFu);
    REG_v_WriteToReg(u_P2REN_ADDR, 0xFFu);

    for(u_indexPin = 0u; u_indexPin < pinMax; u_indexPin++)
    {
      for(u_indexPort = 0u; u_indexPort < portMax; u_indexPort++)
      {
        au_portPinStat[u_indexPort][u_indexPin] = pinInit; // Is initialized and ready to be configured
      }
    }
    u_DioIsInitialized = u_True;
  }
  else
  {
    // IED Implementation Error Detection
    // dioDeinitialized;
  }
}

void GPIO_v_SetUpPin(t_Port e_port, t_Pin e_pin, t_PinDir e_dir, t_FunctionSelect e_funSel)
{
  if(u_True == u_DioIsInitialized)
  {
    if(au_portPinStat[e_port][e_pin] != pinConf)
    {
      if(output == e_dir)
      {
        REG_v_ClearBit(pu_PXREN_ADDR[e_port], e_pin);
        REG_v_SetBit(pu_PXDIR_ADDR[e_port], e_pin);
      }
      else
      {
        REG_v_ClearBit(pu_PXDIR_ADDR[e_port], e_pin);
      }
      switch(e_funSel)
      {
        case primary:
          REG_v_ClearBit(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_SetBit(pu_PXSEL_ADDR[e_port], e_pin);
          break;
        case secondary:
          REG_v_SetBit(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_SetBit(pu_PXSEL_ADDR[e_port], e_pin);
          break;
        default:
          REG_v_ClearBit(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_ClearBit(pu_PXSEL_ADDR[e_port], e_pin);
          break;
      }
      au_portPinStat[e_port][e_pin] = pinConf;
    }
    else
    {
      // IED Implementation Error Detection
      // pinDeInit;
    }
  }
  else
  {
    // IED Implementation Error Detection
    // gpioNotInit;
  }
}

void GPIO_v_ResConf(t_Port e_port, t_Pin e_pin, t_Ren e_ren, t_ResType e_resType)
{
  if(au_portPinStat[e_port][e_pin] == pinConf)
  {
    if(input == (uint8)REG_u_ReadBit(pu_PXDIR_ADDR[e_port], e_pin))
    {
      (e_ren == enable) ? REG_v_SetBit(pu_PXREN_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBit(pu_PXREN_ADDR[e_port], (uint16)e_pin);
      (e_resType == pullUp) ? REG_v_SetBit(pu_PXOUT_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBit(pu_PXOUT_ADDR[e_port], (uint16)e_pin);
    }
    else
    {
      // IED Implementation Error Detection
      // pinNotInput;
    }
  }
  else
  {
    // IED Implementation Error Detection
    // pinNotConf
  }
}

t_PinState GPIO_t_ReadPin(t_Port e_port, t_Pin e_pin)
{
  t_PinState e_retState = low;
  if(au_portPinStat[e_port][e_pin] == pinConf)
  {
    if(input == (uint8)REG_u_ReadBit(pu_PXDIR_ADDR[e_port], e_pin))
    {
      e_retState = REG_u_ReadBit(pu_PXIN_ADDR[e_port], e_pin);
    }
    else
    {
      // IED Implementation Error Detection
      // e_retVal = pinNotInput;
    }
  }
  else
  {
    // IED Implementation Error Detection
    // e_retVal = pinNotConf;
  }
  return e_retState;
}

void GPIO_v_WritePin(t_Port e_port, t_Pin e_pin, t_PinState e_pinState)
{
  if(au_portPinStat[e_port][e_pin] == pinConf)
  {
    if(output == (uint8)REG_u_ReadBit(pu_PXDIR_ADDR[e_port], e_pin))
    {
      (e_pinState == high) ? REG_v_SetBit(pu_PXOUT_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBit(pu_PXOUT_ADDR[e_port], (uint16)e_pin);
    }
    else
    {
      // IED Implementation Error Detection
      // pinNotoutput
    }
  }
  else
  {
    // IED Implementation Error Detection
    // e_retVal = pinNotConf;
  }
}

#ifdef __cplusplus
}
#endif
