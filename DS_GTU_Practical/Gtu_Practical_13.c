#include<stdio.h>


void partition(int a[],int l,int r)
{
    int m;
    if (l < r)
    {
    m=(l+r)/2;
    partition(a,l,m);
    partition(a,m+1,r);

    merge(a,l,m,r);
    }

}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; j = 0; k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void main()
{
    int i,n;
    printf("Enter Your Array Size := ");
    scanf("%d",&n);

    int a[n];

    printf("\nEnter Your Array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    partition(a,0,n-1);


    for(i=0;i<n;i++)
        printf("\n%d",a[i]);

}
