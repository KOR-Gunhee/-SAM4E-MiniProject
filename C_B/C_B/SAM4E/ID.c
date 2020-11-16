#include ".\cpu.h"

uint32_t ID;
volatile uint16_t Pin_num;

void Board_ID_SET()
{	
	CAN_Lowdata(0,Board1);
	CAN_msgID(0,0x10);
 	
// 	if (PIO_OUT_STATUS(PIOD,0x80))
// 	{
// 		CAN_Lowdata(0,Board2);
// 		CAN_msgTx(0,0x87654321);
// 		PIO_OUT_SET(PIOD,0x100);
// 	}
// 	
// 	if (PIO_OUT_STATUS(PIOD,0x100))
// 	{
// 		CAN_Lowdata(0,Board3);
// 		CAN_msgTx(0,0x87654321);
// 	}
}

void Define_Slot(uint16_t num)
{
	CAN0->CAN_MB[1].CAN_MID=0;
	
	if (SM_11(num)){CAN_Lowdata(1,num);CAN_msgID(1,0);}
	else if (SM_12(num)){CAN_Lowdata(1,num-50);CAN_msgID(1,1);}
	else if (SM_21(num)){CAN_Lowdata(1,num-100);CAN_msgID(1,8);}
	else if (SM_22(num)){CAN_Lowdata(1,num-150);CAN_msgID(1,9);}
	else if (SM_31(num)){CAN_Lowdata(1,num-200);CAN_msgID(1,16);}
	else if (SM_32(num)){CAN_Lowdata(1,num-250);CAN_msgID(1,17);}
	else if (SM_41(num)){CAN_Lowdata(1,num-300);CAN_msgID(1,24);}
	else if (SM_42(num)){CAN_Lowdata(1,num-350);CAN_msgID(1,25);}
	else if (SM_51(num)){CAN_Lowdata(1,num-400);CAN_msgID(1,32);}
	else if (SM_52(num)){CAN_Lowdata(1,num-450);CAN_msgID(1,33);}
	else if (SM_61(num)){CAN_Lowdata(1,num-500);CAN_msgID(1,40);}
	else if (SM_62(num)){CAN_Lowdata(1,num-550);CAN_msgID(1,41);}
	else if (SM_71(num)){CAN_Lowdata(1,num-600);CAN_msgID(1,48);}
	else if (SM_72(num)){CAN_Lowdata(1,num-650);CAN_msgID(1,49);}
	else if (SM_81(num)){CAN_Lowdata(1,num-700);CAN_msgID(1,56);}
	else if (SM_82(num)){CAN_Lowdata(1,num-750);CAN_msgID(1,57);}
	else if (SM_91(num)){CAN_Lowdata(1,num-800);CAN_msgID(1,64);}
	else if (SM_92(num)){CAN_Lowdata(1,num-850);CAN_msgID(1,65);}
	else if (SM_101(num)){CAN_Lowdata(1,num-900);CAN_msgID(1,72);}
	else if (SM_102(num)){CAN_Lowdata(1,num-950);CAN_msgID(1,73);}
	else if (SM_111(num)){CAN_Lowdata(1,num-1000);CAN_msgID(1,80);}
	else if (SM_112(num)){CAN_Lowdata(1,num-1050);CAN_msgID(1,81);}
	else if (SM_121(num)){CAN_Lowdata(1,num-1100);CAN_msgID(1,88);}
	else if (SM_122(num)){CAN_Lowdata(1,num-1150);CAN_msgID(1,89);}
	else if (SM_131(num)){CAN_Lowdata(1,num-1200);CAN_msgID(1,96);}
	else if (SM_132(num)){CAN_Lowdata(1,num-1250);CAN_msgID(1,97);}
	else if (SM_141(num)){CAN_Lowdata(1,num-1300);CAN_msgID(1,104);}
	else if (SM_142(num)){CAN_Lowdata(1,num-1350);CAN_msgID(1,105);}
	else if (SM_151(num)){CAN_Lowdata(1,num-1400);CAN_msgID(1,112);}
	else if (SM_152(num)){CAN_Lowdata(1,num-1450);CAN_msgID(1,113);}
	else if (SM_161(num)){CAN_Lowdata(1,num-1500);CAN_msgID(1,120);}
	else if (SM_162(num)){CAN_Lowdata(1,num-1550);CAN_msgID(1,121);}
	else if (SM_171(num)){CAN_Lowdata(1,num-1600);CAN_msgID(1,128);}
	else if (SM_172(num)){CAN_Lowdata(1,num-1650);CAN_msgID(1,129);}
	else if (SM_181(num)){CAN_Lowdata(1,num-1700);CAN_msgID(1,136);}
	else if (SM_182(num)){CAN_Lowdata(1,num-1750);CAN_msgID(1,137);}														
}

int ID_Check(uint16_t num)
{
//	ADC_START();
	if (num<=100)
	{
		//LCR Relay ON
		PIO_OUT_SET(PIOD,0x00000064);
		
		while(!(CAN0->CAN_MB[0].CAN_MSR&(CAN_MSR_MRDY)));
		Define_Slot(num);
	}
	else if (num==101)
	{
		//Mutimeter Relay ON
		PIO_OUT_SET(PIOD,0x00000059);
		
		for (volatile int i=1;i<=40;i++)
		{
			MyDelay2(1000,2000);
			Define_Slot(i);
			if (i==40)
			{
				LED_ON(10);
			}
		}
	}
	else if (num==102)
	{
		PIO_OUT_SET(PIOD,0x0000006A);
		for (Pin_num = 1; Pin_num <= 30; Pin_num++)
		{
			LED_toglle(11);
			CAN_Lowdata(1,Pin_num+50);
			CAN_TX(1);
			ADC_START();
			MyDelay2(1000,500);
			if (Pin_num>40)
			{
				break;
			}
		}
	}
	else
	{
			char US_Buff[32]={0,};
			US_msg_lengh=0;
			US_msg_status=0;
	}
	char US_Buff[32]={0,};
	US_msg_lengh=0;
	US_msg_status=0;
}


