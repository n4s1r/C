#include <stdio.h>
#include <math.h>

double sinus(double x,double eps)
{
	double h,sum;int i=4,a;
 	a=x/(2*(M_PI));
	x-=2*(M_PI)*a;
	sum=x;
	h=(-1)*(pow(x,3)/6);
	do
	{
		sum+=h;
		h*=-(x/i)*(x/(i+1));
		i+=2; 
	}while(fabs(h)>eps);
 return sum;	
}

int main(void)
{
	double x,eps=1.e-16;
	scanf("%lf",&x);
	printf("sinus %lg\n",sinus(x,eps));
	printf("nastoyashiy sinus %lg\n",sin(x));
	return 0;
}
