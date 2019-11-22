#include<iostream>
#include<stdlib.h>
#include<stack>
//Level Order Traversal of BST in Spiral form

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

    stack<struct node *> s1;
    stack<struct node *> s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty()){

        while(!s1.empty()){
            struct node *tmp = s1.top();
            s1.pop();
            cout<<tmp->x<<" ";
            if(tmp->right){
                s2.push(tmp->right);
            }
            if(tmp->left){
                s2.push(tmp->left);
            }
        }

        while(!s2.empty()){
            struct node *tmp = s2.top();
            s2.pop();
            cout<<tmp->x<<" ";
            if(tmp->left){
                s1.push(tmp->left);
            }
            if(tmp->right){
                s1.push(tmp->right);
            }
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
