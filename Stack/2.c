//balancing parentheses

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top=-1;
char arr[10000];
void push(char x,int n){
    if(top<n){
        top++;
        arr[top]=x;
    }
    else
    {
       printf("stack is empty\n");
    }
}

void pop(int n){
    if(top<=-1){
        printf("stack is empty\n");
    }
    else{
        top--;
    }
}

int isempty(int n){
    if(top==-1){
        return 1;
    }
    else
    {
        return -1;
    }
}
void check(char str[]){
    int i;

    for(i=0;str[i]!='\0';i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                push(str[i],strlen(str));
           }
        else if(str[i]=='}' && arr[top]=='{'){
                pop(strlen(str));
        }
        else if(str[i]==']' && arr[top]=='['){
             pop(strlen(str));
        }
        else if(str[i]==')' && arr[top]=='('){
             pop(strlen(str));
        }
        else{
            printf("Not Balanced\n");
            return;
        }
    }

    if(isempty(strlen(str))==1){
        printf("Balanced\n");
    }
    else{
        printf("Not Balanced\n");
    }
}

int main()
{
    char str[10000];
    scanf("%s",str);
    check(str);
    return 0;
}
