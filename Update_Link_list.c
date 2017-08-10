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
            while(s!=NULL)
            {
                printf("%d\n",s->info);
                s=s->next;
            }
        }

int maximum(struct node * s)
        {
            int n=s->info;
            while(s!=NULL)
            {
                if(n<s->info)
                {
                    n=s->info;
                }
                s=s->next;
            }
            return n;

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

int search(struct node * s,int len)
        {
            int no,index=0;
        printf("%d",len);
            printf("Enter Your Search element\n");
            scanf("%d",&no);
            while(s!=NULL)
            {
                index++;
                if(no == s->info)
                {
                    return index;
                }

                s=s->next;
            }
            if( index == len )
                {
                    return -1;
                }
        }

void replace(struct node *s)
{
        int no,new_no;
            printf("Enter Your Search element\n");
            scanf("%d",&no);
            while(s!=NULL)
            {
                if(no == s->info)
                {
                    printf("\nEnter Your New Value\n");
                    scanf("%d",&new_no);
                    s->info=new_no;
                }
                s=s->next;
            }
}


void sort(struct node *s)
{
    int temp;
    struct node *r;
    r=s;
        printf("%d",s);

    printf("%d",r);
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




void main()
{
    struct node *start;
    int max,n,len,search_in;

    c:
        printf("\n      Enter Your Choice\n");
        printf("\t1 : Create \n");
        printf("\t2 : Display \n");
        printf("\t3 : Maximum \n");
        printf("\t4 : Length \n");
        printf("\t5 : Search \n");
        printf("\t6 : Replace \n");
        printf("\t7 : Sort \n");
        printf("\t8 : Reverse \n");
        printf("\t9 : Merge \n");
        printf("\t0 : Exit \n");
        scanf("%d",&n);
    switch(n)
    {
            case 1 :
                start=create();
                len=length(start);
                goto c;
                break;

            case 2 :
                display(start);
                goto c;
                break;

            case 3 :
                max=maximum(start);
                printf("\nMaximum Value is %d\n",max);
                goto c;
                break;

            case 4 :
                len=length(start);
                printf("\nLink List Length is %d\n",len);
                goto c;
                break;

            case 5 :
                search_in=search(start,len);
                printf("\nYour Search Element Position Is %d \n",search_in);
                goto c;
                break;

            case 6 :
                replace(start);
                goto c;
                break;

            case 7 :
                sort(start);
                goto c;
                break;

            case 8 :
                goto c;
                break;

            case 9 :
                goto c;
                break;

            case 0 :break;
            default : break;
    }
}
