//#include "mcal/DIO.h"
//#include "types.h"
//#include "tm4c123gh6pm.h"
//
//#define RS 1 //PortB pin0			 	
//#define RW 2 //PortB pin1       
//#define EN 4 //PortB pin2		 	 	
//
//#define clear_display     0x01
//#define returnHome        0x02
//#define moveCursorRight   0x06
//#define moveCursorLeft    0x08
//#define shiftDisplayRight 0x1C
//#define shiftDisplayLeft  0x18
//#define cursorBlink       0x0F
//#define cursorOff         0x0C
//#define cursorOn          0x0E
//#define Function_set_4bit 0x28
//#define Function_8_bit    0x32
//#define Set5x7FontSize    0x20
//#define FirstRow          0x80
//
///*
//RS  -> B0 REGISTER SELECT : differentiates between data and commands
//R/W -> B1 GRND Read/Write in grnd we want it as output 
//EN  -> B2
//D4  -> B4
//D5  -> B5
//D6  -> B6
//D7  -> B7
//*/
//
////In 4-bit mode, data transfers from microcontroller to the LCD in two consecutive half bytes
//
//void delayMs(int32 n)
//{  
//	uint32_v i,j;            
//	for(i=0;i<n;i++)
//		for(j=0;j<3180;j++)         //delay for 1 msec
//		{}
//}
//
//void delayUs(int32 n)             
//{
//	uint32_v i,j;							
//	for(i=0;i<n;i++)
//		for(j=0;j<3;j++)            //delay for 1 micro second
//		{}
//}
//
//void LCD_Write(uint8 data, uint8 control){
//  data &= 0xF0; // clear lower nibble for control 
//  control &= 0x0F; // clear upper nibble for data 
//  DIO_WritePort(&GPIO_PORTB_DATA_R, (data|control)); // combines data and control into a single byte (RS = control, R/W = 0) 
//  DIO_WritePort(&GPIO_PORTB_DATA_R,(data|control|EN)); // turn on the En of the lcd to perform write operation
//  delayUs(0); 
//  /*The control bits are not included in this step because the LCD has already used them in the previous step to determine whether the operation is a command or data write. 
//    The control bits do not need to be present when the EN signal transitions from high to low.*/
//  DIO_WritePort(&GPIO_PORTB_DATA_R,data); // write data to the data register  
//  DIO_WritePort(&GPIO_PORTB_DATA_R,0); // stop writing data to the LCD
//}
//
//void LCD_Cmd(uint8 command)
//{
//  LCD_Write(command & 0xF0, 0); // Write upper nibble to LCD (extract the MSB from the command)
//  LCD_Write(command << 4,0); // Write lower nibble to LCD (extract the LSB from the command)
//  
//    if (command < 4)
//        delayMs(2);          /* 2ms delay for commands 1 and 2 (1.64ms exactly) */
//    else
//        delayUs(40);        /* 40us delay for other commands */
//}
//
//void LCD_Write_Data(uint8 data)
//{
//    LCD_Write(data & 0xF0, RS);    /* Write upper nibble to LCD and RS = 1 to write data */
//    LCD_Write(data << 4, RS);      /* Write lower nibble to LCD and RS = 1 to write data */
//    delayUs(40);
//}
//
//void LCD_Write_String(uint8_ptr str)
//{  
//	uint32_v i = 0;          //volatile is important 
//	
//	while(*(str+i) != '\0')       //until the end of the string
//	{
//		LCD_Write_Data(*(str+i));    //Write each character of string
//		i++;                        //increment for next character
//	}
//}
//
//void LCD_Write_Integer(int num) {
//    char buffer[16];  // Assuming a 16-character buffer is enough
//    sprintf(buffer, "%d", num);  // Convert the integer to a string
//
//    LCD_Write_String(buffer);  // Display the string on the LCD
//}
//
//
//void LCD_init(void)
//{
//    SYSCTL_RCGCGPIO_R|=0x2; //clk =1 at port B
//    while((SYSCTL_PRGPIO_R & 0x2)!= 0x2); //actual clk value check
//    GPIO_PORTB_CR_R |= 0xFF;
//    GPIO_PORTB_DIR_R|= 0xFF; //all output
//    GPIO_PORTB_DEN_R|= 0xFF; 
//    
//    // initialization sequence
//    delayMs(20); 
//    LCD_Cmd(0x30);
//    delayMs(5);
//    LCD_Cmd(0x30);
//    delayUs(100);
//    LCD_Cmd(0x30);
//    delayUs(40);
//    LCD_Cmd(Function_set_4bit); // select 5x7 font size , 2 rows of LCD  and Select 4-bit Mode of LCD
//    LCD_Cmd(moveCursorRight); // shift cursor right
//    LCD_Cmd(clear_display); // clear whatever is written on display 
//    LCD_Cmd(cursorBlink);  // Enable Display and cursor blinking 
//}   
//
//
//
//
