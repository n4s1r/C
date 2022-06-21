#include <stdio.h>

void printBit (void *a)
{
 int i; 
 unsigned long x;
 x=*(unsigned long*)a;
 for(i=31;i>=0;i--)
 {
	if((x&((unsigned long)1<<i))!=0)printf("1");
	else printf("0");
	if(i==31) printf(" ");
	if(i==30) printf(" ");
	if(i==23) printf(" ");	 
 }
 printf("\n");
}

// понял !!!!

int main (void)
{
 float a=1;
 printf("%2.2f  - ",a);
 printBit(&a);
 return 0;
}
