#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//Count No of Island
bool isvaild(int r,int c,int mat[5][5],bool visited[5][5]){
    return (r>=0 && c>=0 && r<5 && c<5 && (mat[r][c] && !visited[r][c]));
}

void DFS(int row,int col,int mat[5][5],bool visited[5][5]){

    int i;
    static int rowK[]={-1,-1,-1,0,0,1,1,1};
    static int colK[]={-1,0,1,-1,1,-1,0,1};
    visited[row][col]=true;
    for(i=0;i<8;i++){
        if(isvaild(row+rowK[i],col+colK[i],mat,visited)){
            DFS(row+rowK[i],col+colK[i],mat,visited);
        }
    }
}

void CountIsland(int r,int c,int mat[r][c]){

    int i,j,count=0;
    bool visited[r][c];

    memset(visited,0,sizeof(visited));

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(mat[i][j]==1 && !visited[i][j]){
                DFS(i,j,mat,visited);
                count++;
            }
        }
    }

    printf("%d",count);

}

int main(){

    int M[5][5] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
    CountIsland(5,5,M);
    return 0;
}
