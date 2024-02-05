void LM35_init(void);
void UART0Tx(char c);
void UART0_puts(char* s);
int ReadTemperature(void);
void UART_SendTemperature(int temperature);