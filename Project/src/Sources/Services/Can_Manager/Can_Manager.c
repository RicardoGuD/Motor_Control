/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"
#include "GPIO.h"
/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/
struct CanTest
{
uint8_t     can_test_enable;
}CanTestStruct;
/* Temporary CAN Messages */

uint8_t msg1[8]= {0x27, 0x02, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA};
uint8_t dummy_msg2[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};
uint8_t req_msg[8]= {0x27, 0x01, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA};

CAN_PduType    pdu_handler1 = { 2, 4, dummy_msg2};
CAN_PduType		pdu_handlerREQ = { 3, 2, req_msg};
CAN_PduType 	 pdu_handlerMsg1 = {3, 2, msg1};

uint32_t PduHandlerCnt0 = 0;


/*~+:Private Operations*/

uint8_t Flag=0;

/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler6;

void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{
CanMessage_PduHandler0 = CanMessage;
Flag=1;
PduHandlerCnt0++;
}


/*~+:Public Operations*/
void CanManager_SendRequest()
{
	
	CAN_SendFrame(pdu_handlerREQ);

}

void CanManager_SendResponse()
{
	CAN_SendFrame(pdu_handler1);
}

void CanManager_SendMsg()
{
	
	CAN_SendFrame(pdu_handlerMsg1);

}


void SM_CANreceiver()
{
	
	if(CanMessage_PduHandler0.msg_data_field[0]==0x7F)
	{
		LED_ON(LED2);
		LED_OFF(LED1);	
		
	}
	else if(CanMessage_PduHandler0.msg_data_field[0]==0x67)
		{
			LED_ON(LED1);
			LED_OFF(LED2);	
		}
	
		else
		{
			LED_OFF(LED2);
			LED_OFF(LED1);
		}			
	
	
}
