#include <stdio.h>
#include <math.h>

double spline(double *x,double *y,double *d,double t,int n);

int main(void)
{
 double x[2049],y[2049],d[2049],a=0,h,t,dlt_max=0,dlt_old=0,dlt,M=100000;int i,n;
 for(n=17;n<=2049;n=2*n-1)
 {
  h=1.0/(n-1);
  for(i=0;i<n;i++){x[i]=a+i*h;y[i]=sin(x[i]);d[i]=cos(x[i]);}
  dlt_max=0; 
  h=1.0/M;
  for(i=1;i<M;i++){t=a+i*h;if((dlt=fabs(spline(x,y,d,t,n)-sin(t)))>dlt_max)dlt_max=dlt;}
  printf("n %d\tDelta maximum :%lg\tSootnosheniye :%lg\n",n-1,dlt_max,dlt_old/dlt_max);
  dlt_old=dlt_max;
 }
 return 0;
}

double spline(double *x,double *y,double *d,double t,int n)
{
 double spl,c0,c1,c2,c3,h;int i;  
 for(i=1;i<n-1;i++)if(t<x[i])break;
 i--;
 h=x[i+1]-x[i];
 c0=y[i];
 c1=d[i];
 c2=(3*y[i+1]-3*y[i]-d[i+1]*h-2*d[i]*h)/(h*h);
 c3=(2*y[i]-2*y[i+1]+d[i+1]*h+d[i]*h)/(h*h*h);
 spl=c0+c1*(t-x[i])+c2*pow(t-x[i],2)+c3*pow(t-x[i],3);
 return spl;
}
