#include <stdbool.h>
#include "types.h"

#ifndef SYSTIC_H
  #define SYSTIC_H
 
void SysTick_Init(void);

void SysTick_PeriodSet (uint32 ui32Period);

//void SysTick_Delay(uint64_t milliseconds);

bool SysTick_Is_Time_out(void);

extern volatile uint64_t counter;




#endif