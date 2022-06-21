#include <stdio.h>
#include <math.h>

double f(double x)
{
 return x;
}

double lagr(double *x,double *f,double t,int n)
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
 double t;int i,n;  
 scanf("%d%lg",&n,&t);
 double x[n],y[n];
 for(i=0;i<n;i++){x[i]=i;y[i]=f(i);}
 printf("%lg\n",lagr(x,y,t,n));
 return 0;
}


