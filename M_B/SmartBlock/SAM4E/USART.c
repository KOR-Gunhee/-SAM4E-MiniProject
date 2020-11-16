#include ".\cpu.h"

void Init_USART()
{
	USART1->US_BRGR=(67<<US_CD);
	
	USART1->US_MR|=((1<<6)|(1<<7));
	USART1->US_MR|=(1<<11);
	USART1->US_MR&=~((1<<10)|(1<<9));
	USART1->US_MR&=~((1<<13)|(1<<12));
	USART1->US_MR&=~((1<<15)|(1<<14));
	
	NVIC_ClearPendingIRQ(USART1_IRQn);
	NVIC_EnableIRQ(USART1_IRQn);
	
	USART1->US_CR=((1<<US_TXEN)|(1<<US_RXEN));
	USART1->US_IER=US_IER_RXRDY;
}

void US_SendByte(unsigned char ch)
{
	while((USART1->US_CSR&(1<<US_TXRDY))==0);

	USART1->US_THR=ch;
}

int US_SendString(const char *S_str)
{
	while(*S_str)
	{
		US_SendByte(*S_str);
		S_str++;
	}
	return 0;
}

uint32_t US_receive(void)
{
	while((USART1->US_CSR&(1<<US_RXRDY))==0);
	return USART1->US_RHR;
}

uint32_t US_ReadByte(uint16_t *data)
{  
	 
	if((USART1->US_CSR&(1<<US_RXRDY))==0)
	return 1;

	*data = (uint16_t)USART1->US_RHR;
	return 0;
}
