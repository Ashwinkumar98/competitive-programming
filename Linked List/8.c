#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//Reorder a linked List
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

void Order_List(struct node **left,struct node *right){
    if(!right){
        return;
    }
    Order_List(left,right->next);

    if(!(*left)->next){
        return;
    }

    if((*left)!=right && (*left)->next!=right ){
          struct node *next = (*left)->next;
          (*left)->next=right;
          right->next=next;
          *left=next;
    }else{
        if((*left)!=right){
            *left=(*left)->next;
        }
        (*left)->next=NULL;
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
    struct node *head=NULL;
    head=insert_l(head,1);
    head=insert_l(head,3);
    head=insert_l(head,2);


    print(head);
    struct node *tmp=head;
    Order_List(&tmp,head);
     print(head);
    return 0;
}
