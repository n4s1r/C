#include <stdio.h>
#include <math.h>
 /*
   Например: 
   При x=50: 
   Максимальный по модулю элемент ряда =  2.920286e+20
   Шаг сетки максимального по модулю элемента ряда = 3.276800e+04
   Относительная погрешность =  1.776357e-15 
	 Получили что относительная погрешность меньше шага сетки (вполне приемлемо). 
	
	 При x=-30: 
   Максимальный по модулю элемент ряда = 7.762070e+11
   Шаг сетки максимального по модулю элемента ряда = 1.220703e-04
   Абсолютная погрешность = 6.103042e-06
	 Шаг сетки больше абсолютной погрешности, а сама абсолютная погрешность составляет меньше половины шага сетки.
	*/ 
double shagSetki(double a)
{
 double b,d,x;
 x=fabs(a)+1.0;
 while(a+x>a){b=a+x;d=b-a;x/=2.0;}
 return d;	
}

double maxRyad(double x, double eps,double *sum)
{
 double h,ElRyad;
 int i=2;	
 h=x;
 do
 {
  *sum+=h;	
  if(fabs(h)>ElRyad)ElRyad=fabs(h);
 	h*=x/(i++);
 }while(fabs(h)>eps);
 return ElRyad;	
}

int main(void)
{
  double eps=1.e-16,x,maxEl=0,sum=1.0;
  scanf("%le",&x);
  maxEl=maxRyad(x,eps,&sum); 
  printf("Abs. pogreshnost: %le\n",sum-exp(x)); 
  printf("Otn. pogreshnost: %le\n",sum/exp(x)-1.0);
  printf("Max po modulyu element ryada: %le\n",maxEl);
  printf("Shag setki maximalnogo po modulyu elementa etogo ryada: %le\n",shagSetki(maxEl));
  return 0;
}

