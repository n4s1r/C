#include <stdio.h>

int dvaVStepeniN(unsigned n);//1 вопрос
void bitPrint(unsigned a);//2 вопрос
int kollEd(unsigned a);//3 вопрос
int stBit(unsigned a);//4 вопрос
unsigned setBit1(unsigned a,unsigned j);//5 вопрос
unsigned setBit0(unsigned a,unsigned j);//6 вопрос
unsigned invBit(unsigned a,unsigned j);//7 вопрос
int sdvigVlevo(unsigned a);//8 вопрос
int cnt11(unsigned a);//9 вопрос
int swpBit(unsigned a , int b, int c);//10 вопрос
int sdvigDoI(unsigned a, int i);//11 вопрос
int vopros12(unsigned a);//12 вопрос
int vopros13(unsigned a);//13 вопрос 
int mld0Bit1(unsigned a);//14 вопрос
int vse1KromeMld0(unsigned a);//15 вопрос

int main (void)
{
 unsigned n,w,i,j;
 printf("vvedite chislo: ");
 scanf("%d",&n);
 printf("2 v stepeni %d = %d\n", n,dvaVStepeniN(n));
 bitPrint(n);
 printf("kollichestvo edinic v bit.pred. %d\n", kollEd(n));
 printf("nomer starshego bita %d\n", stBit(n));
 printf("nomer bita : ");
 scanf("%d", &i);
 printf("invertaciya %d bita na 1:", i);
 w=setBit1(n,i);
 bitPrint(w);
 printf("invertaciya %d bita na 0:", i);
 w=setBit0(n,i);
 bitPrint(w);
 printf("invertaciya %d bita:", i);
 w=invBit(n,i);
 bitPrint(w);
 printf("sdvig vlevo na 1: ");
 w=sdvigVlevo(n);
 bitPrint(w);
 printf("kollichestvo 11 v bitovom predstavlenii chisla %d %d\n",n, cnt11(n));
 printf("vvedite 2 nomera dlya invertaciyi bitov mejdu soboy iz chisla %d: ", n);
 scanf("%d%d",&i,&j);
 w=swpBit(n,i,j);
 bitPrint(w);
 printf("sdvig napravo do %d elementa: ", i-1);
 w=sdvigDoI(n,i);
 bitPrint(w);
 printf("%d&(%d) : ", n,n-1);
 w=vopros12(n);
 bitPrint(w);
 printf("%d&(%d) : ", n, -n);
 w=vopros13(n);
 bitPrint(w);
 printf("invertaciya mladshego 0 bita na 1: ");
 w=mld0Bit1(n);
 bitPrint(w);
 printf("invertaciya vsex bitov na 1 krome  mladshego 0 bita: ");
 w=vse1KromeMld0(n);
 bitPrint(w);
 return 0;
}

int dvaVStepeniN(unsigned n)
{
 return 1<<n;
}

void bitPrint(unsigned a)
{
 int c;
 printf("chislo %3d :", a);
 for(c=8*sizeof(unsigned)-1;c>=0;c--)
 {
  if(a&(1<<c))
		printf("1");
  else 
		printf("0");
  if(c%8==0) 
		printf(" ");
 }
 printf("\n");
}

int kollEd(unsigned a)
{
 int i;
 for(i=0;a;a>>=1)
	if(a&1)
		i++;
 return i;
}

int stBit(unsigned a)
{
 int i; 
 for(i=0;a;i++)
	a>>=1;
 return i;
}

unsigned setBit1(unsigned a,unsigned j)
{
 return a|(1<<j);
}

unsigned setBit0(unsigned a,unsigned j)
{
 return a&~(1<<j);
}

unsigned invBit(unsigned a,unsigned j)
{
 return a^(1<<j);
}

int sdvigVlevo(unsigned a)
{
 if(a>=128)
	return((a-128)<<1)+1;
 return a<<1;
}

int cnt11(unsigned a)
{
 int cnt=0,c=1,k=0;
 for(int i=0;c;i++)
 {
  if(a&c)
		k++;
  else
  {
		if(k!=0)
			cnt+=k-1;
		k=0;
	}
  c<<=1;
 }
 return cnt;
}

int swpBit(unsigned a ,int b,int c)
{
 if((a&1<<b)==(a&1<<c))
	return a;
 a=a^(1<<b);
 a=a^(1<<c);
 return a; 
}

int sdvigDoI(unsigned a,int i)
{
 int c,b=0;
 for(c=8*sizeof(unsigned)-1;c>=0;c--)
 {
  if(c<i&&a&(1<<c))
		b+=1<<c;
  else if(c>=i&&(a>>1)&(1<<c))
		b+=1<<c;
 }
 return b;
}

int vopros12(unsigned a)//первый младший единичный бит приравнивается к нулю 
{
 return a&(a-1);
}

int vopros13(unsigned a)//все биты приравниваются к нулю ,кроме младшего единичного бита 
{
 return a&(-a);
}

int mld0Bit1(unsigned a)
{
 return a|(a+1);
}

int vse1KromeMld0(unsigned a)
{
 return ~((a|(a+1))-a);
}
 
