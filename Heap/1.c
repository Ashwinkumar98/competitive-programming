#include<stdio.h>
#include<stdlib.h>

int arr[10000],n=-1;
//Max Heap construction
void swap(int arr[],int a,int b){
    int tmp;
    tmp=arr[a];
    arr[a]=arr[b];
    arr[b]=tmp;
}

void InsertValue(int val)
{
    int i,parent;
    n=n+1;
    arr[n]=val;
    i=n;
    while(i>=1){
        parent=i/2;
        if(arr[parent]<arr[i]){
            swap(arr,parent,i);
            i=parent;
        }
        else
        {
            break;
        }
    }
}

int max(int a,int b){

    return (a>b) ? a : b;
}



void Deletion(){
    int i,left,right;
    arr[0]=arr[n];
    n=n-1;
    i=0;
    while(i<=n){
        left=(2*i)+1;
        right=(2*i)+2;

        if(arr[i]<max(arr[left],arr[right])){

            if(max(arr[left],arr[right])==arr[left]){
                swap(arr,i,left);
                i=left;
            }
            else{
                swap(arr,i,right);
                i=right;
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
int main(){
    InsertValue(30);
    InsertValue(5);
    InsertValue(100);
    InsertValue(200);
    InsertValue(500);
    InsertValue(40);
    InsertValue(33);
    InsertValue(105);
    printHeap();
    Deletion();
    printHeap();
     Deletion();
    printHeap();
    return 0;
}
