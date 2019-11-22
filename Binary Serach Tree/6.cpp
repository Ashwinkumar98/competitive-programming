#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>

//Vertical Order traversal
using namespace std;

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
map < int,vector<int> > mapD;

void verticalOrder(struct node *root,int hd){

    if(root==NULL){
        return;
    }

    mapD[hd].push_back(root->x);

    verticalOrder(root->left,hd-1);

    verticalOrder(root->right,hd+1);
}

int main()
{
    int i;

    root=newnode(10);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    root->right->right=newnode(7);
    root->right->right->right=newnode(0);
    root->right->left=newnode(1);

    verticalOrder(root,0);

    map< int,vector<int> > :: iterator it;

    for(it=mapD.begin();it!=mapD.end();it++){
       for(i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
       }
      cout<<"\n";
    }
    return 0;
}
