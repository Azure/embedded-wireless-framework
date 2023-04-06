
#ifndef DEMO_PRINTF_H
#define DEMO_PRINTF_H

#define LOG_TERMINAL_INIT demo_printf_init
#define LOG_TERMINAL demo_printf

void demo_printf_init(void);
void demo_printf(char *format, ...);
void demo_printf_transmit_end(void);

#endif
