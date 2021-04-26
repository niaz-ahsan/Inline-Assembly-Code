/**
 *****************************************************************************************
 Problem Statement: Play with Inline Assembly Code
 *****************************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
#if 0
	__asm volatile("LDR R1,=#0x20001003");
	__asm volatile("LDR R2,=#0x20001007");
	__asm volatile("LDR R0,[R1]");
	__asm volatile("LDR R1,[R2]");
	__asm volatile("ADD R0,R0,R1");
	__asm volatile("STR R0,[R2]");
#endif

	int val = 50;
	__asm volatile("MOV R0,%0": :"r"(val)); // copy C variable value to processor general register

	int control_reg;
	__asm volatile("MRS %0,CONTROL" :"=r"(control_reg) : :);

	for(;;);
}
