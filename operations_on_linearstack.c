#include<stdio.h>
#include<stdlib.h>
#define Max 3
void insert(int *,int *);
void display(int *,int ,int);
void delete(int*,int*,int);

int main()
{    
    int q[Max];
    int r=-1,f=0;
    int ch;
    while(1)
    {  
       printf("enter the choice\n");
       scanf("%d",&ch);
       printf("1.insert\n2.delete\n3.display\n4.exit\n");
       switch(ch) {
         case 1: insert(q,&r); break;
         case 2: delete(q,&f,r); break;
         case 3: display(q,r,f); break;
         default:exit(0);
       }
    }
 }

void insert(int q[],int *r)
{   
    int ele;
    if((*r)==(Max)-1)  {
          printf("the queue is overflow\n");
          return;
      }
     (*r)++;
     printf("enter the queue element to be inserted \n");
     scanf("%d",&ele);
     q[*r]=ele;
  }
void delete(int q[],int *f,int r)
{
  if((*f)>r)  {
        printf("the stack is empty\n");
        return;
    }
    printf("the element deleting from the queue is %d\n",q[*f]);
    (*f)++;
}
void display(int q[],int r,int f)
{   
    int i;
    if(f>r) {
         printf("the queue is empty\n");
         return;
     }
     for(i=f;i<=r;i++)
       printf("%d ",q[i]);
       printf("\n");
}  
