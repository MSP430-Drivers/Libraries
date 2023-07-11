// #include <MSP430_Registers.h>
#include <gpio.h>
#include <gpio_types.h>
// #include <register_utils.h>
// #include <msp430g2553_registers.h>

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer


int main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    GPIO_v_Init();
    GPIO_v_SetUpPin(port1,pin0,output,dio);
    GPIO_v_SetUpPin(port1,pin6,output,dio);
    GPIO_v_WritePin(port1,pin0,1);
    GPIO_v_WritePin(port1,pin6,1);
    GPIO_v_WritePin(port1,pin0,0);
    GPIO_v_WritePin(port1,pin6,0);
    while (1)
    {
        
    }
}