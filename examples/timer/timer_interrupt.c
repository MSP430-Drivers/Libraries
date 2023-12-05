#include <bcm.h>
#include <gpio.h>
#include <icu.h>
#include <platform_types.h>
#include <register_utils.h>
#include <timer.h>
#include <wdt.h>

void callBackTimerA0(void* data);

int main()
{
  WDT_v_Stop();
  GPIO_v_Init();
  ICU_v_Init();
  TIMER_v_Init();
  BCM_v_DCOConf(e_FREQ1MHZ);
  BCM_v_MCLKConf(e_CLK_DCO, e_DIV1);
  BCM_v_SMCLKConf(e_CLK_DCO, e_DIV1);

  // t_DioInst t_timerLed = DIO_v_SetInstance(e_PORT1, e_PIN6, e_OUTPUT);
  // DIO_v_WriteBit(t_timerLed, e_LOW);

  // ICU_v_SetupISR(timer0A0Vector, callBackTimerA0, &t_timerLed);

  TIMER_v_Configure(e_TIMERA0, e_UP, e_SMCLK, e_DIV1);
  TIMER_v_SetInstance(e_TIMERA0, e_COMPARE, e_SLOT0);
  TIMER_v_EnableInterruptCC(e_TIMERA0, e_SLOT0);

  ICU_v_IntEn(u_GIE);

  REG_v_Set16BitReg(TA0CCR0_ADDR, (10000u - 1u)); // start timer 10ms

  while(1)
  {
  }
}

void callBackTimerA0(void* data)
{
  // static t_PinState value = e_LOW;

  // t_DioInst* myInst = (t_DioInst*)data;
  // value ^= e_HIGH;
  // DIO_v_WriteBit(*myInst, value);
}
