#include<stdio.h>
#include<stdlib.h>
//Find Nth node from the end of the linked list
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

void print(struct node *head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("\n");
}

void find(struct node *head,int pos){
    if(head==NULL){
        return;
    }
    find(head->next,pos);
    static int i=0;

    if((++i)==pos){
        printf("%d ",head->data);
    }
}


int main(){
    struct node *head =NULL;
    head=insert_l(head,1);
    head=insert_l(head,2);
    head=insert_l(head,3);
    head=insert_l(head,4);
    head=insert_l(head,5);
    print(head);
    find(head,3);
    return 0;
}
