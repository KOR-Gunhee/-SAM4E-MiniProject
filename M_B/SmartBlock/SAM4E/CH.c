/*
 * CH.c
 *
 * Created: 2018-09-06 오후 3:16:49
 *  Author: DEV_PC
 */ 

#include ".\cpu.h"

void CH_RST()
{
	//Switch Open
	PIO_OUT_CLR(PIOA,0xFFE00000UL);
	PIO_OUT_CLR(PIOB,0x00000103UL);
	PIO_OUT_CLR(PIOC,0xFFFFFFFFUL);
	PIO_OUT_CLR(PIOE,0x0000003AUL);
	//Switch Open
	PIO_OUT_CLR(PIOA,0x001DF87FUL);
	PIO_OUT_CLR(PIOB,0x00000030UL);
	PIO_OUT_CLR(PIOD,0xFFFFFFFFUL);
}

// void CH_Leakage_TEST(uint32_t num)
// {
// 	
// 	for (volatile int i=1;i<=50;i++)
// 	{
// 		CH_Leakage_RST();
// 		switch(num)
// 		{
// 			//Leakage TEST
// 			case 1 : CH1; break; case 2 : CH2; break; case 3 : CH3; break; case 4 : CH4; break;
// 			case 5 : CH5; break; case 6 : CH6; break; case 7 : CH7; break; case 8 : CH8; break;
// 			case 9 : CH9; break; case 10 : CH10; break; case 11 : CH11; break; case 12 : CH12; break;
// 			case 13 : CH13; break; case 14 : CH14; break; case 15 : CH15; break; case 16 : CH16; break;
// 			case 17 : CH17; break; case 18 : CH18; break; case 19 : CH19; break; case 20 : CH20; break;
// 			case 21 : CH21; break; case 22 : CH22; break; case 23 : CH23; break; case 24 : CH24; break;
// 			case 25 : CH25; break; case 26 : CH26; break; case 27 : CH27; break; case 28 : CH28; break;
// 			case 29 : CH29; break; case 30 : CH30; break; case 31 : CH31; break; case 32 : CH32; break;
// 			case 33 : CH33; break; case 34 : CH34; break; case 35 : CH35; break; case 36 : CH36; break;
// 			case 37 : CH37; break; case 38 : CH38; break; case 39 : CH39; break; case 40 : CH40; break;
// 			case 41 : CH41; break; case 42 : CH42; break; case 43 : CH43; break; case 44 : CH44; break;
// 			case 45 : CH45; break; case 46 : CH46; break; case 47 : CH47; break; case 48 : CH48; break;
// 			case 49 : CH49; break; case 50 : CH50; break;
// 		}
// 	}
// 	
// }

void PinSearch_CH()
{
//	Pin3;
// 	for (volatile int i=1;i<=50;i++)
// 	{
// 		CH_RST();
// 		switch(i)
// 		{
// 			case 51 : Pin1; break; case 52 : Pin2; break; case 53 : Pin3; break; case 54 : Pin4; break;
// 			case 55 : Pin5; break; case 56 : Pin6; break; case 57 : Pin7; break; case 58 : Pin8; break;
// 			case 59 : Pin9; break; case 60 : Pin10; break; case 61 : Pin11; break; case 62 : Pin12; break;
// 			case 63 : Pin13; break; case 64 : Pin14; break; case 65 : Pin15; break; case 66 : Pin16; break;
// 			case 67 : Pin17; break; case 68 : Pin18; break; case 69 : Pin19; break; case 70 : Pin20; break;
// 			case 71 : Pin21; break; case 72 : Pin22; break; case 73 : Pin23; break; case 74 : Pin24; break;
// 			case 75 : Pin25; break; case 76 : Pin26; break; case 77 : Pin27; break; case 78 : Pin28; break;
// 			case 79 : Pin29; break; case 80 : Pin30; break; case 81 : Pin31; break; case 82 : Pin32; break;
// 			case 83 : Pin33; break; case 84 : Pin34; break; case 85 : Pin35; break; case 86 : Pin36; break;
// 			case 87 : Pin37; break; case 88 : Pin38; break; case 89 : Pin39; break; case 90 : Pin40; break;
// 			case 91 : Pin41; break; case 92 : Pin42; break; case 93 : Pin43; break; case 94 : Pin44; break;
// 			case 95 : Pin45; break; case 96 : Pin46; break; case 97 : Pin47; break; case 98 : Pin48; break;
// 			case 99 : Pin49; break; case 100 : Pin50; break;
// 		}
// 	}
}

void CH_Set(uint32_t num)
{
	CH_RST();
	switch(num)
	{
		//Leakage TEST
		case 1 : CH1; break; case 2 : CH2; break; case 3 : CH3; break; case 4 : CH4; break;
		case 5 : CH5; break; case 6 : CH6; break; case 7 : CH7; break; case 8 : CH8; break;
		case 9 : CH9; break; case 10 : CH10; break; case 11 : CH11; break; case 12 : CH12; break;
		case 13 : CH13; break; case 14 : CH14; break; case 15 : CH15; break; case 16 : CH16; break;
		case 17 : CH17; break; case 18 : CH18; break; case 19 : CH19; break; case 20 : CH20; break;
		case 21 : CH21; break; case 22 : CH22; break; case 23 : CH23; break; case 24 : CH24; break;
		case 25 : CH25; break; case 26 : CH26; break; case 27 : CH27; break; case 28 : CH28; break;
		case 29 : CH29; break; case 30 : CH30; break; case 31 : CH31; break; case 32 : CH32; break;
		case 33 : CH33; break; case 34 : CH34; break; case 35 : CH35; break; case 36 : CH36; break;
		case 37 : CH37; break; case 38 : CH38; break; case 39 : CH39; break; case 40 : CH40; break;
		case 41 : CH41; break; case 42 : CH42; break; case 43 : CH43; break; case 44 : CH44; break;
		case 45 : CH45; break; case 46 : CH46; break; case 47 : CH47; break; case 48 : CH48; break;
		case 49 : CH49; break; case 50 : CH50; break;
		case 51 : Pin1; break; case 52 : Pin2; break; case 53 : Pin3; break; case 54 : Pin4; break;
 		case 55 : Pin5; break; case 56 : Pin6; break; case 57 : Pin7; break; case 58 : Pin8; break;
 		case 59 : Pin9; break; case 60 : Pin10; break; case 61 : Pin11; break; case 62 : Pin12; break;
 		case 63 : Pin13; break; case 64 : Pin14; break; case 65 : Pin15; break; case 66 : Pin16; break;
 		case 67 : Pin17; break; case 68 : Pin18; break; case 69 : Pin19; break; case 70 : Pin20; break;
 		case 71 : Pin21; break; case 72 : Pin22; break; case 73 : Pin23; break; case 74 : Pin24; break;
 		case 75 : Pin25; break; case 76 : Pin26; break; case 77 : Pin27; break; case 78 : Pin28; break;
 		case 79 : Pin29; break; case 80 : Pin30; break; case 81 : Pin31; break; case 82 : Pin32; break;
 		case 83 : Pin33; break; case 84 : Pin34; break; case 85 : Pin35; break; case 86 : Pin36; break;
 		case 87 : Pin37; break; case 88 : Pin38; break; case 89 : Pin39; break; case 90 : Pin40; break;
 		case 91 : Pin41; break; case 92 : Pin42; break; case 93 : Pin43; break; case 94 : Pin44; break;
 		case 95 : Pin45; break; case 96 : Pin46; break; case 97 : Pin47; break; case 98 : Pin48; break;
 		case 99 : Pin49; break; case 100 : Pin50; break;	
 		//PIN search
// 		case 8000 : PinSearch_CH(); break; 
	}
	CAN_Lowdata(2,count);
	CAN_msgTx(2,0x20);
}