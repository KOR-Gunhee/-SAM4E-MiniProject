/*
 * Delay.c
 *
 * Created: 2018-08-02 오후 2:25:18
 *  Author: DEV_PC
 */ 

#include "SAM4E/cpu.h"
#include "Delay.h"


void InitRealTime()
{
	RTT->RTT_MR=0;
	RTT->RTT_MR=(31<<0);
	RTT->RTT_AR=500;
	RTT->RTT_MR|=(1<<16);
	NVIC_ClearPendingIRQ(RTT_IRQn);
	NVIC_EnableIRQ(RTT_IRQn);
}
