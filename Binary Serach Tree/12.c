//Expression Tree Evaluations
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char x[100];
    struct node *left;
    struct node *right;
};

struct node *newnode(char data[]){

    struct node *tmp;
    tmp=(struct node *) malloc(sizeof(struct node));
    strcpy(tmp->x,data);
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int convertInt(char str[]){
    int i,base=1,val=0;

    for(i=strlen(str)-1;i>=0;i--){
        val=val+((str[i]-'0')*base);
        base*=10;
    }

    return val;
}

int TreeEvaluation(struct node *root){

    if(root==NULL){
        return 0;
    }

    if(root->left==NULL && root->right==NULL){
        return convertInt(root->x);
    }

    int lval=TreeEvaluation(root->left);
    int rval=TreeEvaluation(root->right);

    if(strcmp(root->x,"+")==0){
        return lval+rval;
    }
    else if(strcmp(root->x,"-")==0){
        return lval-rval;
    }
    else if(strcmp(root->x,"*")==0){
        return lval*rval;
    }
    else {
        return lval/rval;
    }
}

int main()
{
    struct node *root;
    root = newnode("+");
    root->left = newnode("*");
    root->left->left = newnode("5");
    root->left->right = newnode("4");
    root->right = newnode("-");
    root->right->left = newnode("100");
    root->right->right = newnode("/");
    root->right->right->left = newnode("20");
    root->right->right->right = newnode("2");
    printf("%d",TreeEvaluation(root));
    return 0;
}
