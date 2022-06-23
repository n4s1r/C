#include <stdio.h>

int main ()
{
 printf("size of int %lld\n", sizeof(int));
 printf("size of short %lld\n", sizeof(short));
 printf("size of long %lld\n", sizeof(long));          //компилятор принимает %d и %lu но выдаёт предупреждение 
 printf("size of long long %lld\n", sizeof(long long));//и требует написать тип  long long usigned int - %lld 
 return 0;
}
// компилятор TDM-GCC  , среда разработки Geany 
