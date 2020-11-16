/*
 * PIO.h
 *
 * Created: 2018-01-05 오전 9:33:14
 *  Author: ghhan
 */ 


#ifndef PIO_H_
#define PIO_H_


#define TXD0 10
#define RXD0 9
#define CANRX0 3
#define CANTX0 2
#define RX1 21
#define TX1 22
//------------------------------------------------------------------------------


#define PIO_DIS_INTR(pio,val) (pio)->PIO_IDR=(val)
#define PIO_DIS_PULLUP(pio,val) (pio)->PIO_PUDR =(val)
#define PIO_EN_PULLUP(pio,val) (pio)->PIO_PUER = (val)
#define PIO_DIS_PULLDOWN(pio,val) (pio)->PIO_PPDDR=(val)
#define PIO_EN_PULLDOWN(pio,val) (pio)->PIO_PPDER=(val)
#define PIO_DIS_INFLT(pio,val) (pio)->PIO_IFDR=(val)
#define PIO_EN_INFLT(pio,val) (pio)->PIO_IFER=(val)
#define PIO_DIS_IFSLOWCLK(pio,val) (pio)->PIO_IFSCDR = (val)
#define PIO_EN_IFSLOWCLK(pio,val) (pio)->PIO_IFSCER =(val)
#define PIO_SET_DEBOUNCE(pio,val) (pio)->PIO_SCDR = (val)
#define PIO_DIS_OPENDRAIN(pio,val) (pio)->PIO_MDDR=(val)
#define PIO_EN_OPENDRAIN(pio,val) (pio)->PIO_MDER=(val)
#define PIO_OUT_CLR(pio,val) (pio)->PIO_CODR=(val)
#define PIO_OUT_SET(pio,val) (pio)->PIO_SODR=(val)
#define PIO_DIS_OUT(pio,val) (pio)->PIO_ODR=(val)
#define PIO_EN_OUT(pio,val) (pio)->PIO_OER=(val)
#define PIO_DIS_IO(pio,val) (pio)->PIO_PDR=(val)
#define PIO_EN_IO(pio,val)  (pio)->PIO_PER=(val)



//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//PIOA
#define BD_PIOA_MSK (0xFFFFF87FUL)
#define BD_PIOA_DIR (0xFFFDF87FUL)
#define BD_PIOA_DEFVAL (0x00000000UL)
#define BD_PIOA_PULLUP (0x00000000UL)
#define BD_PIOA_PULLDN (0x00000000UL)
#define BD_PIOA_OPENDRAIN (0x00000000UL)
#define BD_PIOA_INFILTER (0x00000000UL)
#define BD_PIOA_DEBOUNC (0x00000000UL)
#define DB_PIOA_FLTCLKDIV (0)
//PIOB
#define BD_PIOB_MSK (0x00005023UL)
#define BD_PIOB_DIR (0x00001033UL)
#define BD_PIOB_DEFVAL (0x00000000UL)
#define BD_PIOB_PULLUP (0x00004000UL)
#define BD_PIOB_PULLDN (0x00000000UL)
#define BD_PIOB_OPENDRAIN (0x00000000UL)
#define BD_PIOB_INFILTER (0x00000000UL)
#define BD_PIOB_DEBOUNC (0x00000000UL)
#define DB_PIOB_FLTCLKDIV (0)
//PIOC
#define BD_PIOC_MSK (0xFFFFFFFFUL)
#define BD_PIOC_DIR (0xFFFFFFFFUL)
#define BD_PIOC_DEFVAL (0x00000000UL)
#define BD_PIOC_PULLUP (0x00000000UL)
#define BD_PIOC_PULLDN (0x00000000UL)
#define BD_PIOC_OPENDRAIN (0x00000000UL)
#define BD_PIOC_INFILTER (0x00000000UL)
#define BD_PIOC_DEBOUNC (0x00000000UL)
#define DB_PIOC_FLTCLKDIV (0)
//PIOD
#define BD_PIOD_MSK (0xFFFFFFFFUL)
#define BD_PIOD_DIR (0xFFFFFFFFUL)
#define BD_PIOD_DEFVAL (0x00000000UL)
#define BD_PIOD_PULLUP (0x00000000UL)
#define BD_PIOD_PULLDN (0x00000000UL)
#define BD_PIOD_OPENDRAIN (0x00000000UL)
#define BD_PIOD_INFILTER (0x00000000UL)
#define BD_PIOD_DEBOUNC (0x00000000UL)
#define DB_PIOD_FLTCLKDIV (0)
//PIOE
#define BD_PIOE_MSK (0x0000003AUL)
#define BD_PIOE_DIR (0x0000003AUL)
#define BD_PIOE_DEFVAL (0x00000000UL)
#define BD_PIOE_PULLUP (0x00000000UL)
#define BD_PIOE_PULLDN (0x00000000UL)
#define BD_PIOE_OPENDRAIN (0x00000000UL)
#define BD_PIOE_INFILTER (0x00000000UL)
#define BD_PIOE_DEBOUNC (0x00000000UL)
#define DB_PIOE_FLTCLKDIV (0)

void PIOA_SET();
void PIOB_SET();
void PIOC_SET();
void PIOD_SET();
void PIOE_SET();
void PIOInit();


#endif /* PIO_H_ */