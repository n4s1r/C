#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char *strNcpy(char *a, char *b, int cnt)
{
 int i=0;
 for(;i<cnt;i++){a[i]=b[i];if(b[i]=='\0')break;}
 return a;
}

int main(void)
{
 int i=0;
 char a[100],b[100];
 printf("pervaya stroka: ");
 scanf("%s", a);
 printf("vtoraya stroka: ");
 scanf("%s", b);
 printf("vvedite kollichestvo simvolov iz 2 stroki kotoruyu xotite skopirovat : ");
 scanf("%d", &i);
 printf("moy strncpy - %s\n", strNcpy(a,b,i));
 printf("vvedite stroku 1 : ");scanf("%s",a);
 printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("strncpy - %s\n", strncpy(a,b,i));
 return 0;
}
