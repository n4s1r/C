#include <stdio.h>
#include <math.h>

double f(double t);
double Markov4(double x, double h);
double integral(double alpha, double eps, double *sum_delta_abs, int *n, double *xmin, double *xmax);

int main(void)
{
 double sum_delta_abs=0,x=0,xmin,xmax,alpha;int n=0;
 printf("type alpha: ");
 scanf("%le", &alpha);
 x=integral(alpha,1.e-7,&sum_delta_abs,&n,&xmin,&xmax);
 if(x>0) printf("x = %lf\nGrid steps: %d\nGuaranteed error: %le\nxmin = %le\nxmax = %le\n",x,n,sum_delta_abs,xmin,xmax);
 else printf("no roots\n");
 return 0;
}

double f(double t)
{
 return log(pow((t*t*t*t+1),1.0/3.0));
}

double Markov4(double x,double h)
{
 static double c1=1.0/12.0,c2=5.0/12.0,k1,k2;
 k1=(1.0-sqrt(1.0/5.0))/2;
 k2=(1.0+sqrt(1.0/5.0))/2;
 return h*(c1*(f(x)+f(x+h))+c2*(f(x+k1*h)+f(x+k2*h)));
}

double integral(double alpha,double eps,double *sum_delta_abs,int *n,double *xmin,double *xmax)
{
 double z=0, chi, h=1.0/127, hnew, sum = 0., delta, delta_abs, i1, i2;
 *sum_delta_abs=0.0;
 *n=0.0;
 while (sum<alpha-eps)
 {
  if(z>=0)
  {
   i1=Markov4(z,h);
   i2=Markov4(z,h/2)+Markov4(z+h/2,h/2);
   delta=(i2-i1)/63.;
   delta_abs=fabs(delta);
   chi=pow(delta_abs/eps,1.0/7.0);
   if(chi>10.0)chi=10.0;
   if(chi<0.1)chi=0.1;
   hnew=0.95*h/chi;
   if (delta_abs<eps)
   {
    if (sum+i2>alpha+eps) 
      hnew=h*(alpha-sum)/i2; 
    else
     {
      z+=h;
      sum+=i2;
      *sum_delta_abs+=delta_abs;
      (*n)++;
     }
   }
   h=hnew;
  }
  else{z=-1;break;}
 }
 *xmin=(alpha-sum-*sum_delta_abs)/f(z);
 *xmax=(alpha-sum+*sum_delta_abs)/f(z);
 return z;
}
