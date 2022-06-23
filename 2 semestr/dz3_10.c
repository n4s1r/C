#include <stdio.h>
#include <math.h>

int count=0;

int min(double x, double y, double z)
{
 if(x<=y&&x<=z) return 1;
 if(y<=x&&y<=z) return 2;
 return 3;
}

double f(double x)
{
 count++;
 return x/(1+x*x);
}

int minPopolam(double *x, double a, double b, double (*f)(double), double eps)
{
 int n=0, g;
 double x1, x2, x3, fx1, fx2, fx3, w;
 if(a>b){w=a;a=b;b=w;}
 fx1=f(a);
 fx2=f(*x);
 fx3=f(b);
 if(fx2>fx1||fx2>fx3)printf("narusheno usloviye 3.13\n");
 if(*x<(999*a+b)/1000||*x>(a+999*b)/1000)printf("blizko k qranice ili ne v otrezke\n");
 //if(fx2>fx1||fx2>fx3||
 if(*x<(999*a+b)/1000||*x>(a+999*b)/1000)
 {
  x1=(3*a+b)/4; 
	x2=(a+b)/2; 
	x3=(a+3*b)/4; 
 }
 else if(*x<(2*a+b)/3)
 {
	x1=*x;
	x2=(2*x1+b)/3;
	x3=(x1+2*b)/3;
 }
 else if(*x>(a+2*b)/3)
 {
	x3=*x;
	x2=(2*x3+a)/3;
	x1=(x3+2*a)/3;
 }
 else
 {
	x2=*x;
	x1=(x2+a)/2;
	x3=(b+x2)/2; 
 }
 fx1=f(x1); 
 fx2=f(x2);
 fx3=f(x3);	
 while(fabs(b-a)>eps*fabs(a+b)/2&&fabs(b-a)>eps)
 {
  g=min(fx1, fx2, fx3);
	n++;
  printf("a=%le x1=%lg x2=%lg x3=%lg b=%le\nfx1=%lg fx2=%lg fx3=%lg\n", a, x1, x2, x3, b, fx1, fx2, fx3);
  if(g==1)
  {
	 b=x2;			
	 x2=x1;
	 fx2=fx1;
	}
	else if(g==2)
	{
	 a=x1;
	 b=x3;
  }
	else
	{
	 a=x2;
	 x2=x3;
	 fx2=fx3;
	}
	x1=(a+x2)/2;
	x3=(x2+b)/2;
	fx1=f(x1);
	fx3=f(x3);
 }
 *x=x2;
 return n;
}

int main(void)
{
 double a,b,eps=1.e-15,x;
 int n;
 scanf("%lg%lg%lg",&a,&b,&x);
 n=minPopolam(&x,a,b,f,eps);
 printf("n=%d\ncount=%d\n", n, count);
 printf("%lg\n", x);
 return 0;
}
