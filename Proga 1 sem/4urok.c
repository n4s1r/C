#include <stdio.h>

int a=7;

void f1(int a); // predopistatel funk
void f2(int *a);
void f3(int a);

int main (void)
{
 int a=12;
 printf("main blocka=%d &a=%llu\n", a, (unsigned long long)(&a));

 {
   int a=16;
   printf("blok vidimosti a=%d &a=%llu\n", a, (unsigned long long)(&a));
 }
                                                     
 f1(a);
 printf("main blocka=%d &a=%llu\n", a, (unsigned long long)(&a));

 f2(&a);
 printf("main blocka=%d &a=%llu\n", a, (unsigned long long)(&a));

 f3(a);
 printf("main blocka=%d &a=%llu\n", a, (unsigned long long)(&a));

 return 0;
}

void f1(int a)
{
 a++;
 printf("funk f1 a=%d &a=%llu\n", a, (unsigned long long)(&a));
}


void f2(int *a)
{
 (*a)++;
 printf("funk f2 a=%d &a=%llu\n", *a, (unsigned long long)(&a));
}

void f3(int b)
{
 a+=b;
 printf("funk f1 a=%d &a=%llu\n", a, (unsigned long long)(&a));
}
