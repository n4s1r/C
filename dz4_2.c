#include <stdio.h>
#include <math.h>

double f(double x);
double perv(double x);
int integral(double a, double b, double eps, double *sum, double *sum_delta, double *sum_delta_fabs);
void integral_p(double a, double b, int n, double *sum);

int main(void)
{
 double a,b,p,sum7,sum9,sum11,sump7,sump9,sump11,sum_delta7,sum_delta9,sum_delta11,sum_delta_fabs7,sum_delta_fabs9,sum_delta_fabs11;int n7,n9,n11;
 printf("vvedite a i b: ");
 scanf("%lg%lg",&a,&b);
 p=perv(b)-perv(a);
 printf("nl=%lg\n\n", p);
 printf("eps=1.e-7-->\n");
 n7=integral(a, b, 1.e-7, &sum7, &sum_delta7, &sum_delta_fabs7);
 printf("shaqi=%d\n", n7);
 printf("int=%lg\n", sum7);
 printf("poqr=%lg\n", sum7-p);
 integral_p(a, b, n7, &sump7);
 printf("pogr int_p7-p=%lg\n", sump7-p);
 printf("sredvz=%lg\n", fabs(sum_delta7));
 printf("qarant=%lg\n\n", sum_delta_fabs7);
 printf("eps=1.e-9-->\n");
 n9=integral(a, b, 1.e-9, &sum9, &sum_delta9, &sum_delta_fabs9);
 printf("shaqi=%d\n", n9);
 printf("int=%lg\n", sum9);
 printf("poqr=%lg\n", sum9-p);
 integral_p(a, b, n9, &sump9);
 printf("pogr int_p9-p=%lg\n", sump9-p);
 printf("srednvz=%lg\n", fabs(sum_delta9));
 printf("qarant=%lg\n\n", sum_delta_fabs9);
 printf("eps=1.e-11-->\n");
 n11=integral(a, b, 1.e-11, &sum11, &sum_delta11, &sum_delta_fabs11);
 printf("shaqi=%d\n", n11);
 printf("int=%lg\n", sum11);
 printf("poqr=%lg\n", sum11-p);
 integral_p(a, b, n11, &sump11);
 printf("pogr int_p11-p=%lg\n", sump11-p);
 printf("srednvz:%lg\n", fabs(sum_delta11));
 printf("qarant=%lg\n\n", sum_delta_fabs11);
 printf("(s7-s9)/(s9-s11)=%lg\n",(sum7-sum9)/(sum9-sum11));
 printf("predpologaem=%lg\n", pow(100, 0.8));
 return 0;
}

double f(double x)
{
 //return sin(x);
 //return 1/x;
 return 10/(1+25*x*x);
}

double perv(double x)
{
 //return -cos(x);
 //return log(fabs(x));
 return 2*atan(5*x);
}

int integral(double a, double b, double eps, double *sum, double *sum_delta, double *sum_delta_fabs)
{
 double x=a, chi, h=(b-a)/8, hnew, delta, delta_fabs, f0=f(a), f1, f2, f3, f4, i2;int n=0;
 *sum=0;
 *sum_delta=0;
 *sum_delta_fabs=0;
 while(x<b-eps)
 {
	if(x+h>b)h=b-x;
	f1=f(x+0.25*h);
	f2=f(x+0.5*h);
	f3=f(x+0.75*h);
	f4=f(x+h);
	i2=(f0+4*f1+2*f2+4*f3+f4)*h/12;
  delta=h*(f0-4*f1+6*f2-4*f3+f4)/180;
  delta_fabs=fabs(delta);
  chi=pow(delta_fabs/eps, 0.2); 
  if(chi>10)chi=10;
  if(chi<0.1)chi=0.1;
  hnew=0.95*h/chi; 
  if(delta_fabs<eps){x+=h;f0=f4;*sum+=i2;*sum_delta+=delta;*sum_delta_fabs+=delta_fabs;n++;}
  h=hnew;
 }
 return n;
}
    
void integral_p(double a, double b, int n, double *sum)
{
 int i=0;
 double h=(b-a)/n;
 *sum=f(a)/6+2*f(a+h/2)/3; 
 for(i=1;i<n;i++)*sum+=(f(a+i*h)+2*f(a+(2*i+1)*h/2))/3;
 *sum+=f(b)/6;
 (*sum)*=h;
}
 
