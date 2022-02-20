#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30


int f(char s)
{
    switch(s)
    {
        case '+' :
        case '-' : return  2 ;
        case '*' :
        case '/' : return 4 ;
        case '$' :
        case '^' : return 5 ;
        case '(' : return 0 ;
        case '#' : return -1;
        default  : return 8;
    }
    
}


int g(char s)
{
    switch(s)
    {
        case '+' :
        case '-' : return  1 ;
        case '*' :
        case '/' : return 3 ;
        case '$' :
        case '^' : return 6 ;
        case '(' : return 9 ;
        case ')' : return 0 ;
        default  : return 7 ;
    }
    
}

int main ()
{   
    char s[MAX] ={ '#' };
    char inf[MAX]; //={ "a+b/(c+d)" };
    char pf[MAX] ;
    int i,j,top=0;
    scanf("%s",inf);
    
    for(i=0;i<strlen(inf);i++)
    {
        while(f(s[top]) > g(inf[i]) )
        {
            pf[j]= s[top];
            j++;
            top-- ;
        }
        
        if(f(s[top]) != g(inf[i]) )
           s[++top]=inf[i];        
        else
        top--;
    }
    
    for(;s[top]!='#';top--)
    {
        pf[j++] = s[top];
        pf[j] = '\0';
    } 
    printf("The postfix Expression : %s",pf);
    return 0;
}

