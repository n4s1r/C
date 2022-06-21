#include <stdio.h>

int getst(FILE *f,char *st,char *trash);

int main (void)
{
 int a;
 char st[800],trash[20]=":;.,()[]/-+*!? ";
 FILE *fin;
 fin=fopen("input.txt","r"); 
 if(fin==NULL)printf("Fayl ne nayden");
 trash[15]=10;
 while(1)
 {
  a=getst(fin,st,trash);
  if(a!=0)printf("%d\n",a);
  if(feof(fin))break;
 }
 printf("0");
 return 0;
}

int getst(FILE *f,char *st,char *trash)
{
 int cnt=0,i=0;
 char a=fgetc(f);
 for(;;i++)
 {
  if((a==trash[i]&&cnt!=0)||feof(f)){st[cnt+1]='\0';break;}
  else if(a==trash[i]&&cnt==0){a=fgetc(f);i=-1;}
  else if(trash[i]=='\0'){st[cnt++]=a;a=fgetc(f);i=-1;}
 }
 return cnt;
}

