//check given string is pangram or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check_panagram(char str[]){

    int i,hash[26]={0},flag=0;
    for(i=0;str[i]!='\0';i++){
        hash[tolower(str[i])-'a']++;
    }

    for(i=0;i<26;i++){
        if(hash[i]==0){
            flag=1;
            break;
        }
    }
    (flag==0) ? printf("Panagram\n") : printf("Not Panagram\n");
}

int main()
{
    char str[10000];
    gets(str);
    check_panagram(str);
    return 0;
}
