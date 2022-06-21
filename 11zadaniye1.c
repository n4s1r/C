#include <stdio.h>

//11. Последовательность представляет собой коэффициенты многочлена,
//записанные в порядке возрастания степеней. Вычислить значение многочлена и его
//производной в точке x. Число x вводится с клавиатуры.

int main (void)
{
 int res=0, resP=0 , x , a , i=0 , cnt=0;
 FILE *fin=NULL;
 fin=fopen("input.txt","r");
 if(fin==NULL)
 {
  printf("fayl ne nayden\n");
  return 1;
 }
 printf("vvedite znacheniye tochki: ");
 scanf("%d", &x);
 if(fscanf(fin,"%d",&a)!=1)
 {
  printf("v fayle net elemenotv\n");
  return 2;
 }
 res=a;
 cnt=1;
 for(i=x;fscanf(fin,"%d",&a)==1;i*=x)
 {
  res+=a*i;
  resP+=cnt*a*(i/x);
  cnt++;
 }
 printf("znacheniye mnogochlena v tochke %d = %d\n", x,res);
 printf("znacheniye proizvodnoy mnogochlena v tochke %d = %d\n", x,resP);
 return 0;
}
