/*============================================================================*/
/*                   CONTINENTAL AUTOMOTIVE SYSTEMS                           */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* name:            EMIOS.c
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
/* Initial version for EMIOS driver. Controlling PWM.                                                              */
/*============================================================================*/

/* Includes */
/* -------- */
#include "EMIOS.h"

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
 *  Name                 : sysinit_disableWatchdog
 *  Description          : Disable watchdog
 *  Parameters           :  none.
 *  Return               :  none
 *  Critical/explanation :  No
 **************************************************************/
 
  

/* Exported functions */
/* ------------------ */

/**************************************************************
 *  Name                 : 	Init_EMIOS_0
 *  Description          : 	Initialize system clock settings.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : 	Must be called at init phase, It is not intended for
 *							clock changes in normal application operation.
 **************************************************************/

void Init_EMIOS_0(void) {
  
  EMIOS_0.MCR.B.GPRE= 63;   /* Divide 64 MHz sysclk by 63+1 = 64 for 1MHz eMIOS clk*/
  EMIOS_0.MCR.B.GPREN = 1;	/* Enable eMIOS clock */
  EMIOS_0.MCR.B.GTBE = 1;   /* Enable global time base */
  EMIOS_0.MCR.B.FRZ = 1;    /* Enable stopping channels when in debug mode */
}


/**************************************************************
 *  Name                 : 	Init_PWM
 *  Description          : 	Initialize system clock settings.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : 	Must be called at init phase, It is not intended for
 *							clock changes in normal application operation.
 **************************************************************/


void Init_PWM(void) {        /* EMIOS 0 CH 23: Modulus Up Counter */
  
 
  EMIOS_0.CH[23].CADR.R = 999;      /* Period will be 999+1 = 1000 clocks (1 msec) */
  EMIOS_0.CH[23].CCR.B.MODE = 0x50; /* Modulus Counter Buffered (MCB) */
  EMIOS_0.CH[23].CCR.B.BSL = 0x3;	/* Use internal counter */
  EMIOS_0.CH[23].CCR.B.UCPRE=0;	    /* Set channel prescaler to divide by 1 */
  EMIOS_0.CH[23].CCR.B.UCPEN = 1;   /* Enable prescaler; uses default divide by 1 */
  EMIOS_0.CH[23].CCR.B.FREN = 1; 	/* Freeze channel counting when in debug mode */

							        /* EMIOS 0 CH 21: Output Pulse Width Modulation */
  EMIOS_0.CH[21].CADR.R = 250;      /* Leading edge when channel counter bus=250*/
  EMIOS_0.CH[21].CBDR.R = 999;      /* Trailing edge when channel counter bus=500*/
  EMIOS_0.CH[21].CCR.B.BSL = 0x0;	/* Use counter bus A (default) */
  EMIOS_0.CH[21].CCR.B.EDPOL = 1;	/* Polarity-leading edge sets output/trailing clears*/
  EMIOS_0.CH[21].CCR.B.MODE = 0x60; /* Mode is OPWM Buffered */
  SIU.PCR[69].R = 0x0600;           /* MPC56xxS: Assign EMIOS_0 ch 21 to pad */
}

/**************************************************************
 *  Name                 : 	Init_Encoder
 *  Description          : 	Initialize eMios to work counting pulses from encoder.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : No
 ***************************************************************/
 
 void Init_Encoder(void) {        /* EMIOS 0 CH 16: Modulus Up Counter */
  EMIOS_0.CH[16].CADR.R = 181;  	/*Period will be until pulses necesary to have 20 degrees */
  EMIOS_0.CH[16].CCR.B.MODE = 0x51; /* Modulus Counter Buffered (MCB) */
  EMIOS_0.CH[16].CCR.B.BSL = 0x3;	/* Use internal counter */
  EMIOS_0.CH[16].CCR.B.UCPRE=0;	    /* Set channel prescaler to divide by 1 */
  EMIOS_0.CH[16].CCR.B.UCPEN = 1;   /* Enable prescaler; uses default divide by 1 */
  EMIOS_0.CH[16].CCR.B.FREN = 1; 	/* Freeze channel counting when in debug mode */
  EMIOS_0.CH[16].CCR.B.EDSEL=1;   	/*count both edges*/ 
 
  EMIOS_0.CH[16].CSR.B.FLAG=1;		/*Reset Flag*/
  EMIOS_0.CH[16].CCR.B.FEN=1;		/*Enable Flag Interrupt*/
  
  
  SIU.PCR[64].R = 0x0500;
  INTC_InstallINTCInterruptHandler(Encoder_isr,149,5);
}
 
 /**************************************************************
 *  Name                 : 	Init_Encoder
 *  Description          : 	Initialize eMios to work counting pulses from encoder.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : No
 ***************************************************************/
 
 void Encoder_isr(void) {        /* EMIOS 0 CH 16: Modulus Up Counter */

	static T_UBYTE i=0;
	static T_UBYTE j=0;
	i++;
	if(i>17)
	{
		j++;
	}
	 EMIOS_0.CH[16].CSR.B.FLAG=1;		/*Reset Flag*/
}
 
 
/**************************************************************
 *  Name                 : 	Read_Encoder
 *  Description          : 	Initialize eMios to work counting pulses from encoder.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : No
 ***************************************************************/
 
 T_ULONG Read_Encoder(void)
 {
 	
 	T_ULONG lul_Encoder_count=0;
 	lul_Encoder_count= EMIOS_0.CH[16].CCNTR.R;
 	return lul_Encoder_count; 	
 	
 }
 
 
 

/**************************************************************
 *  Name                 : 	set_Duty_Cycle
 *  Description          : 	changes duty cycle of PWM.
 *  Parameters           : 	none
 *  Return               : 	none
 *  Critical/explanation : No
 ***************************************************************/


void set_Duty_Cycle(vuint16_t Duty)
{
	vuint16_t  A_value=0;
	A_value=1000-(Duty*10);
	EMIOS_0.CH[21].CADR.R = A_value;      /* Leading edge when channel counter bus=500*/

}



