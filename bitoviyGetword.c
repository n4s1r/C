#include <stdio.h>

int main (void)
{
unsigned alpha[8];
unsigned char c;
int i,j;
for(c='a';c<='z';c++)
{
 i=c/32;
 j=c%32;
 alpha[i]|=1<<j;
}
}
