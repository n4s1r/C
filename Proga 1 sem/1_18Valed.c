#include <stdio.h>

int main (void)
{
 float cnt=0 , x  , sredArifm=0 , sredKvOtkl=0 ,sumChl=0, sumKvChl=0; // я мог бы несоздовать последние
 FILE *fin=NULL;                                                    // 2 переменные , но сделал для наглядности 
 fin=fopen("input.txt","r");
 if(fin==NULL)
 {
  printf("fayl ne nayden!\n");
  return 1;
 }
 if(fscanf(fin,"%f",&x)!=1)
 {
  printf("v fayle net elementov\n");
  return -1;
 }
 sumChl=x;
 sumKvChl=x*x;
 for(cnt=1;fscanf(fin,"%f",&x)==1;cnt++)
 {
  sumChl+=x;
  sumKvChl+=x*x;
 }
 sredArifm=sumChl/cnt;
 sredKvOtkl=(sumKvChl/cnt)-(sredArifm*sredArifm);
 printf ("SRED ARIFM  = %f\n" ,sredArifm );
 printf ("SRED KVADRATICHESKOYE OTKL = %f\n" ,sredKvOtkl );
 return 0;
}
