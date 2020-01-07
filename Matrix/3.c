#include<stdio.h>
#include<stdlib.h>
//print matrix in diagonal format
int isvalid(int r,int c,int row,int col){
    if(r>=0 && c>=0 && r<row && c<col){
        return 1;
    }else{
        return 0;
    }
}

void fun(int m,int n,int mat[m][n]){
    int k,i,j;

    for(k=0;k<m;k++){
        printf("%d ",mat[k][0]);
        i=k-1;
        j=1;

        while(isvalid(i,j,m,n)){
            printf("%d ",mat[i][j]);
            i--;
            j++;
        }
        printf("\n");
    }


    for(k=1;k<n;k++){
        printf("%d ",mat[m-1][k]);
        i=m-2;
        j=k+1;

        while(isvalid(i,j,m,n)){
            printf("%d ",mat[i][j]);
            i--;
            j++;
        }
        printf("\n");
    }

}

int main()
{
    int m,n,i,j;
    scanf("%d",&m);
    scanf("%d",&n);
    int mat[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    fun(m,n,mat);
    return 0;
}
