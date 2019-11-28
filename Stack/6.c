//Largest Rectangular Area in a Histogram
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int top=-1,arr[1000];

bool isempty(){
   return (top<=-1) ? true : false;
}

int push(int n,int x){
    if(top>n){
        return -1;
    }
    else
    {
        top++;
        arr[top]=x;

    }
}

int pop(int n){

    if(isempty(n)==-1){
        return -1;
    }else{
        int val = arr[top];
        top--;
        return val;
    }
}

int gettop(int n){
    if(isempty(n)==-1){
        return -1;
    }else{
        return arr[top];
    }
}

void findArea(int hist[],int n){

    int i=0,max_area=0;

    while(i<n){

        if(isempty()==true || hist[gettop(n)]<=hist[i]){
            push(n,i++);
        }else{
            int tp=pop(n);

            int cal_area = hist[tp] *(isempty() ? i : i-gettop(n)-1);

            if(max_area<cal_area){
                max_area=cal_area;
            }
        }
    }

    while(isempty()==false){
         int tp=pop(n);

            int cal_area = hist[tp] *(isempty() ? i : i-gettop(n)-1);

            if(max_area<cal_area){
                max_area=cal_area;
            }
    }

    printf("%d",max_area);
}
int main(){
    int hist[] = { 2,1,2,3,1 };
    int n = sizeof(hist)/sizeof(hist[0]);
    findArea(hist,n);
    return 0;
}
