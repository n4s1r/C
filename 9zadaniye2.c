#include <stdio.h>
#include <stdlib.h>
void f (int *a, int *n, int x);
int main (void)
{
int *a,n,x,i;
 FILE *fin=NULL;
 if((fin=fopen("input.txt","r"))==NULL){return -1;}
 if(!fscanf(fin,"%d",&n)){return -2;}
 if(n<=0){return -3;} 
 a=(int*)malloc(n*sizeof(int));
 if(a==NULL){return -4;}
 for(i=0;fscanf(fin,"%d",&a[i])==1 && i<n ; i++);
 if(i<n-1){n=i++;}
 scanf("%d",&x);
 f(a, &n, x);
 for(i=0;i<n;i++){printf("%d ", a[i]);}
 return 0; 
}
void f(int *a , int *n , int x)
{
 int i=0,j=0;
 for(i=0; i<*n; i++)
  if(a[i]<=x){a[j]=a[i];j++;}
 *n=j;
}

void f1(int *a, int *n, int x)
{
 int tmp ,i=0, j=0;
 while(j<*n)
 {
  tmp=a[i];
  a[i]=a[j];
  a[j]=tmp;
  while(a[i]<=x){i++;}
   j=i;
  while(a[j]>x){j++;}
 }
 (*n)=i;
}

void f2(int *a, int *n, int x)
{
 int tmp ,i=0, j=0;
 while(i<(*n)&&j<(*n))
 {
  if(a[j]<=x && a[i]>x)
  {tmp=a[i];a[i]=a[j];a[j]=tmp; i++;j++;}
  if(a[i]<=x)
   {i++; j=i;}
  if(a[j]>x)
   {j++;}
 }
 (*n)=i;
}
