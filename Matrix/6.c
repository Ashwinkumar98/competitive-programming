#include<stdio.h>
#include<stdlib.h>
//sum of upper and lower triangular matrix
void fun(int m,int n,int mat[m][n]){

    int i=0,j,sum=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                sum+=mat[i][j];
            }
        }
    }
    printf("Lower Triangular Sum %d\n",sum);
    sum=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<=j)
            {
                sum+=mat[i][j];
            }
        }
    }

     printf("Upper Triangular Sum %d\n",sum);
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
