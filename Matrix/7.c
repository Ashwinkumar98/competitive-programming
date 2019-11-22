//Print Matrix in spiral from
#include<stdio.h>
#include<stdlib.h>

int fun(int m,int n,int a[m][n]){
    int i,dir=0,t=0,l=0,r=n-1,b=m-1;

    while(t<=b && l<=r){

        if(dir==0 && t<=b && l<=r)
        {
            for(i=l;i<=r;i++)
            {
                printf("%d ",a[t][i]);
            }
            t++;
            dir=1;
        }
        if(dir==1 && t<=b && l<=r)
        {
            for(i=t;i<=b;i++)
            {
                printf("%d ",a[i][r]);
            }
            r--;
            dir=2;
        }
        if(dir==2 && t<=b && l<=r)
        {
            for(i=r;i>=l;i--)
            {
                printf("%d ",a[b][i]);
            }
            b--;
            dir=3;
        }
        if(dir==3 && t<=b && l<=r){
            for(i=b;i>=t;i--)
            {
                printf("%d ",a[i][l]);
            }
            l++;
            dir=0;
        }
    }
}

int main()
{
    int i,j,m,n;
    scanf("%d ",&m);
    scanf("%d",&n);
    int mat[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    fun(m,n,mat);
    return 0;
}
