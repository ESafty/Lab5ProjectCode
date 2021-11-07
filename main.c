void main() {
  int Y;

  ANSELA.RA1 = 1;
  ANSELD=0;
  TRISA.RA1 = 1;
  TRISD=0;
  
  UART1_Init(9600);
  Delay_ms(100);
  
  UART_Write_Text("LDR Readings:");
  UART1_Write(13);
  UART1_Write(10);
  Delay_ms(1000);

  while(1)
  {
  Z = ADC_Read(1);

  if(Z > 500)
  {
   UART1_Write_Text("limuinous");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(500);
   PORTD = 0xFF;
   }
   else
   {
   UART1_Write_Text("non limunious");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(100);
   PORTD = 0x00;
   }
   
  }
  }