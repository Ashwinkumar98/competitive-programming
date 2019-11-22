//Find a pair in an array of size 'n', whose sum is X

#include<stdio.h>

int fun(int a[],int n,int sum)
{
    int x,i,hash[10000]={0};

    for(i=0;i<n;i++)
    {
        x=sum-a[i];
        if(hash[x]==1)
        {
            printf("%d + %d = %d",x,a[i],sum);
        }
        else
        {
            hash[a[i]]=1;
        }
    }

}

int main()
{
    int i,n,sum;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&sum);
    fun(a,n,sum);
    return 0;
}
