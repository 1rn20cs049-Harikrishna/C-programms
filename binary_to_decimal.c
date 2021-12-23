#include<stdio.h>
int convert(int);

int main()
{
    int dec,bin;
    printf("enter the binary number\n");
    scanf("%d",&bin);
    dec=convert(bin);
    printf(" the binary number is %d\n corresponding decimal value is %d",bin,dec);
    return 0;
}

int convert(int bin)
{   
    if(bin==0)
      return 0;
     else return(bin % 10 + 2 * convert(bin/10));
}
