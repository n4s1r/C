#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f(void)
{
 int i;
 for(i=1 ; i>0 ; i*=i);
 return i;
}

int main (void)
{
 int  w;
 double t;
 t=clock();
 w=f();
 t=(t-clock())/CLOCKS_PER_SEC ;
 printf("vremmya vipolneniye %lg \n%d\n", t, w);
 return 0;
}

