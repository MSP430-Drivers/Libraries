#include <gpio.h>
#include <gpio_types.h>
#include <dio.h>

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer


int main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    GPIO_v_Init();
    t_DioInst t_greenLed = DIO_v_GetInstance(port1,pin0);
    t_DioInst t_redLed = DIO_v_GetInstance(port1,pin6);
    DIO_v_SetBitMode(t_greenLed,output);
    DIO_v_SetBitMode(t_redLed,output);
    DIO_v_WriteBit(t_greenLed,high);
    DIO_v_WriteBit(t_redLed,high);
    while (1)
    {
        
    }
}