#include<iostream>
#include<stdlib.h>
#include<queue>
//Level Order Traversal of BST

using namespace std;

struct node{
    int x;
    struct node *left;
    struct node *right;
};


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
void inorder(struct node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->x<<" ";
    inorder(root->right);
}

void LevelOrder(struct node *root){

    queue<struct node *> q;

    if(root==NULL){
        return;
    }

    q.push(root);

    while(q.empty()==false){

        struct node *tmp = q.front();
        q.pop();

        cout<<tmp->x<<" ";

        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right!=NULL){
            q.push(tmp->right);
        }
    }
}

int main()
{
    struct node *root =NULL;
    root=insert(root,6);
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,8);
    root=insert(root,1);
    inorder(root);
    cout<<"\n";
    LevelOrder(root);
    return 0;
}
