#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
//find fibonaci number in an array
bool perfectSquare(int num){
    int n=sqrt(num);
    return (n*n == num);
}

void fun(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
            if(perfectSquare(5*arr[i]*arr[i]+4) || perfectSquare(5*arr[i]*arr[i]-4)){
                printf("%d\t",arr[i]);
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
    fun(arr,n);
    return 0;
}
