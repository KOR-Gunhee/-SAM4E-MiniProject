#define US_RXD1 21
#define US_TXD1 22
#define US_TXRDY 1
#define US_RXRDY 0
#define US_TXEN 6
#define US_RXEN 4
#define US_CD 0


#ifndef USART_H_
#define USART_H_

void Init_USART();
void US_SendByte(unsigned char ch);
int US_SendString(const char *S_str);
uint32_t US_receive(void);
uint32_t US_ReadByte(uint16_t *data);

#endif /* USART_H_ */