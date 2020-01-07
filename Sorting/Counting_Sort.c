#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void counting_sort(int arr[],int n){
    int i,j;
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    int output[n];
    for(i=0;i<n;i++){
        cnt[arr[i]]++;
    }

    for(i=1;i<n;i++){
        cnt[i]=cnt[i]+cnt[i-1];
    }

    for(i=0;i<n;i++){
        output[cnt[arr[i]]-1]=arr[i];
        cnt[arr[i]]--;
    }

    for(i=0;i<n;i++){
        printf("%d ",output[i]);
    }
}

int main(){
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    counting_sort(a,n);
    return 0;
}
