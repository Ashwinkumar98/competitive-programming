#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap(int a[],int t1,int t2){
    int tmp;
    tmp=a[t1];
    a[t1]=a[t2];
    a[t2]=tmp;
}

int partition(int a[],int p,int r){
    int i,j,pivot;
    pivot=a[r];
    i=p-1;j=p;
    while(j<r)
    {
        if(a[j]<=pivot){
            i=i+1;
            swap(a,i,j);
        }
        j++;
    }
    swap(a,i+1,r);
    return i+1;
}

void QuickSort(int a[],int p,int r)
{
    if(p<r){
        int q=partition(a,p,r);
        QuickSort(a,p,q-1);
        QuickSort(a,q+1,r);
    }
}

void print(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    print(a,n);
    QuickSort(a,0,n-1);
    print(a,n);
    return 0;
}

