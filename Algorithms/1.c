#include<stdio.h>
#include<stdlib.h>

//Knapsack Problem

void fun(int n,int V[],int W[],int We){

    int i,j,tmp,pr=0;
    double p1,p2;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++){

                p1=(V[i]/W[j]);
                p2=(V[j]/W[j]);

                if(p1>p2){
                    tmp=V[i];
                    V[i]=V[j];
                    V[j]=tmp;

                    tmp=W[i];
                    W[i]=W[j];
                    W[j]=tmp;
                }
        }
    }

    for(i=0;i<n;i++){

        if(We<W[i])
        {
            pr+=((We*V[i])/W[i]);
            We=0;

        }
        else{
        We=We-W[i];
        pr+=V[i];

       }
    }

    printf("Profit : %d",pr);
}

int main()
{
    int i,n,Weight;
    scanf("%d",&n);
    int W[n],V[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&V[i]);
        scanf("%d",&W[i]);
    }
    scanf("%d",&Weight);

    fun(n,V,W,Weight);
    return 0;
}
