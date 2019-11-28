#include<stdio.h>
#include<stdlib.h>
//get min in O(1)

int top=-1,arr[1000],min;

int isempty(int n){
   return (top<=-1) ? -1 : 1;
}

int push(int x,int n){
    if(top>n){
        return -1;
    }
    else{
        if(top==-1){
            top++;
            arr[top]=x;
            min=x;
        }
        else if(arr[top]<min){
            top++;
            arr[top]=(2*x-min);
            min=x;
        }
        else{
            top++;
            arr[top]=x;
        }
    }
}

int pop(int n){

    if(top<=-1){
        return -1;
    }
    else{
        if(arr[top]<min){
            int val = arr[top];
            top--;
            min=(2*min-val);
        }
    }

}

int gettop(int n){
    if(isempty(n)){
        return -1;
    }else{
        return arr[top];
    }
}

int main(){
    push(3,6);
    push(5,6);
    push(2,6);
    push(1,6);
    push(0,6);
    printf("%d",min);
    return 0;
}
