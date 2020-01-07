#include<stdio.h>
#include<stdlib.h>
//Lonked List Basics
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

struct node *insert_f(struct node *head,int x){
    struct node *tmp=head;
    if(head==NULL){
        return newnode(x);
    }else{
        struct node *node=newnode(x);
        node->next=head;
        head=node;
        return head;
    }
}

struct node *insert_a(struct node *head,int pos,int x){

    struct node *tmp=head;
    while(tmp!=NULL && tmp->data!=pos){
        tmp=tmp->next;
    }
    struct node *newN = newnode(x);
    newN->next=tmp->next;
    tmp->next=newN;
    return head;
}

struct node *delete_a(struct node *head,int x){
    struct node *tmp=head;
    while(tmp!=NULL && tmp->next!=NULL && tmp->next->data!=x){
        tmp=tmp->next;
    }
    struct node *del=tmp->next;
    tmp->next=tmp->next->next;
    free(del);
    return head;
}

struct node *delete_f(struct node *head)
{
    if(head==NULL){
        return NULL;
    }else{
        struct node *first=head;
        head=first->next;
        free(first);
        return head;
    }
}

struct node *delete_l(struct node *head)
{
    if(head==NULL){
        return NULL;
    }else{
        struct node *tmp=head;
        while(tmp->next->next!=NULL){
            tmp=tmp->next;
        }
        struct node *del = tmp->next;
        tmp->next=NULL;
        free(del);
        return head;
    }
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
    head=insert_f(head,0);
    head=insert_a(head,0,-100);
    print(head);
    head=delete_a(head,-100);
    print(head);
    head=delete_f(head);
    print(head);
    head=delete_l(head);
    print(head);
    return 0;
}
