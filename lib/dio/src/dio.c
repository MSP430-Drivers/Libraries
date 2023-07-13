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

#ifdef __cplusplus
extern "C" {
#endif

t_DioInst DIO_v_GetInstance(t_Port e_port, t_Pin e_pin)
{
  t_DioInst t_dioInstance;
  t_dioInstance.e_port = e_port;
  t_dioInstance.e_pin  = e_pin;
  return t_dioInstance;
}

void DIO_v_SetBitMode(t_DioInst t_dio, t_PinDir e_dir)
{
  GPIO_v_SetUpPin(t_dio.e_port, t_dio.e_pin, e_dir, dio);
}

void DIO_v_WriteBit(t_DioInst t_dio, t_PinState e_state)
{
  GPIO_v_WritePin(t_dio.e_port, t_dio.e_pin, e_state);
}

t_PinState DIO_t_ReadBit(t_DioInst t_dio)
{
  return GPIO_t_ReadPin(t_dio.e_port, t_dio.e_pin);
}

#ifdef __cplusplus
}
#endif