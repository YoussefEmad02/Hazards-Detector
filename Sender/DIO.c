#include "types.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "DIO.h"

void DIO_WritePin(ulong32_ptr port, uint8 pin, uint8 value)
{
  if(value ==1)
    Set_Bit(*port, pin);
  else
    Clear_Bit(*port, pin);
}

void DIO_WritePort(ulong32_ptr port,uint32 value)
{
  *port = value;
}


void DIO_init(void){
  
  SYSCTL_RCGCGPIO_R|=0x20; //clk =1 at port F
  while((SYSCTL_PRGPIO_R&0x00000020) == 0) //actual clk value check 
  {};
  GPIO_PORTF_LOCK_R = 0x4C4F434B; 
  GPIO_PORTF_CR_R |= 0x1F; 
  GPIO_PORTF_DIR_R|= 0x0E;
  GPIO_PORTF_PUR_R|= 0x11;
  GPIO_PORTF_DEN_R|= 0x1F;
  
}

uint8 DIO_ReadPin(ulong32_ptr port,uint8 pin)
{
  return Get_Bit(*port,pin);
}

uint32 DIO_ReadPort(ulong32_ptr port)
{
  return *(port);
}











