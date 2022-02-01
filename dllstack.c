/* stack implementation using linked list */
#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* link;
};
typedef struct node nd ;

nd *push (nd *);
nd * pop (nd *);
void display (nd *);

int main ()
{
  nd *top = NULL;
  int ch;

  while(1)
  {
    printf("\n1.push\n2.pop\n3.display");
    printf("\nEnter the choice\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 : top = push(top); break;
        case 2 : top = pop(top); break;
        case 3 : display(top); break;
        default : printf("Invalid choice\n");
                      exit (0);

    }
  }
}

nd * push ( nd *top )
{
int n;
struct node *t ;
t = (struct node *)malloc(sizeof(struct node));
printf("Enter the data to push into stack\n");
scanf("%d",&n);

if(top == NULL) {
  t->data = n;
  t->link = NULL;
  top = t;
  return top;
 }
else {
  t->data = n;
  t->link = top;
  top = t;
  return top;
   }
}

nd * pop ( nd *top)
{
struct node *temp;
int n;

if(top == NULL) {
    printf("underflow");
}
else  {
   n = top->data;
   printf("the element to be deleted is : %d" ,n);
   temp = top;
   top = top->link;
   free(temp);
   return top;
}
}

void display( nd *top)
{
struct node *temp;
temp = top;

if(temp == NULL) {
   printf("Stack is empty\n");
   return;
}

else {
   printf("stack elements are \n");
while(temp != NULL)
  {
   printf("%d\n",temp->data);
   temp = temp -> link;
  }
 }
}
