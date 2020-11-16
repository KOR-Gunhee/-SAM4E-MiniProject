/*
 * ADC.h
 *
 * Created: 2018-07-19 오후 12:03:36
 *  Author: DEV_PC
 */ 


#ifndef ADC_H_
#define ADC_H_

typedef unsigned char           bool; //!< Boolean.

#define AFEC_SEQ1_CHANNEL_NUM                (8UL)
#define AFEC_INTERRUPT_GAP1                  (8UL)
#define AFEC_INTERRUPT_GAP2                  (1UL)
#define AFEC_TEMP_INT_SOURCE_NUM             (15UL)
#define NUM_OF_AFEC    (1UL)
#define false     0
#define true      1

#  define irq_register_handler(int_num, int_prio)                      \
NVIC_ClearPendingIRQ(    (IRQn_Type)int_num);                      \
NVIC_SetPriority(    (IRQn_Type)int_num, int_prio);                \
NVIC_EnableIRQ(      (IRQn_Type)int_num);                          \

#include <stdlib.h>

enum afec_channel_num {
	AFEC_CHANNEL_0 = 0,
	AFEC_CHANNEL_1,
	AFEC_CHANNEL_2,
	AFEC_CHANNEL_3,
	AFEC_CHANNEL_4,
	AFEC_CHANNEL_5,
	AFEC_CHANNEL_6,
	AFEC_CHANNEL_7,
	AFEC_CHANNEL_8,
	AFEC_CHANNEL_9,
	AFEC_CHANNEL_10,
	AFEC_CHANNEL_11,
	AFEC_CHANNEL_12,
	AFEC_CHANNEL_13,
	AFEC_CHANNEL_14,
	AFEC_TEMPERATURE_SENSOR,
	AFEC_CHANNEL_ALL = 0xFFFF,
} ;

enum afec_interrupt_source {
	AFEC_INTERRUPT_EOC_0 = 0,
	AFEC_INTERRUPT_EOC_1,
	AFEC_INTERRUPT_EOC_2,
	AFEC_INTERRUPT_EOC_3,
	AFEC_INTERRUPT_EOC_4,
	AFEC_INTERRUPT_EOC_5,
	AFEC_INTERRUPT_EOC_6,
	AFEC_INTERRUPT_EOC_7,
	AFEC_INTERRUPT_EOC_8,
	AFEC_INTERRUPT_EOC_9,
	AFEC_INTERRUPT_EOC_10,
	AFEC_INTERRUPT_EOC_11,
	AFEC_INTERRUPT_EOC_12,
	AFEC_INTERRUPT_EOC_13,
	AFEC_INTERRUPT_EOC_14,
	AFEC_INTERRUPT_EOC_15,
	AFEC_INTERRUPT_DATA_READY,
	AFEC_INTERRUPT_OVERRUN_ERROR,
	AFEC_INTERRUPT_COMP_ERROR,
	AFEC_INTERRUPT_END_RXBUF,
	AFEC_INTERRUPT_RXBUF_FULL,
	AFEC_INTERRUPT_TEMP_CHANGE,
	AFEC_INTERRUPT_END_CAL,
	_AFEC_NUM_OF_INTERRUPT_SOURCE,
	AFEC_INTERRUPT_ALL = 0xDF00FFFF,
};

enum status_code {
	STATUS_OK               =  0, //!< Success
	STATUS_ERR_BUSY         =  0x19,
	STATUS_ERR_DENIED       =  0x1C,
	STATUS_ERR_TIMEOUT      =  0x12,
	ERR_IO_ERROR            =  -1, //!< I/O error
	ERR_FLUSHED             =  -2, //!< Request flushed from queue
	ERR_TIMEOUT             =  -3, //!< Operation timed out
	ERR_BAD_DATA            =  -4, //!< Data integrity check failed
	ERR_PROTOCOL            =  -5, //!< Protocol error
	ERR_UNSUPPORTED_DEV     =  -6, //!< Unsupported device
	ERR_NO_MEMORY           =  -7, //!< Insufficient memory
	ERR_INVALID_ARG         =  -8, //!< Invalid argument
	ERR_BAD_ADDRESS         =  -9, //!< Bad address
	ERR_BUSY                =  -10, //!< Resource is busy
	ERR_BAD_FORMAT          =  -11, //!< Data format not recognized
	ERR_NO_TIMER            =  -12, //!< No timer available
	ERR_TIMER_ALREADY_RUNNING   =  -13, //!< Timer already running
	ERR_TIMER_NOT_RUNNING   =  -14, //!< Timer not running
	ERR_ABORTED             =  -15, //!< Operation aborted by user
	/**
	 * \brief Operation in progress
	 *
	 * This status code is for driver-internal use when an operation
	 * is currently being performed.
	 *
	 * \note Drivers should never return this status code to any
	 * callers. It is strictly for internal use.
	 */
	OPERATION_IN_PROGRESS	= -128,
};

enum afec_resolution {
	AFEC_10_BITS = AFE_EMR_RES_LOW_RES,       /* AFEC 10-bit resolution */
	AFEC_12_BITS = AFE_EMR_RES_NO_AVERAGE,    /* AFEC 12-bit resolution */
	AFEC_13_BITS = AFE_EMR_RES_OSR4,          /* AFEC 13-bit resolution */
	AFEC_14_BITS = AFE_EMR_RES_OSR16,         /* AFEC 14-bit resolution */
	AFEC_15_BITS = AFE_EMR_RES_OSR64,         /* AFEC 15-bit resolution */
	AFEC_16_BITS = AFE_EMR_RES_OSR256         /* AFEC 16-bit resolution */
};

/** Definitions for AFEC Start Up Time */
enum afec_startup_time {
	AFEC_STARTUP_TIME_0 = AFE_MR_STARTUP_SUT0,
	AFEC_STARTUP_TIME_1 = AFE_MR_STARTUP_SUT8,
	AFEC_STARTUP_TIME_2 = AFE_MR_STARTUP_SUT16,
	AFEC_STARTUP_TIME_3 = AFE_MR_STARTUP_SUT24,
	AFEC_STARTUP_TIME_4 = AFE_MR_STARTUP_SUT64,
	AFEC_STARTUP_TIME_5 = AFE_MR_STARTUP_SUT80,
	AFEC_STARTUP_TIME_6 = AFE_MR_STARTUP_SUT96,
	AFEC_STARTUP_TIME_7 = AFE_MR_STARTUP_SUT112,
	AFEC_STARTUP_TIME_8 = AFE_MR_STARTUP_SUT512,
	AFEC_STARTUP_TIME_9 = AFE_MR_STARTUP_SUT576,
	AFEC_STARTUP_TIME_10 = AFE_MR_STARTUP_SUT640,
	AFEC_STARTUP_TIME_11 = AFE_MR_STARTUP_SUT704,
	AFEC_STARTUP_TIME_12 = AFE_MR_STARTUP_SUT768,
	AFEC_STARTUP_TIME_13 = AFE_MR_STARTUP_SUT832,
	AFEC_STARTUP_TIME_14 = AFE_MR_STARTUP_SUT896,
	AFEC_STARTUP_TIME_15 = AFE_MR_STARTUP_SUT960
};

/** Definitions for AFEC analog settling time */
enum afec_settling_time {
	AFEC_SETTLING_TIME_0 = AFE_MR_SETTLING_AST3,
	AFEC_SETTLING_TIME_1 = AFE_MR_SETTLING_AST5,
	AFEC_SETTLING_TIME_2 = AFE_MR_SETTLING_AST9,
	AFEC_SETTLING_TIME_3 = AFE_MR_SETTLING_AST17
};

enum afec_cmp_mode {
	AFEC_CMP_MODE_0 = AFE_EMR_CMPMODE_LOW,
	AFEC_CMP_MODE_1 = AFE_EMR_CMPMODE_HIGH,
	AFEC_CMP_MODE_2 = AFE_EMR_CMPMODE_IN,
	AFEC_CMP_MODE_3 = AFE_EMR_CMPMODE_OUT

};
enum afec_gainvalue {
	AFEC_GAINVALUE_0 = 0,
	AFEC_GAINVALUE_1 = 1,
	AFEC_GAINVALUE_2 = 2,
	AFEC_GAINVALUE_3 = 3

};

enum afec_trigger {
	/* Starting a conversion is only possible by software. */
	AFEC_TRIG_SW = AFE_MR_TRGEN_DIS,
	/* External trigger */
	AFEC_TRIG_EXT = AFE_MR_TRGSEL_AFE_TRIG0 | AFE_MR_TRGEN,
	/* TIO Output of the Timer Counter Channel 0 */
	AFEC_TRIG_TIO_CH_0 = AFE_MR_TRGSEL_AFE_TRIG1 | AFE_MR_TRGEN,
	/* TIO Output of the Timer Counter Channel 1 */
	AFEC_TRIG_TIO_CH_1 = AFE_MR_TRGSEL_AFE_TRIG2 | AFE_MR_TRGEN,
	/* TIO Output of the Timer Counter Channel 2 */
	AFEC_TRIG_TIO_CH_2 = AFE_MR_TRGSEL_AFE_TRIG3 | AFE_MR_TRGEN,
	/* PWM Event Line 0 */
	AFEC_TRIG_PWM_EVENT_LINE_0 = AFE_MR_TRGSEL_AFE_TRIG4 | AFE_MR_TRGEN,
	/* PWM Event Line 1 */
	AFEC_TRIG_PWM_EVENT_LINE_1 = AFE_MR_TRGSEL_AFE_TRIG5 | AFE_MR_TRGEN,
	/* Freerun mode conversion. */
	AFEC_TRIG_FREERUN = 0xFF,
};

struct afec_ch_config {
	/** Differential Mode */
	bool diff;
	/** Gain Value */
	enum afec_gainvalue gain;
};

struct afec_config {
	/** Resolution */
	enum afec_resolution resolution;
	/** Master Clock */
	uint32_t mck;
	/** AFEC Clock */
	uint32_t afec_clock;
	/** Start Up Time */
	enum afec_startup_time startup_time;
	/** Analog Settling Time = (settling_time + 1) / AFEC clock */
	enum afec_settling_time settling_time;
	/** Tracking Time = tracktim / AFEC clock */
	uint8_t tracktim;
	/** Transfer Period = (transfer * 2 + 3) / AFEC clock */
	uint8_t transfer;
	/** Analog Change */
	bool anach;
	/** Use Sequence Enable */
	bool useq;
	/** TAG of AFE_LDCR register */
	bool tag;
	/** Single Trigger Mode */
	bool stm;
	/** AFE Bias Current Control */
	uint8_t ibctl;
};

static inline void afec_set_comparison_window(const uint16_t us_low_threshold, const uint16_t us_high_threshold)
{
	AFEC0->AFE_CWR = AFE_CWR_LOWTHRES(us_low_threshold) |
	AFE_CWR_HIGHTHRES(us_high_threshold);
}

static inline uint32_t afec_channel_get_value(enum afec_channel_num afec_ch)
{
	AFEC0->AFE_CSELR = afec_ch;
	return AFEC0->AFE_CDR;
}

static inline uint32_t afec_get_latest_value()
{
	return AFEC0->AFE_LCDR & AFE_LCDR_LDATA_Msk;
}

static inline void afec_channel_set_analog_offset(enum afec_channel_num afec_ch, uint16_t aoffset)
{
	AFEC0->AFE_CSELR = afec_ch;
	AFEC0->AFE_COCR = (aoffset & AFE_COCR_AOFF_Msk);
}

static inline void ADC_START()
{
	AFEC0->AFE_CR = AFE_CR_START;
}

static inline void afec_channel_enable(const enum afec_channel_num afec_ch)
{
	AFEC0->AFE_CHER = (afec_ch == AFEC_CHANNEL_ALL) ?
	AFEC_CHANNEL_ALL : 1 << afec_ch;
}

static inline void afec_set_trigger(const enum afec_trigger trigger)
{
	uint32_t reg;

	reg = AFEC0->AFE_MR;

	if (trigger == AFEC_TRIG_FREERUN) {
		reg |= AFE_MR_FREERUN_ON;
		} else {
		reg &= ~(AFE_MR_TRGSEL_Msk | AFE_MR_TRGEN | AFE_MR_FREERUN_ON);
		reg |= trigger;
	}

	AFEC0->AFE_MR = reg;
}

static inline uint32_t afec_get_interrupt_status()
{
	return AFEC0->AFE_ISR;
}

static inline uint32_t afec_get_interrupt_mask()
{
	return AFEC0->AFE_IMR;
}

typedef void (*afec_callback_t)(void);

enum status_code afec_init(struct afec_config *config);
void afec_get_config_defaults(struct afec_config *const cfg);
void afec_ch_get_config_defaults(struct afec_ch_config *const cfg);
void afec_ch_set_config(const enum afec_channel_num channel, struct afec_ch_config *config);
void afec_configure_sequence(const enum afec_channel_num ch_list[], uint8_t uc_num);
void afec_set_callback(enum afec_interrupt_source source, afec_callback_t callback, uint8_t irq_level);
void afec_process_callback();
void afec_interrupt(uint8_t inst_num, enum afec_interrupt_source source);
void afec_enable_interrupt(enum afec_interrupt_source interrupt_source);
void afec_disable_interrupt(enum afec_interrupt_source interrupt_source);
void afec_set_comparison_mode(const enum afec_cmp_mode mode, const enum afec_channel_num channel,uint8_t cmp_filter);

#endif /* ADC_H_ */
