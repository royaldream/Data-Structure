#include<stdio.h>
#define Size 10
struct stack
{
    int top;
    int n[Size];
}st;

int isempty()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(st.top==Size-1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    st.top++;
    st.n[st.top]=x;
}

int pop()
{
    int x;
    x=st.n[st.top];
    st.top--;
    return x;
}
int change(struct stack s,int n)
{
    st.n[st.top]=n;
}
void peep()
{

    printf("\n\tTop of Stack is = %d\n",st.n[st.top]);
}

void display()
{
printf("\n   Your Stack Is:\n");
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("\t%d\n",st.n[i]);
    }
}
void main()
{
        int n,a,z,no;

        st.top=-1;

        printf("\tEnter Your Stack Size\n");
        scanf("%d",&n);
        stc:

        printf("\t Enter Your Choice \n");
        printf("1 : Push Element In Stack\n");
        printf("2 : Pop Element In Stack\n");
        printf("3 : Change Element In Stack\n");
        printf("4 : Peep Element In Stack\n");
        printf("5 : Display Element In Stack\n");
        printf("0 : Exit\n");
        scanf("%d",&a);

        switch(a)
        {
            case 1: if(isfull())
                    {
                        printf("\nStack is full\n");
                    }
                    else {
                        printf("\tEnter value\n");
                        scanf("%d",&z);
                        push(z);
                    }
                    goto stc;
                    break;
            case 2:
                if(isempty())
                {
                    printf("\nYour Stack is Empty\n");
                }else{
                    z=pop();
                    printf("\nYour Pop Value is %d\n",z);
                }
                goto stc;
                break;

            case 3 : printf("\nEnter Your Change No\n ");
                    scanf("%d",&no);
                    if(isempty())
                        {
                            printf("\nYour Stack is Empty\n");
                        }else{
                           change(st,no);
                        }
                    goto stc;
                    break;
            case 4: peep();
                    goto stc;
                    break;
            case 5: display();
                    goto stc;
                    break;
            case 0: break;
            default : break;

        }

}

