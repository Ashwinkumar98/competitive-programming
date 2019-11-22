//Algorithm to reverse an array
#include<stdio.h>
#include<stdlib.h>

void rev(int a[],int st,int ed)
{
    while(st<=ed)
    {
        int tmp=a[st];
        a[st]=a[ed];
        a[ed]=tmp;
        st++;
        ed--;
    }
}

void reverse(int a[],int n,int d)
{
    int i;
    rev(a,0,d-1);
    rev(a,d,n-1);
    rev(a,0,n-1);

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
    scanf("%d",&d);
    reverse(a,n,d);
    return 0;
}
