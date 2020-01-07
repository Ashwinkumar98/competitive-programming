#include<stdio.h>
#include<stdlib.h>

void swap(int a[],int t1,int t2){
    int tmp;
    tmp=a[t1];
    a[t1]=a[t2];
    a[t2]=tmp;
}

void Selection_Sort(int a[],int n){
    int i,j,min_index;

    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        swap(a,i,min_index);
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
    Selection_Sort(a,n);
    print(a,n);
    return 0;
}
