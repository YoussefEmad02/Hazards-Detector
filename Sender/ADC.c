#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "types.h"
#include "Systic_timer.h"

void ADC_init(void) {
    SYSCTL_RCGCGPIO_R |= 0x10;   // Enable clock to GPIOE
    SYSCTL_RCGCADC_R |= 1;       // Enable clock to ADC0

    // Initialize PE3 for AIN0 input
    GPIO_PORTE_AFSEL_R |= 8;     // Enable alternate function
    GPIO_PORTE_DEN_R &= ~8;      // Disable digital function
    GPIO_PORTE_AMSEL_R |= 8;     // Enable analog function

    // Initialize ADC0
    ADC0_ACTSS_R &= ~8;          // Disable SS3 during configuration
    ADC0_EMUX_R &= ~0xF000;      // Software trigger conversion
    ADC0_SSMUX3_R = 0;           // Get input from channel 0
    ADC0_SSCTL3_R |= 6;          // Take one sample at a time, set flag at 1st sample
    ADC0_ACTSS_R |= 8;           // Enable ADC0 sequencer 3
}