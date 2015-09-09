/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            SpeedCtrl.h
* version:         1.0
* created_by:      Ricardo Guerra 
* date_created:    sep 8 2015
*=============================================================================*/
/* DESCRIPTION : Header file for the SpeedCtrl.c C source.                      */
/*============================================================================*/
/* FUNCTION COMMENT : Provides symbols related to the code to initialize the  */
/* system. Stuff like clocking, mode selection, etc.                          */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/Aug/2015 |                               | Ricardo Guerra   */
/* Initial version for ADC driver.                                                              */
/*============================================================================*/
#ifndef SpeedCtrl_H                                /* To avoid double inclusion */
#define SpeedCtrl_H

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
extern void Check_ADC(T_ULONG ADCSgnl);
//extern void Init_ADC(void);
//extern T_ULONG	Read_ADC(void);



#endif
