#include <stdio.h>

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

void bitprint_c(void *b)
{
 int c, i;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=7;i>=0;i--)
  for(c=7;c>=0;c--)
  {
    if(a[i]&(1<<c))printf("1");
    else printf("0");
    if(i==7 && c==7)printf(" ");
    if(i==6 && c==4)printf(" ");
  }
 printf("\n");
}

void bitprint_ld(void *b)
{
 int c, i;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=7;i>=0;i--)
  for(c=7;c>=0;c--)
  {
    if(a[i]&(1<<c))printf("1");
    else printf("0");
    if(i==7 && c==7)printf(" ");
    if(i==6 && c==4)printf(" ");
  }
 printf("\n");
}

int main (void)
{
 double b=16;
 //int j;
 while(b>0)
 {
	printf("%le\t",b);
  bitprint_c(&b);
  b/=2;
 }
 return 0;
}
