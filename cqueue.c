#include<stdio.h>
#define Size 5

struct queue
{
    int que[Size];
    int r,f;
}q;

int qfull()
{
    if(q.f==(q.r+1)%Size)
    return 1;
    else
    return 0;
}

int qempty()
{
    if(q.f==-1)
    return 1;
    else
    return 0;
}

void push(int x)
{
    q.r=(q.r+1)%Size;
    q.que[q.r]=x;

}

int pop()
{
    int x;
    x=q.que[q.f];
    q.f=(q.f+1)%Size;
    return x;
}

void display()
{
    int i;
    i=q.f;
    printf("\nYour Queue is\n");
   while(i!=q.r)
   {
       printf("%d\n",q.que[i]);
       i=(i+1)%Size;
   }
   printf("%d\n",q.que[i]);
}
void main()
{
    q.f=-1;
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
                if(q.f==-1)
                {
                    q.f++;
                }
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
            goto user;
            break;
        case 0 : break;
        default : printf("\n Wrong Choice ! Please Try again...\n");
        goto user;
        break;
    }



}
