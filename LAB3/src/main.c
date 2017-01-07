/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>

__asm void add(float *a, float *b){
	PUSH {r4-r5,lr}
	LDR r2,[r0]
	LDR r1,[r1]
	LSRS r3,r2,#23
	LSLS r2,r2,#9
	LSRS r2,r2,#9
	LSRS r4,r1,#23
	LSLS r1,r1,#9
	LSRS r1,r1,#9
	CMP r3,r4
	BHI goto1
	SUBS r3,r4,r3
	MOVS r5,#1
	LSLS r5,r5,#23
	ADDS r2,r2,r5
	LSRS r2,r2,r3
	ADDS r1,r1,r5
	ADDS r1,r1,r2
	LSLS r5,r5,#1
	SUBS r5,r5,#1
	CMP r1,r5
	BHI goto2
	ADDS r5,r5,#1
	LSRS r5,r5,#1
	SUBS r1,r1,r5
	LSLS r4,r4,#23
	ADDS r1,r1,r4
	STR r1,[r0]
	POP {r4-r5,pc}
goto2
	ADDS r4,r4,#1
	LSRS r1,r1,#1
	ADDS r5,r5,#1
	LSRS r5,r5,#1
	SUBS r1,r1,r5
	LSLS r4,r4,#23
	ADDS r1,r1,r4
	STR r1,[r0]
	POP {r4-r5,pc}
goto1
	SUBS r4,r3,r4
	MOVS r5,#1
	LSLS r5,r5,#23
	ADDS r1,r1,r5
	LSRS r1,r1,r4
	ADDS r2,r2,r5
	ADDS r1,r1,r2
	LSLS r5,r5,#1
	SUBS r5,r5,#1
	CMP r1,r5
	BHI goto3
	ADDS r5,r5,#1
	LSRS r5,r5,#1
	SUBS r1,r1,r5
	LSLS r3,r3,#23
	ADDS r1,r1,r3
	STR r1,[r0]
	POP {r4-r5,pc}
goto3
	ADDS r3,r3,#1
	LSRS r1,r1,#1
	ADDS r5,r5,#1
	LSRS r5,r5,#1
	SUBS r1,r1,r5
	LSLS r3,r3,#23
	ADDS r1,r1,r3
	STR r1,[r0]
	POP {r4-r5,pc}
}
int main(void)
{
	float a=-5.34, b=7.53,c=-8.53;
	float *num1=&a;
	float *num2=&b;
	float *num3=&c;
	//add(num1,num2);
	add(num1,num3);
	
	
	while (1)
			;
}
// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
