/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        Button Manager.h
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Wed July 6 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : Header for SITCHES MODULE			            		  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 02/07/2015  | SAR/SIF/SCN_xxx               | Erick Salinas    */
/* Integration under Continuus CM                                             */
/*============================================================================*/


#ifndef _Bttn_Mngr_H        /*prevent duplicated includes*/
#define _Bttn_Mngr_H

/* Includes */
/* -------- */

#include "typedefs.h"



/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */

extern T_UBYTE SEND_REQ;
extern T_UBYTE SEND_MSG;


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

extern void PUSH_Init(void);
extern void SM_Button(void);
extern void SM_Button2(void);

/* Functions prototypes */

/*defines*/

#define		REQ_PUSH			INPUT(PUSH1)
#define 	MSG_PUSH			INPUT(PUSH2)


#define PUSH1						64
#define PUSH2						65
#define PUSH3						66
#define PUSH4						67

#define DEACTIVATED					1
#define	ACTIVATED					0

#define	ENABLE						1
#define DISABLE						0

/* Functions macros */

/* Exported defines */

#define t_10ms_debounse 	10





#endif 

