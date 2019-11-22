#include<stdio.h>
#include<stdlib.h>

//stack PUSH,POP,TOP
int top=-1,arr[1000];

int push(int x,int n){

    if(top<=n){
        top++;
        arr[top]=x;
        printf("%d is pushed at %d\n",x,top);
    }
    else{
        printf("Overflow\n");
    }
}

int pop(int n){
    if(top<=-1){
        printf("UnderFlow\n");
    }else{
        int val = arr[top];
        printf("%d is poped from stack\n",val);
        top--;
    }
}

void findtop(int n){
    if(top<=-1){
        printf("stack is empty\n");
    }else{
        printf("Top : %d\n",arr[top]);
    }
}

int main()
{
    int i,val,n=5;
    do{
        printf("1.push 2.pop 3.top\n");
        scanf("%d",&i);


        switch(i){
        case 1 :scanf("%d",&val);
                push(val,n);
                break;
        case 2: pop(n);
                break;
        case 3: findtop(n);
                break;
        }

    }while(1);
    return 0;
}
