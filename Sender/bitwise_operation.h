#ifndef bitwise_operation_h
#define bitwise_operation_h
#define Set_Bit(Register, bit) (Register|=(1<<bit))
#define Clear_Bit(Register, bit) (Register&=(0<<bit)) 
#define Get_Bit(Register, bit) ((Register&(1<<bit)) >> bit)
#define Toggle_Bit(Register, bit) (Register ^=(1<<bit)) 

#endif