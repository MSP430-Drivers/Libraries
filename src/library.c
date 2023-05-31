#include <MSP430_Registers.h>

void main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    while (1)
    {
        
    }
}