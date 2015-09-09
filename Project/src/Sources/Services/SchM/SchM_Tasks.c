/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       SchM_Tasks.c
\brief      Application Tasks
\author     Francisco Martinez
\version    1.0
\date       08/07/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "SchM_Tasks.h"
#include "Can_Manager.h"
#include "Button_Manager.h"
#include "EMIOS.h"


T_ULONG ADCSgnl;

/*~E*/
/*~A*/
/*~+:Scheduler Tasks*/
/*~A*/
/*~+:SchM_3p125ms_Task*/

void SchM_3p125ms_Task(void)
{

SM_Button();
SM_Button2();
ADCSgnl = Read_ADC(ADCSgnl);

}


void SchM_6p25ms_Task(void)
{
Check_ADC( ADCSgnl);
}

void SchM_12p5ms_Task(void)
{

}

void SchM_25ms_Task(void)
{

}


void SchM_50ms_Task(void)
{
	
	SM_CANreceiver();	

}


void SchM_100ms_Task(void)
{
	if(SEND_REQ==1)
	{
	SEND_REQ=0;
	CanManager_SendRequest();
	}	
	
	if(SEND_MSG==1)
	{
		SEND_MSG=0;
		CanManager_SendMsg();
	}

	
	if(Flag==1)
	{
		Flag=0;
		CanManager_SendResponse();
			
	}
	
}


/*~E*/
/*~E*/
