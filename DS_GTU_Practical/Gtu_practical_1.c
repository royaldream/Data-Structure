#include<stdio.h>

void call_value(int a,int b)
{
a=100,b=200;

}
int call_reference(int*a,int*b)
{
*a=100,*b=200;
}

int main()
{
int a=10,b=20;
printf("\n\tCall By Value \n");
call_value(a,b);
printf("a=%d\nb=%d\n",a,b);

printf("\n\tCall By Reference \n");
call_reference(&a,&b);
printf("a=%d\nb=%d",a,b);


}
