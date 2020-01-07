#include<stdio.h>
#include<stdlib.h>
//find the missing number in an array
void fun(int arr[],int n)
{
    int i;

    for(i=1;i<n;i++){
        if(arr[i]-arr[i-1]!=1){
            printf("%d ",arr[i-1]+1);
            break;
        }
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    fun(arr,n);
    return 0;
}
