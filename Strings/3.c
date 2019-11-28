#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
void findWildCardPatterns(char str[],char pat[],int m,int n){
    int i,j;
    bool table[m+1][n+1];



    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            table[i][j]=false;
        }
    }
    table[0][0]=true;

    for(i=1;i<=m;i++){
        if(pat[i-1]=='*'){
            table[0][i]=table[0][i-1];
        }
    }

    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){

            if(pat[j-1]=='*'){
                table[i][j] = (table[i-1][j] || table[i][j-1]);
            }
            else if(pat[j-1]=='?' || str[i-1]==pat[j-1]){
                table[i][j]= table[i-1][j-1];
            }
            else{
                table[i][j]=false;
            }
        }
    }

    if(table[n][m]==true){
        printf("True");
    }
    else{
        printf("false");
    }
}

int main(){
    char str[1000];
    char pat[1000];
    gets(str);
    gets(pat);
    findWildCardPatterns(str,pat,strlen(pat),strlen(str));
    return 0;
}
