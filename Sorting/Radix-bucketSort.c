#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int getMax(int a[],int n){
    int max=a[0],i;
    for(i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}

void sort(int arr[],int n,int place){
    int i,j,output[n],cnt[10]={0};
    for(i=0;i<n;i++){
        cnt[(arr[i]/place)%10]++;
    }

    for(i=1;i<n;i++){
        cnt[i]=cnt[i]+cnt[i-1];
    }

    for(i=n-1;i>=0;i--){
        output[cnt[(arr[i]/place)%10]-1]=arr[i];
        cnt[(arr[i]/place)%10]--;
    }

    for(i=0;i<n;i++){
        printf("%d ",output[i]);
    }
    printf("\n");

    for(i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int a[],int n){
    int i,place,max=getMax(a,n);

    for(place=1; max/place > 0 ;place*=10){
        sort(a,n,place);
    }


}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    radixSort(a,n);
    return 0;
}

