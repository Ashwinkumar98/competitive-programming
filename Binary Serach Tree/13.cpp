#include<iostream>
#include<map>
#include<stdlib.h>
#include<queue>

//top view of binary search tree
using namespace std;

struct node {
    int data;
    int hd;
    struct node *left;
    struct node *right;
};

struct node *newnode(int x){
    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    tmp->data=x;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

void top_view(struct node *root){
    int hd=0;
    queue<struct node *> q;
    map<int,int> mapD;
    root->hd=0;
    q.push(root);

    while(q.size()){
        struct node *tmp = q.front();
        q.pop();
        hd=tmp->hd;
        if(mapD.count(hd)==0){
            mapD[hd]=tmp->data;
        }

        if(tmp->left){
            tmp->left->hd=hd+1;
            q.push(tmp->left);
        }

        if(tmp->right){
            tmp->right->hd=hd-1;
            q.push(tmp->right);
        }
    }

    map<int,int> :: iterator it;

    for(it=mapD.begin();it!=mapD.end();it++){
        cout<<it->second<<" ";
    }
}

int main()
{
    struct node *root;
    root=newnode(10);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    root->right->right=newnode(7);
    root->right->right->right=newnode(0);
    root->right->left=newnode(1);
    top_view(root);
    return 0;
}
