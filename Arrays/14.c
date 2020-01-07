//Find subarray with given sum

#include<stdio.h>
#include<stdlib.h>

void fun(int arr[],int n,int sum){
    int i,start=0,curr_sum=arr[0];
    for(i=1;i<n;i++){
        while(curr_sum>sum && start<i-1){
            curr_sum=curr_sum-arr[start];
            start++;
        }
        if(curr_sum==sum){
            printf("%d %d",start,i-1);
        }

        if(i<n){
            curr_sum=curr_sum+arr[i];
        }
    }
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 23;
    fun(arr, n, sum);
    return 0;
}
