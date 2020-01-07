#include<stdio.h>
#include<stdlib.h>
//Find Middle Node in the Linked List
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

void find_middle(struct node *head){
    struct node *p=head;
    struct node *q=head;

    while(p!=NULL && q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
    }

    printf("%d",p->data);
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
    head=insert_l(head,1);
    head=insert_l(head,2);
    head=insert_l(head,3);
    head=insert_l(head,4);
    head=insert_l(head,5);
    head=insert_l(head,6);
    head=insert_l(head,7);
    print(head);
    find_middle(head);
    return 0;
}

