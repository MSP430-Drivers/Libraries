#include <gpio.h>
#include <gpio_types.h>
#include <dio.h>
#include <icu.h>
#include <register_utils.h>
#include <bcm.h>

#define REG_16BITS(address) *(uint16*)address ///< De-reference for 16bits register
#define WDTCTL REG_16BITS(0x0120u) ///< Watchdog Timer

void callBack(void* data);

int main()
{
    WDTCTL = 0x5A80 | 0x0080;   // Stop watchdog timer
    GPIO_v_Init();
    ICU_v_Init();
    BCM_v_DCOConf(freq_1Mhz);
    BCM_v_MCLKConf(dco,div_1);
    BCM_v_SMCLKConf(dco,div_8);
    BCM_v_ACLKConf(div_8);
    t_DioInst t_pb = DIO_v_SetInstance(port1,pin3,input);
    t_DioInst t_redLed = DIO_v_SetInstance(port1,pin6,output);
    // t_DioInst t_greenLed = DIO_v_SetInstance(port1,pin0,output);
    GPIO_v_SetUpPin(port1,pin4,output,primary);
    GPIO_v_SetUpPin(port1,pin0,output,primary);
    DIO_v_WriteBit(t_redLed,low);
    // DIO_v_WriteBit(t_greenLed,low);
    GPIO_v_ResConf(port1,pin3,disabled,pullUp);
    DIO_v_PinIntEn(t_pb,fallingEdge);
    ICU_v_SetupISR(port1Vector,callBack,&t_redLed);
    ICU_v_IntEn(u_GIE);
    while (1)
    {
        
    }
}

void callBack(void* data)
{   
    t_DioInst * myInst = (t_DioInst*)data;
    if(REG_u_ReadBit(u_P1IFG_ADDR,pin3) == high)
    {
        static t_PinState value = high;
        value ^= high;
        DIO_v_WriteBit(*myInst,value);
        REG_v_ClearBit(u_P1IFG_ADDR,pin3);
    }
}