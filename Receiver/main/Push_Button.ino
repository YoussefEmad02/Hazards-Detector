void Push_Button_Init(void)
{
  DIO_SetPinDirection(DIO_PORTB, 4, DIO_INPUT);        // Set Push Button pin as input
}

unsigned char Push_Button_State(void)
{
  unsigned char Local_Result = DIO_GetPinValue(DIO_PORTB, 4);
  return Local_Result;
}