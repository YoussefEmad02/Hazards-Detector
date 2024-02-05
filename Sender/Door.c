#include "tm4c123gh6pm.h"
#include "DIO.h"

void Magnetic_Init(){
  SYSCTL_RCGCGPIO_R |= 0x10;   // Enable clock for GPIO Port E
  
  while((SYSCTL_PRGPIO_R & 0x10) == 0);   // Wait until the clock is ready
  
  GPIO_PORTE_DIR_R |= 0x00;    // Set Pin 2 as input
  
  GPIO_PORTE_PUR_R |= 0x04;    // Enable pull-up resistor for Pin 2
  
  GPIO_PORTE_DEN_R |= 0x04;    // Enable digital function for Pin 2
  
}

uint8 Magnetic_Read(){
  if (Get_Bit(GPIO_PORTE_DATA_R, 2) == 0)
    return 0;
  else
    return 1;
}
