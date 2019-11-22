#include<stdio.h>
#include<stdlib.h>

struct node{
    int x;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;

struct node *newnode(int val){
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node ));
    tmp->x=val;
    tmp->left=NULL;
    tmp->right=NULL;

    return tmp;
}



void printLeaf(struct node *root){

    if(root==NULL){
        return;
    }
    printLeaf(root->left);

    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->x);
    }

    printLeaf(root->right);
}

int main()
{

    root=newnode(10);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    root->right->right=newnode(7);
    root->right->right->right=newnode(0);
    root->right->left=newnode(1);

    printLeaf(root);

    return 0;
}
