#include <stdio.h>
#include <math.h>

double f(double x)
{
 return sin(x);
}

double lagr(double *x, double *f,double t,int n)
{
 double z,sum=0;int i,j;
 for(i=0;i<n;i++)
 {
	z=1; 
	for(j=0;j<n;j++)if(j!=i)z*=(t-x[j])/(x[i]-x[j]);
	sum+=z*f[i];
 }
 return sum;
}

int main(void)
{
 double h,z,delta,deltaMax=0,t,tMax=0,M=100000;int n,i;
 scanf("%d",&n);
 double x[n],y[n];
 h=1.0/(n-1);
 for(i=0;i<n;i++)
 {
  x[i]=i*h;
  y[i]=f(x[i]);
 }
 h=1.0/(M-1);
 for(i=0;i<M;i++)
 {
  t=i*h;
  delta=fabs(lagr(x,y,t,n)-f(t));
  if(delta>deltaMax){deltaMax=delta;tMax=t;}
 }
 z=1;
 for(i=1;i<=n;i++)z*=0.5/i;
 printf("deltaMax=%le\nz=%le\ntMax=%le\n",deltaMax,z,tMax);	
 return 0;
}
