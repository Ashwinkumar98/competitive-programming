#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>

//Diagonal Order traversal
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

void DigonalTraversal(struct node *root,int d){

    if(root==NULL){
        return;
    }
    mapD[d].push_back(root->x);
    DigonalTraversal(root->left,d+1);
    DigonalTraversal(root->right,d);
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

    DigonalTraversal(root,0);

    map< int, vector<int> > :: iterator it;

    for(it=mapD.begin();it!=mapD.end();it++){

        for(i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
