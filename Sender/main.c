#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Systic_timer.h"
#include "ADC.h"
#include "UART.h"
#include "HC-SR04.h"
#include "LM35.h"
#include "HC-05.h"
#include "Gpio_interrupt.h"
#include "PWM.h"
#include "GPTM.h"
#include "Door.h"

char mesg[20];      /* string format of distance value */

char str[30];

volatile uint32_t temperature ;

volatile uint32_t time;      /* stores pulse on time */

volatile uint32_t distance;  /* stores measured distance value */

volatile uint8 tempflag = 0 ;

volatile uint8 distanceflag = 0 ;

volatile uint8 magneticflag = 0 ;

volatile int status = 0; 

volatile int prevStatus = -1;

volatile int stoppedMessageSent = false;

volatile int startedMessageSent = false;

volatile uint32 temperature ;
volatile uint32 distance ; 
volatile uint8 magnetic ; 

int main(void) {
  
  SysTick_Init();
  
  Gpio_interrupt_init();
  
  ADC_init();   
  
  UART0_init();
  
  UART5_init();
  
  LM35_init();
  
  HC05_init();
  
  Timer0ACapture_init();
  
  PWM_init();
  
  INT_Init();  
  
  Magnetic_Init();
  
  IntStop();
  
  while (1) {
    while (status) {
      if (tempflag) {
        setHighIntensity();
        SysTick_PeriodSet(4000);
        
      } else if (distanceflag) {
        setMediumIntensity();
        SysTick_PeriodSet(4000);
        
      } else if (magneticflag) {
        setLowIntensity();
        SysTick_PeriodSet(4000);
        
      }
    }
  }
}

void GPIOF_Handler(void) {
  if (GPIO_PORTF_MIS_R & 0x10) {
    // Stop button pressed (PF4/SW1)
    GPIO_PORTF_ICR_R |= 0x10; // Clear the interrupt flag
    status = 0 ;
    
    if (status != prevStatus && !stoppedMessageSent) {
      // Only send the message if the status has changed and the message hasn't been sent
      stoppedMessageSent = 1;
      startedMessageSent = 0;
      prevStatus = status;
      //            Bluetooth_Write_String("System Stopped\n");
      IntStop();
      clearLED();
    }
  }
  
  if (GPIO_PORTF_MIS_R & 0x01) {
    // Start button pressed (PF0/SW2)
    GPIO_PORTF_ICR_R |= 0x01; // Clear the interrupt flag
    status = 1;
    if (status != prevStatus && !startedMessageSent) {
      // Only send the message if the status has changed and the message hasn't been sent
      startedMessageSent = 1;
      stoppedMessageSent = 0;
      prevStatus = status;
      //            Bluetooth_Write_String("System Started\n");
      IntStart();
    }
  }
}

void TMR2B_INT_Handler(void) {
  clearflag();
  temperature = ReadTemperature();
  time = Measure_distance(); // Take pulse duration measurement
  distance = (time * 10625) / 10000000; // Convert pulse duration into distance
  magnetic = Magnetic_Read();
  
  if (temperature > 23 && !tempflag) {
    tempflag = 1;
    sprintf(str , "%d , %d , %d ,Fire is Reported" , temperature , distance , magnetic);
    Bluetooth_Write_String(str);
  } else if (temperature <= 23) {
    tempflag = 0;
    clearLED();
  }
  
  if (distance < 3 && !distanceflag) {
    distanceflag = 1;
    sprintf(str , "%d,%d,%d,Intrusion" , temperature , distance , magnetic);
    Bluetooth_Write_String(str);
  } else if (distance >= 3) {
    distanceflag = 0;
    clearLED();
  }
  
  if (magnetic && !magneticflag) {
    magneticflag = 1;
    sprintf(str , "%d,%d,%d,Door is opened" , temperature , distance , magnetic);
    Bluetooth_Write_String(str);
    clearLED();
  } else if (!magnetic) {
    magneticflag = 0;
    clearLED();
  }
}


