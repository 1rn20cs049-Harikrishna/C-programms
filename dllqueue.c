/* QUEUE implementation using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node *link;
};
typedef struct node nd;

struct queue{
nd *front;
nd *rear;
};
typedef struct queue q;

void  insert_rear (q *);
void delete_front (q *);
void display(q *);

int main ()
{
  q p = {0,0};
  int ch;
  while(1)
  {
    printf("\n1.insert\n2.delete\n3.display\n4.exit\n ");
    printf("enter the choice\n");
    scanf("%d",&ch);
    switch(ch)
          {
             case 1 : insert_rear(&p); break;
             case 2 : delete_front(&p); break;
             case 3 : display(&p); break;
             default : printf("Invalid choice\n");
                       exit(0);
          }
    }
}

void  insert_rear (q *p)
{
  nd *t;
  int n;
  t = (nd *)malloc(sizeof(nd));

  printf("Enter the data to inserted into Queue\n");
  scanf("%d",&n);
  t->data = n;

if( (p->front) == NULL) {
   (p->front) = (p ->rear) = t;
    p->front->link = NULL;
    p->rear->link = NULL;
 }

else {
   p->rear -> link = t;
   p->rear = t;
   p->rear->link = NULL;
 }
}

void delete_front(q *p)
{
   nd *t;

if(p->front == NULL)  {
   printf("\nUnderflow");
   return;
}

else {
   t = p->front ;
   printf("Element to be deleted is %d\n",t->data);
   p->front = p->front->link;
   free(t);
  }
}

void display(q *p )
{
 nd *temp;
 temp = p -> front;

if(p->front == NULL ) {
   printf("Queue is empty\n");
}

else  {
  printf("Queue elements are : \n");

while(temp != NULL )
     {
        printf("\n%d",temp->data);
        temp = temp->link;
     }
   }
}
