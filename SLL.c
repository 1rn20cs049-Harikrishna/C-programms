#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*link;
};
typedef struct node nd;


int main()
{
    nd *first=NULL;
    nd *second=NULL;
    nd *third=NULL;
    
    int a,b,c;
    
    printf("Enter the three elements\n");
    scanf("%d%d%d",&a,&b,&c);
    first=(nd *)malloc(sizeof(first));
    second=(nd *)malloc(sizeof(second));
    third=(nd *)malloc(sizeof(third));
    
    first->data=a;
    first->link=second;
    
    second->data=b;
    second->link=third;
    
    third->data=c;
    third->link=NULL;
    
    printf("Three elements are : \n");
    printf("%d\n%d\n%d", first->data,second->data,third->data);
   
    return 0;  
    
}
