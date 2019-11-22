#include<stdio.h>
#include<stdlib.h>

//Job Sequencing Problem
void sort(int n,int P[],int D[]){

    int i,j,tmp;

    for(i=0;i<n;i++){

        for(j=i+1;j<n;j++){

            if(P[i]<P[j]){
                tmp=P[i];
                P[i]=P[j];
                P[j]=tmp;

                tmp=D[i];
                D[i]=D[j];
                D[j]=tmp;
            }
        }
    }
}
void fun(int n,int P[],int D[]){

    int j,i,slot[n],pr=0;

    for(i=0;i<n;i++){
        slot[i]=0;
    }

    sort(n,P,D);

    for(i=0;i<n;i++){

        for(j=D[i]-1;j>=0;j--){

            if(slot[j]==0){
                slot[j]=1;
                pr+=P[i];

                break;
            }
        }

    }

    printf("%d",pr);
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int P[n],D[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&P[i]);
        scanf("%d",&D[i]);
    }

    fun(n,P,D);
    return 0;
}
