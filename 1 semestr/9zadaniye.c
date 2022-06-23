#include <stdio.h>

//9. Определить число абсолютно максимальных элементов в последовательности.

int main ()
{
 int a, n=0, max;
 FILE *fin=NULL;
 fin=fopen("input.txt","r");
 if(fin==NULL)
 {
  printf("fayl ne nayden\n");
  return 1;
 }
 if(fscanf(fin,"%d",&a)!=1)
 {
  printf("elementov netu\n");
  return -1;
 }
 max=a;
 n++;
 while(fscanf(fin,"%d",&a)==1)
 {
  if(max==a)
   n++;
  if(max<a)
  {
   n=1;
   max=a;  
  }
 }
 printf("chislo abs maximumov - %d sam maximum - %d\n",n, max ); 
 return 0;
}
