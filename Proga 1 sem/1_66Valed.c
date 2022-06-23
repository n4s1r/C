#include <stdio.h>
#include <time.h>

//500000-ое простое число 7368787 подсчитает за  секунд 0.991000

void dobavProstChisel(int *a,int n)
{
 int j,i=4,p=11,m,q=1; 
 while(i<n)
 {
  m=0;
  for(j=2;a[j]*a[j]<=p;j++){if(p%a[j]==0){m=1;break;}}
  if(m==0){a[i++]=p;}
  p+=3+(q=-q);
 }
}
 
int main(void)
{
 int n;
 double t;
 int a[500000];
 printf ("vvedite chislo bolshe 4: ");
 scanf ("%d", &n);
 a[0]=2;a[1]=3;a[2]=5;a[3]=7;
 t=clock();
 dobavProstChisel(a,n);
 t=(clock()-t)/CLOCKS_PER_SEC;
 printf("%d\n",a[n-1]);
 printf("vremya zatrachennoye na vipoln %lf\n", t);
 return 0;
}
 
