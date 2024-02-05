#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "types.h"
#include "Systic_timer.h"


void UART0_init(void)
{
    SYSCTL_RCGCUART_R |= 1; /* provide clock to UART0 */
    SYSCTL_RCGCGPIO_R |= 0x01; /* enable clock to GPIOA */

    /* UART0 initialization */
    UART0_CTL_R = 0;            /* disable UART0 */
    UART0_IBRD_R = 104;         /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
    UART0_FBRD_R = 11;          /* fraction part */
    UART0_CC_R = 0;             /* use system clock */
    UART0_LCRH_R = 0x60;         /* 8-bit, no parity, 1-stop bit, no FIFO */
    UART0_CTL_R = 0x301;         /* enable UART0, TXE, RXE */

    /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
    GPIO_PORTA_DEN_R = 0x03;    /* Make PA0 and PA1 as digital */
    GPIO_PORTA_AFSEL_R = 0x03;  /* Use PA0, PA1 alternate function */
    GPIO_PORTA_PCTL_R = 0x11;   /* configure PA0 and PA1 for UART */
}



void UART5_init(void)
{
    SYSCTL_RCGCUART_R |= 0x20;  /* enable clock to UART5 */
    SYSCTL_RCGCGPIO_R |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    SysTick_PeriodSet(100);
    /* UART0 initialization */
    UART5_CTL_R = 0;         /* UART5 module disbable */
    UART5_IBRD_R = 104;      /* for 9600 baud rate, integer = 104 */
    UART5_FBRD_R = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5_CC_R = 0;          /*select system clock*/
    UART5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
}


void UART0Tx(char c)
{
    while ((UART0_FR_R & 0x20) != 0)
        ; /* wait until Tx buffer not full */
    UART0_DR_R = c; /* before giving it another byte */
}

void UART0_puts(char *s)
{
    while (*s != 0) /* if not end of string */
        UART0Tx(*s++); /* send the character through UART0 */
}

