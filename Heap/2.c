#include<stdio.h>
#include<stdlib.h>

int arr[1000],n=-1;
//Min Heap
void swap(int arr[],int a,int b){

    int tmp;

    tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}

int min(int a,int b){
    return (a<b) ? a : b;
}

void InsertMin(int data){
    int i,parent;
    n=n+1;
    arr[n]=data;
    i=n;
    while(i>=1){
        parent=(i/2);
        if(arr[parent]>arr[i])
        {
            swap(arr,i,parent);
            i=parent;
        }        else{
            return;
        }
    }
}

void Deletion(){
    int i;
    arr[0]=arr[n];
    n=n-1;
    i=0;
    while(i<=n){
        int left=(2*i)+1;
        int rigth=(2*i)+2;

        if(arr[i]>min(arr[left],arr[rigth])){

            if(min(arr[left],arr[rigth])==arr[left] ){
                swap(arr,left,i);
                i=left;
            }
            else
            {
                swap(arr,rigth,i);
                i=rigth;
            }
        }
        else{
            return;
        }
    }
}

void printHeap(){
    int i;
    for(i=0;i<=n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    InsertMin(56);
    InsertMin(12);
    InsertMin(78);
    InsertMin(34);
    InsertMin(21);
    InsertMin(10);
    printHeap();
    Deletion();
    printHeap();
    Deletion();
    printHeap();
    return 0;
}
