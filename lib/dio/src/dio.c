/**********************************************************************************************************************
 * \file dio.c
 *
 * \author  Marco Aguilar
 *
 * \date Jul-11-2023
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the GPIO Driver
 *********************************************************************************************************************/

#include <dio.h>
#include <gpio.h>
#include <msp430g2553_registers.h>
#include <register_utils.h>

#ifdef __cplusplus
extern "C" {
#endif

volatile uint16* const pu_PXIE_ADDR[2]  = { u_P1IE_ADDR, u_P2IE_ADDR };
volatile uint16* const pu_PXIES_ADDR[2] = { u_P1IES_ADDR, u_P2IES_ADDR };

t_DioInst DIO_v_SetInstance(t_Port e_port, t_Pin e_pin, t_PinDir e_dir)
{
  t_DioInst t_dioInstance;
  t_dioInstance.e_port = e_port;
  t_dioInstance.e_pin  = e_pin;
  t_dioInstance.e_dir  = e_dir;
  GPIO_v_SetUpPin(e_port, e_pin, e_dir, dio);
  return t_dioInstance;
}

void DIO_v_WriteBit(t_DioInst t_dio, t_PinState e_state)
{
  GPIO_v_WritePin(t_dio.e_port, t_dio.e_pin, e_state);
}

t_PinState DIO_t_ReadBit(t_DioInst t_dio)
{
  return GPIO_t_ReadPin(t_dio.e_port, t_dio.e_pin);
}

void DIO_v_PinIntEn(t_DioInst t_dio, t_EdgeSelect e_edgeMode)
{
  if(input == t_dio.e_dir)
  {
    REG_v_SetBit(pu_PXIE_ADDR[t_dio.e_port], t_dio.e_pin);
    (risingEdge == e_edgeMode) ? REG_v_ClearBit(pu_PXIES_ADDR[t_dio.e_port], t_dio.e_pin) : REG_v_SetBit(pu_PXIES_ADDR[t_dio.e_port], t_dio.e_pin);
  }
  else
  {
    // IED Implementation Error Detection
    // pinNotInput;
  }
}

void DIO_v_PinIntDis(t_DioInst t_dio)
{
  if(input == t_dio.e_dir)
  {
    if(enable == REG_u_ReadBit(pu_PXIE_ADDR[t_dio.e_port], t_dio.e_pin))
    {
      REG_v_ClearBit(pu_PXIE_ADDR[t_dio.e_port], t_dio.e_pin);
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

#ifdef __cplusplus
}
#endif