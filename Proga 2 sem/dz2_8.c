#include <stdio.h>
#include <math.h>

int sign(double a)
{
 if(a>0)return 1;
 return -1;
}

int kvUr(double b, double c, double *x1, double *x2)
{
 double d,eps=1.e-15;
 d=b*b-4*c;
 if(d<0)return 0;
 *x1=-(b+sign(b)*sqrt(d))/2;
 if(fabs(*x1)<eps){*x2=0;return 0;}
 *x2=c/(*x1);
 if(b==0)*x2=-(*x2);
 return 1; 
}

int kvUrSh(double b, double c,double *x1, double *x2)
{
 double d;
 d=b*b-4*c;
 if(d<0)return 0;
 *x1=(-b+sqrt(d))/2; 
 *x2=(-b-sqrt(d))/2;
 return 1;
}

int main(void)
{
 double x1,x2,b,c,bSh,cSh,b1,c1,res1,res2,res1sh,res2sh;	
 int f=0,f1=0;
 printf("vvedite 2 chisla: ");
 scanf("%lf%lf",&b,&c);
 printf("tochniye b i c:\n");
 printf("b = %le\n",b);
 printf("c = %le\n",c);
 printf("\n");
 f=kvUrSh(b,c,&x1,&x2);
 if(f)
 {
	printf("Iz funk kvUrSh:\n"); 
	bSh=-(x1+x2);
  cSh=x1*x2;
  res1sh=x1*x1+b*x1+c;
  res2sh=x2*x2+b*x2+c;
  printf("b = %le\n",bSh);
  printf("c = %le\n",cSh);
  printf("f(x1) : %le\n",res1sh);
  printf("f(x2) : %le\n",res2sh);
  printf("\n"); 
 }
 f1=kvUr(b,c,&x1,&x2);
 if(f1)
 {
	printf("Iz funk kvUr:\n"); 
	b1=-(x1+x2);
  c1=x1*x2;
  res1=x1*x1+b*x1+c;
  res2=x2*x2+b*x2+c;
  printf("b = %le\n",b1);
  printf("c = %le\n",c1);
  printf("f(x1) : %le\n", res1);
  printf("f(x2) : %le\n", res2); 
  printf("\n");
 }
 if(f&&f1)
 {
	 if(fabs(res1)<fabs(res1sh))printf("kvUr() luchshe dlya x1\n");
	 else if(fabs(res1)>fabs(res1sh)) printf("kvUrSh() luchshe dlya x1\n"); 
	 else printf("oni ravni dlya x1\n");
	 if(fabs(res2)<fabs(res2sh))printf("kvUr() luchshe dlya x2\n");
	 else if(fabs(res2)>fabs(res2sh)) printf("kvUrSh() luchshe dlya x2\n"); 
	 else printf("oni ravni dlya x2\n");
 }
 return 0;
} 


