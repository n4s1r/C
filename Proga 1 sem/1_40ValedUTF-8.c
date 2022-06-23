#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sdvig(int *a,int n , int k);

int main (void)
{
 int *a,n,k,i=0;
 double tFull;
 FILE *fin=NULL;
 if((fin=fopen("input.txt","r"))==NULL){printf("fayl ne nayden\n");return -1;}
 if(fscanf(fin,"%d",&n)!=1){printf("v fayle net elementov\n");return -2;}
 if(n<=0){printf("oshibka videleniye pamyati\n");return -3;}
 a=(int*)malloc(n*sizeof(int));
 for(i=0;i<n && fscanf(fin,"%d",&a[i])==1;i++);
 if(i<n)n=i;
 printf("skolko raz sdvinut elementi massiva vpravo: ");
 scanf("%d",&k);
 tFull=clock();
 sdvig(a,n,k);
 tFull=(clock()-tFull)/CLOCKS_PER_SEC;
 //for(i=0; i<n; i++)printf("%2d ", a[i]);
 printf("\nobsheye vremya dlya sdviga - %lf", tFull);
 return 0;
}
void printArray (int *a,int n)
{
 for(int i=0; i<n; i++)
  printf("%2d ", a[i]);
 printf("\n");
}
void sdvig(int *a ,int n, int k)
{
 int i=0,tmp,tmp1=a[0],glavEl=0, cnt=0;
 k%=n;
 if(k==0)return ;   
 for(i=k ; i<n*k; i+=k)
 { 
  tmp=a[i%n];
  if(i%n==glavEl){a[(i++)%n]=tmp1;tmp1=a[i%n];glavEl=i%n;continue;}  
  a[i%n]=tmp1;tmp1=tmp;
  printArray(a,n);
  cnt++;
 }
 a[i%n]=tmp1;
 printArray(a,n);
 printf("cnt - %d\n", ++cnt);
}
