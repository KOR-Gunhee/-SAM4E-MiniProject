#include "sam.h"
#include "main.h"

uint32_t ul_sysclk = 84000000;

int US_msg_status=0;
int CAN_msg_status=0;

static uint32_t g_max_digital = 0;
static uint16_t gs_us_low_threshold = 0;
static uint16_t gs_us_high_threshold = 0;


static void afec_print_comp_result(void)
{
	uint16_t us_adc;
	char i[32+1];
	volatile int a=0;
	
	/* Disable Compare Interrupt. */
	afec_disable_interrupt(AFEC_INTERRUPT_COMP_ERROR);

	a=afec_channel_get_value(AFEC_CHANNEL_0);
	us_adc = afec_channel_get_value(AFEC_CHANNEL_0);

	US_SendString(utoa(Pin_num-1,i,10));
	US_SendString("\r\n");
	Pin_num=41;
}

void pin_search()
{
	gs_us_low_threshold = 0x0;
	gs_us_high_threshold = 0x7FF;	
	
	struct afec_config afec_cfg;
	struct afec_ch_config afec_ch_cfg;
	
	afec_get_config_defaults(&afec_cfg);
	afec_init(&afec_cfg);
	
	afec_ch_get_config_defaults(&afec_ch_cfg);
	afec_channel_set_analog_offset(AFEC_CHANNEL_0, 0x800);
	afec_ch_set_config(AFEC_CHANNEL_0, &afec_ch_cfg);
	afec_set_trigger(AFEC_TRIG_SW);
	afec_set_comparison_mode(AFEC_CMP_MODE_2, AFEC_CHANNEL_0, 0);
	afec_set_comparison_window(gs_us_low_threshold, gs_us_high_threshold);
	afec_channel_enable(AFEC_CHANNEL_0);
	afec_set_callback(AFEC_INTERRUPT_COMP_ERROR, afec_print_comp_result, 1);
}	

void Init_BD()
{
	WDT->WDT_MR=WDT_MR_WDDIS;
	
	SystemInit();
	
	__disable_irq();
	
	PMC_Ena();
	
	PIOInit();
	
	Init_USART();
	
	can_reset_all_mailbox(CAN0);
	can_init(CAN0, ul_sysclk, 1000);
	CANBOARD();
	
	__enable_irq();
}

int main()
{
	uint8_t  byte00;
	
	g_max_digital = MAX_DIGITAL_12_BIT;
	
	Init_BD();
	pin_search();
 	Main_Init_receive();
	
	
	//BD1 Relay ON
	PIO_OUT_SET(PIOD,0x00000040);
		
	
	while (1)	
    {	
		if (US_GetString(&byte00)>0)
 		{
			if (US_msg_status==1)
			{
				ID_Check(atoi(US_Buff));
			}
 		}
	}
}
