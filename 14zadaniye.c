#include <stdio.h>

//14. Определить число чисел последовательности НЕ РАВНЫХ абсолютно минимальному элементу в последовательности.

int main ()
{
 int a , cnt=0 , min=0 ,minCnt=0;
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
  return -1;     // cnt - колличество всех элементов
 }               // minCnt - колличество всех абсолютно минимальных элементов
 min=a;          // значение 1 ого эл. присваиваем min возможно оно будет абсолютным минимумом
 minCnt++;       // и увеличиваем колл. абс. мин. на 1 
 for(cnt=1;fscanf(fin,"%d",&a)==1;cnt++)  
 {                                      
  if(min==a)     // если минимальный элемент равен следуещему эл. из послед  
   minCnt++;     // то minCnt увеличиваем на 1
  if(min>a)      // ecли след. эл. из послед. меньше min 
  {
   min=a;        // то min присваиваем значение этого эл.
   minCnt=1;     // и колл. абс. мин. эл. присваиваем 1
  }
 }
 cnt-=minCnt; // вычетаем от общего колличества элементов колличество всех абсолютных минимумов
 printf("chislo chisel ne ravnix absolutnomu minimalnomu chislu %d v posledovatelnosti =  %d\n",min,cnt); 
 return 0;
}
