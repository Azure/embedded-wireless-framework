
#ifndef __pic32cmls60_curiosity_buttons__h__included__
#define __pic32cmls60_curiosity_buttons__h__included__

#ifdef __cplusplus
extern "C" {
#endif
    
#include "definitions.h"
#include "ewf_adapter.h"
#include "ewf_example.config.h"

typedef enum
{
   BUTTON_PRESS_FALSE = 0,
   BUTTON_PRESS_TRUE
} BUTTON_EventStatus;

// Button Press Telemetry Events
typedef union
{
    struct
    {
        uint16_t sw0 : 1;
        uint16_t sw1 : 1;
        uint16_t reserved : 14;
    };
    uint16_t as_uint16;
} button_press_flag_t;

typedef struct
{
    uint32_t            sw0_press_count;
    uint32_t            sw1_press_count;
    button_press_flag_t flag;
} BUTTON_PressData;

void BUTTON_SW0_callback(void);
void BUTTON_SW1_callback(void);

BUTTON_EventStatus BUTTON_SW0_check(void);
BUTTON_EventStatus BUTTON_SW1_check(void);

#ifdef __cplusplus
}
#endif

#endif /* __pic32cmls60_curiosity_buttons__h__included__ */