//Find duplicates in O(n) time and O(1) extra space

#include<stdio.h>
#include<stdlib.h>
void fun(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        if(arr[abs(arr[i])]>=0){
            arr[abs(arr[i])] = - arr[abs(arr[i])];
        }
        else{
            printf("%d\t",abs(arr[i]));
        }
    }
}
int main(){
    int arr[] = {1, 2, 3, 26, 3, 6, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    fun(arr, arr_size);
    return 0;
}
