#include <stdio.h>


void bitPrint(unsigned a)
{
 int c;
 for(c=8*sizeof(unsigned)-1;c>=0;c--)
 {
  if(a&(1<<c))printf("1");
  else printf("0");
  if(c%8==0) printf(" ");
 }
}

void bitPrint1(unsigned a)
{
 int c=1;
 if(!a)printf("0");
 while(a)
 {
  if(a&1)printf("1");
  else printf("0");
  c++;
  a>>=1;
 }
}

unsigned setBit1(unsigned a,unsigned j)
{
 return a|(1<<j);
}

unsigned setBit0(unsigned a,unsigned j)
{
 return a&~(1<<j);
}

unsigned invBit(unsigned a,unsigned j)
{
 return a^(1<<j);
}

int stBit(int a)
{
 int i; 
 for(i=0;a;i++)a>>=1;
 return i;
}

int numBit(unsigned a)
{
 int i;
 for(i=0;a;a>>=1)if(a&1)i++;
 return i;
}

int main (void)
{
 unsigned b;
 int j;
 printf("vvedite chislo : ");
 scanf("%u",&b);
 bitPrint(b);
 printf("\n");
 bitPrint1(b);
 printf("\n");
 printf("16richniy vid chisla  %x\n",b);// %x это для 16 ричного предс.
 printf("vvedite ind bita: ");
 scanf("%d", &j);
 unsigned w;
 w=setBit1(b,j);
 bitPrint(w);
 printf("\n");
 w=setBit0(b,j);
 bitPrint(w);
 printf("\n");
 w=invBit(b,j);
 bitPrint(w);
 printf("\n");
 printf("strash bit %u\n", stBit(b));
 bitPrint(b);
 printf("\n");
 printf("chislo bit %u\n", numBit(b));
 return 0;
}

