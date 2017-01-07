/*----------------------------------------------------------------------------
 *----------------------------------------------------------------------------*/
#include <MKL25Z4.H>
#define NUM_ELS (10)
#define NOT_FOUND (-1)
#include <stdio.h>

int list[NUM_ELS];
int offset[10] = {31,94,55,19,98,85,38,356,134,15};


void init_list(void) {
	unsigned int i;
	for (i=0; i<NUM_ELS; i++) {
		if (i<5) {
			list[i] = i*i*i-offset[i];
		} else
			list[i] = i*2000;
	}
}

int find_in_list(int key) {
	unsigned int i;
	for (i=0; i<NUM_ELS; i++) {
		if (list[i] == key)
			return i;
	}
	return -1;
}

//__asm void myFun(){
	
	//LDR r1,=0x1ffff004;	
	
//}


int main(void)
{
	int a, b, c;
	
	init_list();
	
	a = find_in_list(3);
	b = find_in_list(-31);
	c = find_in_list(44);
	
	printf("gamvv");
//	myFun();

	
	
	while (1)
			;
}
// *******************************ARM University Program Copyright © ARM Ltd 2013*************************************   
