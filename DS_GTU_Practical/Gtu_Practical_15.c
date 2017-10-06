#include<stdio.h>
int binary_search(int a[],int n,int key)
{
	int l,h,m;
	l=0;h=n-1;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==key)
			return (m+1);
		else if(a[m]>key)
			h=m-1;
		else
			l=m+1;
	}
	return -1;
}
void main()
{
	int n,i,j,key;
	printf("Enter size of Array = ");
	scanf("%d",&n);
	int a[n];
	printf("Enter Array in a Ascending Order\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("enter number you want to search = ");
	scanf("%d",&key);
	n=binary_search(a,n,key);
	if(n!=-1)
		printf("Searched Number is at Position = %d",n);
	else
		printf("\nNumber Not Found.\n");
}
