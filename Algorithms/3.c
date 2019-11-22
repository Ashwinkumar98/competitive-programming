#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//Longest Common sub sequence
int max(int a, int b)
{
    return (a > b)? a : b;
}

int LCS(char a[],char b[],int m,int n){

    int i,j,mat[m+1][n+1];

    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){

                if(i==0 || j==0){
                    mat[i][j]=0;
                }
                else if(a[i-1]==b[j-1]){
                    mat[i][j]=mat[i-1][j-1]+1;
                }
                else{
                    mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
                }
        }
    }

    return mat[m][n];

}

int main(){
    char a[1000],b[1000];
    scanf("%s",a);
    scanf("%s",b);
    printf("%d",LCS(a,b,strlen(a),strlen(b)));
    return 0;
}
