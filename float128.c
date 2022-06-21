#include <stdio.h>

int main(void)
{
 __float128 a=1.0 , b=1.0;
 double x;
 int i=0;
 do
 {
  x=a;
  printf("%d: %le\n", i,x);
  a/=2;i--;
 }
 while(b+a>b);
 return 0;
}
