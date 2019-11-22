#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Return maximum occurring character in an input string
void Fun(char str[]){

    int max=0,i,hash[26]={0};
    char res;
    for(i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            hash[str[i]-'a']++;
            if(max<hash[str[i]-'a']){
                max=hash[str[i]-'a'];
                res=str[i];
            }
        }
    }

    printf("%c",res);

}

int main()
{
    char str[10000];
    gets(str);
    Fun(str);
    return 0;
}
