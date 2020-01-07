//Equilibrium index of an array
#include<stdio.h>
#include<stdlib.h>
int fun(int arr[],int n,int sum){
    int i,left=0;

    for(i=0;i<n;i++){

        sum=sum-arr[i];

         if(sum==left){
            return i;
        }

        left=left+arr[i];


    }

    return -1;
}
int main(){
    int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
     if(fun(arr,arr_size,0)==-1)
     {
         printf("No Equilibrium Index");
     }
     else{
        printf("Equilibrium Index : %d",fun(arr,arr_size,0));
     }
    return 0;
}
