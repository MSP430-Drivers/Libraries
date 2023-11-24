#include <gpio.h>
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
  return 0;
}
