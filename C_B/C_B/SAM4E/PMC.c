#include ".\cpu.h"

void PMC_Ena()
{
	//UART, CAN0, CAN1 주변장치 클럭 활성화
	PMC->PMC_PCER0|=((1<<ID_PIOA)|(1<<ID_PIOB)|(1<<ID_PIOC)|(1<<ID_PIOD)|(1<<ID_USART1)|(1<<ID_AFEC0));
	PMC->PMC_PCER1|=(1<<(ID_CAN0-32));
}