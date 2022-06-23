#include <stdio.h>

void hSort(long long *a,int n)
{
 int star,l,r,i,j;
 long long tmp;
 for (i=n/2-1;i>=0;i--)
 {
  j=i;star=j;  
  while(2*j<n)
  {	
   star=j;l=2*star+1;r=2*star+2;
   if(l<n&&a[l]<a[star])star=l;
   if(r<n&&a[r]<a[star])star=r;
   if(a[star]==a[j])break;
   tmp=a[j];a[j]=a[star];a[star]=tmp;j=star;
  }
 }
}

void heapify(long long *a,int n)
{
  int i=0,l,r,star=0;
  long long tmp;
  while(2*i<n)
  {	  
   l=2*i+1;r=l+1;
   if(l<n&&a[l]<a[star])star=l;
   if(r<n&&a[r]<a[star])star=r;
   if(a[star]==a[i])break;
   tmp=a[i];a[i]=a[star];a[star]=tmp;i=star;
  }
}

int main()
{
 int n,k,i,maxInd;
 scanf("%d %d", &k, &n);
 long long  a[n],b[k],tmp=0;
 for(i=0;i<n;i++){scanf("%lld", &a[i]);if(i<k)b[i]=a[i];}
 if(k==1){for(i=0;i<n;i++)tmp+=a[i];printf("%lld\n",tmp);}
 else if(k<n)
 {
  hSort(b,k);
  for(i=k;i<n;i++){b[0]+=a[i];heapify(b,k);}
  maxInd=((k-1)/2)+1;
  for(i=((k-1)/2)+2;i<k;i++)if(b[maxInd]<b[i])maxInd=i;
  printf("%lld",b[maxInd]);
 }
 else
 {
  maxInd=0;
  for(i=0;i<n;i++)if(a[maxInd]<a[i])maxInd=i;
  printf("%lld",a[maxInd]);
 }
} 
