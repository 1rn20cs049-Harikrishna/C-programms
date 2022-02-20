#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term
{
	int cf, ex, ey, ez;
	struct term *link;
};
typedef struct term tm;

void insert_front(tm *,FILE*);
void display(tm *);
void eval(tm *,FILE*);
void polyadd(tm *, tm *, tm *);

int main()
{
	int n,i;
	tm  p1 = { .link = &p1 };
	tm  p2 = { .link = &p2 };
	tm  p3 = { .link = &p3 };
	
	//soln for a
	FILE* fp;
	   fp=fopen("data.txt","r");
	printf("\nEnter the value of n");
	fscanf(fp,"%d",&n);
	for(i=0; i<n; i++)
		insert_front(&p1,fp);
	eval(&p1,fp);
	display(&p1);
	
	//p2 creation
	
	printf("\nEnter the value of n\n");
	fscanf(fp,"%d",&n);
	
	for(i=0; i<n; i++ )
		insert_front(&p2,fp);
	
	polyadd(&p1, &p2, &p3);
	display(&p3);
	 
}

void insert_front(tm *h,FILE* fp)
{
	tm *t = (tm *)malloc(sizeof(tm));
	printf("Enter cf,ex,ey,ez\n");
	fscanf(fp,"%d%d%d%d",&(t->cf),&(t->ex),&(t->ey),&(t->ez));
	t->link = h->link;
	h->link = t;
}

void eval(tm *h,FILE* fp)
{
	int x,y,z;
	double sum = 0;
	printf("Enter the value for x, y and z\n");
	fscanf(fp,"%d%d%d",&x,&y,&z);
	
	tm *t;
	for(t=h->link; t != h; t=t->link)
		sum = sum + (t->cf) * pow(x,(t->ex)) * pow(y,(t->ey)) * pow(z,(t->ez));
	
	printf("sum = %lf\n",sum);
}

void display(tm *h)
{
	if(h->link == h)
	{
		printf("Empty\n");
		return;
	}
	tm *t;
	for(t=h->link; t!=h;t=t->link)
		printf("(%d  x^%d  y^%d  z^%d)  +  ",t->cf,t->ex,t->ey,t->ez);
}
	
void polyadd(tm *h1, tm *h2, tm *h3)
{
	tm *t, *t1, *n;
	for(t=h1->link; t!=h1; t=t->link)
	{
		for(t1=h2->link; t1 != h2; t1 = t1->link)
		{
			if( t1->cf != -999 && ((t->ex == t1->ex) && (t->ey == t1->ey) && (t->ez == t1->ez) ) )
			{
				n = (tm*)malloc(sizeof(tm));
				(*n) = (*t1);
				n->cf += t->cf;
				t1->cf = -999;
				n->link = h3->link; 
				h3->link = n;
				break;
			}
		}
		if( t1== h2 )
		{
			n = (tm*)malloc(sizeof(tm));
			(*n) = (*t);
			n->link = h3->link;
			h3->link = n;
		}
	}
	for( t1 = h2->link; t1 != h2; t1 = t1->link)
		if( t1->cf != -999 )
		{
			n = (tm*)malloc(sizeof(tm));
			(*n) = (*t1);
			n->link = h3->link;
			h3->link = n;
		}
}
/** data.txt 
   5
6 2 2 1 
-4 0 1 5 
3 3 1 1 
2 1 5 1 
-2 1 1 3 
1 1 1 

3 
6 2 2 1 
2 1 5 1 
-2 1 1 3 
*/
