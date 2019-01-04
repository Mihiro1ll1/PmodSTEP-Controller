/***************************************************************************
 *
 * PmodSTEP.h -- Driver definitions for PmodSTEP
 * Author: Mihiro Sonoyama
 * Revision History: 
 * 	03/01/2019	Create	(Mihiro)
 *
 ***************************************************************************/

#ifndef PMODSTEP_H
#define PMODSTEP_H


/****************** Include Files ********************/
#include "xil_types.h"
#include "xstatus.h"

#define PMODSTEP_S00_AXI_SLV_REG0_OFFSET 0
#define PMODSTEP_S00_AXI_SLV_REG1_OFFSET 4
#define PMODSTEP_S00_AXI_SLV_REG2_OFFSET 8
#define PMODSTEP_S00_AXI_SLV_REG3_OFFSET 12


/**************************** Type Definitions *****************************/
/**
 *
 * Write a value to a PMODSTEP register. A 32 bit write is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is written.
 *
 * @param   BaseAddress is the base address of the PMODSTEPdevice.
 * @param   RegOffset is the register offset from the base to write to.
 * @param   Data is the data written to the register.
 *
 * @return  None.
 *
 * @note
 * C-style signature:
 * 	void PMODSTEP_mWriteReg(u32 BaseAddress, unsigned RegOffset, u32 Data)
 *
 */
#define PMODSTEP_mWriteReg(BaseAddress, RegOffset, Data) \
  	Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))

/**
 *
 * Read a value from a PMODSTEP register. A 32 bit read is performed.
 * If the component is implemented in a smaller width, only the least
 * significant data is read from the register. The most significant data
 * will be read as 0.
 *
 * @param   BaseAddress is the base address of the PMODSTEP device.
 * @param   RegOffset is the register offset from the base to write to.
 *
 * @return  Data is the data from the register.
 *
 * @note
 * C-style signature:
 * 	u32 PMODSTEP_mReadReg(u32 BaseAddress, unsigned RegOffset)
 *
 */
#define PMODSTEP_mReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))

/*--- For PmodSTEP ---*/
typedef struct PmodSTEP {
	unsigned int* enable;
	unsigned int* direction;
} PmodSTEP;


/************************** Function Prototypes ****************************/
/**
 *
 * Run a self-test on the driver/device. Note this may be a destructive test if
 * resets of the device are performed.
 *
 * If the hardware system is not built correctly, this function may never
 * return to the caller.
 *
 * @param   baseaddr_p is the base address of the PMODSTEP instance to be worked on.
 *
 * @return
 *
 *    - XST_SUCCESS   if all self-test code passed
 *    - XST_FAILURE   if any self-test code failed
 *
 * @note    Caching must be turned off for this function to work.
 * @note    Self test may fail if data memory and device are not on the same bus.
 *
 */
XStatus PMODSTEP_Reg_SelfTest(void * baseaddr_p);

#endif // PMODSTEP_H

/*--- For PmodSTEP ---*/
void STEP_init(PmodSTEP *InstancePtr, u32 BASEADDR);
void STEP_start(PmodSTEP *InstancePtr, unsigned int Dir);
void STEP_stop(PmodSTEP *InstancePtr);
