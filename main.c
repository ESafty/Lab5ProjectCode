void main() {
  int Y;

  ANSELA.RA1 = 1; // setting RA1 as analogue input and port D as digital output
  ANSELD=0;
  TRISA.RA1 = 1;
  TRISD=0;
  
  UART1_Init(9600); 
  Delay_ms(100);
  
  UART_Write_Text("LDR Readings:");  // displays on the UART monitor the message "LDR Readings"
  UART1_Write(13);
  UART1_Write(10);
  Delay_ms(1000);

  while(1) // infinite loop
  {
  Z = ADC_Read(1); // reads the analogue value of the LDR from RA1

  if(Z > 500) // condition of resistance 
  {
   UART1_Write_Text("limuinous");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(500);
   PORTD = 0xFF;  // PORT D = Activate
   }
   else
   {
   UART1_Write_Text("non limunious");
   UART1_Write(13);
   UART1_Write(10);
   Delay_ms(100);
   PORTD = 0x00; // PORT D = Deactivate
   }
   
  }
  }
