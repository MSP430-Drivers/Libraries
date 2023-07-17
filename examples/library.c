#include <gpio.h>
#include <gpio_types.h>
#include <dio.h>
#include <icu.h>

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer

void callBack(void* data);

int main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    GPIO_v_Init();
    ICU_v_Init();
    t_DioInst t_pb = DIO_v_SetInstance(port1,pin3,input);
    GPIO_v_ResConf(port1,pin3,disabled,pullUp);
    DIO_v_PinIntEn(t_pb,fallingEdge);
    ICU_v_SetupISR(port1Vector,callBack,NULL);
    ICU_v_IntEn(u_GIE);
    while (1)
    {
        
    }
}

void callBack(void* data)
{   
    t_DioInst t_redLed = DIO_v_SetInstance(port1,pin6,output);
    DIO_v_WriteBit(t_redLed,high);
}