#include <gpio.h>
#include <icu.h>
#include <register_utils.h>
#include <wdt.h>

void callBackPort1(void* data);

int main()
{
  WDT_v_Stop();
  GPIO_v_Init();
  ICU_v_Init();

  t_GPIO_PinDescriptor t_greenLed   = GPIO_t_NewInstance(e_PORT1, e_PIN0, e_OUTPUT, e_PIN_DIO, e_RES_DIS, e_PULL_UP);
  t_GPIO_PinDescriptor t_redLed     = GPIO_t_NewInstance(e_PORT1, e_PIN6, e_OUTPUT, e_PIN_DIO, e_RES_DIS, e_PULL_UP);
  t_GPIO_PinDescriptor t_pushButton = GPIO_t_NewInstance(e_PORT1, e_PIN3, e_INPUT, e_PIN_DIO, e_RES_DIS, e_PULL_UP);

  GPIO_v_SetUpPin(&t_greenLed);
  GPIO_v_SetUpPin(&t_redLed);
  GPIO_v_SetUpPin(&t_pushButton);

  GPIO_v_WritePin(&t_greenLed, e_HIGH);
  GPIO_v_WritePin(&t_redLed, e_LOW);

  GPIO_v_PinIntEn(&t_pushButton, e_RISING_EDGE);
  ICU_v_SetupISR(port1Vector, callBackPort1, &t_redLed);

  ICU_v_IntEn(u_GIE);

  while(1)
  {
    /* code */
  }
}

void callBackPort1(void* data)
{
  t_GPIO_PinDescriptor* e_myInst = (t_GPIO_PinDescriptor*)data;

  if(REG_u_GetBitIn8BitReg(u_P1IFG_ADDR, e_PIN3) == e_HIGH)
  {
    static t_PinState e_value = e_LOW;
    e_value ^= e_HIGH;
    GPIO_v_WritePin(e_myInst, e_value);
    REG_v_ClearBitIn8BitReg(u_P1IFG_ADDR, e_PIN3);
  }
}