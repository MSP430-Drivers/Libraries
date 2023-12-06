#include <gpio.h>
#include <icu.h>
#include <register_utils.h>
#include <bcm.h>
#include <platform_types.h>
#include <wdt.h>
#include <timer.h>
#include <adc.h>

int main()
{
  WDT_v_Stop();
  return 0;
}
