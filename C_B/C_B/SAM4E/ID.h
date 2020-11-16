/*
 * ID.h
 *
 * Created: 2018-07-27 오후 2:38:14
 *  Author: DEV_PC
 */ 


#ifndef ID_H_
#define ID_H_

#define Board1 0x1000 
#define Board2 0x1001
#define Board3 0x1002

#define SM_11(num)	(num<=50)
#define SM_12(num)	((50<num)&&(num<=100))
#define SM_21(num)	((100<num)&&(num<=150))
#define SM_22(num)	((150<num)&&(num<=200))
#define SM_31(num)	((200<num)&&(num<=250))
#define SM_32(num)	((250<num)&&(num<=300))
#define SM_41(num)	((300<num)&&(num<=350))
#define SM_42(num)	((350<num)&&(num<=400))
#define SM_51(num)	((400<num)&&(num<=450))
#define SM_52(num)	((450<num)&&(num<=500))
#define SM_61(num)	((500<num)&&(num<=550))
#define SM_62(num)	((550<num)&&(num<=600))
#define SM_71(num)	((600<num)&&(num<=650))
#define SM_72(num)	((650<num)&&(num<=700))
#define SM_81(num)	((700<num)&&(num<=750))
#define SM_82(num)	((750<num)&&(num<=800))
#define SM_91(num)	((800<num)&&(num<=850))
#define SM_92(num)	((850<num)&&(num<=900))
#define SM_101(num)	((900<num)&&(num<=950))
#define SM_102(num)	((950<num)&&(num<=1000))
#define SM_111(num)	((1000<num)&&(num<=1050))
#define SM_112(num)	((1050<num)&&(num<=1100))
#define SM_121(num)	((1100<num)&&(num<=1150))
#define SM_122(num)	((1150<num)&&(num<=1200))
#define SM_131(num)	((1200<num)&&(num<=1250))
#define SM_132(num)	((1250<num)&&(num<=1300))
#define SM_141(num)	((1300<num)&&(num<=1350))
#define SM_142(num)	((1350<num)&&(num<=1400))
#define SM_151(num)	((1400<num)&&(num<=1450))
#define SM_152(num)	((1450<num)&&(num<=1500))
#define SM_161(num)	((1500<num)&&(num<=1550))
#define SM_162(num)	((1550<num)&&(num<=1600))
#define SM_171(num)	((1600<num)&&(num<=1650))
#define SM_172(num)	((1650<num)&&(num<=1700))
#define SM_181(num)	((1700<num)&&(num<=1750))
#define SM_182(num)	((1750<num)&&(num<=1800))

#define VOLT_REF        (3300)
#define MAX_DIGITAL_12_BIT     (4095UL)

extern volatile uint16_t Pin_num;


void Board_ID_SET();
int ID_Check(uint16_t num);
void Define_Slot(uint16_t num);

#endif /* ID_H_ */