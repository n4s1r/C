#include <stdio.h>

int deleniye(long long x,long long y,long long *a,long long *x1);

int main(void)
{
 long long x,y,a[100000],i,n,x1=-2;
 printf("vvedite 2 chisla: ");
 scanf("%lld%lld",&x,&y);
 if(y==0){printf("trudno podschitat\n");return -1;}
 if((x<0&&y>0)||(x>0&&y<0))printf("-");
 if(x<0)x=-x;  
 if(y<0)y=-y;
 n=deleniye(x,y,a,&x1);
 if(n==99999)printf("vsyu chast ne udalos podschitat\n");  
 for(i=0;i<n;i++)
 {
  if(i==0&&n!=1)printf("%lld.",a[i]);
  else if(n!=1&&x1==i){printf("(");x1=-1;}
  if(n==1||i!=0)printf("%lld",a[i]);
 }
 if(x1==-1)printf(")");
 return 0;
}

int deleniye(long long x,long long y,long long *a,long long *x1)
{
 long long i=0,j=0,b[100000];
 a[i]=x/y;b[i++]=0;
 while(i<100000)
 {
  x=x%y;b[i]=x; 
  x=x*10;a[i]=x/y;
  for(j=0;j<i;j++)if(b[j]==b[i]){if(*x1==-2)*x1=j;b[i]=0;break;}
  if(b[i++]==0)break;
 }
 return i-1;
}
