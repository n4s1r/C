#include <stdio.h>
#include <math.h>

double my_exp(double x)
{
	double sum=1.0, h, eps=1.e-16; int i=2;
	h=x;
	do
	{
		sum+=h;
		h*=x/i;
		i++;
	}
	while(fabs(h)>eps);
	return sum;
}

int main(void)
{

 double x,expx,res,delta;	
 scanf("%lg",&x);
 expx=exp(x);
 res=my_exp(x);
 delta=res-expx;
 printf("exp(x)=%lg %lg %le %le", expx,res,delta,(res/expx-1.0));
 return 0;
}
