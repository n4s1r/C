#include <stdio.h>

void F();
void D();
void L_D();
void F128(); 

int main(void)//машинный эпсилон для чисел типа float, double ,long double, __float128.
{
 printf("Tip        Stepen dvoyki     Mashinniy epsilon\n");
 F();//float	
 D();//double
 L_D();//long double  
 F128();//__float128
 return 0;
}

void F()
{
 float a=1.0,b=1.0,x;
 int i=0;
 while(b+a!=b){x=a;a/=2;i--;}
 printf("float:          %d\t\t%le\n",++i,x);
}

void D()
{
 double a=1.0,x;
 int i=0;
 while(1.0+a!=1.0){x=a;a/=2;i--;}
 printf("double:         %d\t\t%le\n",++i,x);
} 

void L_D()
{
 long double a=1.0,b=1.0;double x;
 int i=0;
 while(b+a!=b){x=a;a/=2;i--;}
 printf("long double:    %d\t\t%le\n",++i,x);
} 

void F128()
{
 __float128 a=1.0,b=1.0;double x;
 int i=0;
 while(b+a!=b){x=a;a/=2;i--;}
 printf("__float128:    %d \t\t%le\n",++i,x);
} 

