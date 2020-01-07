#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
//Find first node of loop in a linked list
struct node *newnode(int x){
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}

void findLoop(struct node *head){
    struct node *p=head;
    struct node *q=head;
    p=p->next;
    q=q->next->next;
    while(p!=NULL && q!=NULL && q->next!=NULL){
            p=p->next;
            q=q->next->next;
            if(p==q){
                printf("Loop Found\n");
                break;
            }
    }

    p=head;
    while(p!=q){
        printf("%d %d\n",p->data,q->data);
        p=p->next;
        q=q->next;
    }

    printf("%d ",q->data);
}

void print(struct node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct node *head =NULL;
    head=newnode(1);
    head->next=newnode(2);
    head->next->next=newnode(3);
    head->next->next->next=newnode(4);
    head->next->next->next->next=newnode(5);
    head->next->next->next->next->next=newnode(6);
    head->next->next->next->next->next->next=head->next->next;
    findLoop(head);
    return 0;
}

