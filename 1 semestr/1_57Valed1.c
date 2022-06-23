#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Сортировка методом перестановки максимального элемента
void sort (int *a , int n);

int main (void)
{
 srand(time(NULL));
 int *a , n , i=0;
 FILE *fin=NULL;
 fin=fopen("input.txt","w");
 fprintf(fin,"10");
 for(int k=0; k<10 ; k++)fprintf(fin,"%d ", rand()%10);
 fclose(fin); 
 if((fin=fopen("input.txt","r"))==NULL)
 {printf("fayl ne nayden\n");return -1;}
 if(fscanf(fin,"%d",&n)!=1){printf("v fayle net elementov\n");return -2;}
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n && fscanf(fin,"%d",&a[i])==1;i++);
 if(i<n-1){n=i++;}
 for(i=0; i<n; i++){printf("%d ", a[i]);}
 printf("\n");
 sort(a,n);
 for(i=0; i<n; i++){printf("%d ", a[i]);}
 printf("\n");
 return 0;
}

void sort (int *a , int n)
{
 int i=0 , j=0 , tmp=0 , cnt=0, maxInd=0;
 for(i=0 ; i<n; i++)
 {
  maxInd=0;
  for(j=0;j<n-cnt; j++){if(a[maxInd]<a[j])maxInd=j;}
  cnt++;
  tmp=a[maxInd];a[maxInd]=a[n-cnt];a[n-cnt]=tmp; 
 }  // oper     O
}//(n(n-1))/2  n^2
 // 50000  el i vremya
 // 100000 el i vremya
 // 200000 el i vremya
