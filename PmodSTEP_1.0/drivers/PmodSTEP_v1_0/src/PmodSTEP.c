/***************************************************************************
 *
 * PmodSTEP.c -- Driver definitions for PmodSTEP
 * Author: Mihiro Sonoyama
 * Revision History: 
 * 	03/01/2019	Create	(Mihiro)
 *
 ***************************************************************************/

/***************************** Include Files *******************************/
#include "PmodSTEP.h"

/************************** Function Definitions ***************************/

/* Initialize device
 *
 * Args:
 * 	InstancePtr - the pointer of PmodSTEP object
 * 	BASEADDR - the base address of the I/O reg (BRAM) of PmodSTEP
 *
 */ 
void STEP_init(PmodSTEP *InstancePtr, u32 BASEADDR) {
	InstancePtr->enable = (unsigned int*)BASEADDR;
	InstancePtr->direction = (unsigned int*)(BASEADDR+0x04);

	*(InstancePtr->enable) = 0x0;
	*(InstancePtr->direction) = 0x0;
}

/* Start motor
 *
 * Args:
 * 	InstancePtr - the pointer of PmodSTEP object
 *	Dir - the rotation direction (0:clockwise, 1:counter-clockwise)
 *
 */
void STEP_start(PmodSTEP *InstancePtr, unsigned int Dir){
	*(InstancePtr->enable) = 0x1;
	*(InstancePtr->direction) = Dir;
}

/* Stop motor
 *
 * Args:
 * 	InstancePtr - the pointer of PmodSTEP object
 *
 */
void STEP_stop(PmodSTEP *InstancePtr){
	*(InstancePtr->enable) = 0x0;
}
