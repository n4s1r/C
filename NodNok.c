#include <stdio.h>

int nodNok(int a,int b,int*nod,int*nok);

int main(void)
{
 int a,b,nod,nok;
 printf("vvedite a i b: ");  
 scanf("%d%d",&a,&b);
 if(!nodNok(a,b,&nod,&nok))printf("NOD(a,b)=%d\nNOK(a,b)=%d\n",nod,nok);
 else printf("nekorrektniye danniye\n");
 return 0;
}

int nodNok(int a,int b,int *nod,int *nok)
{
 long long tmp,a1,b1;
 if(a==0||b==0)return 1;
 if(a<0)a=-a; 
 if(b<0)b=-b;
 if(a==b){*nod=a;*nok=a;return 0;}
 a1=a;b1=b;
 while(b1!=0){tmp=a1%b1;a1=b1;b1=tmp;}
 * nod=a1; * nok=((a/( * nod)) * (b/( * nod)))*(*nod);
 if(nok<=0)return 1;
 return 0;
}
