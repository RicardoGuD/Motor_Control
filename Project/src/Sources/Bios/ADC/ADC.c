/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            ADC.c
* version:         1.0
* created_by:      Erick Salinas
* date_created:    May 17 2010
*=============================================================================*/
/* DESCRIPTION : Source file for System Init functionality                    */
/*============================================================================*/
/* FUNCTION COMMENT : Provides code for basic system initializations.         */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/August/2015 |                              | Erick Salinas  */
/* Initial version for ADC driver.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MCU_derivative.h"
#include "typedefs.h"
#include "ADC.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */



/*==================================================*/ 
/* Definition of constants                 */
/*==================================================*/ 
/* BYTE constants */

/* WORD constants */

/* LONG and STRUCTURE constants */


/*======================================================*/ 
/* Definition of RAM variables                 */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */

/* LONG and STRUCTURE RAM variables */

static T_UBYTE Prueba=0;

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

/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : Name
 *  Description          : none
 *  Parameters           :  none.
 *  Return               :  none
 *  Critical/explanation :  No
 **************************************************************/
 
  

/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 : 	Init_ADC
 *  Description          : 	Initialize system clock settings.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : 	Must be called at init phase, It is not intended for
 *							clock changes in normal application operation.
 **************************************************************/
void Init_ADC()
{
	 SIU.PCR[20].R = 0x2000;         /* MPC56xxB: Initialize PB[4] as ANS0 */
     SIU.PCR[21].R=0x2000;				//Initialize PB[5]

 	  ADC_0.MCR.R = 0x20000000;         /* Initialize ADC0 for scan mode */
	  ADC_0.NCMR0.R = 0x00000003;     /* Select ANS0:2 inputs for conversion */
	  ADC_0.CTR0.R = 0x00008606;      /* Conversion times for 32MHz ADClock */
	  ADC_0.MCR.B.NSTART=1;             /* Trigger normal conversions for ADC0 */




}

/**************************************************************
 *  Name                 : 	Read_ADC
 *  Description          : 	Initialize system clock settings.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : 	Must be called at init phase, It is not intended for
 *							clock changes in normal application operation.
 **************************************************************/

T_ULONG	Read_ADC()
{
	T_ULONG Result=0;
    while (ADC_0.CDR[0].B.VALID != 1) {};                /* Wait for last scan to complete */
    Result= ADC_0.CDR[0].B.CDATA;
    return Result;	
	
}


T_ULONG	Read_ADC_1()
{
	T_ULONG Result=0;
    while (ADC_0.CDR[1].B.VALID != 1) {};                /* Wait for last scan to complete */
    Result= ADC_0.CDR[1].B.CDATA;
    return Result;	
	
}

