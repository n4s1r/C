#include <stdio.h>
#include <math.h>

double f0(double x){return 1;}
double f1(double x){return x;}
double f2(double x){return x*x;}
double f3(double x){return x*x*x;}
double f4(double x){return x*x*x*x;}
double f5(double x){return x*x*x*x*x;}
double f6(double x){return x*x*x*x*x*x;}

double markov4(double a,double b,double(*f)(double))
{
	return ((b-a)*(f(a)+5*f((a+b)/2-(b-a)/(2*sqrt(5)))+5*f((a+b)/2+(b-a)/(2*sqrt(5)))+f(b)))/12; 
}

int main(void)
{
 double a=2,b=3,res,i0,i1,i2,i3,i4,i5,i6;
 i0=b-a;
 i1=(b*b-a*a)/2; 
 i2=(b*b*b-a*a*a)/3;
 i3=(b*b*b*b-a*a*a*a)/4;
 i4=(b*b*b*b*b-a*a*a*a*a)/5;
 i5=(b*b*b*b*b*b-a*a*a*a*a*a)/6; 
 i6=(b*b*b*b*b*b*b-a*a*a*a*a*a*a)/7; 
 res=markov4(a,b,f0);printf("cent: %le\tpogr:%le\n",res,fabs(res-i0));
 res=markov4(a,b,f1);printf("cent: %le\tpogr:%le\n",res,fabs(res-i1));
 res=markov4(a,b,f2);printf("cent: %le\tpogr:%le\n",res,fabs(res-i2));
 res=markov4(a,b,f3);printf("cent: %le\tpogr:%le\n",res,fabs(res-i3));
 res=markov4(a,b,f4);printf("cent: %le\tpogr:%le\n",res,fabs(res-i4));// погрешность порядка шага сетки
 res=markov4(a,b,f5);printf("cent: %le\tpogr:%le\n",res,fabs(res-i5));
 res=markov4(a,b,f6);printf("cent: %le\tpogr:%le\n",res,fabs(res-i6));// на 6 степени работает не правильно 
 return 0;
}
