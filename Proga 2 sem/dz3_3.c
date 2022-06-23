#include <stdio.h>
#include <math.h>

double f(double x);
double df(double x);
double nyuton(double x,double eps);

int main(void)
{
 double x;
 printf("vvedite x: ");
 scanf("%lf",&x);
 printf("x = %lf\n",nyuton(x,1.e-15));
 return 0;
}

double f(double x)
{
 return 10*atan(20*x*x-200)+sqrt(x*x+1);
}

double df(double x)
{
 return 4000*x/(40001+400*x*x*x*x-8000*x*x)+x/sqrt(x*x+1);
}

double nyuton(double x,double eps)
{
 double h;int i=0; 
 do
 {
  i++;
  h=f(x)/df(x);  
  x-=h;
 } 
 while(fabs(h)>eps&&i<1024);
 return x;
}
