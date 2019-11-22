#include<stdio.h>
#include<stdlib.h>
//Construct BST from preorder Traversal
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

struct node *ConvertNode(int pre[],int *preIndex,int low,int high,int size){

    if(*preIndex >=size || low>high){
        return NULL;
    }

    struct node *root = newnode(pre[*preIndex]);
    *preIndex = *preIndex+1;

    if(low==high)
        return root;
    int i;
    for(i=low;i<=high;i++){
        if(pre[i]>root->x)
            break;
    }
    root->left= ConvertNode(pre,preIndex, *preIndex , i-1,size);

    root->right = ConvertNode(pre,preIndex, i,high,size);

    return root;

}


void inorder(struct node *root){

    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d->",root->x);
    inorder(root->right);
}

int main(){

    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
    int preindex=0;
    struct node *root = ConvertNode(pre,&preindex,0,size-1,size);
    inorder(root);
    return 0;
}
