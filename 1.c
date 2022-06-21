#include <stdio.h>

int main(void)
{
 printf("float %lld\n", sizeof(float));         			    //float          4 
 printf("unsigned long %lld\n", sizeof(unsigned long));   //unsigned long  4
 printf("double %lld\n", sizeof(double)); 			          //double         8
 printf("long double %lld\n",sizeof(long double)); 				//long double   16
 printf("__float128 %lld\n",sizeof(__float128));   				//__float128    16
 return 0;
}
