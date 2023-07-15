/**********************************************************************************************************************
 * \file dio.h
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

#ifndef DIO_H
#define DIO_H

#include <gpio_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  t_Port   e_port;
  t_Pin    e_pin;
  t_PinDir e_dir;
} t_DioInst;

t_DioInst DIO_v_SetInstance(t_Port e_port, t_Pin e_pin, t_PinDir e_dir);

void DIO_v_WriteBit(t_DioInst t_dio, t_PinState e_state);

t_PinState DIO_t_ReadBit(t_DioInst t_dio);

void DIO_v_PinIntEn(t_DioInst t_dio, t_EdgeSelect e_edgeMode);

#ifdef __cplusplus
}
#endif

#endif