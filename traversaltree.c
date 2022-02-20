#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node {
    char info;
    struct node *llink,*rlink;
};
typedef struct node nd;

nd *create (char *postfix)
{
    nd *temp,*st[20];
    int i,top=-1;
    
    for(i=0;postfix[i]!='\0';i++)
      {
          temp =(nd *)malloc(sizeof(nd));
          temp->info = postfix[i];
          temp->rlink = temp->llink =0;
      
      if(isalnum(postfix[i]))
          st[++top]=temp;

      else {
          temp->rlink =st[top--];
          temp->llink = st[top--];
          st[++top] =temp;
        }
   }
 return st[top--];

}

void preorder(nd *r)
{
    if(r) 
    {
        printf("%c",r->info);
        preorder(r->llink);
        preorder(r->rlink);
    }
}

void inorder(nd *r)
{
    if(r) 
      {
       inorder(r->llink);
        printf("%c",r->info);
        inorder(r->rlink);
    }
}

void postorder(nd *r)
{
    if(r) 
    {
        postorder(r->llink);
        postorder(r->rlink);
        printf("%c",r->info);
    }
}

int main()
{
    nd *root =0;
    char postfix [] = {"632-5*+2^3+"};
    root = create(postfix);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}
