#ifndef DIO_H
#define DIO_H
#include "bitwise_operation.h"
#include "types.h"
void Delay(void);
void DIO_WritePin(ulong32_ptr port, uint8 pin, uint8 value);
void DIO_WritePort(ulong32_ptr,uint32 value);
void DIO_init(void);
uint8 DIO_ReadPin(ulong32_ptr port,uint8 pin);
uint32 DIO_ReadPort(ulong32_ptr port);
#endif


