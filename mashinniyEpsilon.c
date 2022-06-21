#include <stdio.h>

void printBit(void *a)
{
 int i; 
 for(i=63;i>=0;i--)
 {
	if(((*(unsigned long long*)a)&((unsigned long long)1<<i))!=0) printf("1");
	else printf("0");
	if(i==63||i==62||i==52) printf(" ");
 }
 printf("\n");
}

int main(void)
{
	double x=1.0, b; 
	int i=0;
	do
	{
		printf("%d: %le  ",i,x);
		printBit(&x);
		b=1+x;
		printBit(&b);
		x/=2.0; 
		i--;
		printf("\n");
	}
	while(1.0+x>1.0);
	printf("\n");
	printf("otlichiye ot edinici \n");
	b=1;
	//printf("%lf  ", b);
	printBit(&b);
	return 0;
}
