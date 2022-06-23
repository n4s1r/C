#include <stdio.h>
#include <stdlib.h>

void f(int *a , int n);

int main (void)
{
 int a[10]; // stat mas
 for(int i=0;i<10; i++)
  a[i]=i;
 printf("adres massiva - %p\n", a);
 printf("adres 1 elem. - %p\n", &a[0]);
 printf("adres 2 elem. - %p\n", &a[1]);

 int *mas; // dinam massiv
 int n;
 FILE *fin;

 if((fin=fopen("input.txt","r"))==NULL){printf("fayl ne nayden!\n"); return -1;}
 if(!fscanf(fin,"%d",&n)){printf("elementov net!\n"); return -2;}
 if(n<=0){printf("oshibka razmernosti massiva n=%d!\n",n); return -3;} 
 mas=(int*)malloc(n*sizeof(int));
 if(mas==NULL){printf("oshibka videleniya pamyati\n"); return -4;}

 printf("do raboti funk : ");
 for(int i=0;fscanf(fin,"%d",&mas[i])==1 && i<n ; i++)
  printf("%d ", mas[i]);        
 printf("\n");

 f(mas,n);

 printf("posle raboti funk : ");
 for(int i=0; i<n; i++)
  printf("%d ", mas[i]);
 printf("\n");
 printf("adres massiva - %p\n", mas);
 printf("adres 1 elem. - %p\n", &mas[0]);
 printf("adres 2 elem. - %p\n", &mas[1]);
 return 0;
}

void f(int *a , int n)
{
 for(int i=0 ; i<n; i++) 
 {
  if(a[i]<0)
   a[i]=-a[i];
 }
}

 /*
 int n;
 FILE *fin=NULL;
 fin=fopen("input.txt","w");
 printf("vvedite koll elementov : ");
 scanf("%d", &n);
 fprintf(fin,"%d\n",n);
 for(int i=0; i<n; i++)
 {
  if(i%2) 
   fprintf(fin,"%d ",-i);
  else
   fprintf(fin,"%d ", i);
  if(i%9==0)
   fprintf(fin,"\n");
 }
 fclose(fin);
 int a;
 fin=fopen("input.txt", "r");
 while(fscanf(fin,"%d",&a)==1)
  printf("%d " , a);
 */
