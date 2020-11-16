/*
 * Delay.c
 *
 * Created: 2018-08-02 오후 2:25:18
 *  Author: DEV_PC
 */ 

#include ".\cpu.h"

void MyDelay(volatile uint32_t delay)
{
	while(delay)
	{
		delay--;
	}
}
void MyDelay2(volatile uint32_t delay1,volatile uint32_t delay2)
{
	while(delay1)
	{
		MyDelay(delay2);
		delay1--;
	}
}