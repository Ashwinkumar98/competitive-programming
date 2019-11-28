//Reversal of stack

#include<stdio.h>
#include<stdlib.h>

int top=-1,arr[1000];

int isempty(int n){
   return (top<=-1) ? -1 : 1;
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
    if(isempty(n)){
        return -1;
    }else{
        return arr[top];
    }
}

void insert_at_bottom(int n,int val){

    if(isempty(n)==-1){
        push(n,val);
    }else{
        int x = pop(n);
        insert_at_bottom(n,val);
        push(n,x);
    }
}

void reverse(int n){

    if(isempty(n)==1){

        int val = pop(n);
        reverse(n);
        insert_at_bottom(n,val);
    }
}

int main(){
    int n = 4;
    push(n,1);
    push(n,2);
    push(n,3);
    push(n,4);

    reverse(n);

     while(isempty(n)==1){
        printf("%d ",pop(n));
    }

    return 0;
}
