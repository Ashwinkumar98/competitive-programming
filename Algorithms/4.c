#include<stdio.h>
#include<stdlib.h>
//Longest Increasing sub sequence
int max(int a, int b)
{
    return (a > b)? a : b;
}

void fun(int n,int a[]){

    int j,i,LIS[n];

    for(i=0;i<n;i++){
        LIS[i]=1;
    }

    for(i=1;i<n;i++){
        j=0;
        while(j!=i){
            if(a[j]<a[i]){

                LIS[i]=max(LIS[j]+1,LIS[i]);
            }
            j++;
        }
    }

    int max=0;
    for(i=0;i<n;i++){
       if(max<LIS[i]){
            max=LIS[i];

       }
    }

    printf("\n%d",max);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    fun(n,a);
    return 0;
}
