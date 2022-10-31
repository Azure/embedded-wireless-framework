/**********************************************
* Button Press Telemetry - JSON Message Format
* e.g.
* {
*   "button_event" :
*   {
*     "button_name" : "SW0",
*     "press_count" : 1
*   }
* }
**********************************************/

#include "pic32cmls60-curiosity-buttons.h"

BUTTON_PressData BUTTON_pressData = {0};
char BUTTON_eventBuffer[EWF_CONFIG_TELEMETRY_TOPIC_LENGTH];

void BUTTON_SW0_callback(void)
{
    BUTTON_pressData.flag.sw0 = BUTTON_PRESS_TRUE;
    BUTTON_pressData.sw0_press_count++;
    LED0_Toggle();
}

void BUTTON_SW1_callback(void)
{
    BUTTON_pressData.flag.sw1 = BUTTON_PRESS_TRUE;
    BUTTON_pressData.sw1_press_count++;
    LED1_Toggle();
}

BUTTON_EventStatus BUTTON_SW0_check(void)
{
    uint8_t buffer_length;

    bool SW0_pressed = BUTTON_pressData.flag.sw0 == 1 ? BUTTON_PRESS_TRUE : BUTTON_PRESS_FALSE;

    BUTTON_pressData.flag.sw0 = BUTTON_PRESS_FALSE;

    if (SW0_pressed == BUTTON_PRESS_FALSE)
    {
        return BUTTON_PRESS_FALSE;
    }
    else
    {
        EWF_LOG("AZURE: Button SW0 Count %lu", BUTTON_pressData.sw0_press_count);
        buffer_length = (uint8_t)snprintf(BUTTON_eventBuffer, sizeof(BUTTON_eventBuffer), 
            " {\"button_event\" : {\"button_name\" : \"SW0\", \"press_count\" : %u} } ", 
            BUTTON_pressData.sw0_press_count);
        return BUTTON_PRESS_TRUE;
    }
}

BUTTON_EventStatus BUTTON_SW1_check(void)
{
    uint8_t buffer_length;

    bool SW1_pressed = BUTTON_pressData.flag.sw1 == 1 ? BUTTON_PRESS_TRUE : BUTTON_PRESS_FALSE;

    BUTTON_pressData.flag.sw1 = BUTTON_PRESS_FALSE;

    if (SW1_pressed == BUTTON_PRESS_FALSE)
    {
        return BUTTON_PRESS_FALSE;
    }
    else
    {
        EWF_LOG("AZURE: Button SW1 Count %lu", BUTTON_pressData.sw1_press_count);
        buffer_length = (uint8_t)snprintf(BUTTON_eventBuffer, sizeof(BUTTON_eventBuffer), 
            " {\"button_event\" : {\"button_name\" : \"SW1\", \"press_count\" : %u} } ", 
            BUTTON_pressData.sw1_press_count);
        return BUTTON_PRESS_TRUE;
    }
}
