#include<stdio.h>
#define Size 10

struct queue
{
    int que[Size];
    int r,f;
}q;

int qfull()
{
    if(q.r==Size-1)
    return 1;
    else
    return 0;
}

int qempty()
{
    if(q.f>q.r)
    return 1;
    else
    return 0;
}

void push(int x)
{
    q.r++;
    q.que[q.r]=x;
}

int pop()
{
    int x;
    x=q.que[q.f];
    q.f++;
    return x;
}
void display()
{
    int i;
    printf("\nYour Queue is\n");
    for(i=q.f;i<=q.r;i++)
    {
        printf("%d\n",q.que[i]);
    }
}
void main()
{
    q.f=0;
    q.r=-1;
    int ch,x;
    user:
    printf("\n\tEnter Your Choice\n");
    printf("1 : INSERT \n");
    printf("2 : DELETE \n");
    printf("3 : DISPLAY \n");
    printf("0 : Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :
            if(qfull())
            {
                printf("\nQueue is Full.\n");
            }
            else
            {
                printf("Enter Your Element.\n");
                scanf("%d",&x);
                push(x);
            }
            goto user;break;
        case 2 :
            if(qempty())
            {
                printf("\nQueue is Empty.\n");
            }
            else
            {
                x=pop();
                printf("Your Delete Element %d.\n",x);


            }
            goto user;break;
        case 3 :
            if(qempty())
            {
                printf("\nQueue is Empty.\n");
            }
            else
            {
                display();
            }
            goto user;break;
        case 0 : break;
        default : printf("\n Wrong Choice ! Please Try again...\n");
        goto user;
        break;
    }



}







