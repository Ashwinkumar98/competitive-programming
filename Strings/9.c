 //Given a string, we have to reverse the string without changing the position of punctuations and spaces.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int t1,int t2,char str[]){
    char tmp;
    tmp=str[t1];
    str[t1]=str[t2];
    str[t2]=tmp;
}

void fun(char str[]){
    int l=0,r=strlen(str)-1;

    while(l<r){

        while(str[l]==':' || str[l]=='@' || str[l]==' '){
            l++;
        }

        while(str[r]==':' || str[r]=='@' || str[r]==' '){
            r--;
        }

        if(l<r){
            swap(l,r,str);
            l++;
            r--;
        }
    }
    printf("%s",str);
}

int main(){
    char str[1000];
    gets(str);
    fun(str);
    return 0;
}
