#include<stdio.h>
#include<stdlib.h>
//Boundary Traversal of Binary Tree
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

void printLeft(struct node *root){

    if(root==NULL){
        return;
    }

    if(root->left){
        printf("%d ",root->x);
        printLeft(root->left);
    }
    else if(root->right)
    {
        printf("%d ",root->x);
        printLeft(root->right);
    }

}

void printRight(struct node * root){

    if(root==NULL){
        return;
    }

    if(root->right){
        printRight(root->right);
        printf("%d ",root->x);
    }
    else if(root->left){
        printRight(root->left);
        printf("%d ",root->x);
    }

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

    printLeft(root->left);
    printLeaf(root);
    printRight(root);

    return 0;
}
