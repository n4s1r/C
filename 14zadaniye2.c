#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void f(int *a, int *n, int x);
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
void f(int *a, int *n, int x)
{
 int i=0, j=0 , tmp;
 if(x<0)
 x=-x;
 while(j<*n&&i<*n)
 {
  if(abs(a[j])>=x&&abs(a[i])<x){tmp=a[i];a[i]=a[j];a[j]=tmp;i++;j++;}
  if(abs(a[j])<x){j++;}
  if(abs(a[i])>x){i++;}
 }
 *n=i; 
}
