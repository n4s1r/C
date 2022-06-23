#include <stdio.h>
#include <math.h>

void printBit (void *a)
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

//Написать программу вычисления шага сетки и построить график зависимости шага сетки ε(x) от значения x.

int main(void)
{
 double a,b,x;//4294967296
 while(1)
 {
	int i=0;
	printf("vvedite chislo: "); 
  scanf("%lf",&b);
  a=pow(2,300);// 2^300 нужен для того чтобы найти более точное значение шага сетки для больших чисел можно увеличить значение 
  while(b+a!=b){a/=2;i--;}
  i+=301;          //12345678901234567890
  x=pow(2,i);  //1.024000e+03
  printf("shag setki: 2^(%d)  %le \n",i, x);
  printBit(&x);
 }
 return 0;
}

int main1(void)
{
 double a,b,x;//4294967296
 double y;/**/
 int i=0;
 while(1)/**/
 {
	printf("vvedite chislo: "); 
  scanf("%lf",&b);
  //a=pow(2,300);// 2^300 нужен для того чтобы найти более точное значение шага сетки для больших чисел можно увеличить значение 
  a=1;
  while(b+a!=b){y=b+a; printf("%.22lf\n", y);printBit(&y); x=a;a/=2;i++;}  
  printf("\n%d\n",--i);
  printBit(&x);/**/
  printf("shag setki: %le\n",x);
 }
 return 0;
}

