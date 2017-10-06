#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *back,*next;
}node;


node * create(node ** last)
{
    node * newnode,* root,* prev;
    int info;
    root=NULL;
    printf("Enter Your No (-999 To Stop).\n");
    scanf("%d",&info);
    while(info!=-999)
    {
        newnode=(node *)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->info=info;
        if(root==NULL)
        {
            root=newnode;
            newnode->back=NULL;
        }
        else
        {
            newnode->back=prev;
            prev->next=newnode;

        }
        prev=newnode;
        printf("Enter Your No (-999 To Stop).\n");
        scanf("%d",&info);

    }

    if(root!=NULL)
    {
        *last=newnode;
    }
    return root;

}

void display(node * s,node * last)
{
    printf("\n------Your Link List------\n");
    while(s!=NULL)
        {
            printf("%d\n",s->info);
            s=s->next;
        }

    printf("\n\------Your Reverse Link List------\n");
    while(last!=NULL)
        {
            printf("%d\n",last->info);
            last=last->back;
        }
}

node * insert_front(node * start,node ** last)
{
    node *newnode,*root;
    int info;


        printf("\nEnter Your Insert Info\n");
        scanf("%d",&info);
        newnode=(node *)malloc(sizeof(node));
        newnode->info=info;

        if(start!=NULL)
        {
        newnode->next=start;
        newnode->back=NULL;
        start->back=newnode;
        }
        else{
        newnode->back=NULL;
        newnode->next=NULL;
        * last=newnode;}



        root=newnode;
return root;
}

node * insert_end(node * last,node **start)
{
    node *newnode,*root;
    int info;
        printf("\nEnter Your Insert Info\n");
        scanf("%d",&info);
        newnode=(node *)malloc(sizeof(node));
        newnode->info=info;
        if(last!=NULL)
        {
        newnode->back=last;
        newnode->next=NULL;
        last->next=newnode;
        }
        else{
        newnode->back=NULL;
        newnode->next=NULL;
        *start=newnode;}
        return newnode;
}

node * delete_end(node * last)
{
    node *temp;

    printf("\n\tYour Last Node Delete.\n");
    temp=last->back;
    last->back->next=NULL;
    return temp;
}

node * delete_position(node * start)
{
    node * root,*prev,*temp;
    int i=0,p;
    printf("\nEnter Your Position.\n");
    scanf("%d",&p);

        root=start;
        temp=start;
    if(p==1)
    {
        printf("\nNot Valid Position.\n");
    }
    else
    {
        while(i<p-3 && temp->next!=start)
            {
                temp=temp->next;

                i++;
            }
                prev=temp->next;
                temp->next->next->back=temp;
                temp->next=temp->next->next;
                free(prev);

}
    return root;
}

void main()
{
    node *start,*last;
    int no;

user:
    printf("\n\tEnter Your Choice\n");
    printf("1 : Create Doubly Link List.\n");
    printf("2 : Insert a node at the front of the linked list.\n");
    printf("3 : Insert a node at the end of the linked list.\n");
    printf("4 : Delete a last node of the linked list.\n");
    printf("5 : Delete a node before specified position.\n");
    printf("6 : Display Link List.\n");
    printf("0 : Exit\n");
    scanf("%d",&no);

    switch(no)
    {
        case 1 :
        start=create(&last);
        goto user;

        case 2 :
        start=insert_front(start,&last);
        goto user;

        case 3 :
        last=insert_end(last,&start);
        goto user;

        case 4 :
        last=delete_end(last);
        goto user;

        case 5 :
        start=delete_position(start);
        goto user;

        case 6 :
        display(start,last);
        goto user;

        case 0 :
        break;
    }
}
