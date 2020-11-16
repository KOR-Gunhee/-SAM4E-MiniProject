#include ".\cpu.h"

afec_callback_t afec_callback_pointer[NUM_OF_AFEC][_AFEC_NUM_OF_INTERRUPT_SOURCE];

static void afec_set_config(struct afec_config *config)
{
	uint32_t reg = 0;

	reg = (config->useq ? AFE_MR_USEQ_REG_ORDER : 0) |

	(config->anach ? AFE_MR_ANACH_ALLOWED : 0) |
	AFE_MR_PRESCAL(config->mck / (2 * config->afec_clock) - 1) |
	(config->settling_time) |

	AFE_MR_TRACKTIM(config->tracktim) |
	AFE_MR_TRANSFER(config->transfer) |
	(config->startup_time);

	AFEC0->AFE_MR = reg;

	AFEC0->AFE_EMR = (config->tag ? AFE_EMR_TAG : 0) |
	(config->resolution) |
	(config->stm ? AFE_EMR_STM : 0);

	AFEC0->AFE_ACR = AFE_ACR_IBCTL(config->ibctl);
}

enum status_code afec_init(struct afec_config *config)
{
	uint32_t i;
	
	if ((AFEC0->AFE_ISR & AFE_ISR_DRDY) == AFE_ISR_DRDY) {
		return STATUS_ERR_BUSY;
	}
	/* Reset and configure the AFEC module */
	AFEC0->AFE_CR = AFE_CR_SWRST;
	afec_set_config(config);

	for (i = 0; i < _AFEC_NUM_OF_INTERRUPT_SOURCE; i++)
	{
		afec_callback_pointer[0][i] = 0;
	}
	return STATUS_OK;
}

void afec_set_comparison_mode(const enum afec_cmp_mode mode,const enum afec_channel_num channel, uint8_t cmp_filter)
{
	uint32_t reg;

	reg = AFEC0->AFE_EMR;

	reg &= ~(AFE_EMR_CMPSEL_Msk |
	AFE_EMR_CMPMODE_Msk |
	AFE_EMR_CMPFILTER_Msk);
	reg |= mode |
	((channel == AFEC_CHANNEL_ALL) ? AFE_EMR_CMPALL
	: AFE_EMR_CMPSEL(channel)) |
	AFE_EMR_CMPFILTER(cmp_filter);

	AFEC0->AFE_EMR = reg;
}

void afec_get_config_defaults(struct afec_config *const cfg)
{
	/* Sanity check argument. */

	cfg->resolution = AFEC_12_BITS;
	cfg->mck = 120000000;
	cfg->afec_clock = 6000000UL;
	cfg->startup_time = AFEC_STARTUP_TIME_4;
	#if !(SAMV71 || SAMV70 || SAME70 || SAMS70)
	cfg->settling_time = AFEC_SETTLING_TIME_0;
	#endif
	cfg->tracktim = 2;
	cfg->transfer = 1;
	cfg->anach = true;
	cfg->useq = false;
	cfg->tag = true;
	cfg->stm = true;
	cfg->ibctl = 1;
}

void afec_ch_get_config_defaults(struct afec_ch_config *const cfg)
{
	cfg->diff = false;
	cfg->gain = AFEC_GAINVALUE_1;
}

void afec_ch_set_config(const enum afec_channel_num channel, struct afec_ch_config *config)
{
	uint32_t reg = 0;

	reg = AFEC0->AFE_DIFFR;
	reg &= ~(0x1u << channel);
	reg |= (config->diff) ? (0x1u << channel) : 0;
	AFEC0->AFE_DIFFR = reg;

	reg = AFEC0->AFE_CGR;
	reg &= ~(0x03u << (2 * channel));
	reg |= (config->gain) << (2 * channel);
	AFEC0->AFE_CGR = reg;
}

void afec_configure_sequence(const enum afec_channel_num ch_list[], uint8_t uc_num)
{
	uint8_t uc_counter;

	/* Set user sequence mode */
	AFEC0->AFE_MR |= AFE_MR_USEQ_REG_ORDER;
	AFEC0->AFE_SEQ1R = 0;
	AFEC0->AFE_SEQ2R = 0;

	if (uc_num < AFEC_SEQ1_CHANNEL_NUM) {
		for (uc_counter = 0; uc_counter < uc_num; uc_counter++) {
			AFEC0->AFE_SEQ1R |=
			ch_list[uc_counter] << (4 * uc_counter);
		}
		} else {
		for (uc_counter = 0; uc_counter < AFEC_SEQ1_CHANNEL_NUM; uc_counter++) {
			AFEC0->AFE_SEQ1R |=
			ch_list[uc_counter] << (4 * uc_counter);
		}
		for (uc_counter = 0; uc_counter < uc_num - AFEC_SEQ1_CHANNEL_NUM;
		uc_counter++) {
			AFEC0->AFE_SEQ2R |=
			ch_list[uc_counter + AFEC_SEQ1_CHANNEL_NUM] << (4 * uc_counter);
		}
	}
}

void afec_enable_interrupt(enum afec_interrupt_source interrupt_source)
{
	if (interrupt_source == AFEC_INTERRUPT_ALL) {
		AFEC0->AFE_IER = AFEC_INTERRUPT_ALL;
		return;
	}

	if (interrupt_source < AFEC_INTERRUPT_DATA_READY) {
		#if (SAMV71 || SAMV70 || SAME70 || SAMS70)
		if (interrupt_source == AFEC_INTERRUPT_EOC_11) {
			AFEC0->AFE_IER = 1 << AFEC_TEMP_INT_SOURCE_NUM;
			#else
			if (interrupt_source == AFEC_INTERRUPT_EOC_15) {
				AFEC0->AFE_IER = 1 << AFEC_TEMP_INT_SOURCE_NUM;
				#endif
				} else {
				AFEC0->AFE_IER = 1 << interrupt_source;
			}
			} else if (interrupt_source < AFEC_INTERRUPT_TEMP_CHANGE) {
			AFEC0->AFE_IER = 1 << (interrupt_source + AFEC_INTERRUPT_GAP1);
			} else {
			AFEC0->AFE_IER = 1 << (interrupt_source + AFEC_INTERRUPT_GAP1
			+ AFEC_INTERRUPT_GAP2);
		}
	}
	
	void afec_set_callback(enum afec_interrupt_source source, afec_callback_t callback, uint8_t irq_level)
	{
		uint32_t i = 0;
		afec_callback_pointer[i][source] = callback;
		
		irq_register_handler(AFEC0_IRQn, irq_level);
		
		/* Enable the specified interrupt source */
		AFEC0->AFE_IER=(1<<26);
		//afec_enable_interrupt(source);
	}

void afec_disable_interrupt(enum afec_interrupt_source interrupt_source)
{
	if (interrupt_source == AFEC_INTERRUPT_ALL) {
		AFEC0->AFE_IDR = AFEC_INTERRUPT_ALL;
		return;
	}

	if (interrupt_source < AFEC_INTERRUPT_DATA_READY) {
		#if (SAMV71 || SAMV70 || SAME70 || SAMS70)
		if (interrupt_source == AFEC_INTERRUPT_EOC_11) {
			AFEC0->AFE_IDR = 1 << AFEC_TEMP_INT_SOURCE_NUM;
			#else
			if (interrupt_source == AFEC_INTERRUPT_EOC_15) {
				AFEC0->AFE_IDR = 1 << AFEC_TEMP_INT_SOURCE_NUM;
				#endif
				} else {
				AFEC0->AFE_IDR = 1 << interrupt_source;
			}
			} else if (interrupt_source < AFEC_INTERRUPT_TEMP_CHANGE) {
			AFEC0->AFE_IDR = 1 << (interrupt_source + AFEC_INTERRUPT_GAP1);
			} else {
			AFEC0->AFE_IDR = 1 << (interrupt_source + AFEC_INTERRUPT_GAP1
			+ AFEC_INTERRUPT_GAP2);
		}
	}


	extern void afec_interrupt(uint8_t inst_num, enum afec_interrupt_source source)
	{
		if (afec_callback_pointer[inst_num][source]) {
			afec_callback_pointer[inst_num][source]();
		}
	}

	extern void afec_process_callback()
	{
		volatile uint32_t status;
		uint32_t cnt, inst_num;
		status = afec_get_interrupt_status() & afec_get_interrupt_mask();
		inst_num = 0;

		for (cnt = 0; cnt < _AFEC_NUM_OF_INTERRUPT_SOURCE; cnt++)
		{
			if (cnt < AFEC_INTERRUPT_DATA_READY)
			{
				if (status & (1 << cnt))
				{
					afec_interrupt(inst_num, (enum afec_interrupt_source)cnt);
				}
				
			}
			else if (cnt < AFEC_INTERRUPT_TEMP_CHANGE)
			{
				if (status & (1 << (cnt + AFEC_INTERRUPT_GAP1)))
				{
					afec_interrupt(inst_num, (enum afec_interrupt_source)cnt);
				}
			}
			else
			{
				if (status & (1 << (cnt + AFEC_INTERRUPT_GAP1 + AFEC_INTERRUPT_GAP2)))
				{
					afec_interrupt(inst_num, (enum afec_interrupt_source)cnt);
				}
			}
		}
	}



