    //Trapping Rain Water
#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    return (a>b) ? a : b;
}
int min(int a,int b){
    return (a<b) ? a : b;
}
void fun(int arr[],int n)
{
    int i,water=0,left[n],right[n];
    left[0]=arr[0];
    for(i=1;i<n;i++){
        left[i]=max(left[i-1],arr[i]);
    }
    right[n-1]=arr[n-1];
    for(i=n-2;i>=0;i--){
        right[i]=max(right[i+1],arr[i]);
    }
    for(i=0;i<n;i++){
        water+=min(left[i],right[i])-arr[i];
    }
    printf("%d",water);
}
int main(){
    int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    fun(arr,n);
    return 0;
}
