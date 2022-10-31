#ifndef __pic32cmls60_curiosity_led__h__included__
#define __pic32cmls60_curiosity_led__h__included__

#ifdef __cplusplus
extern "C" {
#endif
    
#include "definitions.h"                // SYS function prototypes

#define LED_TOTAL 2

/* LED Colors */
typedef enum 
{
    LED0_GREEN = 0,
    LED1_RED,
} LED_COLOR;

/* LED Modes */
typedef enum 
{
    LED_OFF = 0,
    LED_ON,
    LED_BLINKING,
    LED_MODE_INVALID,
} LED_MODE;

/* LED Controller Structure */
typedef struct
{
    LED_MODE mode;    
} LED_CTRL;

extern LED_CTRL LED_controller[LED_TOTAL];

void LED_init(void);
void LED_refresh(void);

#ifdef __cplusplus
}
#endif

#endif /* __pic32cmls60_curiosity_led__h__included__ */