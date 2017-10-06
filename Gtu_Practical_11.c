#include<stdio.h>
typedef struct TREE
{
    int data;
    struct TREE *left,*right;
}TREE;

TREE *InsertTree(int data,TREE *p)
{
    if(!p)
    {
        p=(TREE *)malloc(sizeof(TREE));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
    }
    else{

        if(data < p->data)
        {
            p->left = InsertTree(data,p->left);
        }else
        if(data > p->data)
        {
            p->right = InsertTree(data,p->right);
        }
        return p;
    }
}

void main()
{
    int x;
    TREE *root=NULL;
        while(1)
        {
            printf("Enter Your Data (-999 To Stop)\n");
            scanf("%d",&x);
            if(x==-999)
            {
                break;
            }
            root=InsertTree(x,root);
        }
}

