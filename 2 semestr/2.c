#include <stdio.h>

void bitprint(void *a);

int main (void)
{
 double b;
 int j;
 scanf("%lg",&b);
 
 for(j=0; j<20;j++,b/=2)
 {
	printf("%le\t",b); 
  bitprint(&b);
 }
 return 0;
}

void bitprint(void *b)
{
 int c, i;
 unsigned *a;
 a=(unsigned*)b;
 for(i=1;i>=0;i--)
 {
  for(c=8*sizeof(unsigned)-1;c>=0;c--)
  {
    if(a[i]&(1<<c))printf("1");
    else printf("0");
    if(c%8==0)printf("  ");
  }
  printf("    ");
 } 
 printf("\n");
}

// union - союз 
