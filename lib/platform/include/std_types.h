/**********************************************************************************************************************
 * \file Std_Types.h
 *
 * \author  Marco Aguilar
 *
 * \date Jul-16-2022
 *
 * \version 1.1 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  which are relevant for std types
 *********************************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#define NULL ((void*)0)

typedef signed char   sint8;
typedef unsigned char uint8;

typedef signed short int   sint16;
typedef unsigned short int uint16;

typedef signed long int   sint32;
typedef unsigned long int uint32;

static const uint8 u_True  = 1u;
static const uint8 u_False = 0u;
static const uint8 u_OK    = 0u;
static const uint8 u_NOK   = 0u;

#ifdef __cplusplus
}
#endif

#endif