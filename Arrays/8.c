//Find the Number Occurring Odd Number of Times

#include<stdio.h>
#include<stdlib.h>
void find(int a[],int n)
{
    int res=0,i;
    for(i=0;i<n;i++){
        res=res^a[i];
    }
    printf("%d",res);
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
    find(a,n);
    return 0;
}
