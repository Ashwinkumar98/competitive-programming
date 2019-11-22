//Binary Search in a sorted Array

#include<stdio.h>
#include<stdlib.h>

int Search(int a[],int l,int r,int x)
{
    int mid;

    if(l<r)
    {
        mid=(l+r)/2;
    }
    else{
        return -1;
    }

    if(x==a[mid])
    {
        return 1;
    }

    else if(x<a[mid]){
        Search(a,l,mid-1,x);
    }

    else if(x>a[mid]){
        Search(a,mid+1,r,x);
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
    if(Search(a,0,n-1,d)==1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
