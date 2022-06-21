#include <stdio.h>
#include <math.h>

int nf=0;

int sign(double d)
{
 if(d>0)return 1;
 else if(d<0)return -1;
 return 0;
}

double f(double y)
{
	nf++;
	return sin(y);
}

int rootHalf(double *x,double a,double b,double (*f)(double),double eps)
{
	int i=0;
	double c,fa=f(a),fb=f(b),fc;
	if(sign(fa)==0){*x=a;return 1;}
	if(sign(fb)==0){*x=b;return 1;}
	if(sign(fa)==sign(fb))return 0;
	do
	{
	 c=(a+b)/2;fc=f(c);
	 if(sign(fc)==0){*x=c;break;}
	 if(sign(fc)==sign(fa))a=c;
	 if(sign(fc)==sign(fb))b=c;
	 i++;
	} 
	while(fabs(b-a)<eps*fabs(a+b)/2||fabs(b-a)<eps);
	return i;
}

int main(void)
{
 double x,a,b;int i=0;
 printf("vvedite [a b]: ");
 scanf("%le%le",&a,&b);
 i=rootHalf(&x,a,b,&f,1.e-15);
 printf("koll iteraciy %d\n",i);
 if(i!=0)printf("koren %le\nkoll vizovov funk %d\n",x,nf);
 return 0;
}
