/**********************************************************************************************************************
 * \file gpio.h
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
 *  which are relevant for the GPIO Driver
 *********************************************************************************************************************/

#ifndef GPIO_H
#define GPIO_H

#include <gpio_types.h>
#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

static uint8 au_portPinStat[portMax][pinMax] = { { pinNotInit } };

void GPIO_u_Init(void);

void GPIO_t_SetUpPin(t_Port e_port, t_Pin e_pin, t_PinDir e_dir);

void GPIO_t_ResConf(t_Port e_port, t_Pin e_pin, t_Ren e_ren, t_ResType e_resType);

t_PinState GPIO_t_ReadPin(t_Port e_port, t_Pin e_pin);

void GPIO_t_WritePin(t_Port e_port, t_Pin e_pin, t_PinState e_pinState);

#ifdef __cplusplus
}
#endif

#endif
