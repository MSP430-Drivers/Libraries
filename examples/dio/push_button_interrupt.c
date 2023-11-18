#include <bcm.h>
#include <dio.h>
#include <gpio.h>
#include <icu.h>
#include <platform_types.h>
#include <register_utils.h>
#include <wdt.h>

void v_CallBackDIO(void* data);

int main()
{
  WDT_v_Stop();
  GPIO_v_Init();
  ICU_v_Init();
  BCM_v_DCOConf(e_FREQ1MHZ);
  BCM_v_MCLKConf(e_CLK_DCO, e_DIV1);
  BCM_v_SMCLKConf(e_CLK_DCO, e_DIV1);

  t_DioInst t_pb     = DIO_v_SetInstance(e_PORT1, e_PIN3, e_INPUT);
  t_DioInst t_redLed = DIO_v_SetInstance(e_PORT1, e_PIN6, e_OUTPUT);
  DIO_v_PinIntEn(t_pb, e_RISING_EDGE);
  DIO_v_WriteBit(t_redLed, e_LOW);

  ICU_v_SetupISR(port1Vector, v_CallBackDIO, &t_redLed);

  ICU_v_IntEn(u_GIE);

  while(1)
  {
  }
}

void v_CallBackDIO(void* data)
{
  t_DioInst* myInst = (t_DioInst*)data;
  if(REG_u_GetBitIn8BitReg(u_P1IFG_ADDR, e_PIN3) == e_HIGH)
  {
    static t_PinState value = e_LOW;
    value ^= e_HIGH;
    DIO_v_WriteBit(*myInst, value);
    REG_v_ClearBitIn8BitReg(u_P1IFG_ADDR, e_PIN3);
  }
}
