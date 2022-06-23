#include <stdio.h>
#include <math.h>

void printBit (void *b , int n )
{
 int c, i;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=9;i>=0;i--)
  for(c=7;c>=0;c--)
   if(a[i]&(1<<c))printf("1");
   else printf("0");
 printf("\n");
}

void setChar (void *b,int n)
{
 int i , w;
 char *a ,c;
 a=(char*)b;
 while(1){
 printf("vvedi nomer bayta (<0 dlya vixoda): ");
 scanf("%d",&i);
 if(i<0 || i>n) return ;
 printf("vvedi celoye chislo (budet ispolz poled bayt): ");
 scanf("%d",&w);
 c=w;
 a[i]=c;
 printf("vvedyon simvol %c\n", a[i]);
 }
}


int main(void)
{
 long double a=123;
 printBit(&a,sizeof(long double));
 setChar(&a,sizeof(long double));
 printBit(&a,sizeof(long double));
 printf("chislo v itoge: %.50Lf \n", a);
 return 0;
}
