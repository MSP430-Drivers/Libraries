#ifndef MSP430G2553_REGISTERS_H
#define MSP430G2553_REGISTERS_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
 * DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 ************************************************************/
volatile uint16* const u_P1IN_ADDR   = (uint16*)0x0020u; ///< Port 1 Input Address
volatile uint16* const u_P1OUT_ADDR  = (uint16*)0x0021u; ///< Port 1 Output Address
volatile uint16* const u_P1DIR_ADDR  = (uint16*)0x0022u; ///< Port 1 Direction Address
volatile uint16* const u_P1IFG_ADDR  = (uint16*)0x0023u; ///< Port 1 Interrupt Flag Address
volatile uint16* const u_P1IES_ADDR  = (uint16*)0x0024u; ///< Port 1 Interrupt Edge Select Address
volatile uint16* const u_P1IE_ADDR   = (uint16*)0x0025u; ///< Port 1 Interrupt Enable Address
volatile uint16* const u_P1SEL_ADDR  = (uint16*)0x0026u; ///< Port 1 Port Select Address
volatile uint16* const u_P1SEL2_ADDR = (uint16*)0x0041u; ///< Port 1 Port Select2 Address
volatile uint16* const u_P1REN_ADDR  = (uint16*)0x0027u; ///< Port 1 Resistor Enable Address
volatile uint16* const u_P2IN_ADDR   = (uint16*)0x0028u; ///< Port 2 Input Address
volatile uint16* const u_P2OUT_ADDR  = (uint16*)0x0029u; ///< Port 2 Output Address
volatile uint16* const u_P2DIR_ADDR  = (uint16*)0x002Au; ///< Port 2 Direction Address
volatile uint16* const u_P2IFG_ADDR  = (uint16*)0x002Bu; ///< Port 2 Interrupt Flag Address
volatile uint16* const u_P2IES_ADDR  = (uint16*)0x002Cu; ///< Port 2 Interrupt Edge Select Address
volatile uint16* const u_P2IE_ADDR   = (uint16*)0x002Du; ///< Port 2 Interrupt Enable Address
volatile uint16* const u_P2SEL_ADDR  = (uint16*)0x002Eu; ///< Port 2 Port Select Address
volatile uint16* const u_P2SEL2_ADDR = (uint16*)0x0042u; ///< Port 2 Port Select2 Address
volatile uint16* const u_P2REN_ADDR  = (uint16*)0x002Fu; ///< Port 2 Resistor Enable Address

#ifdef __cplusplus
}
#endif

#endif