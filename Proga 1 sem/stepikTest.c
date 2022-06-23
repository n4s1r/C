#include <stdio.h>

int main() 
{
 int min,max,minInd,maxInd,n,m;
 scanf("%d %d", &n,&m);
 int a[n][m],res=0;  
  for(int i=0; i<n; i++)
   for(int j=0; j<m; j++)
    scanf("%d", &a[i][j]);
  for(int i=0; i<n;i++)
    res+=a[i][m-1];
  min=res;
  minInd=m-1;  
  max=res;
  maxInd=m-1;  
  for(int i=m-1;i>=0;i--)
  {
   res=0;
   for(int j=0; j<n;j++)
    res+=a[j][i];    
   if(res<min){min=res;minInd=i;}
   if(res>max){max=res;maxInd=i;}   
  }
  int tmp;  
 for(int i=0; i<n; i++)  
 {
  tmp=a[i][minInd];
  a[i][minInd]=a[i][maxInd];
  a[i][maxInd]=tmp;   
 }
     
  for(int i=0; i<n; i++)
  {
   for(int j=0; j<m; j++)
    printf("%d ", a[i][j]);
   printf("\n");
  }
      
 return 0;
}
