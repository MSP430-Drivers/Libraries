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

static uint8          u_DioIsInitialized;
uint8                 au_portPinStat[portMax][pinMax] = { { pinNotInit } };
volatile uint8* const pu_PXDIR_ADDR[2]                = { u_P1DIR_ADDR, u_P2DIR_ADDR };
volatile uint8* const pu_PXREN_ADDR[2]                = { u_P1REN_ADDR, u_P2REN_ADDR };
volatile uint8* const pu_PXOUT_ADDR[2]                = { u_P1OUT_ADDR, u_P2OUT_ADDR };
volatile uint8* const pu_PXIN_ADDR[2]                 = { u_P1IN_ADDR, u_P1IN_ADDR };
volatile uint8* const pu_PXSEL_ADDR[2]                = { u_P1SEL_ADDR, u_P2SEL_ADDR };
volatile uint8* const pu_PXSEL2_ADDR[2]               = { u_P1SEL2_ADDR, u_P2SEL2_ADDR };

void GPIO_v_Init(void)
{
  if(!u_DioIsInitialized)
  {
    uint8 u_indexPin;
    uint8 u_indexPort;
    // Low consumption for unused pins
    REG_v_Set8BitReg(u_P1DIR_ADDR, e_INPUT);
    REG_v_Set8BitReg(u_P2DIR_ADDR, e_INPUT);
    REG_v_Set8BitReg(u_P1OUT_ADDR, e_INPUT);
    REG_v_Set8BitReg(u_P2OUT_ADDR, e_INPUT);

    // Datashet recomend enable Internal resistor
    REG_v_Set8BitReg(u_P1REN_ADDR, 0xFFu);
    REG_v_Set8BitReg(u_P2REN_ADDR, 0xFFu);

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
      if(e_OUTPUT == e_dir)
      {
        REG_v_ClearBitIn8BitReg(pu_PXREN_ADDR[e_port], e_pin);
        REG_v_SetBitIn8BitReg(pu_PXDIR_ADDR[e_port], e_pin);
      }
      else
      {
        REG_v_ClearBitIn8BitReg(pu_PXDIR_ADDR[e_port], e_pin);
      }
      switch(e_funSel)
      {
        case e_PIN_PRIMARY:
          REG_v_ClearBitIn8BitReg(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_SetBitIn8BitReg(pu_PXSEL_ADDR[e_port], e_pin);
          break;
        case e_PIN_SECONDARY:
          REG_v_SetBitIn8BitReg(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_SetBitIn8BitReg(pu_PXSEL_ADDR[e_port], e_pin);
          break;
        default:
          REG_v_ClearBitIn8BitReg(pu_PXSEL2_ADDR[e_port], e_pin);
          REG_v_ClearBitIn8BitReg(pu_PXSEL_ADDR[e_port], e_pin);
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
    if(e_INPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[e_port], e_pin))
    {
      (e_ren == e_RES_EN) ? REG_v_SetBitIn8BitReg(pu_PXREN_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBitIn8BitReg(pu_PXREN_ADDR[e_port], (uint16)e_pin);
      (e_resType == e_PULL_UP) ? REG_v_SetBitIn8BitReg(pu_PXOUT_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBitIn8BitReg(pu_PXOUT_ADDR[e_port], (uint16)e_pin);
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
  t_PinState e_retState = e_LOW;
  if(au_portPinStat[e_port][e_pin] == pinConf)
  {
    if(e_INPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[e_port], e_pin))
    {
      e_retState = REG_u_GetBitIn8BitReg(pu_PXIN_ADDR[e_port], e_pin);
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
    if(e_OUTPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[e_port], e_pin))
    {
      (e_pinState == e_HIGH) ? REG_v_SetBitIn8BitReg(pu_PXOUT_ADDR[e_port], (uint16)e_pin) : REG_v_ClearBitIn8BitReg(pu_PXOUT_ADDR[e_port], (uint16)e_pin);
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
