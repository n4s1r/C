#include <stdio.h>
#include <time.h>

// 1000000 простое число подсчитает за ~ 10 или 8 секунд

void dobavProstChisel(int *a,int n)
{
 for(int k=4,j,i=9;k<n;i+=2)
 {
  //m=0;  
  for(j=1;a[j]<=(i/a[j]);j++){if(i%a[j]==0){break;}}
  if(a[j]>(i/a[j])){a[k++]=i;}
 }
}
 
int main(void)
{
 int n;
 float t;
 printf ("vvedite chislo bolshe 4: ");
 scanf ("%d", &n);
 int a[n];
 //int b[1000000];
 //for(int i=0; i<1000000;i++){b[i]=i*2;}
 //printf("%d\n", b[999999]); 
 a[0]=2;a[1]=3;a[2]=5;a[3]=7;
 t=clock();
 dobavProstChisel(a,n);
 t=(clock()-t)/CLOCKS_PER_SEC;
 printf("%d\n",a[n-1]);
 printf("vremya zatrachennoye na vipoln %f\n", t);
 return 0;
}
