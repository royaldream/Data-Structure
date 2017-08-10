#include<stdio.h>
#define Size 100
struct stack
{
    int top;
    char n[Size];
}st;
int isempty_revers()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
void push_revers(char x)
{
    st.top++;
    st.n[st.top]=x;
}

char pop_revers()
{
    char x;
    x=st.n[st.top];
    st.top--;
    return x;
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
int isempty()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
void main()
{
        int i=0,n,num,p,j;
        char str[Size],x,s[Size];

        c:

        st.top=-1;
        printf("\n\tEnter Your Choice\n");
        printf("1 : Reverse a line of text \n");
        printf("2 : Convert a number in base 10 to base 2\n");
        printf("3 : Check the string for the PALINDROM\n");
        printf("0 : Exit\n");
        scanf("%d",&n);

        switch(n)
        {
            case 1:
             printf("\tEnter Your String\n");
                scanf("%s",str);


                    for(i=0;str[i]!='\0';i++)
                    {
                        push_revers(str[i]);
                    }
                i=0;
                    while(!isempty_revers())
                    {
                        x=pop_revers();
                        printf("%c",x);
                    }
                goto c;
                break;

            case 2:
                printf("\nEnter Your Decimal Number\n");
                scanf("%d",&num);
                    while(num>0)
                    {
                        p=num%2;
                        push(p);
                        num=num/2;
                    }
                    while(!isempty())
                    {
                        p=pop();
                        printf("%d",p);
                    }
                goto c;
                break;

            case 3:
                    printf("\tEnter Your String\n");
                    scanf("%s",str);


                    for(i=0;str[i]!='\0';i++)
                    {
                        n=i;
                    }
                    n=n+1;
                    if((n%2)!=0)
                    {
                        if(str[(n/2)]=='x')
                        {
                            j=0;
                            for(i=0;str[i]!='\0';i++)
                            {
                                if(str[i]=='x')
                                {
                                    j++;
                                }
                            }
                            if(j>1)
                            {
                                printf("\nYour String Is Not Valid\n");
                            }
                            j=0;
                                printf("\n");

                                for(i=0;str[i]!='\0';i++)
                                {
                                    push_revers(str[i]);
                                    //printf("%c",st.n[i]);

                                }
                                n=n-1;
                                for(i=0;i<n;i++)
                                {

                                        if(st.n[i]==st.n[n-i])
                                        {
                                           continue;
                                        }
                                        else
                                        {
                                            break;
                                        }
                                }
                                if(i==n)
                                {
                                    printf("\n Your String is PALINDROM .\n");
                                }
                                else
                                {
                                    printf("\nYour String is Not PALINDROM .\n");
                                }
                        }
                        else
                        {
                            printf("\nString is not Valid\n");
                        }

                    }
                    else{
                        printf("\nString is not Valid\n");
                        goto c;
                        }
                goto c;
                break;
        }
}
