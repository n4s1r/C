#include <stdio.h>
#include <math.h>

double f(int n);
int maximum(int a,int b);
void printArray(int n,double a[n][n]);
void zapolneniye_test1(int n, double a[n][n]);
void zapolneniye_test1_obr(int n, double a[n][n]);
void zapolneniye_test2(int n, double a[n][n]);
void zapolneniye_test2_obr(int n, double a[n][n]);
void zapolneniye_gilbert(int n, double a[n][n]);
void zapolneniye_gilbert_obr(int n, double a[n][n]);
void zapolneniye_gilbert_plus_edin(int n,double a[n][n]);

int main(void)
{	 
 int n=0;
 printf("vvedite n : ");
 scanf("%d",&n);
 double a[n][n]; 
 printf("\ntest 1 : \n");
 zapolneniye_test1(n,a);
 printArray(n,a);
 printf("\nobr k testu 1 :\n");
 zapolneniye_test1_obr(n,a);
 printArray(n,a);
 printf("\ntest 2 : \n");
 zapolneniye_test2(n,a);
 printArray(n,a);
 printf("\nobr k testu 2 :\n");
 zapolneniye_test2_obr(n,a);
 printArray(n,a);
 printf("\nmatrica gilberta : \n"); 
 zapolneniye_gilbert(n,a);
 printArray(n,a);
 printf("\nobratnaya k matrice gilberta : \n"); 
 zapolneniye_gilbert_obr(n,a);
 printArray(n,a);
 printf("\nmatrica gilberta plyus edin matrica: \n"); 
 zapolneniye_gilbert_plus_edin(n,a);
 printArray(n,a);
 return 0;
}

double f(int n) 
{
 if(n==0||n==1) return 1;
 return n*f(n-1);	
}

int maximum(int a,int b)
{
 return a>=b?a:b;	
}

void printArray(int n,double a[n][n])
{
 for(int i=0;i<n;i++)
 {
 	for(int j=0;j<n;j++)
 		printf("%lg\t",a[i][j]);
 	printf("\n");
 }
 printf("\n");
}

void zapolneniye_test1(int n, double a[n][n])
{
 int i,j;
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
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=n-maximum(i,j);
}

void zapolneniye_test2(int n, double a[n][n])
{
 int i,j;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   a[i][j]=fabs(i-j);
}

void zapolneniye_test2_obr(int n, double a[n][n])
{
 int i,j;double m=(double)n;
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

void zapolneniye_gilbert(int n, double a[n][n])
{
 int i,j;
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   a[i-1][j-1]=1.0/(i+j-1.0);
}

void zapolneniye_gilbert_obr(int n, double a[n][n])
{
 int i,j;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  {
   a[i][j]=(f(n+i)*f(n+j))/(f(j)*f(j)*f(i)*f(i)*f(n-j-1)*f(n-i-1)*(i+j+1));
   if((i+j)%2)a[i][j]=-a[i][j];
  }
}

void zapolneniye_gilbert_plus_edin(int n,double a[n][n])
{
 int i,j;	
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
	 a[i][j]=1.0/(1.0+i+j)+!(j-i);
}
