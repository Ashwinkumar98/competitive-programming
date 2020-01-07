#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Reverse alternate K nodes in a Singly Linked List
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

struct node * reverse_alt(struct node *head,int k){

    struct node *curr,*prev,*next;
    int i=0;
    curr=head;
    prev=NULL;
    while(curr!=NULL && i<k){
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
       i++;
    }

    if(head!=NULL){
        head->next=curr;
    }
    i=0;
    while(curr!=NULL && i<k-1){
        curr=curr->next;
        i++;
    }
    if(curr!=NULL){
        curr->next=reverse_alt(curr->next,k);
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
    struct node *head=NULL;
    head=insert_l(head,1);
    head=insert_l(head,2);
    head=insert_l(head,3);
    head=insert_l(head,4);
    head=insert_l(head,5);
    head=insert_l(head,6);
    print(head);
    head=reverse_alt(head,2);
    print(head);
    return 0;
}
