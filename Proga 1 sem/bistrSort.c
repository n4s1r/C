#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qSort(int *a, int left ,int right);

void printArray(int *a , int left, int right)
{
 for(int i=0; i<left ; i++)
 printf("   ");
 for(int i=left; i<=right; i++)
  printf("%2d ", a[i]);
 printf("\n");
}

int main (void)
{
 srand(time(NULL));
 int *a , i=0, n=4;
 double fTime;
 FILE *fin=NULL;
 if((fin=fopen("input.txt","r"))==NULL){printf("vayl ne nayden\n"); return -1;}
 if(!(fscanf(fin,"%d",&n))){printf("v fayle net elementov\n");return -2;}
 if(n<=0){printf("oshibka pamyati\n"); return -3;}
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n&&fscanf(fin,"%d",&a[i]);i++);
 fTime=clock();
 printArray(a,0,n-1);
 qSort(a,0,n-1);
 printArray(a,0,n-1);
 fTime=(clock()-fTime)/CLOCKS_PER_SEC;
 printf("\nobsheye vremya dlay sort %lf\n", fTime);
 return 0;
}

void qSort(int *a, int lev , int prav)
{
 int l=lev, r=prav, p=a[(l+r)/2] , tmp=0;
 printArray(a,lev, prav);
 while (l<=r)
 {
  while(a[l]<p)l++; 
  while(a[r]>p)r--;
  if(l<=r){tmp=a[l];a[l++]=a[r];a[r--]=tmp;}
 }
 if(lev<r)qSort(a,lev,r);
 if(l<prav)qSort(a,l,prav);
}
