#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void hSort1(int *a, int n);
void printArray (int *a , int n);

// 1000000 эл. 0.289 секунд

int main (void) 
{
 int *a,n,i=0;
 FILE *fin=NULL;
 double fT;
 if(!(fin=fopen("input.txt","r"))){printf("problemi!\n");return -1;}
 if(fscanf(fin,"%d",&n)!=1&&n<=0){printf("oshibka videl pamyati\n");return -2;}
 a=(int*)malloc(n*sizeof(int));
 for(i=0; i<n&&fscanf(fin,"%d",&a[i]);i++);
 if(i<n)n=i;
 for(int j=0 ; j<n; j++)printf("%2d ", a[j]);
 printf("\n");
 fT=clock();
 hSort1(a,n);
 fT=(clock()-fT)/CLOCKS_PER_SEC;
 for(int j=0 ; j<n; j++)printf("%2d ", a[j]);
 printf("\n");
 printArray(a,n);
 printf("\npolnoye vremya %lf\n", fT);
 return 0;
}

void hSort1(int *a, int n)
{
  int star,l,r,i,j,tmp;
  for (i=n/2-1;i>=0;i--)
  {
   j=i;star=j;  
   while(2*j<n)
   {	
    star=j;l=2*star+1;r=2*star+2;
    if(l<n&&a[l]>a[star])star=l;
    if(r<n&&a[r]>a[star])star=r;
    if(a[star]==a[j])break;
    tmp=a[j];a[j]=a[star];a[star]=tmp;j=star;
   for i=n-1;i>0;i--)
  {
   if(a[0]!=a[i]){tmp=a[0];a[0]=a[i];a[i]=tmp;}  
   j=0;star=0;  
   while(2*j<i)
   {
    star=j;l=2*star+1;r=2*star+2;
    if(l<i&&a[l]>a[star])star=l;
    if(r<i&&a[r]>a[star])star=r;
    if(a[star]==a[j])break;
    tmp=a[j];a[j]=a[star];a[star]=tmp;j=star;
   }
  }
}

void printArray (int *a , int n)
{
 int i=0, cnt=1, prob=16;
 for(int j=0; j<=prob;j++)printf("  ");
 printf("%d", a[i]);
 for(i=1; i<n; i++)
 {
  if(i+1==pow(2,cnt)){printf("\n");cnt++;for(int j=0; j<=prob/pow(2,cnt-1);j++)printf("  ");}
  printf("%d", a[i]); 
  for(int j=0; j<=prob/pow(2,cnt);j++)printf("  ");
 }
}
