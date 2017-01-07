/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#define NUM_ELS (10)
#define NOT_FOUND (-1)


__asm void parking(float mem[10] ,float lic[10]) //insert parking licence and hours
{
loop
			LDR R2,=0xaa13e002
			LSLS R2,R2,#16
			LDR R3,[R0]
			STR  R3,[R2]
			ADDS R0,#4
			CMP R2,#0
			BNE loop
			BX lr
}

__asm void cost(float arr[10],int lic)
{
	LSLS R1,R1,#2
	LDR R2,[R0,R1]
	CMP R2,#0x00000000
	BEQ gotoerror
	LDR r3,=0x3f800000 ;1
	CMP R2,R3
	BLT goto025
	LDR r3,=0x40000000 ;2
	CMP R2,R3
	BLT goto050
	LDR r3,=0x40400000 ;3
	CMP R2,R3
	BLT goto1
	LDR r3,=0x40a00000 ;5
	bx lr
	
goto025
			LDR r3,=0x3f800000 ;0.25
			bx lr

goto050
			LDR r3,=0x3f000000
			bx lr
goto1
			LDR r3,=0x3f800000
			bx lr
gotoerror
			bx lr
	
}



int main(void)
{
float charlic[10]={0xa1b2,0xf1f2,0x21cc,0xeeff,0xda90,0x421d,0x8aa1,0x5ead,0xa110,0x4aed};
float mem[10] = {1.2,2.2,3.3,4.4,5.5,0.6,7.7,8.8,9.9,0};
float price=0;
parking(mem,charlic);
//cost(mem,5);

		while (1)
			;
}
// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
