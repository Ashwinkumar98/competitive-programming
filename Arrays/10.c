#include<stdio.h>
#include<stdlib.h>
//find Frequency of elements in an array
void frequency(int arr[],int n,int freq[]){
    int i,j,cnt;
    for(i=0;i<n;i++){
        cnt=1;
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                cnt++;
                freq[j]=0;
            }
        }
         if(freq[i]!=0){
            freq[i]=cnt;
        }
    }

    for(i=0;i<n;i++){
        if(freq[i]!=0){
            printf("Frequency of %d is %d\n",arr[i],freq[i]);
        }
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n],freq[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        freq[i]=-1;
    }
    frequency(arr,n,freq);
    return 0;
}
