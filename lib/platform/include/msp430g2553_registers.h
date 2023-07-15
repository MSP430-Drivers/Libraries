#ifndef MSP430G2553_REGISTERS_H
#define MSP430G2553_REGISTERS_H

#include <std_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************
 * DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 ************************************************************/
static volatile uint16* const u_P1IN_ADDR   = (uint16*)0x0020u; ///< Port 1 Input Address
static volatile uint16* const u_P1OUT_ADDR  = (uint16*)0x0021u; ///< Port 1 Output Address
static volatile uint16* const u_P1DIR_ADDR  = (uint16*)0x0022u; ///< Port 1 Direction Address
static volatile uint16* const u_P1IFG_ADDR  = (uint16*)0x0023u; ///< Port 1 Interrupt Flag Address
static volatile uint16* const u_P1IES_ADDR  = (uint16*)0x0024u; ///< Port 1 Interrupt Edge Select Address
static volatile uint16* const u_P1IE_ADDR   = (uint16*)0x0025u; ///< Port 1 Interrupt Enable Address
static volatile uint16* const u_P1SEL_ADDR  = (uint16*)0x0026u; ///< Port 1 Port Select Address
static volatile uint16* const u_P1SEL2_ADDR = (uint16*)0x0041u; ///< Port 1 Port Select2 Address
static volatile uint16* const u_P1REN_ADDR  = (uint16*)0x0027u; ///< Port 1 Resistor Enable Address
static volatile uint16* const u_P2IN_ADDR   = (uint16*)0x0028u; ///< Port 2 Input Address
static volatile uint16* const u_P2OUT_ADDR  = (uint16*)0x0029u; ///< Port 2 Output Address
static volatile uint16* const u_P2DIR_ADDR  = (uint16*)0x002Au; ///< Port 2 Direction Address
static volatile uint16* const u_P2IFG_ADDR  = (uint16*)0x002Bu; ///< Port 2 Interrupt Flag Address
static volatile uint16* const u_P2IES_ADDR  = (uint16*)0x002Cu; ///< Port 2 Interrupt Edge Select Address
static volatile uint16* const u_P2IE_ADDR   = (uint16*)0x002Du; ///< Port 2 Interrupt Enable Address
static volatile uint16* const u_P2SEL_ADDR  = (uint16*)0x002Eu; ///< Port 2 Port Select Address
static volatile uint16* const u_P2SEL2_ADDR = (uint16*)0x0042u; ///< Port 2 Port Select2 Address
static volatile uint16* const u_P2REN_ADDR  = (uint16*)0x002Fu; ///< Port 2 Resistor Enable Address

/************************************************************
 * STATUS REGISTER BITS
 ************************************************************/

#define C (uint16)0x0001u
#define Z (uint16)0x0002u
#define N (uint16)0x0004u
#define V (uint16)0x0100u
// #define GIE    (uint16)0x0008u
// #define CPUOFF (uint16)0x0010u
// #define OSCOFF (uint16)0x0020u
// #define SCG0   (uint16)0x0040u
// #define SCG1   (uint16)0x0080u
// #define LPM0 (CPUOFF)
// #define LPM1 (SCG0 + CPUOFF)
// #define LPM2 (SCG1 + CPUOFF)
// #define LPM3 (SCG1 + SCG0 + CPUOFF)
// #define LPM4 (SCG1 + SCG0 + OSCOFF + CPUOFF)

static const uint16 u_GIE    = 0x0008u;
static const uint16 u_CPUOFF = 0x0010u;
static const uint16 u_OSCOFF = 0x0020u;
static const uint16 u_SCG0   = 0x0040u;
static const uint16 u_SCG1   = 0x0080u;
/* Low Power Modes coded with Bits 4-7 in SR */
static const uint16 u_LPM0 = u_CPUOFF;
static const uint16 u_LPM1 = u_SCG0 + u_CPUOFF;
static const uint16 u_LPM2 = u_SCG1 + u_CPUOFF;
static const uint16 u_LPM3 = u_SCG1 + u_SCG0 + u_CPUOFF;
static const uint16 u_LPM4 = u_SCG1 + u_SCG0 + u_OSCOFF + u_CPUOFF;

/************************************************************
 * Interrupt Vectors (offset from 0xFFE0)
 * The interrupt attribute requires a constant string or a
 * literal number, and macros are a common way to achieve this.
 ************************************************************/
#define TRAPINT_VECTOR     (uint8)1  //< 0xFFE0 TRAPINT
#define PORT1_VECTOR       (uint8)3  //< 0xFFE4 Port 1
#define PORT2_VECTOR       (uint8)4  //< 0xFFE6 Port 2
#define ADC10_VECTOR       (uint8)6  //< 0xFFEA ADC10
#define USCIAB0TX_VECTOR   (uint8)7  //< 0xFFEC USCI A0/B0 Transmit
#define USCIAB0RX_VECTOR   (uint8)8  //< 0xFFEE USCI A0/B0 Receive
#define TIMER0_A1_VECTOR   (uint8)9  //< 0xFFF2 Timer0_A CC0
#define TIMER0_A0_VECTOR   (uint8)10 //< 0xFFF0 Timer0_A CC1, TA0
#define WDT_VECTOR         (uint8)11 //< 0xFFF4 Watchdog Timer
#define COMPARATORA_VECTOR (uint8)12 //< 0xFFF6 Comparator A
#define TIMER1_A1_VECTOR   (uint8)13 //< 0xFFF8 Timer1_A CC1-4, TA1
#define TIMER1_A0_VECTOR   (uint8)14 //< 0xFFFA Timer1_A CC0
#define NMI_VECTOR         (uint8)15 //< 0xFFFC Non-maskable
#define RESET_VECTOR       (uint8)16 //< 0xFFFE Reset [Highest Priority]
#define MAX_INT_VECTOR     (uint8)14 //<

#ifdef __cplusplus
}
#endif

#endif