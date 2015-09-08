/*******************************************************************************/
/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        Switches.c
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:   	Wed July  1 14:38:03 2004 %
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the statemachine working by PIT 	  */
/* Interruptions	                                                 		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 01/07/2015  |                               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/

/* Includes */
/* -------- */

#include "GPIO.h"
#include "Button_Manager.h"



/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */

T_UBYTE SM_Button_state=1;
T_UBYTE SM_Button_state2=1;

T_UBYTE SEND_REQ=0;
T_UBYTE SEND_MSG=0;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */



/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */




/* Exported functions prototypes */
/* ----------------------------- */



/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */


/**************************************************************
 *  Name                 : Out_Leds
 *  Description          :	Translate the value in variable rub_level to digital outputs
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [No]
 **************************************************************/

 
 



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	PUSH_Init
 *  Description          :	Initialize push ports as inputs
 *  Parameters           :  [void]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


void PUSH_Init(void)
{
	
	vfnGPIO_Init_channel(PUSH1,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE4 --> PUSH1*/
	vfnGPIO_Init_channel(PUSH2,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE5 --> PUSH2*/
	vfnGPIO_Init_channel(PUSH3,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE6 --> PUSH3*/
	vfnGPIO_Init_channel(PUSH4,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);  /* PE7 --> PUSH4*/
	
}

/**************************************************************
 *  Name                 :	Debounse_PUSH_1ms
 *  Description          :	Detects a valid push without debounse. Ejecute in the 1ms task.
 *  Parameters           :  [void]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
T_UBYTE Debounce_active(void)
{
	
static T_UBYTE lub_counter_REQ=0;
static T_UBYTE lul_response=0;

	/*Debounse REQ push*/


	
	if(REQ_PUSH==ACTIVATED)
	{
		lub_counter_REQ++;
		if(lub_counter_REQ>t_10ms_debounse)
		{
			lul_response=1;
			lub_counter_REQ=0;	
		}
	}
	else
	{
		lub_counter_REQ=0;
		lul_response=0;
	}

return lul_response;

}


T_UBYTE Debounce_inactive(void)
{
	
static T_UBYTE lub_counter_REQ=0;
static T_UBYTE lul_response=0;

	/*Debounse REQ push*/


	
	if(REQ_PUSH==DEACTIVATED)
	{
		lub_counter_REQ++;
		if(lub_counter_REQ>t_10ms_debounse)
		{
			lul_response=1;
			lub_counter_REQ=0;	
		}
	}
	else
	{
		lub_counter_REQ=0;
		lul_response=0;
	}

return lul_response;

}



void SM_Button(void)
{

static T_ULONG lul_counter_Send=0;
	
	switch(SM_Button_state)
	{
		
		case 1: if(Debounce_active()==1)
				{
				SM_Button_state=2;
				}
				else
				{
					
				}
		
		break; 		
		
		
		case 2: if(Debounce_inactive()==1)
				{
				SM_Button_state=3;
				}
				
				else
				{
					
				}
		
		
		break; 
		
		
		
		
		case 3: lul_counter_Send++;
				if(lul_counter_Send>100)
				{
					SEND_REQ=1;	
					lul_counter_Send=0;
					SM_Button_state=1;				
				}
				else
				{
					
				}
		
		
		
		break;
		
		
		
		default:
		
		
		break;
		
			
	}
	
	
	
}

////////////////Button 2 ///////////////////////////////////////////////////////////////////////////////////
 
T_UBYTE Debounce_active2(void)
{
	
static T_UBYTE lub_counter_REQ=0;
static T_UBYTE lul_response=0;

	/*Debounse REQ push*/


	
	if(MSG_PUSH==ACTIVATED)
	{
		lub_counter_REQ++;
		if(lub_counter_REQ>t_10ms_debounse)
		{
			lul_response=1;
			lub_counter_REQ=0;	
		}
	}
	else
	{
		lub_counter_REQ=0;
		lul_response=0;
	}

return lul_response;

}


T_UBYTE Debounce_inactive2(void)
{
	
static T_UBYTE lub_counter_REQ=0;
static T_UBYTE lul_response=0;

	/*Debounse REQ push*/


	
	if(MSG_PUSH==DEACTIVATED)
	{
		lub_counter_REQ++;
		if(lub_counter_REQ>t_10ms_debounse)
		{
			lul_response=1;
			lub_counter_REQ=0;	
		}
	}
	else
	{
		lub_counter_REQ=0;
		lul_response=0;
	}

return lul_response;

}



void SM_Button2(void)
{

static T_ULONG lul_counter_Send=0;
	
	switch(SM_Button_state2)
	{
		
		case 1: if(Debounce_active2()==1)
				{
				SM_Button_state2=2;
				}
				else
				{
					
				}
		
		break; 		
		
		
		case 2: if(Debounce_inactive2()==1)
				{
				SM_Button_state2=3;
				}
				
				else
				{
					
				}
		
		
		break; 
		
		
		
		
		case 3: lul_counter_Send++;
				if(lul_counter_Send>100)
				{
					SEND_MSG=1;	
					lul_counter_Send=0;
					SM_Button_state2=1;				
				}
				else
				{
					
				}
		
		
		
		break;
		
		
		
		default:
		
		
		break;
		
		
		
		
		
		
	}
	
	
	
}