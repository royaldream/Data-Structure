#include<stdio.h>

typedef struct Tree
{
    int data;
    struct tree *left,*right;
}Tree;

Tree * inserttree(int data,Tree *p)
{
    if(!p)
    {

        p=(Tree *)malloc(sizeof(Tree));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
    }
    else{
        if(data<p->data)
            p->left=inserttree(data,p->left);
        if(data>p->data)
            p->right=inserttree(data,p->right);

    }return p;
}

void rec_preorder(Tree * tree)
{

    if(tree !=NULL)
    {
        printf("%d\t",tree->data);
        rec_preorder(tree->left);
        rec_preorder(tree->right);
    }
}
void rec_inorder(Tree * tree)
{

    if(tree !=NULL)
    {   rec_inorder(tree->left);
        printf("%d\t",tree->data);
        rec_inorder(tree->right);
    }
}
void rec_postorder(Tree * tree)
{

    if(tree !=NULL)
    {
        rec_postorder(tree->left);
        rec_postorder(tree->right);
        printf("%d\t",tree->data);

    }
}
void main()
{
    int x;
    Tree * root=NULL;
    while(1)
    {
        printf("\nEnter num -999 to stop\n");
        scanf("%d",&x);
        if(x==-999)
        {
            break;
        }
        root=inserttree(x,root);
    }
     printf("\n\n---Recursive Preorder---\n");
     rec_preorder(root);
     printf("\n\n---Recursive inorder---\n");
     rec_inorder(root);
     printf("\n\n---Recursive Postorder---\n");
     rec_postorder(root);

}
