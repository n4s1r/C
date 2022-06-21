#include <stdio.h>
#include <math.h>

double f(double x)
{
 return sin(x);
}

double spline(double *x, double *y, int n, double k)
{
 double sp;int i;
 for(i=1;i<n-1;i++) 
  if(k<x[i])  
   break;
 i--;
 sp=y[i]+(y[i+1]-y[i])*(k-x[i])/(x[i+1]-x[i]);
 return sp;
}

int main(void)
{
 double x[2049], y[2049],a=0,h,delta,delta_old=0,delta_max=0.0,k,M=100000;int i,n;
 for(n=17;n<=2049;n=2*n-1)
 {
  printf("n=%d\t",n-1);
  h=1.0/(n-1);
  for(i=0;i<n;i++)
  {
   x[i]=a+i*h;
   y[i]=f(x[i]);
  }
  delta_max=0.0; 
  h=1.0/M;
  for(i=1;i<M;i++)
  {       
   k=a+i*h;
   if((delta=fabs(spline(x,y,n,k)-f(k)))>delta_max) delta_max=delta;	
  }
  printf("delta_max=%le\t",delta_max);
  printf("otnosheniye: %le\n",delta_old/delta_max);
  delta_old=delta_max;
 }
 return 0;
}
