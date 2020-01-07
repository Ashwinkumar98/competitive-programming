// Given an array, find the minimum of all the greater numbers for each element in the array.

#include<stdio.h>
#include<stdlib.h>

void fun(int n,int arr[]){

    int i,j,mindiff,ele;

    for(i=0;i<n;i++){
        mindiff=-1;
        ele=0;
        for(j=0;j<n;j++){
            if(mindiff==-1 && arr[i]<arr[j]){
                mindiff=arr[j]-arr[i];
                ele=arr[j];
            }
            else{
                if(arr[i]<arr[j] && mindiff>arr[j]-arr[i]){
                mindiff=arr[j]-arr[i];
                ele=arr[j];}
            }
        }

        if(mindiff==0){
            printf("_ ");
        }
        else{
            printf("%d ",ele);
        }
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    fun(n,arr);
    return 0;
}
