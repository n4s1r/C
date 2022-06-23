#include <stdio.h>

int main (void)
{
 int i=0 , n=0; 
 FILE *fin=NULL;
 fin=fopen("input.txt","w"); 
 printf("vvedite kollichestvo ellemenot v fayle: ");
 scanf("%d" ,&n);
 for(i=1; i<=n;i++)   
 {
  if(i%2==0)fprintf(fin,"%d ", -i);
  else fprintf(fin,"%d ",i); 
  if(i%10==0)fprintf(fin,"\n");
 }
 return 0;
}

