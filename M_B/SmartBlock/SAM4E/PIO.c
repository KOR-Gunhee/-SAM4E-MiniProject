﻿#include ".\cpu.h"

void PIOA_SET()
{
	//----------- PIOC Config --------------------
	PIO_DIS_INTR(PIOA,BD_PIOA_MSK);
	// pull-up and pull down
	PIO_DIS_PULLUP(PIOA,~(uint32_t)BD_PIOA_PULLUP);
	PIO_EN_PULLUP(PIOA,BD_PIOA_PULLUP);
	PIO_DIS_PULLDOWN(PIOA,(~(uint32_t)BD_PIOA_PULLDN));
	PIO_EN_PULLDOWN(PIOA,BD_PIOA_PULLDN);
	// filter
	PIO_DIS_INFLT(PIOA,~(uint32_t)BD_PIOA_INFILTER);
	PIO_EN_INFLT(PIOA,BD_PIOA_INFILTER);
	PIO_DIS_IFSLOWCLK(PIOA,~(uint32_t)BD_PIOA_DEBOUNC);
	PIO_EN_IFSLOWCLK(PIOA,BD_PIOA_DEBOUNC);
	PIO_SET_DEBOUNCE(PIOA,DB_PIOA_FLTCLKDIV);
	// OUTPUT Config
	PIO_DIS_OPENDRAIN(PIOA,~(uint32_t)BD_PIOA_OPENDRAIN);
	PIO_EN_OPENDRAIN(PIOA,BD_PIOA_OPENDRAIN);
	PIO_OUT_CLR(PIOA,~(uint32_t)BD_PIOA_DEFVAL);
	PIO_OUT_SET(PIOA,BD_PIOA_DEFVAL);
	// IO Enable
	PIO_DIS_OUT(PIOA,~(uint32_t)BD_PIOA_DIR);
	PIO_EN_OUT(PIOA,BD_PIOA_DIR);
	PIO_DIS_IO(PIOA,~(uint32_t)BD_PIOA_MSK);
	PIO_EN_IO(PIOA,BD_PIOA_MSK);
}

void PIOB_SET()
{
	//----------- PIOC Config --------------------
	PIO_DIS_INTR(PIOB,BD_PIOB_MSK);
	// pull-up and pull down
	PIO_DIS_PULLUP(PIOB,~(uint32_t)BD_PIOB_PULLUP);
	PIO_EN_PULLUP(PIOB,BD_PIOB_PULLUP);
	PIO_DIS_PULLDOWN(PIOB,(~(uint32_t)BD_PIOB_PULLDN));
	PIO_EN_PULLDOWN(PIOB,BD_PIOB_PULLDN);
	// filter
	PIO_DIS_INFLT(PIOB,~(uint32_t)BD_PIOB_INFILTER);
	PIO_EN_INFLT(PIOB,BD_PIOB_INFILTER);
	PIO_DIS_IFSLOWCLK(PIOB,~(uint32_t)BD_PIOB_DEBOUNC);
	PIO_EN_IFSLOWCLK(PIOB,BD_PIOB_DEBOUNC);
	PIO_SET_DEBOUNCE(PIOB,DB_PIOB_FLTCLKDIV);
	// OUTPUT Config
	PIO_DIS_OPENDRAIN(PIOB,~(uint32_t)BD_PIOB_OPENDRAIN);
	PIO_EN_OPENDRAIN(PIOB,BD_PIOB_OPENDRAIN);
	PIO_OUT_CLR(PIOB,~(uint32_t)BD_PIOB_DEFVAL);
	PIO_OUT_SET(PIOB,BD_PIOB_DEFVAL);
	// IO Enable
	PIO_DIS_OUT(PIOB,~(uint32_t)BD_PIOB_DIR);
	PIO_EN_OUT(PIOB,BD_PIOB_DIR);
	PIO_DIS_IO(PIOB,~(uint32_t)BD_PIOB_MSK);
	PIO_EN_IO(PIOB,BD_PIOB_MSK);
}

void PIOC_SET()
{
	//----------- PIOC Config --------------------
	PIO_DIS_INTR(PIOC,BD_PIOC_MSK);
	// pull-up and pull down
	PIO_DIS_PULLUP(PIOC,~(uint32_t)BD_PIOC_PULLUP);
	PIO_EN_PULLUP(PIOC,BD_PIOC_PULLUP);
	PIO_DIS_PULLDOWN(PIOC,(~(uint32_t)BD_PIOC_PULLDN));
	PIO_EN_PULLDOWN(PIOC,BD_PIOC_PULLDN);
	// filter
	PIO_DIS_INFLT(PIOC,~(uint32_t)BD_PIOC_INFILTER);
	PIO_EN_INFLT(PIOC,BD_PIOC_INFILTER);
	PIO_DIS_IFSLOWCLK(PIOC,~(uint32_t)BD_PIOC_DEBOUNC);
	PIO_EN_IFSLOWCLK(PIOC,BD_PIOC_DEBOUNC);
	PIO_SET_DEBOUNCE(PIOC,DB_PIOC_FLTCLKDIV);
	// OUTPUT Config
	PIO_DIS_OPENDRAIN(PIOC,~(uint32_t)BD_PIOC_OPENDRAIN);
	PIO_EN_OPENDRAIN(PIOC,BD_PIOC_OPENDRAIN);
	PIO_OUT_CLR(PIOC,~(uint32_t)BD_PIOC_DEFVAL);
	PIO_OUT_SET(PIOC,BD_PIOC_DEFVAL);
	// IO Enable
	PIO_DIS_OUT(PIOC,~(uint32_t)BD_PIOC_DIR);
	PIO_EN_OUT(PIOC,BD_PIOC_DIR);
	PIO_DIS_IO(PIOC,~(uint32_t)BD_PIOC_MSK);
	PIO_EN_IO(PIOC,BD_PIOC_MSK);
}

void PIOD_SET()
{
	//----------- PIOC Config --------------------
	PIO_DIS_INTR(PIOD,BD_PIOD_MSK);
	// pull-up and pull down
	PIO_DIS_PULLUP(PIOD,~(uint32_t)BD_PIOD_PULLUP);
	PIO_EN_PULLUP(PIOD,BD_PIOD_PULLUP);
	PIO_DIS_PULLDOWN(PIOD,(~(uint32_t)BD_PIOD_PULLDN));
	PIO_EN_PULLDOWN(PIOD,BD_PIOD_PULLDN);
	// filter
	PIO_DIS_INFLT(PIOD,~(uint32_t)BD_PIOD_INFILTER);
	PIO_EN_INFLT(PIOD,BD_PIOD_INFILTER);
	PIO_DIS_IFSLOWCLK(PIOD,~(uint32_t)BD_PIOD_DEBOUNC);
	PIO_EN_IFSLOWCLK(PIOD,BD_PIOD_DEBOUNC);
	PIO_SET_DEBOUNCE(PIOD,DB_PIOD_FLTCLKDIV);
	// OUTPUT Config
	PIO_DIS_OPENDRAIN(PIOD,~(uint32_t)BD_PIOD_OPENDRAIN);
	PIO_EN_OPENDRAIN(PIOD,BD_PIOD_OPENDRAIN);
	PIO_OUT_CLR(PIOD,~(uint32_t)BD_PIOD_DEFVAL);
	PIO_OUT_SET(PIOD,BD_PIOD_DEFVAL);
	// IO Enable
	PIO_DIS_OUT(PIOD,~(uint32_t)BD_PIOD_DIR);
	PIO_EN_OUT(PIOD,BD_PIOD_DIR);
	PIO_DIS_IO(PIOD,~(uint32_t)BD_PIOD_MSK);
	PIO_EN_IO(PIOD,BD_PIOD_MSK);
}

void PIOE_SET()
{
	//----------- PIOC Config --------------------
	PIO_DIS_INTR(PIOE,BD_PIOE_MSK);
	// pull-up and pull down
	PIO_DIS_PULLUP(PIOE,~(uint32_t)BD_PIOE_PULLUP);
	PIO_EN_PULLUP(PIOE,BD_PIOE_PULLUP);
	PIO_DIS_PULLDOWN(PIOE,(~(uint32_t)BD_PIOE_PULLDN));
	PIO_EN_PULLDOWN(PIOE,BD_PIOE_PULLDN);
	// filter
	PIO_DIS_INFLT(PIOE,~(uint32_t)BD_PIOD_INFILTER);
	PIO_EN_INFLT(PIOE,BD_PIOE_INFILTER);
	PIO_DIS_IFSLOWCLK(PIOE,~(uint32_t)BD_PIOE_DEBOUNC);
	PIO_EN_IFSLOWCLK(PIOE,BD_PIOE_DEBOUNC);
	PIO_SET_DEBOUNCE(PIOE,DB_PIOE_FLTCLKDIV);
	// OUTPUT Config
	PIO_DIS_OPENDRAIN(PIOE,~(uint32_t)BD_PIOE_OPENDRAIN);
	PIO_EN_OPENDRAIN(PIOE,BD_PIOE_OPENDRAIN);
	PIO_OUT_CLR(PIOE,~(uint32_t)BD_PIOE_DEFVAL);
	PIO_OUT_SET(PIOE,BD_PIOD_DEFVAL);
	// IO Enable
	PIO_DIS_OUT(PIOE,~(uint32_t)BD_PIOE_DIR);
	PIO_EN_OUT(PIOE,BD_PIOD_DIR);
	PIO_DIS_IO(PIOE,~(uint32_t)BD_PIOE_MSK);
	PIO_EN_IO(PIOE,BD_PIOE_MSK);
}

void PIOInit(void)
{
	//CAN0 PORT B 주변장치 활성화 및 기능 A 사용
	PIOB->PIO_ABCDSR[0]&=~((1<<CANRX0)|(1<<CANTX0));
	PIOB->PIO_ABCDSR[1]&=~((1<<CANRX0)|(1<<CANTX0));
	
	PIOA_SET();
	PIOB_SET();
	PIOC_SET();
	PIOD_SET();
	PIOE_SET();
}