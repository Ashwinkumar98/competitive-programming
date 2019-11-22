#include<iostream>
#include<map>
#include<queue>
#include<stdlib.h>
#include<vector>

using namespace std;

//Left and Right side view of binary search Tree

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

void LevelOrder(struct node * root){
    map <int ,vector <int> > mapD;
    queue<struct node *> q;
    int i,level=0,nodeCount;

    if(root==NULL){
        return;
    }

    q.push(root);

    while(!q.empty()){



            nodeCount=q.size();

            while(nodeCount>0){

                struct node *tmp = q.front();
                q.pop();
                mapD[level].push_back(tmp->x);
                if(tmp->left){
                    q.push(tmp->left);
                }

                if(tmp->right){
                    q.push(tmp->right);
                }

                nodeCount--;
            }
            level++;
    }

    map< int, vector<int> > :: iterator it;

    cout<<"Left view of Binary search Tree\n";

    for(it=mapD.begin();it!=mapD.end();it++){

        for(i=0;i<it->second.size();i++){
            if(i==0){
                 cout<<it->second[i]<<" ";
            }
        }
        cout<<"\n";
    }

    cout<<"Right view of Binary search Tree\n";

    for(it=mapD.begin();it!=mapD.end();it++){

        for(i=0;i<it->second.size();i++){
            if(i==(it->second.size()-1)){
                 cout<<it->second[i]<<" ";
            }
        }
        cout<<"\n";
    }

}



int main(){
    int i;
    struct node *root=NULL;
    root=newnode(10);
    root->left=newnode(2);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right=newnode(3);
    root->right->right=newnode(7);
    root->right->right->right=newnode(0);
    root->right->left=newnode(1);
    LevelOrder(root);
    return 0;
}
