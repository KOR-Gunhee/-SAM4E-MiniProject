/*
 * mode_sel.h
 *
 * Created: 2018-06-13 오후 12:13:22
 *  Author: DEV_PC
 */ 


#ifndef MODE_SEL_H_
#define MODE_SEL_H_

#define ch_On(pio,ch) (pio)->PIO_PER|=(1<<ch)
#define ch_Ena(pio,ch) (pio)->PIO_OER|=(1<<ch)
#define ch_set(pio,ch) (pio)->PIO_SODR|=(1<<ch)
#define ch_cle(pio,ch) (pio)->PIO_CODR|=(1<<ch)


void ch_rst();
extern void ch_High(Pio *pio, uint8_t ch);
void PinSearch_suffle(uint8_t ch);



#endif /* MODE_SEL_H_ */