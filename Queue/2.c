//circular queue
#include<stdio.h>
#include<stdlib.h>

int queue[10000],n,front=-1,rear=-1,n;

void enqueue(int val){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[front]=val;
        printf("%d is enqueued\n",val);
    }
    else if((rear+1)%n == front){
        printf("Queue is full\n");
    }
    else {
        rear = (rear+1)%n;
        queue[rear]=val;
        printf("%d is enqueued\n",val);
    }
}

void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        printf("%d is dequeued\n",queue[front]);
        front=rear=-1;
    }else{
       printf("%d is dequeued\n",queue[front]);
       front=(front+1)%n;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else{
        int i=front;

        while(i!=rear){
            printf("%d\t",queue[i]);
            i=(i+1)%n;
        }
        printf("%d\t",queue[rear]);
    }
    printf("\n");
}
int main(){
    int i,val;
    printf("Enter the queue size\n");
    scanf("%d",&n);
    while(1){
        printf("1.Enqueue 2.Dequeue 3.Display 4.exit\n");
        scanf("%d",&i);
        switch(i){
            case 1 : printf("Enter the value : ");
                     scanf("%d",&val);
                     enqueue(val);
                     break;
            case 2 : dequeue();
                     break;
            case 3 : display();
                     break;
            case 4 : exit(0);
        }
    }
    return 0;
}
