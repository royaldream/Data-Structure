#include<stdio.h>

void quicksort(int a[],int low,int high)
{
	int i;
	if(low<high)
	{
		i=quick_partition(a,low,high);
		quicksort(a,low,i-1);
		quicksort(a,i+1,high);
	}
}
int quick_partition(int a[],int low,int high)
{
	int i,p,q,t;
	p=low+1;
	q=high;
	i=a[low];
	while(p<=q)
	{
		while(a[p]<=i)
			p++;
		while(a[q]>i)
			q--;
		if(q>p)
			{
				t=a[p];
				a[p]=a[q];
				a[q]=t;
			}
       }
	t=a[low];
	a[low]=a[q];
	a[q]=t;
return q;
}
void main()
{

	int i,n;
	printf("Enter Your Arry Size\n");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter Your %d No:",i);
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
       	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
}
