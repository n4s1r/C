#include <stdio.h>
#include <string.h>

int getWord(FILE *fin,char *a,char *b);

int main(void)
{
 int i,j=0,n=0;
 char a[100],c[100];
 FILE *fin=NULL;
 fin=fopen("input.txt","r");
 while (fscanf(fin,"%s",a)==1)n++;
 fclose(fin);
 fin=fopen("input.txt","r");
 for(int i=33; i<127; i++)
 {
  c[j++]=i;
  if(i==64)i=90;
  else if(i==96)i=122;
 }
 for(i=0;i<n;i++)printf("%s %d\n",a,getWord(fin,a,c));
 return 0;
}

int getWord(FILE *fin,char *a,char *b)   
{
 int i=0,j=0,k=0,n=0,f=0;
 fscanf(fin,"%s",a);
 char c[100];
 strcpy(c,a);
 for(;a[i]!='\0';i++)
 {
  for(j=0;b[j]!='\0';j++){if(a[i]==b[j]){if(f==0){a[k++]=' ';f=1;}break;}}
  if(b[j]=='\0'){a[k++]=a[i];n++;f=0;}
 }
 if(k==1){strcpy(a,c);return 0;} 
 a[k]='\0'; 
 return n;  
}
