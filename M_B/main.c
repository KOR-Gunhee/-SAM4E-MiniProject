#include "sam.h"
#include "main.h"
#include <string.h>

uint32_t ul_sysclk = 84000000;

int CAN_msg_status=0;
volatile int count=0;

enum afec_channel_num ch_list[] =
{
	AFEC_CHANNEL_0,
};

static inline enum status_code afec_start_calibration()
{
	uint32_t reg;

	reg = AFEC0->AFE_CHSR;
	AFEC0->AFE_CDOR = reg;

	if ((AFEC0->AFE_MR & AFE_MR_FREERUN) == AFE_MR_FREERUN_ON) {
		return STATUS_ERR_BUSY;
	}
	AFEC0->AFE_CR = AFE_CR_AUTOCAL;
	return STATUS_OK;
}

static void Init_ADC()
{
	struct afec_config afec_cfg;
	struct afec_ch_config afec_ch_cfg;
	
	PMC->PMC_PCER0|=(1<<ID_AFEC0);
	
	afec_get_config_defaults(&afec_cfg);
	afec_ch_get_config_defaults(&afec_ch_cfg);
	
	afec_init(&afec_cfg);
	afec_ch_set_config(AFEC_CHANNEL_0, &afec_ch_cfg);
	afec_channel_set_analog_offset(AFEC_CHANNEL_0, 0x800);
	afec_set_trigger(AFEC_TRIG_SW);
	afec_channel_enable(AFEC_CHANNEL_0);
	afec_set_callback(AFEC_INTERRUPT_DATA_READY, Volt_val, 1);
	afec_start_calibration();
	while((afec_get_interrupt_status() & AFE_ISR_EOCAL) != AFE_ISR_EOCAL);
}

void Init_BD()
{
	WDT->WDT_MR=WDT_MR_WDDIS;
	
	SystemInit();
	
	__disable_irq();
	
	PMC_Ena();
	
	PIOInit();

	can_reset_all_mailbox(CAN0);
	can_init(CAN0, ul_sysclk, 1000);
	CANBOARD();

	__enable_irq();
}

int main()
{	
	uint8_t  byte01;
	
	g_afec0_sample_data = 0;
	g_max_digital = MAX_DIGITAL_12_BIT;

    Init_BD();
 	Init_ADC();
	ADC_START();	
	
	Pin1;
	
 	while (1) 
    {	
		if (CAN_Getmsg(&byte01)>0)
		{
			count++;
			CH_Set(BD_CH);
		}
	}
} 
