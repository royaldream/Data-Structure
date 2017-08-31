#include<stdio.h>

struct node
{
    int info;
    struct node *next;
}st;

struct node *create()
        {
            struct node *root,*newnode,*prev;
            int n;
            printf("Enter Your Number (-999 To Stop)\n");
            scanf("%d",&n);
            root=NULL;
            while(n!=-999)
            {
                newnode=(struct node *)malloc(sizeof(struct node));

                newnode->info=n;
                newnode->next=NULL;
                if(root==NULL)
                {
                   root=newnode;
                }
                else
                {
                    prev->next=newnode;

                }
                prev=newnode;
                printf("Enter Your Number\n");
                scanf("%d",&n);
            }

            if(root!=NULL)
            {
                newnode->next=root;
            }

            return root;
}
void display(struct node * s)
        {
            struct node *p;
            p=s;
            printf("Your Link List is ...\n");

            do
            {
                printf("%d\n",s->info);
                s=s->next;
            }while(s!=p);

            printf("%d\n",s->info);
}

struct node *insert(struct node *s,int i)
{
    struct node *root,*temp,*newnode;
    int val,index=1,p=1;
    root=s;
    if(i==0)
    {
        if(s==NULL)
        {
            printf("\nEnter Your Values.\n");
            scanf("%d",&val);
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->info=val;
            newnode->next=newnode;
            root=newnode;

        }
        else{
            temp=s;
            printf("\nEnter Your Values.\n");
            scanf("%d",&val);
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->info=val;
            newnode->next=NULL;
                while(s->next!=temp)
                {
                    s=s->next;
                }
            s->next=newnode;
            newnode->next=temp;
        }

    }else if(i==1)
    {
        if(s==NULL)
        {
            printf("\nEnter Your Values.\n");
            scanf("%d",&val);
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->info=val;
            newnode->next=newnode;
            root=newnode;

        }else
        {

        printf("\nEnter Your Values.\n");
        scanf("%d",&val);
        printf("Enter Your Position\n");
        scanf("%d",&index);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->info=val;
        newnode->next=NULL;
        if(index==1 || s==NULL)
        {
            temp=s;
            newnode->next=s;
            root=newnode;
            while(s->next!=temp)
            {
                s=s->next;
            }
            s->next=newnode;
        }
        else{
            temp=s;
            while(p<index-1 && temp->next!=s)
                {
                    temp=temp->next;
                    p++;
                }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        }
    }
    return root;
}

struct node * deletee(struct node *s,int i)
{
    struct node *temp,*root,*last;
    int index=1,p=1;
    root=s;
    if(i==0)
    {
        temp=s->next;
        root=temp;
        last=s;
        while(s->next!=last)
        {
            s=s->next;
        }
        s->next=temp;

    }
    else if(i==1)
    {
        printf("Enter Your Position\n");
        scanf("%d",&index);
        temp=s;
        while(p<index && temp->next!=s)
            {
                temp=temp->next;
                p++;
            }
            if(temp->next==s && i<index)
            {
                printf("\nNot Valid Position.\n");
            }
            else{
            last=temp->next;
            temp->next=temp->next->next;
            free(last);

           }

    }


    return root;

}




void main()
{
    struct node *start;
    int i;

    start=create();


user:
    printf("\tEnter Your Choice\n");
    printf("1 : Insert a node at the end of the linked list.\n");
    printf("2 : Insert a node before specified position.\n");
    printf("3 : Delete a first node of the linked list.\n");
    printf("4 : Delete a node after specified position.\n");
    printf("5 : Display\n");
    printf("0 : Exit\n");
    scanf("%d",&i);

    switch(i)
    {
        case 1:
            start=insert(start,0);
            goto user;
            break;
        case 2:
            start=insert(start,1);
            goto user;
            break;
        case 3:
            start=deletee(start,0);
            goto user;
            break;
        case 4:
            start=deletee(start,1);
            goto user;
            break;
        case 5:
            display(start);
            goto user;
            break;
        case 0:
            break;
        default:
            printf("\nWrong Choice.\n");
            goto user;
            break;

    }

}
