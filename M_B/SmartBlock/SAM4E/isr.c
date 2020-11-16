#include ".\cpu.h"

ISR_ST_CAN_FIFO volatile ISR_Can_Buff;


void CAN0_Handler()
{
	uint32_t can0_status;
	can0_status=CAN_GET_STATUS(CAN0);
	if ((can0_status&CAN_SR_MB4)==CAN_SR_MB4)
	{
		define_BDID(datal_val(4));			
		CAN_RST_RXSTATUS(CAN0,4);
	}
	
	if ((can0_status&CAN_SR_MB5)==CAN_SR_MB5)
	{
		if(ISR_Can_Buff.Tail>=ISR_SZ_CAN_BUFF){ISR_Can_Buff.Tail=0;}
		ISR_Can_Buff.Buff[ISR_Can_Buff.Tail++]=datal_val(5);
		CAN_RST_RXSTATUS(CAN0,5);
	}
}

void AFEC0_Handler()
{
	afec_process_callback();
}

// void PIOC_Handler()
// {
// 	CAN_Lowdata(2,1);
// 	CAN_msgTx(2,0x20);
// }
