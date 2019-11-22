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

struct node * insert(struct node *root,int x){
    if(root==NULL){
        return newnode(x);
    }
    else if(x<root->x){
        root->left=insert(root->left,x);
    }
    else{
        root->right=insert(root->right,x);
    }
    return root;
}

struct node * successor(struct node *tmp){

    while(tmp->left!=NULL){
        tmp=tmp->left;
    }

    return tmp;
}


void deleteNode(int x){


    struct node *tmp=root,*parent;

    while(tmp!=NULL && tmp->x!=x){
        parent=tmp;
        if(x<tmp->x){
            tmp=tmp->left;
        }
        else{
            tmp=tmp->right;
        }
    }

    if(tmp->left==NULL && tmp->right==NULL)
    {
        if(tmp!=root){

            if(parent->left=tmp)
            {
                parent->left=NULL;
            }
            else{
                parent->right=NULL;
            }
            free(tmp);
        }
        else{
            root=NULL;
        }
    }
    else if(tmp->left!=NULL && tmp->right!=NULL){

        struct node *suc = successor(tmp->right);

        int val = suc->x;

        deleteNode(suc->x);

        root->x=val;

    }
    else
    {
        struct node *child = (tmp->left) ? tmp->left : tmp->right;

        if(root==tmp){
            root=child;
        }
        else{
            if(parent->left==tmp){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
        free(tmp);
    }

}

void inorder(struct node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d->",root->x);
    inorder(root->right);
}

int main()
{

    root=insert(root,6);
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,1);
    inorder(root);
    deleteNode(1);
    printf("\n");
    inorder(root);
    return 0;
}
