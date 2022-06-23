#include <stdio.h>
#include <quadmath.h>

void printBits (void *b)
{
 int c, i;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=15;i>=0;i--)
 for(c=7;c>=0;c--)
 {
  if(a[i]&(1<<c))printf("1");
  else printf("0");
 }
 printf("\n");
}

int main(void)
{
	__float128 a=16.0; int i=4;
	do
	{
		printf("%d: %le=\t",i,a);
		printBits(&a); printf("\n");
		a/=2.0; i--;
	}
	while( a>0 );
	return 0;
}
