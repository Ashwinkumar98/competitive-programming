#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROW 9
#define COL 9


bool checkRow(int r,int mat[][COL]){
    int i;
    int cnt[10]={0};
    for(i=0;i<COL;i++){
        if(mat[r][i]!=0 && cnt[mat[r][i]]==0){
            cnt[mat[r][i]]++;
        }
        else{
            return false;
        }

    }
    return true;
}

bool checkCol(int c,int mat[][COL]){
    int i;
    int cnt[10]={0};
    for(i=0;i<ROW;i++){
        if(mat[i][c]!=0 &&cnt[mat[i][c]]==0){
            cnt[mat[i][c]]++;
        }
        else{
            return false;
        }

    }
    return true;
}

bool checkBox(int r,int c,int mat[][COL])
{
    int i,j,m,n,cnt[10]={0};
    m=r-r%3;
    n=c-c%3;

    for(i=m;i<m+3;i++){
        for(j=n;j<n+3;j++){
            if(mat[i][j]!=0 && cnt[mat[i][j]]==0){
                cnt[mat[i][j]]++;
            }
            else{
                return false;
            }

        }
    }
    return true;
}

bool isvalid(int r,int c,int mat[][COL]){
    return checkRow(r,mat) && checkCol(c,mat) && checkBox(r,c,mat);
}

bool checkSuduko(int mat[][COL]){
    int i,j;

    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(isvalid(i,j,mat)==false){
                return false;
            }
        }
    }

    return true;
}


int main(){
    int i,j,mat[ROW][COL];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    if(checkSuduko(mat)){
        printf("Valid");
    }else{
        printf("Not valid");
    }
    return 0;
}
