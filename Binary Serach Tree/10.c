#include<stdio.h>
#include<stdlib.h>
//Lowest common ancestor
struct node {
    int x;
    struct node *left;
    struct node *right;
};

struct node *newnode(int x){
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    tmp->x=x;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

struct node *LCA(struct node *root,struct node *n1 ,struct node *n2){

    if(root==NULL){
        return NULL;
    }

    if(root==n1 || root==n2){
        return root;
    }

    struct node *left = LCA(root->left,n1,n2);
    struct node *rigth = LCA(root->right,n1,n2);

    if(left!=NULL && rigth!=NULL){
        return root;
    }
    if(left==NULL && rigth==NULL){
        return NULL;
    }

    return left!=NULL ?  left : rigth;

};

int main(){
    struct node *root;
    root=newnode(3);
    root->left=newnode(6);
    root->left->left=newnode(2);
    root->left->right=newnode(11);
    root->left->right->right=newnode(5);
    root->left->right->left=newnode(9);
    root->right=newnode(8);
    root->right->right=newnode(13);
    root->right->right->left=newnode(7);
    struct node *n1 = root->left->left;
    struct node *n2 = root->left->right->right;
    printf("%d",LCA(root,n1,n2)->x);
    return 0;
}
