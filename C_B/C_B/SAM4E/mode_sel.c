#include ".\cpu.h"


void ch_rst()
{
	PIOD->PIO_PER&=0;
	PIOD->PIO_OER&=0;
	PIOD->PIO_CODR&=0;
}

void ch_High(Pio *pio, uint8_t ch)
{
	ch_On(pio,ch);
	ch_Ena(pio,ch);
	ch_set(pio,ch);
}

void PinSearch_suffle(uint8_t ch)
{
	for (volatile int i=0;i<=2;i++)
	{
		if (i==0){CAN_msgID(ch,0);}
		else if (i==1){CAN_msgID(ch,1);}
		else if (i==2){CAN_msgID(ch,8);}
		for (volatile int j=51;j<=100;j++)
		{
			MyDelay2(1000,10000);
			CAN_Lowdata(ch,j);
			CAN_TX(ch);
		}
	}
}