void LED_Init(void)
{
  DIO_SetPinDirection(DIO_PORTD, 3, DIO_OUTPUT);        // Set LED pin as output
}

void LED_State(unsigned char State)
{
  switch (State) {
    case LED_ON:
      DIO_SetPinValue(DIO_PORTD, 3, DIO_HIGH);
    break;
    case LED_OFF:
      DIO_SetPinValue(DIO_PORTD, 3, DIO_LOW);
    break;
    }
}