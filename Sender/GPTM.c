#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "driverlib/interrupt.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"  
#include "driverlib/timer.h"
#include "driverlib/sysctl.h"

#define SYSCTL_PERIPH_TIMER2   0xf0000402

void TMR2B_INT_Handler(void);


void TMR2_INT_init(void){
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
  
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER2)){}
  
  TimerClockSourceSet(TIMER2_BASE , TIMER_CLOCK_SYSTEM);
         
  TimerConfigure(TIMER2_BASE , (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC));
  
  TimerLoadSet(TIMER2_BASE , TIMER_B , 64000);     //4MSEC
    
  TimerPrescaleSet(TIMER2_BASE , TIMER_B , 250);
  
  IntRegister(INT_TIMER2B , TMR2B_INT_Handler);
  
  IntPrioritySet(INT_TIMER2B , 0x1);
  
  TimerIntClear(TIMER2_BASE , TIMER_TIMB_TIMEOUT);
  
  TimerIntEnable(TIMER2_BASE, TIMER_TIMB_TIMEOUT);
  
  IntEnable(INT_TIMER2B);
  
  TimerEnable(TIMER2_BASE , TIMER_B);
  
}
         
         

void INT_Init(void){
  
   IntMasterDisable();
   
   TMR2_INT_init();
   
   IntMasterEnable();
   
}

void clearflag(void){

    TimerIntClear(  TIMER2_BASE ,   TIMER_TIMB_TIMEOUT  );

}

  
void IntStart(void)
{
  
  IntEnable(INT_TIMER2B);
  
}


void IntStop(void){
  
  IntDisable(INT_TIMER2B);
  
}
  
  
void Timer0ACapture_init(void)
{
  SYSCTL_RCGCTIMER_R |= 1;     /* enable clock to Timer Block 0 */
  SYSCTL_RCGCGPIO_R |=0x03; /* enable clock to PORTA */
  while((SYSCTL_PRGPIO_R&0x00000003) == 0) //actual clk value check 
  {};
  
  GPIO_PORTB_DIR_R &= ~0x40;        /* make PB6 an input pin */
  GPIO_PORTB_DEN_R |= 0x40;         /* make PB6 as digital pin */
  GPIO_PORTB_AFSEL_R|= 0x40;       /* use PB6 alternate function */
  GPIO_PORTB_PCTL_R &= ~0x0F000000;  /* configure PB6 for T0CCP0 */
  GPIO_PORTB_PCTL_R |=  0x07000000;
  GPIO_PORTA_DIR_R |=(1<<5);         /* set PA5 as a digial output pin */
  GPIO_PORTA_DEN_R |=(1<<5);           /* make PA5 as digital pin */
  
  TIMER0_CTL_R &= ~1;          /* disable timer0A during setup */
  TIMER0_CFG_R = 4;            /* 16-bit timer mode */
  TIMER0_TAMR_R  = 0x17;        /* up-count, edge-time, capture mode */
  TIMER0_CTL_R |=0x0C;        /* capture the rising edge */
  TIMER0_CTL_R  |= (1<<0);           /* enable timer0A */
  
}

void Delay_MicroSecond(int time)
{
  SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
  TIMER1_CTL_R = 0;            /* disable Timer before initialization */
  TIMER1_CFG_R = 0x04;         /* 16-bit option */ 
  TIMER1_TAMR_R = 0x02;        /* periodic mode and down-counter */
  TIMER1_TAILR_R = 16 - 1;  /* TimerA interval load value reg */
  TIMER1_ICR_R = 0x1;          /* clear the TimerA timeout flag */
  TIMER1_CTL_R |= 0x01;        /* enable Timer A after initialization */
  
  for(int i = 0; i < time; i++)
  {
    while ((TIMER1_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
    TIMER1_ICR_R = 0x1;      /* clear the TimerA timeout flag */
  }
}
           
  