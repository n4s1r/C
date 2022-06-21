#include <stdio.h>
#include <math.h>

int nf; // число обращений к функции

int sign(double x)
{
 if(x>0)return 1;
 else if(x<0)return -1;
 return 0;
}

double g(double x)
{
 nf++;
 return exp(x-M_PI)-1;// e^(x-pi)-1
}

int root_chords(double *x,double a,double b,double (*f)(double),double epsilon)
{
 double fa,fb,fc,c[2];
 int i=0,ifa,ifb,ifc,k=1;
 c[0]=a; 
 c[1]=b; 
 fa=f(a); 
 fb=f(b);
 if(fabs(fa)<epsilon){*x=a; return 1;}
 if(fabs(fb)<epsilon){*x=b; return 1;}
 ifa=sign(fa); 
 ifb=sign(fb);
 if(ifa*ifb!=-1) return 0;
 while(fabs(c[1]-c[0])>epsilon)
 {
  i=!i;
  c[i]=(a*fb-b*fa)/(fb-fa);
  fc=f(c[i]); 
  ifc=sign(fc);
  if(fabs(fc)<epsilon)
  {
		*x=c[i]; 
		return k+1;
	}
  if(ifc*ifa==1)
  {
		a=c[i]; 
		fa=fc;
	}
  else 
  {
		b=c[i]; 
		fb=fc;
	}
	k++;
 }
 *x=c[i]; 
 return k; 
}

int main(void)
{
 double x; int res;
 nf=0;
 res=root_chords(&x,-10,45,g,1.e-15);
 if(res)
 {
  printf("x=%lg\nchislo iteraciy=%d\n",x,res-1);
  printf("chislo obrasheniye k funk=%d\n",nf);
 }
 else 
  printf("metod ne primenim\n");
 return 0;
}
