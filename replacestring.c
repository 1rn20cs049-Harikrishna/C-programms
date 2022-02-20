#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int slen(char *);
void replace(char * ,char*, char *,char *);

int main ()
{
    char T[40]; //= {"bahvdahsvbahgsahba"};
    char P[20];//={"ba"};
    char REP[20];//={"BA"};
    char FIN[50];
    
    printf("Enter the main string\n");
    scanf("%s",T);
    printf("Enter the pattern need to match the main string\n");
    scanf("%s",P);
    printf("Enter the replacement string\n");
    scanf("%s",REP);
    replace(T,P,REP,FIN);
    
    printf("%s\n",FIN);


}


int slen (char *s)
{
    int len=0;
    for(;s[len]!='\0';len++);
    return len;
}

void replace(char *T,char *P,char *REP,char *FIN)
{
  int k=0,s,r,l,q = 0,z;
  s=slen(T);  r=slen(P);

  for(;k<=s;)
  {
      for(l=0;l<r;l++)
          if(P[l]!=T[k+l])
              break;
    if(l == r)
    {
      for(z=0;z<slen(REP);z++)
          FIN[q++]=REP[z];
           k = k+r;
     }
     else {
         FIN[q++] = T[k++];
    }
     FIN[q]='\0';
    }
  
}







