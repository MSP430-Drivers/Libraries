#include <MSP430_Registers.h>
#include <Dio.h>
#include <register_utils.h>

int main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    // DIO_v_init();
    // (void)DIO_u_configPin(bit0, port1, output, gpio, disabled);
    // (void)DIO_u_configPin(bit6, port1, output, gpio, disabled);
    // (void)DIO_u_setPinState(bit0, port1, high);
    // (void)DIO_u_setPinState(bit6, port1, high);
    // testFunc();
    while (1)
    {
        
    }
}