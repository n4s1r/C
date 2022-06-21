#include <stdio.h>
#include <math.h>

double f(int n);

int maximum(int a,int b)
{
 return a>=b?a:b;  
}

void printArray(int n,double a[n][n]);
void zapolneniye_test1(int n, double a[n][n]);
void zapolneniye_test1_obr(int n, double a[n][n]);
void zapolneniye_test2(int n, double a[n][n]);
void zapolneniye_test2_obr(int n, double a[n][n]);
void umnojeniye(int n, double m1[n][n], double m2[n][n]);
void zapolneniye_gilbert(int n, double a[n][n]);
void zapolneniye_gilbert_obr(int n, double a[n][n]);

int main(void)
{
 int n;
 printf("vvedite n: ");
 scanf("%d",&n);
 double m1[n][n],m2[n][n];
  
 zapolneniye_test1(n,m1);
 printArray(n,m1);
 zapolneniye_test1_obr(n,m2);
 printArray(n,m2);
 printf("\nUmnojeniye matrici test1 i matrici obr matrici test1:\n");
 umnojeniye(n,m1,m2);
 
 zapolneniye_test2(n,m1);
 printArray(n,m1);
 zapolneniye_test2_obr(n,m2);
 printArray(n,m2);
 printf("\nUmnojeniye matrici test2 i matrici obr matrici test2:\n");
 umnojeniye(n,m1,m2);
 
 zapolneniye_gilbert(n,m1);
 printArray(n,m1);
 zapolneniye_gilbert_obr(n,m2);
 printArray(n,m2);
 printf("\nUmnojeniye matrici gilberta i matrici obr matrici gilberta:\n");
 umnojeniye(n,m1,m2);
 return 0;
}

double f(int n)
{
 if(n==0||n==1) return 1;
 return n*f(n-1);  
}

void printArray(int n,double a[n][n])
{ 
 printf("\n");
 int i,j;  
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
    printf("%lg\t",a[i][j]);
  printf("\n");
 }  
 printf("\n");
}

void zapolneniye_test1(int n, double a[n][n])
{
 int i,j;
 printf("\ntest 1 : \n");
 for(i=0;i<n;i++)
   for(j=0;j<n;j++)
   { 
     if(i+j==0)a[i][j]=1;
     else if(i==j && j>=1 && j<=n-1)a[i][j]=2;
     else if(fabs(i-j)==1)a[i][j]=-1;
     else a[i][j]=0;
   }
}

void zapolneniye_test1_obr(int n, double a[n][n])
{
 int i,j;  
 printf("\nobr k testu 1 :\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=n-maximum(i,j); 
}

void zapolneniye_test2(int n, double a[n][n])
{
 int i,j;
 printf("\ntest 2 : \n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=fabs(i-j);
}

void zapolneniye_test2_obr(int n, double a[n][n])
{
 int i,j;double m=(double)n;  
 printf("\nobr k testu 2 :\n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   if(i==j&&(j==0||j==n-1))a[i][j]=-(m-2)/(2*m-2);
   else if(i==j&&(j>0&&j<n-1))a[i][j]=-1;
   else if(fabs(i-j)==1)a[i][j]=0.5;
   else if((i==0&&j==n-1)||(i==n-1&&j==0))a[i][j]=1.0/(2*m-2);
   else a[i][j]=0;
  }
}

void umnojeniye(int n, double m1[n][n], double m2[n][n])
{
 double a[n][n];int i,j,c;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=0;  
 for(i=0;i<n;i++)
  for(c=0;c<n;c++)
  {
   for(j=0;j<n;j++)
    a[i][c]+=m1[i][j]*m2[j][c]; 
   if(fabs(a[i][c])<1.e-6)a[i][c]=0;
  }
 printArray(n,a);
}

void zapolneniye_gilbert(int n, double a[n][n])
{
 int i,j;
 printf("\nmatrica gilberta : \n");
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   a[i-1][j-1]=1.0/(i+j-1.0);
}

void zapolneniye_gilbert_obr(int n, double a[n][n])
{
 int i,j;
 printf("\nobratnaya k matrice gilberta : \n");
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   a[i][j]=(f(n+i)*f(n+j))/(f(j)*f(j)*f(i)*f(i)*f(n-j-1)*f(n-i-1)*(i+j+1));
   if((i+j)%2)a[i][j]=-a[i][j];
  }  
}
