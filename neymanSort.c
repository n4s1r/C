#include <stdio.h>
#include <time.h>

// сорт. 1000000 эл 32.853 сек.   

int main(void)
{   
 FILE *fin=NULL , *f[4];    
 int a,b,c,i,j,k[4],z[4];
 char fayl[4][6];
 for(i=0;i<4;i++){sprintf(fayl[i], "%d.txt", i);}
 double fT;
 fT=clock(); 
 while(1)
 {
  c=0;
  fin=fopen("input.txt", "r");
  for(i=0;i<4;i++)
  {
   f[i]=fopen(fayl[i],"w");
   fprintf(f[i]," ");
  }   
  fscanf(fin,"%d", &a);
  fprintf(f[0],"%d ", a);
  while(fscanf(fin,"%d",&b)==1)
  {
   if(b<a)c++; 
   fprintf(f[c%4],"%d ",b);a=b;
  }
  if(c==0)break;
  fclose(fin);
  for(i=0;i<4;i++){fclose(f[i]);}
  fin=fopen("input.txt", "w");
  for(i=0;i<4;i++){f[i]=fopen(fayl[i],"r");}
  for(i=0;i<4;i++)k[i]=0;
  for(i=0;i<4;i++){if(fscanf(f[i],"%d",&z[i])!=1)k[i]=-1;}
  while(k[0]+k[1]+k[2]+k[3]!=-4)
  {                        
   c=0;                    
   for(i=0;i<4;i++)        
    if(k[i]==0)             
      {                
       if(c==0){j=i;c=1;}
       if(z[i]<z[j])j=i;	
      }
   if(c==0){for(i=0;i<4;i++)if(k[i]==1)k[i]=0;}
   else
     {	
      fprintf(fin,"%d ",a=z[j]);
      if(fscanf(f[j],"%d",&z[j])!=1)k[j]=-1;
      if(k[j]==0)if(z[j]<a)k[j]=1;
     }
   }
  fclose(fin);
  for(i=0;i<4;i++){fclose(f[i]);}
 }
 fT=(clock()-fT)/CLOCKS_PER_SEC;
 printf("obsheye vremya %lf\n",fT );
 fin=fopen("input.txt","r");
 while(fscanf(fin,"%d",&a)==1)printf("%d ", a);
 return 0;
}

