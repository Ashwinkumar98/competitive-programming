//Algorithm to check given linked list is palindrome (or) not
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

bool check_palindrome(struct node **left,struct node *rigth){
    if(rigth==NULL){
        return true;
    }
    if(check_palindrome(left,rigth->next)==false){
        return false;
    }
    bool ispal = ((*left)->data==rigth->data);
    *left=(*left)->next;
    return ispal;
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
    head=insert_l(head,2);
    head=insert_l(head,1);
    //print(head);
    check_palindrome(&head,head) ? printf("YES") : printf("NO");
    return 0;
}

