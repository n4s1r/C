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
 double t0, t1;
 t0=clock();
 w=f();
 t1=clock();
 printf("vremmya vipolneniye %lg \n%d\n", (t1-t0)/CLOCKS_PER_SEC , w);
 return 0;
}

