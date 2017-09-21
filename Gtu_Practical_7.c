#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int info;
	struct stack *next;
};

struct stack* push(int n,struct stack *r)
{
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->info=n;
	newnode->next=r;
	r=newnode;
	return r;
}

struct stack* pop(struct stack *r)
{
	struct stack *p;
	if(r==NULL)
		printf("\nStack is empty\n");
	else
	{
		p=r;
		r=r->next;
		free(p);
	}
	return r;
}

int peep(struct stack *r)
{
	return (r->info);
}

void display(struct stack *r)
{
    printf("\n------------Your Stack-----------\n");
	while(r!=NULL)
	{
		printf("\t%d\n",r->info);
		r=r->next;
	}
	printf("\n");
}

int main()
{
	struct stack *top;
	int c,n;
	top=NULL;
	read:
	printf("Enter your choice\n1 : Push Element\n2 : pop Element\n3 : Display Top of stack\n4 : Display Stack\n5 : Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("Enter Number = ");
			scanf("%d",&n);
			top=push(n,top);
			goto read;
		case 2:
			top=pop(top);
			goto read;
		case 3:
			n=peep(top);
			printf("Top of stack = %d\n",n);
			goto read;
		case 4:
			display(top);
			goto read;
		case 5:
			break;
		default:
			printf("\nWrong choice!\n");
			goto read;
	}
}
