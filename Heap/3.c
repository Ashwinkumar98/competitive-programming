#include<stdio.h>
#include<stdlib.h>
//Heap Sort
void swap(int arr[],int a,int b){

    int tmp;

    tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}


void Heapify(int arr[],int n,int i){
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;

    if(left<n && arr[left]>arr[largest]){
        largest=left;

    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr,i,largest);
        Heapify(arr,n,largest);
    }
}

void PrintHeap(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int i, arr[]={7,8,10,12,67,33};
    for(i=2;i>=0;i--){
        Heapify(arr,6,i);

    }
    PrintHeap(arr,6);
    for(i=5;i>=0;i--){
        swap(arr,0,i);
        Heapify(arr,i,0);
    }
    PrintHeap(arr,6);
    return 0;
}
