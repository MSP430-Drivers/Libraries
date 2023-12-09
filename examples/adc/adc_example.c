#include <adc.h>
#include <register_utils.h>
#include <wdt.h>

int main()
{
  WDT_v_Stop();
  ADC_v_Init();
  ADC_v_Config(e_VCC, e_8ADC10CLKS, e_50KSPS, e_STRAIGHT, e_ADC_DIV1, e_ADC_CLK, e_SINGLE);
  ADC_v_SetChannel(e_CHA1);
  ADC_v_StartConversion();

  while(1)
  {
    /* code */
  }
}
