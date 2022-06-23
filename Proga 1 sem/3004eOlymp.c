#include <stdio.h>
void hSort1(long long *a, int n)
{
  int star,l,r,i,j;
  long long tmp;
  for (i=n/2-1;i>=0;i--)
  {
   j=i;star=j;  
   while(2*j<n)
   {	
    star=j;l=2*star+1;r=2*star+2;
    if(l<n&&a[l]>a[star])star=l;
    if(r<n&&a[r]>a[star])star=r;
    if(a[star]==a[j])break;
    tmp=a[j];a[j]=a[star];a[star]=tmp;j=star; //swap
   }
  }
   for(i=n-1;i>0;i--)
   {
    if(a[0]!=a[i]){tmp=a[0];a[0]=a[i];a[i]=tmp;} //swap
    j=0;star=0;  
    while(2*j<i)
   {
    star=j;l=2*star+1;r=2*star+2;
    if(l<i&&a[l]>a[star])star=l;
    if(r<i&&a[r]>a[star])star=r;
    if(a[star]==a[j])break;
    tmp=a[j];a[j]=a[star];a[star]=tmp;j=star;
   }
  }
}

int main (void) 
{
 int n,k,minInd,i,j,maxInd;
 scanf("%d%d", &n, &k);
 long long  a[n];
 for(i=0;i<n; i++)
  scanf("%lld", &a[i]);
 hSort1(a,k);
 if(k<n)
 {
  for(j=k;j<n;j++)
  {
   minInd=0;
   for(i=0;i<k;i++)
    if(a[minInd]>a[i])
      minInd=i;
   a[minInd]+=a[j];
  }
 }
 maxInd=0;
  for(i=0;i<n&&i<k;i++)
   if(a[maxInd]<a[i])
     maxInd=i;
 printf("%lld\n",a[maxInd]);
 return 0;
}
