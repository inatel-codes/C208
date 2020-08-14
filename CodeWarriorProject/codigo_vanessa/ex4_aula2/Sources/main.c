/* ###################################################################
 **     Filename    : main.c
 **     Project     : ex4_aula2
 **     Processor   : MKL25Z128VLK4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2019-08-13, 16:02, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	int cont = 0;
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */
	for (;;) {
		switch (cont) {

		case 0:
			LED1_Put(0);
			LED2_Put(0);
			LED3_Put(0);
			if (Bit1_GetVal(Bit1_DevideData) == 0 && Bit2_GetVal(Bit2_DevideData) == 1) {
				cont++;
				WAIT1_Waitms(250);
			}
			break;
		case 1:
			LED1_Put(1);
			LED2_Put(0);
			LED3_Put(0);
			if ((Bit1_GetVal(Bit1_DevideData) == 0)	&& (Bit2_GetVal(Bit2_DevideData) == 1)) {
				cont++;
				WAIT1_Waitms(250);
			} 
			if (Bit2_GetVal(Bit2_DevideData) == 0) {
				
				cont = 0;
			}
			break;
		case 2:
			LED1_Put(0);
			LED2_Put(1);
			LED3_Put(0);
			if ((Bit1_GetVal(Bit1_DevideData) == 0)	&& (Bit2_GetVal(Bit2_DevideData) == 1)) {
				cont++;
				WAIT1_Waitms(250);
			} 
			if (Bit2_GetVal(Bit2_DevideData) == 0){
				cont = 0;
			}
			break;
		case 3:
			LED1_Put(0);
			LED2_Put(0);
			LED3_Put(1);
			if ((Bit1_GetVal(Bit1_DevideData) == 0)	&& (Bit2_GetVal(Bit2_DevideData) == 1)) {
				cont++;
				WAIT1_Waitms(250);
			} 
			if(Bit2_GetVal(Bit2_DevideData) == 0){
				cont = 1;
			}
			break;

		}

	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */