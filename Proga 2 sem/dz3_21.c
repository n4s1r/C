#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linRegres(double*x,double*y,double*a,double*b,int n);

int main(void)
{
 double x[100],y[100],xMin=0,dx=10,a=1,b=1,eps=0.3,err;int n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  x[i]=xMin+(dx*rand())/RAND_MAX;
  err=eps*((2.0*rand())/RAND_MAX-1.0);
  y[i]=a*x[i]+b+err;
 }
 linRegres(x,y,&a,&b,n);
 printf("%lg\n%lg\n",a,b);	
 return 0;
}
 
int linRegres(double*x,double*y,double*a,double*b,int n)
{
 double sumX,sumX2,sumY,sumXY;int i;
 for(i=0;i<n;i++){sumX+=x[i];sumY+=y[i];sumXY+=x[i]*y[i];sumX2+=x[i]*x[i];}  
 if(fabs(n*sumX2-sumX*sumX)<0)return 1;
 *a=(n*sumXY-sumX*sumY)/(n*sumX2-sumX*sumX);  
 *b=(sumX2-sumXY)/(n*sumX-sumX);
 return 0;
}
