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
            return root;
        }

void display(struct node * s)
        {
            printf("\n");
            printf("\tYour Link List is .\n");
            while(s!=NULL)
            {
                printf("%d\n",s->info);
                s=s->next;
            }
        }
int length(struct node *s)
        {
            int i=0;
            while(s!=NULL)
            {
                i++;
                s=s->next;
            }
            return i;
        }
struct node *insert(struct node *s,int in)
{
    int value=0,index,i=0,swap;
    struct node *r;
    struct node *pre,*new_node,*temp,*root;
    printf("\nEnter Your Insert Value\n");
    scanf("%d",&value);

            switch(in)
            {
                case 1 :    temp=(struct node *)malloc(sizeof(struct node));
                            temp->info=value;
                            temp->next=s;
                            return temp;
                            break;
                case 2:
                            root=s;
                            temp=(struct node *)malloc(sizeof(struct node));
                            temp->info=value;
                            while(s!=NULL)
                            {
                                pre=s;
                                s=s->next;
                            }
                            pre->next=temp;
                            return root;
                            break;
                case 3 :temp=(struct node *)malloc(sizeof(struct node));
                    temp->info=value;
                    temp->next=s;
                    root=temp;
                    r=temp;
                    while(temp!=NULL)
                    {
                        while(r!=NULL)
                        {
                                if(r->info<temp->info)
                                    {
                                        swap=r->info;
                                        r->info=temp->info;
                                        temp->info=swap;
                                    }
                                r=r->next;

                        }
                        temp=temp->next;
                        r=temp;
                    }
            return root;

            }
    }

void sort(struct node *s)
{
    int temp;
    struct node *r;
    r=s;
    while(s!=NULL)
    {
        while(r!=NULL)
        {
                if(r->info<s->info)
                    {
                        temp=r->info;
                        r->info=s->info;
                        s->info=temp;
                    }
                r=r->next;

        }
        s=s->next;
        r=s;
    }
}
struct node *delete_node(struct node *s,int in)
{
    struct node *pre,*temp,*root;
    int index=0,i=1;

    switch(in)
    {
        case 1:
            root=s;
            s->info=s->next->info;
            s->next=s->next->next;
            return root;
            break;
        case 2:
            root=s;
            printf("Enter Your Position Delete Node\n");
            scanf("%d",&index);
            while(i<index-2 && s!=NULL)
                        {
                            s=s->next;
                            i++;
                        }
                        if(s==NULL && i<index)
                        {
                            printf("\nInvalid Index\n");
                        }
                        else{
                            s->next=s->next->next;
                        }
                        return root;
            break;
        case 3:
            root=s;
            printf("\nEnter Your Position Delete Node\n");
            scanf("%d",&index);
            while(i<=index-1 && s!=NULL)
                        {
                            s=s->next;
                            i++;
                        }
                        if(s==NULL || i<index)
                        {
                            printf("\nInvalid Index\n");
                        }
                        else{
                            s->next=s->next->next;
                        }
                        return root;
            break;


    }

}


void main()
{
    struct node *start,*start1;
    int len,n;

    printf("\nEnter Your Link-List\n");
    start=create();
    // len=length(start);
    // display(start);
    user:
    printf("\t Enter Your Choice");
    printf("\n1 : Insert a node at the front of the linked list.\n");
    printf("2 : Insert a node at the end of the linked list.\n");
    printf("3 : Insert a node such that linked list is in ascending order.\n");
    printf("4 : Delete a first node of the linked list.\n");
    printf("5 : Delete a node before specified position.\n");
    printf("6 : Delete a node after specified position.\n");
    printf("7 : Display\n");
    printf("0 : Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1 :
            start=insert(start,1);
            goto user;
            break;

        case 2 :
            start=insert(start,2);
            goto user;
            break;

        case 3 :
            start=insert(start,3);
            goto user;
            break;
        case 4:
            start=delete_node(start,1);
            printf("\nYour First Node is Deleted\n");
            goto user;
            break;
        case 5:
            start=delete_node(start,2);
            goto user;
            break;
        case 6:
            start=delete_node(start,3);
            goto user;
            break;
        case 7:
            display(start);
            goto user;
            break;

        case 0: break;

        default : printf("\nWrong Choice\n");
                    goto user;
                    break;
    }
}
