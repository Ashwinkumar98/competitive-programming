// Insert 0 after consecutive (K times) of 1 is found.

#include<stdio.h>
#include<stdlib.h>
void fun(int arr[],int n,int k){
    int i=0,j,cnt;

    while(i<n){
        cnt=0;
        while(arr[i]==1 && cnt<k ){
            printf("%d ",arr[i]);
            cnt++;
            i++;
        }
        if(cnt==k){
            printf("0 ");
        }
        while(arr[i]==0 && i<n){
            printf("%d ",arr[i]);
            i++;
        }
    }
}
int main(){
   int n,i,k;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    fun(arr,n,k);
    return 0;
}
