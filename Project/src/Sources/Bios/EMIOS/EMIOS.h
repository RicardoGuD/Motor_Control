/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            EMIOS.h
* version:         1.0
* created_by:      Erick Salinas 
* date_created:    Aug 31 2015
*=============================================================================*/
/* DESCRIPTION : Header file for the sysinit.c C source.                      */
/*============================================================================*/
/* FUNCTION COMMENT : Provides symbols related to the code to initialize the  */
/* system. Stuff like clocking, mode selection, etc.                          */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/Aug/2015 |                               | Erick Salinas    */
/* Initial version for EMIOS driver. Controlling PWM.                                                              */
/*============================================================================*/
#ifndef EMIOS_H                                /* To avoid double inclusion */
#define EMIOS_H

/* Includes */
/* -------- */
#include "typedefs.h"
#include "MCU_derivative.h" 



/* Exported types and constants */
/* ---------------------------- */

/* Types definition */

/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */

/* WORD constants */

/* LONG and STRUCTURE constants */

/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */

/* WORD RAM variables */

/* LONG and STRUCTURE RAM variables */

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */


/* Generic Defines */



/* Function-like macros */


/* Functions prototypes */

extern void Init_PWM(void);
extern void Init_EMIOS_0(void);
extern void set_Duty_Cycle(vuint16_t Duty);
extern void Init_Encoder(void);
extern T_ULONG Read_Encoder(void);
extern void Encoder_isr(void);





#endif
