//Remove all duplicates from a given string.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Fun(char str[]){

    int i,hash[26]={0};

    for(i=0;i<strlen(str);i++){

        if(str[i]!=' '){

            if(hash[str[i]-'a']==0){
                hash[str[i]-'a']=1;
                printf("%c",str[i]);
            }

        }

    }
}

int main()
{
    char str[10000];
    gets(str);
    Fun(str);
    return 0;
}
