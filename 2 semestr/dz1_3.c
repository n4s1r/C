#include <stdio.h>

//Написать функцию печати битового представления для long double, __float128.
//long double и __float128  - 16 байт - 128 бит  
// для long double лучше печатать до 10 байта 
// в long double старший единичный бит мантисы отображается

void printBitLD(void *b);
void printBit__F128(void *b);

int main(void)
{
 long double a;
 __float128 b;
 printf("vvedite chislo dlya long double : ");
 scanf("%Lf",&a);
 b=a;
 printf("long double:\n");
 printf("%-10.4Lf  - ",a);
 printBitLD(&a);
 printf("__float128:\n"); 
 printf("%-10.4Lf  - ",a);
 printBit__F128(&b);
 return 0;
}

void printBitLD(void *b)
{
 int i , j;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=9;i>=0;i--)
 {
	 for(j=7;j>=0;j--)
	 {
		if(a[i]&(1<<j))printf("1");
		else printf("0");
		if((i==9 && j==7)||(i==9 && j==6)||(i==8 && j==0)) printf(" ");
	 }
 }
 printf("\n");
}

void printBit__F128(void *b)
{
 int i,j;
 unsigned char *a;
 a=(unsigned char*)b;
 for(i=15;i>=0;i--)
 {
	 for(j=7;j>=0;j--)
	 {
		if(a[i]&(1<<j))printf("1");
		else printf("0");
		if((i==15 && j==7)||(i==15 && j==6)||(i==14 && j==0)) printf(" ");
	 }
 }
 printf("\n");
}

