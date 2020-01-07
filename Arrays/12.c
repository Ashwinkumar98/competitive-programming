//Union of two arrays
#include<stdio.h>
#include<stdlib.h>
int fun(int a[],int b[],int m,int n){

    int i=0,j=0;

    while(i<m && j<n){
        if(a[i]==b[j]){
            printf("%d ",a[i]);
            i++;j++;
        }else if(a[i]<b[j]){
            printf("%d ",a[i]);
            i++;
        }else {
            printf("%d ",b[j]);
            j++;
        }
    }

    while(i<m){
        printf("%d ",a[i]);
        i++;
    }

    while(j<n){
        printf("%d",b[j]);
        j++;
    }
}
int main(){
    int m,n,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[m];
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    fun(a,b,n,m);
    return 0;
}
