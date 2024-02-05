#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "types.h"
#include "Systic_timer.h"
#include "ADC.h"
#include "UART.h"

/* This program converts the analog output from an LM34 and converts it to temperature
in Fahrenheit.
Notice from Table 7-5, AIN0 channel is on PE3 pin. Temp is sent to UART to be viewed on
TeraTerminal */

void LM35_init(void)
{

    /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
    GPIO_PORTA_DEN_R = 0x03;    /* Make PA0 and PA1 as digital */
    GPIO_PORTA_AFSEL_R = 0x03;  /* Use PA0, PA1 alternate function */
    GPIO_PORTA_PCTL_R = 0x11;   /* configure PA0 and PA1 for UART */
}


int ReadTemperature(void) {
  
    int temperature;

    ADC0_PSSI_R |= 8; // Start a conversion sequence 3
    
    while ((ADC0_RIS_R & 8) == 0); // Wait for conversion complete

    // Read raw ADC value
    int adcValue = ADC0_SSFIFO3_R;

    // Scale ADC value to temperature
    //      temperature = ((ADC0_SSFIFO3_R * 3000) / 4096) / 10;
    
    temperature = (((ADC0_SSFIFO3_R * 3.3) / 4096) * 100 ) ;

    ADC0_ISC_R = 8; // Clear completion flag

    return temperature;
}


