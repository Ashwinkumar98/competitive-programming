#include<stdio.h>
#include<stdlib.h>
//knapsack problem dp
int max(int a,int b){
    return (a>b) ? a : b;
}

int fun(int n,int w[],int p[],int m){

    int i,j,mat[n+1][m+1];

    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){

            if(i==0 || j==0){
                mat[i][j]=0;
            }else if (w[i-1]<=j){
                mat[i][j]=max(mat[i-1][j],mat[i-1][j-w[i-1]]+p[i-1]);
            }
            else{
                 mat[i][j]=mat[i-1][j];
            }

        }
    }
    return mat[n][m];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d",fun(n,wt,val,W));
    return 0;
}
