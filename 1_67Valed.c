#include <stdio.h>

void razlojNaProstMnoj(int n);

int main (void)
{
 int n;
 printf("vvedite chsilo : ");
 scanf("%d", &n);
 razlojNaProstMnoj(n);
 return 0;
}

void razlojNaProstMnoj(int n)
{
 printf("1 "); 
 for(int i=2;n!=1;)
 {
  if(n%i==0){printf("%d ",i);n/=i;}
  else if(i!=2)i+=2;
  else if(i==2)i++;
 }
}
