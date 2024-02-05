#include "BIT_MATH.h"
#include "DIO.h"
#include "Buzzer.h"
#include "LED.h"


int main() {
  Buzzer_Init();
  LED_Init();
  Adc_Init();
  PWM_Init();
  LCD_Init();
  int LDR_Reading;
  unsigned char Push_Button_Reading;
  int n = 1;
  Serial.begin(9600);
  float prev_Voltage = 0.0;
  while (1) {
    Push_Button_Reading = Push_Button_State();
    LDR_Reading = Adc_ReadChannel(1);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = LDR_Reading * (5.0 / 1023.0);
    // print out the value you read:
    Serial.println(voltage);
    if (n == 1)
    {
      LCD_Command(0x80);  // Set LCD cursor to the beginning of the first line
      LCD_String("No Alarm        ");
    }
    if (voltage < 2.5) {

      Buzzer_State(Ring);
      LED_State(LED_ON);

      if (voltage > 2 && voltage < 2.7 && voltage != prev_Voltage) {
        LCD_Clear();
        LCD_Command(0x80);  // Set LCD cursor to the beginning of the first line
        LCD_String("Door Opened     ");
        _delay_ms(500);
      } else if (voltage > 1.2 && voltage < 2 && voltage != prev_Voltage) {
        LCD_Clear();
        LCD_Command(0x80);  // Set LCD cursor to the beginning of the first line
        LCD_String("Intrusion       ");
        _delay_ms(500);
      } else if (voltage > 0 && voltage < 1.1 && voltage != prev_Voltage) {
        LCD_Clear();
        LCD_Command(0x80);  // Set LCD cursor to the beginning of the first line
        LCD_String("Fire Is Reported");
        _delay_ms(500);
      }
      prev_Voltage = voltage;
      n = 0;
    } if (Push_Button_Reading == DIO_HIGH) {
      _delay_ms(5000);
      LCD_Command(0x80);  // Set LCD cursor to the beginning of the first line
      LCD_String("No Alarm        ");
      Buzzer_State(Mute);
      LED_State(LED_OFF);
      _delay_ms(50);
    }
  }
}