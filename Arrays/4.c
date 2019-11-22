#include<stdio.h>
#include<stdlib.h>

void segrate(int a[],int n)
{
    int i,l=0,r=n-1;

    while(l<=r)
    {
        while(a[l]==1)
        {
            l++;
        }

        while(a[r]==0)
        {
            r--;
        }

        if(l<r)
        {
            int tmp=a[l];
            a[l]=a[r];
            a[r]=tmp;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int i,n,d;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    segrate(a,n);
    return 0;
}

