#include ".\cpu.h"

uint16_t SLOT_ID=0;
uint16_t MCU_ID=0;
uint16_t BD_ID=0;
uint32_t Init_ID=0;


void define_BDID(uint16_t num)
{
	if (num==Board1)
	{
		BD_ID=0;
	}
	else if (num==Board2)
	{
		BD_ID=1;
	}
	else if (num==Board3)
	{
		BD_ID=3;
	}
	Init_ID=MCU_ID+(BD_ID<<1)+(SLOT_ID<<3);
	CAN_CH_receive(Init_ID);
}

