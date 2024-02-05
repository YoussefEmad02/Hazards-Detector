#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"  //For Interrupt assigments vector numbers
#include "driverlib/interrupt.h"
#include "systick.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Systic_timer.h"

void SysTick_Disable (void){
  Clear_Bit(NVIC_ST_CTRL_R,0);
}

void SysTick_Enable (void){
  Set_Bit(NVIC_ST_CTRL_R,0);
  Set_Bit(NVIC_ST_CTRL_R,2);
}
uint32 SysTick_PeriodGet (void){
  uint32 noTicks = DIO_ReadPort(&NVIC_ST_RELOAD_R);
  return ((noTicks + 1) / (16*(1000000)))*1000; //required delay = (Number of ticks + 1) / frequency (16MHZ) in seconds
}

void SysTick_PeriodSet (uint32 ui32Period){
  uint32 noTicks = ((double)ui32Period/1000) * (16*(1000000)) - 1; // Number of ticks = (required delay in seconds * frequency(16MHZ))- 1
     // Ensure the value does not exceed the maximum reload value which is 24 bit 
    if (noTicks > 0x00FFFFFF) {
        noTicks = 0x00FFFFFF;
    } 
  
  DIO_WritePort(&NVIC_ST_RELOAD_R, noTicks);
}

uint32 SysTick_ValueGet (void){
  uint32 noTicks = DIO_ReadPort(&NVIC_ST_CURRENT_R);
  return ((noTicks + 1) / 1/(16*(1000000)))*1000;
  //return DIO_ReadPort(&NVIC_ST_CURRENT_R);
}
bool SysTick_Is_Time_out(void){
  if(DIO_ReadPin(&NVIC_ST_CTRL_R,16))
    return true;
  return false;
}

void SysTick_Init (void){
  SysTick_Disable();
  SysTick_PeriodSet(1000);
  DIO_WritePort(&NVIC_ST_CURRENT_R, 0);
  SysTick_Enable();
}


//
//volatile uint64_t counter;
//
//static void Systick_Handler(void) {
//    counter++;
//}
//
//
//void Systick_Init_int(void){
//  
//  IntMasterDisable(); // Disable processor interrupt
//     
//  SysTickDisable();    // Disable counter
//  
//  SysTickPeriodSet(15999);  // 1ms / 1 / 16MHZ
//  
//  HWREG(NVIC_ST_CURRENT) = 0 ;  // Any write to current reg clears it
//  
//  IntRegister(FAULT_SYSTICK, Systick_Handler); //Interrupt handler
//  
//  IntPrioritySet(FAULT_SYSTICK, 0); 
//  
//  SysTickIntEnable(); //Enable interrupt
//  
//  SysTickEnable();   // Eable counter
//  
//  IntEnable(FAULT_SYSTICK); //Enables interrupt on NVIC level
//  
//  IntMasterEnable();// Enable processor interrupt
// 
//}
//
//bool SysTick_Is_Time_out(void) {
//    if ((NVIC_ST_CTRL_R & 0x10000) == 0) {
//   return false;
//} else {
//   return true;
//}
//}
//
//uint32_t millis(void) {
//    return counter;
//}
//
//void SysTick_Delay(uint64_t milliseconds) {
//    counter = 0;
//    while (milliseconds > counter);
//}










  

