#include<stdio.h>
#include<stdlib.h>
//declaration
typedef struct node
{
    int info;
    struct node *next;
}queue;
//insert
queue* ins(queue ** f,queue *r,int n)
{
    queue *newnode;
    newnode=(queue*)malloc(sizeof(queue));
    newnode->info=n;
    newnode->next=NULL;
    if(r==NULL)
        *f=r=newnode;
    else
    {
        r->next=newnode;
        r=r->next;
    }
    return r;
}
//delete
queue* del(queue *f,queue ** r)
{
    if(f==*r)
        f=*r=NULL;
    else
        f=f->next;
    return f;
}
//display
void display(queue *f)
{
    while(f!=NULL)
    {
        printf("\n%d",f->info);
        f=f->next;
    }
}
//main
void main()
{
    queue *f,*r;
    int c,n;
    f=r=NULL;
    read:
    printf("\n\nEnter Your choice\n1 : Insert\n2 : Delete\n3 : Display\n4 : Exit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            printf("Enter number = ");
            scanf("%d",&n);
            r=ins(&f,r,n);
            goto read;
        case 2:
            if(f==NULL && r==NULL)
                printf("\nQueue is empty\n");
            else
                f=del(f,&r);
            goto read;
        case 3:
            if(f==NULL && r==NULL)
                printf("\nQueue is empty\n");
            else
                display(f);
            goto read;
        case 4:
            break;
        default:
            printf("Wrong choice");
            goto read;
    }
}
