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


uint8 DIO_u_Init(void);

#ifdef __cplusplus
}
#endif

#endif
