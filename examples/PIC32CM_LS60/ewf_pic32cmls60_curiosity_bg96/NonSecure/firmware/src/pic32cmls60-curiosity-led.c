#include "pic32cmls60-curiosity-led.h"

LED_CTRL LED_controller[LED_TOTAL];

void LED_init(void)
{
    for (int counter = 0; counter < LED_TOTAL; counter++)
    {
        LED_controller[counter].mode = LED_OFF;
    }
}

void LED_refresh(void)
{       
    switch (LED_controller[LED0_GREEN].mode)
    {
        case LED_OFF: LED0_Off(); break;
        case LED_ON: LED0_On(); break;
        case LED_BLINKING: LED0_Toggle(); break;
        default: break;
    }
    switch (LED_controller[LED1_RED].mode)
    {
        case LED_OFF: LED1_Off(); break;
        case LED_ON: LED1_On(); break;
        case LED_BLINKING: LED1_Toggle(); break;
        default: break;
    }
}
