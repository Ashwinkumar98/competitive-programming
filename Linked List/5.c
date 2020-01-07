//Reverse a Linked List
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *newnode(int x){
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}

struct node *insert_l(struct node *head,int x){
    struct node *tmp=head;
    if(tmp==NULL)
    {
        return newnode(x);
    }else{
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=newnode(x);
        return head;
    }
}

//Using Recursion
struct node *head =NULL;
void reverse(struct  node *p){
   if(p->next==NULL){
        head=p;
        return;
    }
    else{
        reverse(p->next);
        struct node *q=p->next;
        q->next=p;
        p->next=NULL;
    }
}

//Using Loop
struct node * reverse_l(struct node *head){
    struct node *curr=head;
    struct node *prev=NULL;
    struct node *next;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    return prev;
}

void print(struct node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){

    head=insert_l(head,1);
    head=insert_l(head,2);
    head=insert_l(head,3);
    head=insert_l(head,4);
    head=insert_l(head,5);
    head=insert_l(head,6);
    head=insert_l(head,7);
    print(head);
    head=reverse_l(head);
    print(head);
    return 0;
}
