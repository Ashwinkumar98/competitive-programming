#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//infix to prefix
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

char pop(int n){
    if(top<=-1){
        printf("stack is empty\n");
    }
    else{
        char x=arr[top];
        top--;
        return x;
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

char gettop(int n){
    if(isempty(n)==-1){
        return arr[top];
    }
    else
    {
        return -1;
    }
}

int preference(char x){
    switch(x){
        case '+' : return 1;

        case '-' : return 1;

        case '*' : return 2;

        case '/' : return 2;

        case '^' : return 3;

        default :  return -1;
    }
}

void convert(char str[],int n){
    int i;

    for(i=0;str[i]!='\0';i++){

        if(str[i]>='a' && str[i]<='z'){
            printf("%c",str[i]);
        }
        else if(str[i]=='(')
        {
            push(str[i],n);
        }
        else if(str[i]==')'){
            while(isempty(n)==-1 && gettop(n)!='('){
                printf("%c",pop(n));
            }
            if(gettop(n)=='('){
               pop(n);
            }
        }
        else{
            while(isempty(n)==-1 && preference(str[i])<=preference(arr[top])){
                printf("%c",pop(n));
            }
            push(str[i],n);
        }
    }

    while(isempty(n)==-1){
        printf("%c",pop(n));
    }


}
int main()
{
    char str[10000];
    gets(str);
    convert(str,strlen(str));
    return 0;
}
