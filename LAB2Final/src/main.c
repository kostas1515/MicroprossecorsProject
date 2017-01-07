/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#define NUM_ELS (10)
#define NOT_FOUND (-1)



__asm void cost(float arr[10],int lic)
{
	LSLS R1,R1,#2
	LDR R2,[R0,R1]
	CMP R2,#0x00000000;to sugkrinw me to 0
	BEQ gotoerror
	LDR r3,=0x3f800000 ;1
	CMP R2,R3
	BLT goto025
	LDR r3,=0x40000000 ;2
	CMP R2,R3
	BLT goto050
	LDR r3,=0x40400000 ;3
	CMP R2,R3
	BLT goto1 ; an den plirei kamoia apo tis sunthikes bazw na plirwnei 5 
	LDR r3,=0x40a00000 ;5
	STR R3,[R3]
	bx lr
	
goto025
			LDR r3,=0x3f800000 ;0.25
			STR R3,[R3]
			bx lr

goto050
			LDR r3,=0x3f000000
			STR R3,[R3]
			bx lr
goto1
			LDR r3,=0x3f800000
			STR R3,[R3]
			bx lr
gotoerror ; ama i timi einai to 0 tote den epistrefetai kamoia timi
			bx lr
	
}



int main(void)
{
float mem[10] = {1.2,2.2,3.3,4.4,5.5,0.6,7.7,8.8,9.9,0};
float price=0;
cost(mem,5);// vriskei to kostos analoga me tin thesi stin mnimi poy epilegoyme

		while (1)
			;
}
// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
