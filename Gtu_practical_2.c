#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,c,*p,sum=0,i;
	printf("enter your choice\nType 1 to use malloc function\nType 2 to use calloc function\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			printf("Enter Size  = ");
			scanf("%d",&n);
			p=(int*)malloc(n*sizeof(int));
			for(i=0;i<n;i++)
			{
				printf("Enter number = ");
				scanf("%d",(p+i));
				sum=sum+*(p+i);
			}
			printf("\nsum of values = %d",sum);
			free(p);
			break;
		case 2:
			printf("Enter Size = ");
			scanf("%d",&n);
			p=(int*)calloc(n,sizeof(int));
			for(i=0;i<n;i++)
			{
				printf("Enter number = ");
				scanf("%d",(p+i));
				sum=sum+*(p+i);
			}
			printf("\nsum of values = %d",sum);
			free(p);
			break;
		default:
			printf("wrong choice");
			break;
	}
}
