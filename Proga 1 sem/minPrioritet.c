#include <stdio.h>

void print (long long *a, int n)
{
 for(int i=0;i<n;i++)printf("%2lld ",a[i]);
 printf("\n");
}

void hWhile(long long *a, int n, int i)
{
  int l, r, largest=i;
  long long tmp;  
  while(2*i<n)
  {	  
   l=2*i+1;r=l+1;
   if(l<n && a[l]<a[largest])largest=l;
   if(r<n && a[r]<a[largest])largest=r;
   if(a[largest]==a[i])break;
   tmp=a[i];a[i]=a[largest];a[largest]=tmp;
   i=largest;
  }
}
void hSort(long long *a, int n)
{
  int i;
  for (i=n/2-1; i>=0; i--)
   hWhile(a,n,i);	
}

void heapIncreasKey(long long *a, int i , long long key)
{
 a[i]=key;
 long long tmp;
 while(i>0 && a[(i-1)/2]<a[i] )
 {
  tmp=a[i];a[i]=a[(i-1)/2];a[(i-1)/2]=tmp;
  i=(i-1)/2;
 }
}

int main (void)
{
 long long a[]={5,4,3,2,1};
 int n=5;
 int b;
 int i=0;
 hSort(a,n);
 print(a,n);
 while(i<5)
 {
  scanf("%d",&b);
  a[n-1]+=b;
  hSort(a,n);
  heapIncreasKey(a,n-1,a[n-1]);
  print(a,n);
  i++;
 }
 return 0;
}
