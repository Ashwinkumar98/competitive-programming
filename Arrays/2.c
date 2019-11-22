//Algorithm to rotate array of size 'n' by 'd' elements
#include<stdio.h>
#include<stdlib.h>

int GCD(int a,int b)
{
    if(b==0){
        return a;
    }

    return GCD(b,a%b);
}
void Rotate(int a[],int n,int k)
{
    int tmp,i,j,d;

    for(i=0;i<GCD(n,k);i++)
    {
        tmp=a[i];
        j=i;
        while(1)
        {
            d=(j+k)%n;
            if(d==i)
            {
                break;
            }
            a[j]=a[d];
            j=d;
        }
        a[j]=tmp;
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
    scanf("%d",&d);
    Rotate(a,n,d);
    return 0;
}
