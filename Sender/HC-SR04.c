/* This example code Measures the distance using HC-SR04 Ultrasonic range sensor*/
/* It displays the measured distance value on computer using UART communication moduel of TM4C123 */
/* Timer0A is used to measure distance by measuring pulse duration of Echo output signal */
/* Timer1A is used to make percise microsecond delay function */

/*header files for TM4C123 device and sprintf library */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "types.h"
#include "Systic_timer.h"
#include "HC-SR04.h"
#include "GPTM.h"

//uint32_t time; /*stores pulse on time */
//uint32_t distance; /* stores measured distance value */
//char mesg[20];  /* string format of distance value */

/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */

uint32_t Measure_distance(void)
{
    int lastEdge, thisEdge;

    /* Given 10us trigger pulse */
    GPIO_PORTA_DATA_R &= ~(1 << 5); /* make trigger pin low */
    Delay_MicroSecond(10);          /* 10 microseconds delay */
    GPIO_PORTA_DATA_R |= (1 << 5);  /* make trigger pin high */
    Delay_MicroSecond(10);          /* 10 microseconds delay */
    GPIO_PORTA_DATA_R &= ~(1 << 5); /* make trigger pin low */

    while (1)
    {
        TIMER0_ICR_R = 4; /* clear Timer0A capture flag */
        while ((TIMER0_RIS_R & 4) == 0); /* wait till captured */

        if (GPIO_PORTB_DATA_R & (1 << 6))
        { /* check if rising edge occurs */
            lastEdge = TIMER0_TAR_R; /* save the timestamp */

            /* detect falling edge */
            TIMER0_ICR_R = 4; /* clear Timer0A capture flag */

            while ((TIMER0_RIS_R & 4) == 0)
                ; /* wait till captured */

            thisEdge = TIMER0_TAR_R; /* save the timestamp */

            return (thisEdge - lastEdge); /* return the time difference */
        }
    }
}




