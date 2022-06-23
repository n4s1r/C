#include <stdio.h>


int main()
{
 FILE *fin=NULL;
 fin=fopen("input.txt","r");
 int x;
 int y;
 int f=0;
 fscanf(fin,"%d",&x);
 while(fscanf(fin,"%d",&y)==1)
 {
  if(x<y)
  {
   printf("%d ", x);	  
   f=1;
  }
  else if(x>=y && f==1)
  {
   printf("%d\n",y);
   f=0;
  }
  x=y;
 }
 if(f==1)
   printf("%d\n",y);
 return 0;
}
