#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "driverlib/interrupt.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"  


void GPIOF_Handler(void);


void Gpio_interrupt_init(void)
{
    
     SYSCTL_RCGCGPIO_R |= (1<<5);   /* Set bit5 of RCGCGPIO to enable clock to PORTF*/
     GPIO_PORTF_LOCK_R = 0x4C4F434B;   /* unlock commit register */
     GPIO_PORTF_CR_R = 0x01;           /* make PORTF0 configurable */
     GPIO_PORTF_LOCK_R = 0;            /* lock commit register */


    /*Initialize PF3 as a digital output, PF0 and PF4 as digital input pins */
	
      GPIO_PORTF_DIR_R|= 0x0E;       /* Set PF3 as digital output to control green LED */
      GPIO_PORTF_DEN_R|= 0x1F;             /* make PORTF4-0 digital pins */
      GPIO_PORTF_PUR_R |= (1<<4)|(1<<0);             /* enable pull up for PORTF4, 0 */
    
    /* configure PORTF4, 0 for falling edge trigger interrupt */
     GPIO_PORTF_IS_R  &= ~(1<<4)|~(1<<0);        /* make bit 4, 0 edge sensitive >> 1 is level sensitive*/
     GPIO_PORTF_IBE_R &=~(1<<4)|~(1<<0);         /* trigger is controlled by IEV    0 ev & 1 both edges*/ 
     GPIO_PORTF_IEV_R &= ~(1<<4)|~(1<<0);        /* falling edge trigger   >> 1 rising edge trigger*/
     GPIO_PORTF_ICR_R |= (1<<4)|(1<<0);          /* clear any prior interrupt */
     GPIO_PORTF_IM_R  |= (1<<4)|(1<<0);          /* unmask interrupt and enable for ports 0 and 4 and sent to interupt controller*/
    
     IntEnable(INT_GPIOF);
     IntPrioritySet(INT_GPIOF , 0x2);
     IntRegister(INT_GPIOF_TM4C123  , GPIOF_Handler);

        
    
}