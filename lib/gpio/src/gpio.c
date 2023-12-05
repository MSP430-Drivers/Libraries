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

volatile uint8* const pu_PXDIR_ADDR[2]  = { u_P1DIR_ADDR, u_P2DIR_ADDR };
volatile uint8* const pu_PXREN_ADDR[2]  = { u_P1REN_ADDR, u_P2REN_ADDR };
volatile uint8* const pu_PXOUT_ADDR[2]  = { u_P1OUT_ADDR, u_P2OUT_ADDR };
volatile uint8* const pu_PXIN_ADDR[2]   = { u_P1IN_ADDR, u_P1IN_ADDR };
volatile uint8* const pu_PXSEL_ADDR[2]  = { u_P1SEL_ADDR, u_P2SEL_ADDR };
volatile uint8* const pu_PXSEL2_ADDR[2] = { u_P1SEL2_ADDR, u_P2SEL2_ADDR };
volatile uint8* const pu_PXIE_ADDR[2]   = { u_P1IE_ADDR, u_P2IE_ADDR };
volatile uint8* const pu_PXIES_ADDR[2]  = { u_P1IES_ADDR, u_P2IES_ADDR };

uint8        au_portPinStat[portMax][pinMax] = { { pinNotInit } };
static uint8 u_DioIsInitialized;

static void GPIO_v_ResConf(t_GPIO_PinDescriptor* self);

static void GPIO_v_ResConf(t_GPIO_PinDescriptor* self)
{
  if(e_INPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[self->e_port], self->e_pin))
  {
    if(self->e_resistor == e_RES_EN)
    {
      REG_v_SetBitIn8BitReg(pu_PXREN_ADDR[self->e_port], (uint16)self->e_pin);
      if(self->e_resType == e_PULL_UP)
      {
        REG_v_SetBitIn8BitReg(pu_PXOUT_ADDR[self->e_port], (uint16)self->e_pin);
      }
      else
      {
        REG_v_ClearBitIn8BitReg(pu_PXOUT_ADDR[self->e_port], (uint16)self->e_pin);
      }
    }
    else
    {
      REG_v_ClearBitIn8BitReg(pu_PXREN_ADDR[self->e_port], (uint16)self->e_pin);
    }
  }
  else
  {
    // IED Implementation Error Detection
    // pinNotInput;
  }
}

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

t_GPIO_PinDescriptor GPIO_t_NewInstance(t_Port e_port, t_Pin e_pin, t_PinDir e_pinDir, t_FunctionSelect e_funcSel, t_Ren e_res, t_ResType e_resType)
{
  t_GPIO_PinDescriptor t_retInstance;
  t_retInstance.e_port     = e_port;
  t_retInstance.e_pin      = e_pin;
  t_retInstance.e_dir      = e_pinDir;
  t_retInstance.e_function = e_funcSel;
  t_retInstance.e_resistor = e_res;
  t_retInstance.e_resType  = e_resType;
  return t_retInstance;
}

// DIR: 0-> input; 1-> output
void GPIO_v_SetUpPin(t_GPIO_PinDescriptor* self)
{
  if(u_True == u_DioIsInitialized)
  {
    if(au_portPinStat[self->e_port][self->e_pin] != pinConf)
    {
      if(e_OUTPUT == self->e_dir)
      {
        REG_v_SetBitIn8BitReg(pu_PXDIR_ADDR[self->e_port], self->e_pin);
      }
      else
      {
        REG_v_ClearBitIn8BitReg(pu_PXDIR_ADDR[self->e_port], self->e_pin);
      }
      REG_v_ClearBitIn8BitReg(pu_PXREN_ADDR[self->e_port], self->e_pin); // disable internal resistor for both input and output dir
      switch(self->e_function)
      {
        case e_PIN_PRIMARY:
          REG_v_ClearBitIn8BitReg(pu_PXSEL2_ADDR[self->e_port], self->e_pin);
          REG_v_SetBitIn8BitReg(pu_PXSEL_ADDR[self->e_port], self->e_pin);
          break;
        case e_PIN_SECONDARY:
          REG_v_SetBitIn8BitReg(pu_PXSEL2_ADDR[self->e_port], self->e_pin);
          REG_v_SetBitIn8BitReg(pu_PXSEL_ADDR[self->e_port], self->e_pin);
          break;
        default:
          REG_v_ClearBitIn8BitReg(pu_PXSEL2_ADDR[self->e_port], self->e_pin);
          REG_v_ClearBitIn8BitReg(pu_PXSEL_ADDR[self->e_port], self->e_pin);
          break;
      }
      GPIO_v_ResConf(self);
      au_portPinStat[self->e_port][self->e_pin] = pinConf;
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

t_PinState GPIO_t_ReadPin(t_GPIO_PinDescriptor* self)
{
  t_PinState e_retState = e_LOW;
  if(au_portPinStat[self->e_port][self->e_pin] == pinConf)
  {
    if(e_INPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[self->e_port], self->e_pin))
    {
      e_retState = REG_u_GetBitIn8BitReg(pu_PXIN_ADDR[self->e_port], self->e_pin);
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

void GPIO_v_WritePin(t_GPIO_PinDescriptor* self, t_PinState e_pinState)
{
  if(au_portPinStat[self->e_port][self->e_pin] == pinConf)
  {
    if(e_OUTPUT == (uint8)REG_u_GetBitIn8BitReg(pu_PXDIR_ADDR[self->e_port], self->e_pin))
    {
      if(e_pinState == e_HIGH)
      {
        REG_v_SetBitIn8BitReg(pu_PXOUT_ADDR[self->e_port], (uint16)self->e_pin);
      }
      else
      {
        REG_v_ClearBitIn8BitReg(pu_PXOUT_ADDR[self->e_port], (uint16)self->e_pin);
      }
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

void GPIO_v_PinIntEn(t_GPIO_PinDescriptor* self, t_EdgeSelect e_edgeMode)
{
  if((e_INPUT == self->e_dir) && (self->e_function == e_PIN_DIO))
  {
    REG_v_SetBitIn8BitReg(pu_PXIE_ADDR[self->e_port], self->e_pin);
    if(e_RISING_EDGE == e_edgeMode)
    {
      REG_v_ClearBitIn8BitReg(pu_PXIES_ADDR[self->e_port], self->e_pin);
    }
    else
    {
      REG_v_SetBitIn8BitReg(pu_PXIES_ADDR[self->e_port], self->e_pin);
    }
  }
  else
  {
    // IED Implementation Error Detection
    // pinNotInput;
  }
}

void GPIO_v_PinIntDis(t_GPIO_PinDescriptor* self)
{
  if(e_INPUT == self->e_dir)
  {
    if(1u == REG_u_GetBitIn8BitReg(pu_PXIE_ADDR[self->e_port], self->e_pin)) // if interrupt is enable
    {
      REG_v_ClearBitIn8BitReg(pu_PXIE_ADDR[self->e_port], self->e_pin);
    }
    else
    {
      // IED Implementation Error Detection
      // noBitIntEn;
    }
  }
  else
  {
    // IED Implementation Error Detection
    // pinNotInput;
  }
}

void GPIO_v_DeInit(void)
{
  if(u_DioIsInitialized)
  {
    u_DioIsInitialized = u_False;
  }
  else
  {
    // IED Implementation Error Detection
    // gpioNotInitialized;
  }
}

#ifdef __cplusplus
}
#endif
