#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortPros (int *a ,int n);

//Сортировка Просеиванием.
//50000   3.737000 секунд
//100000  14.925000 cекунд
//200000  59.375000 cекунд

int main (void)
{
 int *a, n, i=0 ;
 float tFull;
 FILE *fin=NULL;
 if((fin=fopen("input.txt","r"))==NULL)
 {printf("fayl ne nayden\n");return -1;}
 if(fscanf(fin,"%d",&n)!=1){printf("v fayle net elementov\n");return -2;}
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n && fscanf(fin,"%d",&a[i])==1;i++);
 if(i<n)n=i;
 tFull=clock();
 sortPros(a,n);
 tFull=(clock()-tFull)/CLOCKS_PER_SEC;
 for(i=0; i<n; i++)printf("%d ", a[i]);
 printf("\n"); 
 printf("obsheye vremya - %lf\n", tFull);
 return 0;
}


void sortPros (int *a ,int n)
{
 int i=0,j=0,tmp;
 for (i=0;i<n-1; i++)
 	for(j=i+1;j>0&&a[j]<a[j-1];j--){tmp=a[j];a[j]=a[j-1];a[j-1]=tmp;}
}
