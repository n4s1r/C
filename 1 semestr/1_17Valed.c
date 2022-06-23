#include <stdio.h>

/*1.17. Пусть последовательность является неубывающей. Определите
количество элементов, которые появляются в этой последовательности
более k раз, ( значение k вводится с клавиатуры).*/

int main (void)
{
 int x, y , k ,i=1, cnt=0;
 FILE *fin=NULL;
 fin=fopen("input.txt","r");
 if(!fscanf(fin,"%d",&x))
 {
  printf("fayl ne nayden\n");
  return -1;
 }
 if(!fscanf(fin,"%d",&x))
 {
  printf("v fayle net elementov\n");
  return -2; 
 }
 printf("vvedite k : ");
 scanf("%d",&k);
 while(fscanf(fin,"%d",&y)==1)
 {
  if(x>y)
  {
   printf("posled ne neubivayushaya\n");
   return -3;
  }
  else if(x==y)
   i++;
  else
  {
   if(i>k)
    cnt++;
   i=1;
  }
  x=y;
 }
 if(i>k)
  cnt++;
 printf("kollichestvo elementov kotoriye vstrech bolee %d raz - %d\n", k, cnt );
 return 0;
}
