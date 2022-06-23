#include <stdio.h>

//Проверить, чем отличаются битовые представления чисел x, −x, x/2, x/4, x/8, x + 1, x + 2
//−x - бит знака меняется на 0 если х (-) или на 1 если x (+) 
//x/2 - порядок числа (степень) уменьшается на 1 
//x/4 - порядок числа (степень) уменьшается на 2
//x/8 - порядок числа (степень) уменьшается на 3
//x + 1 - мантиса увеличивается на 1 (может увеличиться порядок числа)
//x + 2 - мантиса увеличивается на 2 (может увеличиться порядок числа)
  
void printBit (void *a);  

int main(void)
{
 double a,b;//тип double 8 байт 64 бит 11 бит под учёт порядка числа (степени)
 printf("vvedite chislo x: ");
 scanf("%lf",&a);
 printf("%-10lf  - " , a);
 printBit(&a);
 b=a;a=-a;
 printf("%-10lf  - ",a);
 printBit(&a);
 a=b;
 a/=2;
 printf("%-10lf  - ",a);
 printBit(&a);
 a/=2;
 printf("%-10lf  - ",a);
 printBit(&a);
 a/=2;
 printf("%-10lf  - ",a);
 printBit(&a);
 a=b;a++;
 printf("%-10lf  - ",a);
 printBit(&a);
 a++;
 printf("%-10lf  - ",a);
 printBit(&a); 
 return 0;
}

void printBit (void *a)
{
 int i; 
 for(i=63;i>=0;i--)
 {
	if(((*(unsigned long long*)a)&((unsigned long long)1<<i))!=0) printf("1");
	else printf("0");
	if(i==63||i==62||i==52) printf(" ");
 }
 printf("\n");
}
