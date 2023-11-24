#include <gpio.h>
// #include <dio.h>
#include <icu.h>
#include <register_utils.h>
#include <bcm.h>
#include <platform_types.h>
#include <wdt.h>
#include <timer.h>

void callBack(void* data);
void callBackTimerA0(void* data);

int main()
{
    WDT_v_Stop();
    // GPIO_v_Init();
    // ICU_v_Init();
    // TIMER_v_Init();
    // BCM_v_DCOConf(e_FREQ1MHZ);
    // BCM_v_MCLKConf(e_CLK_DCO,e_DIV1);
    // BCM_v_SMCLKConf(e_CLK_DCO,e_DIV1);
    // BCM_v_ACLKConf(e_DIV1);
    // TIMER_v_Configure(e_TIMERA0,e_UP,e_SMCLK,e_DIV1);
    // TIMER_v_SetInstance(e_TIMERA0,e_COMPARE,e_SLOT0);
    // TIMER_v_EnableInterruptCC(e_TIMERA0,e_SLOT0);
    // REG_v_Set16BitReg(TA0CCR0_ADDR, 10000u);
    // t_DioInst t_pb = DIO_v_SetInstance(e_PORT1,e_PIN3,e_INPUT);
    // t_DioInst t_redLed = DIO_v_SetInstance(e_PORT1,e_PIN6,e_OUTPUT);
    // t_DioInst t_timerLed = DIO_v_SetInstance(e_PORT1,e_PIN1,e_OUTPUT);
    // t_DioInst t_greenLed = DIO_v_SetInstance(e_PORT1,e_PIN0,e_OUTPUT);
    // GPIO_v_SetUpPin(e_PORT1,e_PIN4,e_OUTPUT,e_PIN_PRIMARY);
    // GPIO_v_SetUpPin(e_PORT1,e_PIN0,e_OUTPUT,e_PIN_PRIMARY);
    // DIO_v_WriteBit(t_redLed,e_LOW);
    // DIO_v_WriteBit(t_timerLed,e_LOW);
    // DIO_v_WriteBit(t_greenLed,e_LOW);
    // GPIO_v_ResConf(e_PORT1,e_PIN3,e_RES_DIS,e_PULL_UP);
    // DIO_v_PinIntEn(t_pb,e_FALLING_EDGE);
    // ICU_v_SetupISR(port1Vector,callBack,&t_redLed);
    // ICU_v_SetupISR(timer0A0Vector,callBackTimerA0,&t_timerLed);
    // ICU_v_IntEn(u_GIE);
    while (1)
    {
        
    }
}

// void callBack(void* data)
// {   
//     t_DioInst * myInst = (t_DioInst*)data;
//     if(REG_u_GetBitIn8BitReg(u_P1IFG_ADDR,e_PIN3) == e_HIGH)
//     {
//         static t_PinState value = e_HIGH;
//         value ^= e_HIGH;
//         DIO_v_WriteBit(*myInst,value);
//         REG_v_ClearBitIn8BitReg(u_P1IFG_ADDR,e_PIN3);
//     }
// }

// void callBackTimerA0(void* data)
// {
//   t_DioInst * myInst = (t_DioInst*)data;
//   if(REG_u_GetBitIn16BitReg(TA0CCTL0_ADDR,0) == e_HIGH)
//   {
//     static t_PinState value = e_HIGH;
//     value ^= e_HIGH;
//     DIO_v_WriteBit(*myInst,value);
//     REG_v_ClearBitIn16BitReg(TA0CCTL0_ADDR,0);
//   }
// }