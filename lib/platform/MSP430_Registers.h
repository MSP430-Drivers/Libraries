/**********************************************************************************************************************
 * \file MSP430_Registers.h
 *
 * \author  Marco Aguilar
 *
 * \date Jul-16-2022
 *
 * \version 1.0 \n \n
 *
 * This file contains:
 *  - Definitions
 *  - Types
 *  - Interface Prototypes
 *  which are relevant for the ADC driver
 *********************************************************************************************************************/

#include <Std_Types.h>

#ifndef MSP430_REGISTERS_H
#define MSP430_REGISTERS_H

#ifdef __cplusplus
extern "C" {
#endif

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define REG_8BITS(address)  *(uint8*)address  ///< De-refenrece for 8bits register

/************************************************************
 * DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 ************************************************************/
#define P1IN_ADDR   (uint16)0x0020u ///< Port 1 Input Address
#define P1OUT_ADDR  (uint16)0x0021u ///< Port 1 Output Address
#define P1DIR_ADDR  (uint16)0x0022u ///< Port 1 Direction Address
#define P1IFG_ADDR  (uint16)0x0023u ///< Port 1 Interrupt Flag Address
#define P1IES_ADDR  (uint16)0x0024u ///< Port 1 Interrupt Edge Select Address
#define P1IE_ADDR   (uint16)0x0025u ///< Port 1 Interrupt Enable Address
#define P1SEL_ADDR  (uint16)0x0026u ///< Port 1 Port Select Address
#define P1SEL2_ADDR (uint16)0x0041u ///< Port 1 Port Select2 Address
#define P1REN_ADDR  (uint16)0x0027u ///< Port 1 Resistor Enable Address
#define P2IN_ADDR   (uint16)0x0028u ///< Port 2 Input Address
#define P2OUT_ADDR  (uint16)0x0029u ///< Port 2 Output Address
#define P2DIR_ADDR  (uint16)0x002Au ///< Port 2 Direction Address
#define P2IFG_ADDR  (uint16)0x002Bu ///< Port 2 Interrupt Flag Address
#define P2IES_ADDR  (uint16)0x002Cu ///< Port 2 Interrupt Edge Select Address
#define P2IE_ADDR   (uint16)0x002Du ///< Port 2 Interrupt Enable Address
#define P2SEL_ADDR  (uint16)0x002Eu ///< Port 2 Port Select Address
#define P2SEL2_ADDR (uint16)0x0042u ///< Port 2 Port Select2 Address
#define P2REN_ADDR  (uint16)0x002Fu ///< Port 2 Resistor Enable Address

#define P1IN        REG_8BITS(P1IN_ADDR)   ///< Port 1 Input
#define P1OUT       REG_8BITS(P1OUT_ADDR)  ///< Port 1 Output
#define P1DIR       REG_8BITS(P1DIR_ADDR)  ///< Port 1 Direction
#define P1IFG       REG_8BITS(P1IFG_ADDR)  ///< Port 1 Interrupt Flag
#define P1IES       REG_8BITS(P1IES_ADDR)  ///< Port 1 Interrupt Edge Select
#define P1IE        REG_8BITS(P1IE_ADDR)   ///< Port 1 Interrupt Enable
#define P1SEL       REG_8BITS(P1SEL_ADDR)  ///< Port 1 Port Select
#define P1SEL2      REG_8BITS(P1SEL2_ADDR) ///< Port 1 Port Select2
#define P1REN       REG_8BITS(P1REN_ADDR)  ///< Port 1 Resistor Enable
#define P2IN        REG_8BITS(P2IN_ADDR)   ///< Port 2 Input
#define P2OUT       REG_8BITS(P2OUT_ADDR)  ///< Port 2 Output
#define P2DIR       REG_8BITS(P2DIR_ADDR)  ///< Port 2 Direction
#define P2IFG       REG_8BITS(P2IFG_ADDR)  ///< Port 2 Interrupt Flag
#define P2IES       REG_8BITS(P2IES_ADDR)  ///< Port 2 Interrupt Edge Select
#define P2IE        REG_8BITS(P2IE_ADDR)   ///< Port 2 Interrupt Enable
#define P2SEL       REG_8BITS(P2SEL_ADDR)  ///< Port 2 Port Select
#define P2SEL2      REG_8BITS(P2SEL2_ADDR) ///< Port 2 Port Select2
#define P2REN       REG_8BITS(P2REN_ADDR)  ///< Port 2 Resistor Enable

/************************************************************
 * WATCHDOG TIMER
 ************************************************************/
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer

/************************************************************
 * Basic Clock Module
 ************************************************************/
#define DCOCTL_ADDR  (uint16)0x0056u ///< DCO control address
#define BCSCTL1_ADDR (uint16)0x0057u ///< Basic clock system control 1 address
#define BCSCTL2_ADDR (uint16)0x0058u ///< Basic clock system control 2 address
#define BCSCTL3_ADDR (uint16)0x0053u ///< Basic clock system control 3 address

#define DCOCTL       REG_8BITS(DCOCTL_ADDR)  ///< DCO control register
#define BCSCTL1      REG_8BITS(BCSCTL1_ADDR) ///< Basic clock system control 1
#define BCSCTL2      REG_8BITS(BCSCTL2_ADDR) ///< Basic clock system control 2
#define BCSCTL3      REG_8BITS(BCSCTL3_ADDR) ///< Basic clock system control 3

/************************************************************
 * Calibration Data in Info Mem
 ************************************************************/
#define CALDCO_16MHZ_ADDR (uint16)0x10F8 ///< Address for the DCOCTL
#define CALBC1_16MHZ_ADDR (uint16)0x10F9 ///< Address for the BCSCTL1
#define CALDCO_12MHZ_ADDR (uint16)0x10FA ///< Address for the DCOCTL
#define CALBC1_12MHZ_ADDR (uint16)0x10FB ///< Address for the BCSCTL1
#define CALDCO_8MHZ_ADDR  (uint16)0x10FC ///< Address for the DCOCTL
#define CALBC1_8MHZ_ADDR  (uint16)0x10FD ///< Address for the BCSCTL1
#define CALDCO_1MHZ_ADDR  (uint16)0x10FE ///< Address for the DCOCTL
#define CALBC1_1MHZ_ADDR  (uint16)0x10FF ///< Address for the BCSCTL1

#define CALDCO_16MHZ      REG_8BITS(CALDCO_16MHZ_ADDR) ///< Value for the DCOCTL register for 16 MHz, TA = 25°C
#define CALBC1_16MHZ      REG_8BITS(CALBC1_16MHZ_ADDR) ///< Value for the BCSCTL1 register for 16 MHz, TA = 25°C
#define CALDCO_12MHZ      REG_8BITS(CALDCO_12MHZ_ADDR) ///< Value for the DCOCTL register for 12 MHz, TA = 25°C
#define CALBC1_12MHZ      REG_8BITS(CALBC1_12MHZ_ADDR) ///< Value for the BCSCTL1 register for 12 MHz, TA = 25°C
#define CALDCO_8MHZ       REG_8BITS(CALDCO_8MHZ_ADDR)  ///< Value for the DCOCTL register for 8 MHz, TA = 25°C
#define CALBC1_8MHZ       REG_8BITS(CALBC1_8MHZ_ADDR)  ///< Value for the BCSCTL1 register for 8 MHz, TA = 25°C
#define CALDCO_1MHZ       REG_8BITS(CALDCO_1MHZ_ADDR)  ///< Value for the DCOCTL register for 1 MHz, TA = 25°C
#define CALBC1_1MHZ       REG_8BITS(CALBC1_1MHZ_ADDR)  ///< Value for the BCSCTL1 register for 1 MHz, TA = 25°C

/************************************************************
 * STATUS REGISTER BITS
 ************************************************************/

#define C      (uint16)0x0001u
#define Z      (uint16)0x0002u
#define N      (uint16)0x0004u
#define V      (uint16)0x0100u
#define GIE    (uint16)0x0008u
#define CPUOFF (uint16)0x0010u
#define OSCOFF (uint16)0x0020u
#define SCG0   (uint16)0x0040u
#define SCG1   (uint16)0x0080u
/* Low Power Modes coded with Bits 4-7 in SR */
#define LPM0 (CPUOFF)
#define LPM1 (SCG0 + CPUOFF)
#define LPM2 (SCG1 + CPUOFF)
#define LPM3 (SCG1 + SCG0 + CPUOFF)
#define LPM4 (SCG1 + SCG0 + OSCOFF + CPUOFF)

/************************************************************
 * TimerA
 ************************************************************/
#define TA0IV_ADDR    (uint16)0x012Eu
#define TA0CTL_ADDR   (uint16)0x0160u
#define TA0CCTL0_ADDR (uint16)0x0162u
#define TA0CCTL1_ADDR (uint16)0x0164u
#define TA0CCTL2_ADDR (uint16)0x0166u
#define TA0R_ADDR     (uint16)0x0170u
#define TA0CCR0_ADDR  (uint16)0x0172u
#define TA0CCR1_ADDR  (uint16)0x0174u
#define TA0CCR2_ADDR  (uint16)0x0176u

#define TA0IV         REG_16BITS(TA0IV_ADDR)
#define TA0CTL        REG_16BITS(TA0CTL_ADDR)
#define TA0CCTL0      REG_16BITS(TA0CCTL0_ADDR)
#define TA0CCTL1      REG_16BITS(TA0CCTL1_ADDR)
#define TA0CCTL2      REG_16BITS(TA0CCTL2_ADDR)
#define TA0R          REG_16BITS(TA0R_ADDR)
#define TA0CCR0       REG_16BITS(TA0CCR0_ADDR)
#define TA0CCR1       REG_16BITS(TA0CCR1_ADDR)
#define TA0CCR2       REG_16BITS(TA0CCR2_ADDR)

/************************************************************
 * Interrupt Vectors (offset from 0xFFE0)
 ************************************************************/

#define TRAPINT_VECTOR     (1)       /* 0xFFE0 TRAPINT */
#define PORT1_VECTOR       (3)       /* 0xFFE4 Port 1 */
#define PORT2_VECTOR       (4)       /* 0xFFE6 Port 2 */
#define ADC10_VECTOR       (6)       /* 0xFFEA ADC10 */
#define USCIAB0TX_VECTOR   (7)       /* 0xFFEC USCI A0/B0 Transmit */
#define USCIAB0RX_VECTOR   (8)       /* 0xFFEE USCI A0/B0 Receive */
#define TIMER0_A1_VECTOR   (9)       /* 0xFFF2 Timer0_A CC0 */
#define TIMER0_A0_VECTOR   (10)       /* 0xFFF0 Timer0_A CC1, TA0 */
#define WDT_VECTOR         (11)      /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR (12)      /* 0xFFF6 Comparator A */
#define TIMER1_A1_VECTOR   (13)      /* 0xFFF8 Timer1_A CC1-4, TA1 */
#define TIMER1_A0_VECTOR   (14)      /* 0xFFFA Timer1_A CC0 */
#define NMI_VECTOR         (15)      /* 0xFFFC Non-maskable */
#define RESET_VECTOR       (16) /* 0xFFFE Reset [Highest Priority] */

#ifdef __cplusplus
}
#endif

#endif
