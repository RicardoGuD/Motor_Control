/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            SpeedCtrl.c
* version:         1.0
* created_by:      Ricardo Guerra
* date_created:    sep 8 2015
*=============================================================================*/
/* DESCRIPTION : Source file for engine speed control functionality           */
/*============================================================================*/
/* FUNCTION COMMENT : Convert the ADC signal into the speed signal for 		  */
/*                    the engine .       								      */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/August/2015 |                              | Ricardo Guerra */
/* Initial version for ADC driver.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "MCU_derivative.h"
#include "typedefs.h"
#include "SpeedCtrl.h"
#include "GPIO.h"
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

//static T_UBYTE Prueba=0;

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
 *  Name                 : 	Read_ADC
 *  Description          : 	Initialize system clock settings.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : 	Must be called at init phase, It is not intended for
 *							clock changes in normal application operation.
 **************************************************************/

void Check_ADC(T_ULONG ADCSgnl)
{
	set_Duty_Cycle(ADCSgnl);
}




