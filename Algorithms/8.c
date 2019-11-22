#include<stdio.h>
#include<stdlib.h>
void findSum(int a[],int n){
    int i;
    int incl = a[0];
    int excl = 0;
    int exclNew;

    for(i=1;i<n;i++){
        exclNew =(incl>excl) ? incl : excl;
        incl=a[i]+excl;
        excl=exclNew;
    }

    printf("%d",(incl>excl) ? incl :excl);
}
int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSum(arr,n);
    return 0;
}
