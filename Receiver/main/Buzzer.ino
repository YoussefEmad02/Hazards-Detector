void Buzzer_Init(void)
{
  DIO_SetPinDirection(DIO_PORTD, 2, DIO_OUTPUT);        // Set Buzzer pin as output
}

void Buzzer_State(unsigned char State)
{
  switch (State) {
    case Ring:
      DIO_SetPinValue(DIO_PORTD, 2, DIO_HIGH);
    break;
    case Mute:
      DIO_SetPinValue(DIO_PORTD, 2, DIO_LOW);
    break;
  }
}