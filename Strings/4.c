#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Revere words in a given string.
void reverse(char str[],int st,int ed){
    char tmp;
    while(st<=ed){
        tmp=str[st];
        str[st]=str[ed];
        str[ed]=tmp;
        st++;
        ed--;
    }
}

void reversestring(char str[]){
    int i,st=0;

    for(i=0;str[i]!='\0';i++){
        if(str[i+1]==' ' || str[i+1]=='\0'){
            reverse(str,st,i);
            st=i+2;
        }
    }
    reverse(str,0,strlen(str)-1);
    printf("%s",str);
}

int main(){
    char str[10000];
    gets(str);
    reversestring(str);
    return 0;
}
