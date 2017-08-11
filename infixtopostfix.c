#include<stdio.h>
#define Size 100
struct stack
{
    int top;
    char s[Size];
}st,p;

void push(char x)
{
    st.top++;
    st.s[st.top] = x;
}

char pop()
{
    char x;
    x=st.s[st.top];
    st.top--;
    return x;

}
void push_post(char x)
{
    p.top++;
    p.s[p.top] = x;

}

char pop_post()
{
    char x;
    x=p.s[p.top];
    p.top--;
    return x;

}

int priority(char x)
{
    if(x == '$')
    return -1;
    if(x == '(')
    return 0;
    if(x == '+' || x == '-')
    return 1;
    if(x == '*' || x == '/')
    return 2;
    if(x == '^')
    return 3;
}
int isempty()
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}
 main()
{
    char exp[Size],x,t;
    int i=0;
    st.top=0;
    p.top=-1;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    int len=strlen(exp);


   for(i=0;exp[i]!='\0';i++)
        {
            push(exp[len-i-1]);

        }
    p.s[p.top++] = '$';
    while(!isempty())
        {
            x=pop();



            if(isalnum(x))
            {
                printf("%c",x);
            }
            else if(x=='(')
            {
                push_post(x);

            }
            else if(x == ')')
            {
                while((t = pop_post()) != '(')
                {
                    printf("%c", t);
                }
            }
            else
            {

                while(priority(p.s[p.top]) >= priority(x))
                {
                    printf("%c",pop_post());
                }
                push_post(x);


            }
    }
    while(p.top != -1)
            {
                printf("%c",pop_post());
            }
/*
while(exp!='\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
            printf("%c", x);
        }
        else
        {
            while(priority(st.s[st.top]) >= priority(exp[i]))
            printf("%c",pop());
            push(exp[i]);
        }
        i++;
    }
     while(st.top!= -1)
        {
        printf("%c",pop());
        */

}
