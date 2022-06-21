#include <stdio.h>

void printBit (void *a)
{
 int i; 
 unsigned long long x;
 x=*(unsigned long long*)a;
 for(i=63;i>=0;i--)
 {
	if((x&((unsigned long long)1<<i))!=0)printf("1");
	else printf("0");
	if(i==63) printf(" ");
	if(i==62) printf(" ");
	if(i==52) printf(" ");	 
 }
 printf("\n");
}

int main(void)
{
 double a;
 scanf("%lf",&a);
 for(int i=0; i<10; i++)
 { 
  printf("%-10lf  -  " , a);
  printBit(&a);
  a/=2;
 }
 return 0;
}
