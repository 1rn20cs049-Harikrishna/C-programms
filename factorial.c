#include<stdio.h>
int fact(int n) {
    if(n==0)
    return 1;
    return(n*fact(n-1));
}

int main()
{  
    int a;
    scanf("%d",&a);
    printf("%d\n",fact(a));
    return 0;
}
