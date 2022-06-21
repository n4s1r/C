#include <stdio.h>
#include <math.h>

void printBit (void *a);

int main(void)
{ 
 double x,a,b,c;
 printf("enter the number: ");scanf("%le",&a); 
 x=fabs(a)+1.0;
 while(a+x>a){b=a+x;c=b-a;x/=2.0;}
 printf("entered number :\n"); printBit(&a);
 printf("shaq setki : %le\n",c); 	
 printf("chislo otlichnoye ot vedyonoqo na shaq setki v poslednem  znachishem bite ( samiy posledniy bit v mantisse plus 1 ) :\n");printBit(&b);
 return 0;
}//1 - 2.04  2, 3.5 ,4

void printBit (void *a)
{
 int n; 
 for(n=63;n>=0;n--)
 {
	if(((*(unsigned long long *)a)&((unsigned long long)1<<n))!=0) printf("1");
	else printf("0");
	if(n==63||n==62||n==52) printf(" ");
 }
 printf("\n");
}
