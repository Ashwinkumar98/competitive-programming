#include<stdio.h>
#include<stdlib.h>
//Coin Change problem
int fun(int n,int a[],int N){

    int table[n+1][N+1],i,j;

    for(i=0;i<=n;i++){
        for(j=0;j<=N;j++){

            table[i][j]=0;
        }
    }

    for(i=0;i<=n;i++){
        table[i][0]=1;
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=N;j++){
            if(a[i-1]>j){
                table[i][j]=table[i-1][j];
            }
            else
            {
                table[i][j]=table[i-1][j]+table[i][j-a[i-1]];
            }
        }
    }

    return table[n][N];
}

int main(){
    int N,n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&N);
    printf("%d",fun(n,a,N));
    return 0;
}
