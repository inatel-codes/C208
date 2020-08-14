/* ###################################################################
**     Filename    : main.c
**     Project     : ex3_aula4
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2019-08-14, 10:11, # CodeGen: 0
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
#include "Bit1.h"
#include "PWM1.h"
#include "PwmLdd1.h"
#include "TU1.h"
#include "PTA.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "WAIT1.h"
#include "MCUC1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#define DESLIGADO 0
#define LIGADO 1

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  int op = DESLIGADO;
  int flag = 0;
  unsigned int conversao;
  unsigned int dc;
  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  for(;;)
  {
	  if(Bit1_GetVal(Bit1_DeviceData)== 0 && flag == 0){
		  op = LIGADO;
		  WAIT1_Waitms(500);
		  flag = 1;
	  }
	  else if(Bit1_GetVal(Bit1_DeviceData)== 0 && flag == 1){
		  op = DESLIGADO;
		  WAIT1_Waitms(500);
		  flag = 0;
	  }
	  
	  switch(op){
	  	  case DESLIGADO:
	  		  PWM1_SetRatio16(0);
	  		  break;
	  	  case LIGADO:
	  		  AD1_Measure(42);
	  		  AD1_GetValue16(&conversao);
	  		  
	  		  dc =65535-conversao;
	  		  
	  		  PWM1_SetRatio16(dc);
	  		  
	  		  break;
	  }
	  
	  
	  
	  
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
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