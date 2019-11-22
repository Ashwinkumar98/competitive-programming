#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string.h>

//PostFix to Exprssion Tree
using namespace std;
struct node{
    char x;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data){

    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    tmp->x=data;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node *createNode(char str[]){
    stack<struct node *> s;
    int i;

    for(i=0;i<strlen(str);i++){

        if(str[i]>='a' && str[i]<='z'){
            s.push(newnode(str[i]));
        }
        else
        {
            struct node *t1=s.top();
            s.pop();
            struct node *t2=s.top();
            s.pop();
            struct node *head=newnode(str[i]);
            head->left=t2;
            head->right=t1;
            s.push(head);
        }
    }
    struct node *root;
    root=s.top();
    s.pop();
    return root;
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->x<<" ";
    inorder(root->right);
}

int main()
{
    char str[] = "ab+ef*g*-";
    struct node *root=createNode(str);
    inorder(root);
    return 0;
}
