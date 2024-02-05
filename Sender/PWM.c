/* Generates 50HZ and variable duty cycle on PF2 pin of TM4C123 Tiva C Launchpad */
/* PWM1 module and PWM generator 3 of PWM1 module is used. Hence PWM channel*/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include "Systic_timer.h"
#include "bitwise_operation.h"

volatile int duty_cycle = 4999;  // Declare duty_cycle globally


void PWM_init(void)
{

int duty_cycle = 4999;
    
/* Clock setting for PWM and GPIO PORT */
SYSCTL_RCGCPWM_R |= 2;       /* Enable clock to PWM1 module */

SYSCTL_RCGCGPIO_R |= 0x20;  /* Enable system clock to PORTF */

SYSCTL_RCC_R |= (1<<20);    /* Enable System Clock Divisor function  */

SYSCTL_RCC_R |= 0x000E0000; /* Use pre-divider valur of 64 and after that feed clock to PWM1 module*/

 /* Setting of PF2 pin for M1PWM6 channel output pin */
GPIO_PORTF_AFSEL_R |= (1<<2);  /* PF2 sets a alternate function */

GPIO_PORTF_PCTL_R &= ~0x00000F00; /*set PF2 as output pin */

GPIO_PORTF_PCTL_R |= 0x00000500; /* make PF2 PWM output pin */

GPIO_PORTF_DEN_R |= (1<<2);      /* set PF2 as a digital pin */
    
PWM1_3_CTL_R &= ~(1<<0);   /* Disable Generator 3 counter */

PWM1_3_CTL_R &= ~(1<<1);   /* select down count mode of counter 3*/

PWM1_3_GENA_R = 0x0000008C;  /* Set PWM output when counter reloaded and clear when matches PWMCMPA */

PWM1_3_LOAD_R = 3000;     /* set load value for 50Hz 16MHz/65 = 250kHz and (250KHz/5000) */

PWM1_3_CMPA_R = 2999;     /* set duty cyle to to minumum value*/

PWM1_3_CTL_R = 1;           /* Enable Generator 3 counter */

PWM1_ENABLE_R = 0x40;  /* Enable PWM1 channel 6 output */

}

void setLowIntensity(void) {
  PWM1_ENABLE_R = 0x40;
    duty_cycle = 2950;
    PWM1_3_CMPA_R = duty_cycle;
}

void setMediumIntensity(void) {
    PWM1_ENABLE_R = 0x40;

    duty_cycle = 2700;
    PWM1_3_CMPA_R = duty_cycle;
}

void setHighIntensity(void) {
    PWM1_ENABLE_R = 0x40;

    duty_cycle = 0;
    PWM1_3_CMPA_R = duty_cycle;
}

void clearLED(void) {
    // Turn off the LED by setting the duty cycle to a high value
    PWM1_ENABLE_R  &= ~ 0x40;

}

