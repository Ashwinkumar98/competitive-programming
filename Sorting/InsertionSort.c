#include<stdio.h>
#include<stdlib.h>

void sort(int a[],int n){
    int key,i,j;

    for(j=0;j<n;j++){
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key){
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}

void print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    print(a,n);
    sort(a,n);
    print(a,n);
    return 0;
}
