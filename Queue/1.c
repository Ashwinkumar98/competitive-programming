#include<stdio.h>
#include<stdlib.h>
//Queue Data structures
int queue[10000],front=0,rear=0;

void printQueue(){
    int i;

    for(i=0;i<rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void enqueue(int val,int n){
    if(rear==n){
        printf("Overflow\n");
    }
    else{
        queue[rear]=val;
        rear++;
        printQueue();
    }
}

void dequeue(int n){
    if(front==rear){
        printf("Underflow\n");
    }else{
        queue[front]=0;
        front++;
        printQueue();
    }
}


int main()
{
    enqueue(1,4);
    enqueue(2,4);
    enqueue(3,4);
    enqueue(4,4);
    enqueue(5,4);
    dequeue(4);
    dequeue(4);
    dequeue(4);
    dequeue(4);
    dequeue(4);
    return 0;
}
