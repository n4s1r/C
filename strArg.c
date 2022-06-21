#include <stdio.h>
#include <stdlib.h>
int main (int cntArg , char **strAr)
{
 int i, a, b;
 for(i=0; i<cntArg ; i++)
 printf("%d %s\n", i, strAr[i]);
 sscanf(strAr[1],"%d", &a );
 b=atoi(strAr[1]);
 printf("a = %d b = %d\n", a, b);
 return 0;// cmd DIR <  cd 
}
