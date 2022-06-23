#include <stdio.h>
#include <math.h>

double myExp(double x)
{
	double sum=1.0, h, eps=1.e-16; int i=2;
	h=x;
	do
	{
		sum+=h;
		h*=x/(i++);
	}
	while(fabs(h)>eps);
	return sum;
}

int main(void)
{
  double x,resx,res;
  double x1,a,b,c;
  while(scanf("%lf",&x)==1)
  {
		resx=exp(x);
		res=myExp(x);
		a=res;
		x1=fabs(a)+1.0;
    while(a+x1>a){b=a+x1;c=b-a;x1/=2.0;}
    printf("shag setki %le\n", c);
		printf("exp(x)=%lg\nnash exp(x)=%lg  abs. pogr. %le otnos. pogr. %le\n",resx,res,res-resx,(res/resx-1.0));
	}
	return 0;
}
