/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            ADC.h
* version:         1.0
* created_by:      Erick Salinas 
* date_created:    Aug 31 2015
*=============================================================================*/
/* DESCRIPTION : Header file for the ADC.c C source.                      */
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
/* Initial version for ADC driver.                                                              */
/*============================================================================*/
#ifndef ADC_H                                /* To avoid double inclusion */
#define ADC_H

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

extern void Init_ADC(void);
extern T_ULONG	Read_ADC(void);



#endif
