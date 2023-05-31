/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (8)
#endif
/* ISR prototypes */
void r_icu_isr(void);
void gpt_counter_overflow_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void ether_eint_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_ICU_IRQ10 ((IRQn_Type) 0) /* ICU IRQ10 (External pin interrupt 10) */
#define ICU_IRQ10_IRQn          ((IRQn_Type) 0) /* ICU IRQ10 (External pin interrupt 10) */
#define VECTOR_NUMBER_ICU_IRQ11 ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define ICU_IRQ11_IRQn          ((IRQn_Type) 1) /* ICU IRQ11 (External pin interrupt 11) */
#define VECTOR_NUMBER_GPT0_COUNTER_OVERFLOW ((IRQn_Type) 2) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define GPT0_COUNTER_OVERFLOW_IRQn          ((IRQn_Type) 2) /* GPT0 COUNTER OVERFLOW (Overflow) */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 3) /* SCI0 RXI (Receive data full) */
#define SCI0_RXI_IRQn          ((IRQn_Type) 3) /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 4) /* SCI0 TXI (Transmit data empty) */
#define SCI0_TXI_IRQn          ((IRQn_Type) 4) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 5) /* SCI0 TEI (Transmit end) */
#define SCI0_TEI_IRQn          ((IRQn_Type) 5) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 6) /* SCI0 ERI (Receive error) */
#define SCI0_ERI_IRQn          ((IRQn_Type) 6) /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 7) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 7) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
