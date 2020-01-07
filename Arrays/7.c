//Algorithm to find the largest sub array with equal number of 0's and 1's

#include<stdio.h>
#include<stdlib.h>

void fun(int arr[],int n){
    int i,j,sum,maxsize=-1,start;

    for(i=0;i<n;i++){
        sum = (arr[i]==0) ? -1 : 1;
        for(j=i+1;j<n;j++){
            sum +=((arr[j]==0) ? -1 : 1);
            if(sum==0 && maxsize<j-i+1){
                maxsize=j-i+1;
                start=i;
            }
        }
    }

    if(maxsize==-1){
        printf("No sub array\n");
    }else{
        printf("%d %d",start,start+maxsize-1);
    }
}

int main(){
    int arr[] = {1, 1, 1, 1, 1, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    fun(arr, size);
    return 0;
}
