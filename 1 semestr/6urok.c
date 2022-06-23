#include <stdio.h>
#include <stdlib.h>

int f(void)
{
 int i;
 for(i=1 ; i>0 ; i++);
 return i;
}

int factorial(int n);
//int fib(int n);

int main (void)
{
 //int w;
 //w=f();
 //printf("w = %d\n", w);
 int n=9, i , a[]={1,2,3,4,5,6,7,8,9};// stat mas
 //printf("isxod massiv\n");
 for(i=0 ; i<n;i++)
 { 
  printf("%d ", a[i]);
  if(i%10==9)
   printf("\n");
 }
 printf("\n");

 int n1=40, a1[n1];
 for(i=0 ; i<n1;i++)
  a1[i]=factorial(i);
 for(i=0 ; i<n1;i++)
 { 
  printf("%d ", a1[i]);
  if(i%10==9)
   printf("\n");
 }
 printf("\n");
 //int chisl=5;
 //printf("fibon - %d\n",fib(chisl+2));
/*
 int x=14 , a2[x];
 for(i=0 ; i<x;i++)
  a2[i]=fib(i);
 for(i=0 ; i<x;i++)
 { 
  printf("%d ", a2[i]);
  if(i%10==9)
   printf("\n");
 }
 printf("\n");
  */
 return 0;
}

int factorial(int n)
{
 if(n<1)
  return 1;
 return n*factorial(n-1);
}

int fib(int n)
{
 static int mas[40]={0};
 if(n<=0){printf("chtoto ochen strannoye %d\n", n);exit(1);}
 if(mas[n-1]!=0)return mas[n-1];
 if(n==2 || n==1) return mas[n-1]=1;
 return mas[n-1]=fib(n-1)+fib(n-2);
}
