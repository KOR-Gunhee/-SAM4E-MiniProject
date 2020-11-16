/*
 * ID.h
 *
 * Created: 2018-07-27 오후 2:38:14
 *  Author: DEV_PC
 */ 


#ifndef ID_H_
#define ID_H_

#include "CH.h"
#include "Delay.h"

#define Board1 0x1000
#define Board2 0x1001
#define Board3 0x1002

#define VOLT_REF        (3300)
#define MAX_DIGITAL_12_BIT     (4095UL)

static uint32_t g_max_digital;
float g_afec0_sample_data;

static uint32_t val_MDL;
static uint32_t aver_val;
static volatile int suffle00=0;

extern uint16_t SLOT_ID;
extern uint16_t MCU_ID;
extern uint16_t BD_ID;
extern uint32_t Init_ID;


static uint32_t check_ID(float temp)
{
	int32_t j;
	float f;
	
	f = 100.00 * temp;

	j = (uint32_t)f;

	j = j / 100;
	
	return j;
}

static void Volt_aver(uint32_t val)
{
	uint16_t max_val = 2240;
	
//	CAN_Lowdata(2,val);
//	CAN_msgTx(2,0x20);
	
	for (volatile int a=0;a<=17;a++)
	{
		if (((max_val-(130*a))>val)&&(val>(max_val-60-(130*a))))
		{
			SLOT_ID=0;
			if (PIOB->PIO_PDSR&(1<<14))
			{
				MyDelay2(1000,2000);
				MCU_ID=0;
				Main_Init_send();
			}
			else
			{
				MyDelay2(1000,2000);
				MCU_ID=1;
				Main_Init_send();
			}
			break;
		}
	}
}

static void Volt_val(void)
{	
	g_afec0_sample_data = afec_get_latest_value();
	val_MDL=check_ID(g_afec0_sample_data * VOLT_REF / g_max_digital);
	
	if (suffle00==14)
	{
		Volt_aver(aver_val/15);
		suffle00=0;
	}
	else if (suffle00<14)
	{
		aver_val+=val_MDL;
		ADC_START();
		suffle00++;
	}
}

void define_BDID(uint16_t num);

#endif /* ID_H_ */