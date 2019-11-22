//Maximum Sum Increasing Subsequence

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
    return (a>b) ? a : b;
}

int fun(int a[],int n){

    int i,j,table[n];

    for(i=0;i<n;i++){
        table[i]=a[i];
    }

    for(i=0;i<n;i++){
        j=0;
        while(j!=i){
            if(a[j]<a[i]){
                table[i]=max(table[j]+a[i],table[i]);
            }
            j++;
        }
    }
    int max=table[0];

    for(i=1;i<n;i++){
        if(max<table[i]){
            max=table[i];
        }
    }
    printf("%d",max);
}

int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    fun(arr,n);
    return 0;
}
