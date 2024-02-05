#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "Buzzer.h"
#include "Systic_timer.h"


void initBuzzer(void) {
    SYSCTL_RCGCGPIO_R |= 0x08; // Enable peripheral
    GPIO_PORTD_LOCK_R = 0x4C4F434B;   /* unlock commit register */
    GPIO_PORTD_CR_R = (1<<3);           
    GPIO_PORTD_LOCK_R = 0;            /* lock commit register */	
    GPIO_PORTD_DIR_R |= (1<<3);       
    GPIO_PORTD_DEN_R |= (1<<3);            
}

inline void buzzer(bool enable) {
    if (enable) {
        Set_Bit(GPIO_PORTD_DATA_R , 3);
    } else {
        Clear_Bit(GPIO_PORTD_DATA_R , 3);
    }
}

void beepBuzzer(void) {
    buzzer(true);
    SysTick_Delay(1000);
    buzzer(false);
}

void beepLongBuzzer(void) {
    buzzer(true);
    SysTick_Delay(5000);
    buzzer(false);
}

void beepBuzzerWithInterval(uint64_t duration, uint64_t interval) {
    while (1) {
        buzzer(true);  // Start the buzzer
        SysTick_Delay(duration);  // Delay for the specified duration
        buzzer(false);  // Stop the buzzer
        SysTick_Delay(interval);  // Delay for the specified interval
    }
}

