#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char *strNcpy (char *a, char *b, int cnt);
int strCmp  (char *a , char *b);
char *strStr (char *a, char *b);
char *strCat (char *a, char *b);
long long strSpn (char *a, char *b);
long long strCspn (char *a, char *b); 

int main (int cntArg , char **strAr)
{
 int i;
 char a[10],b[10];
 printf("vvedite stroku 1 : ");scanf("%s",a);
 printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("vvedite kollichestvo simvolov kotoruyu xotite izmenit v 1 stroke: ");
 scanf("%d",&i);
 if(i<=0)return -1;
 printf("moy strncpy - %s\n", strNcpy(a,b,i));
 printf("vvedite stroku 1 : ");scanf("%s",a);
 printf("vvedite stroku 2 : ");scanf("%s",b);
 //printf("strncpy - %s\n", strncpy(a,b,i));

 //printf("vvedite stroku 1 : ");scanf("%s",a);
 //printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("moy strcmp - %d\n",strCmp(a,b));
 //printf("strcmp - %d\n", strcmp(a,b));

 //printf("vvedite stroku 1 : ");scanf("%s",a);
 //printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("moy strstr - %s\n",strStr(a,b));
 //printf("strstr - %s\n",strstr(a,b));

 //printf("vvedite stroku 1 : ");scanf("%s",a);
 //printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("moy strcat - %s\n",strCat(a,b));
 //printf("strcat - %s\n",strcat(a,b));

 printf("vvedite stroku 1 : ");scanf("%s",a);
 printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("moy strSpn - %lld\n", strSpn(a,b));
// printf("strSpn - %lld\n", strspn(a,b));

 //printf("vvedite stroku 1 : ");scanf("%s",a);
 //printf("vvedite stroku 2 : ");scanf("%s",b);
 printf("moy strcspn - %lld\n", strCspn(a,b));
// printf("strcspn - %lld\n", strcspn(a,b));

 return 0;
} 

char *strNcpy(char *a, char *b, int cnt)
{
 int i=0;
 for(;i<cnt;i++){a[i]=b[i];if(b[i]=='\0')break;}
 return a;
}

int strCmp (char *a , char *b)
{
 int i=0;
 for(;a[i]!='\0' && b[i]!='\0';i++)
 {
  if(a[i]>b[i])return 1;
  if(a[i]<b[i])return -1;
 }
 if(a[i]!='\0')return 1;
 if(b[i]!='\0')return -1;
 return 0;
}

char *strStr(char *a, char *b)
{
 int i=0,j=0,n=-1;
 for(i=0,j=0;a[i]!='\0'&&b[j]!='\0';i++)
 {
  if(a[i]==b[j]){j++;n=i;}
  else{j=0;n=-1;}
 }
 if(n==-1||b[j]!='\0')return "(null)";
 return a+(i-j);
}

char *strCat(char *a,char *b)
{
 int i=0,j=0;
 for(; b[j]!='\0';i++)
 if(a[i]=='\0'){a[i+1]='\0';a[i]=b[j++];}
 return a;
}

long long strSpn(char *a, char*b)
{
 long long cnt=0,i=0, j=0, n=0;
 for(;a[i]!='\0';i++)
 {
  n=0;
  for(j=0; b[j]!='\0'; j++){if(a[i]==b[j]){cnt++;n=1;break;}}
  if(n==0)break;
 }
 return cnt;
}

long long strCspn(char *a , char *b)
{
 long long  i=0,j=0;
 for(i=0;a[i]!='\0';i++){for(j=0;b[j]!='\0';j++){if(b[j]==a[i])return i;}}
 return i;
}
