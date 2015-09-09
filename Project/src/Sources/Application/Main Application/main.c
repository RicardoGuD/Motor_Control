/*~A*/
/*~+:Import*/
#include    "GPIO.h"
#include    "PIT.h"
#include    "bspi.h"
#include    "MemAlloc_Cfg.h"
#include    "SchM_Cfg.h"
#include    "Can.h"
#include    "Can_Cfg.h"
#include    "sysinit.h"
#include 	"EMIOS.h"
#include	"ADC.h"



/*~E*/
/*~A*/
/*~+:Main Code*/

T_UBYTE Prueba=0;

int main(void) 

{


	/* Mode initializations */
	sysinit_InitMode();
	/* Clock initializations */
	sysinit_InitSysClock();
	/* Memory Allcoation Initialization */
	MemAllocInit(&MemAllocConfig);
	/*Initialize LEDs on TRK-MPC560xB board */
	vfnGPIO_LED_Init(); 
	/*Initialize Push button*/
	PUSH_Init();
	/*Initialize EMIOS_0*/
	Init_EMIOS_0();
	/*Initialize Encoder*/
	Init_Encoder();
	/*Initialize PWM*/
	Init_PWM();
	/*Initialize ADC*/
	Init_ADC();
	/* SBC dependencies */
    InitDSPI_1();
    ConfigureMZC33905DSPI_1();
	/* CAN Initialization */
	CAN_Initialization(&can_driver_config);
	/* Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	/* SchM Initialization */
	SchM_Init(&SchMConfig);
    /* Enable External Interrupts*/
    enableIrq();
    /*Init Duty cycle*/
    set_Duty_Cycle(99);
    
    /* SchM Start */
  	 SchM_Start();
	/* Infinite loop - Should never reach this point */


	for (;;) 
	{
	/*	T_ULONG ADC1;
		T_ULONG ADC2;
		
		ADC1=Read_ADC();
		ADC2=Read_ADC_1();*/
	
	
	}
}