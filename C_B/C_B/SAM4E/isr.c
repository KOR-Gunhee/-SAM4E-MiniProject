#include ".\cpu.h"

ISR_ST_USART_FIFO volatile ISR_Usart1_Buff;
ISR_ST_CAN_FIFO volatile ISR_Can_Buff;


void USART1_Handler(void)
{
	uint32_t usart1_status;
	usart1_status= US_GET_STATUS(USART1);
	if((usart1_status&US_CSR_RXRDY)==US_CSR_RXRDY)
	{
		if(ISR_Usart1_Buff.Tail>=ISR_SZ_US1_BUFF){ISR_Usart1_Buff.Tail=0;}
		ISR_Usart1_Buff.Buff[ISR_Usart1_Buff.Tail++]=(uint8_t)US_GET_RXDATA(USART1);
	}
	US_RST_RXSTATUS(USART1);
	
}

void CAN0_Handler()
{
	volatile int a = 0;
	char i[32+1];
	
	uint32_t can0_status;
	can0_status=CAN_GET_STATUS(CAN0);
	
	// M/B ready 
	if ((can0_status&CAN_SR_MB4)==CAN_SR_MB4)
	{
		if (datal_val(4)==0x12345678)
		{
			LED_ON(9);
			Board_ID_SET();
		}
		CAN_RST_RXSTATUS(CAN0,4);
	}
	
	else if ((can0_status&CAN_SR_MB5)==CAN_SR_MB5)
	{
		if(ISR_Can_Buff.Tail>=ISR_SZ_CAN_BUFF){ISR_Can_Buff.Tail=0;}
		ISR_Can_Buff.Buff[ISR_Can_Buff.Tail++]=datal_val(5);
		CAN_RST_RXSTATUS(CAN0,5);
	}
	
	else if ((can0_status&CAN_SR_MB6)==CAN_SR_MB6)
	{
		a=datal_val(6);
//		US_SendString("Good");
		US_SendString(utoa(a,i,10));
		US_SendString("\r\n");
		CAN_RST_RXSTATUS(CAN0,6);
	}
}

void AFEC0_Handler()
{
	afec_process_callback();
}