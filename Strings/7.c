//Run Length Encoding

#include<stdio.h>
#include<stdlib.h>

void Encoding(char str[]){
    int i,len=1,k=0;
    char res[10000];
    for(i=1;str[i]!='\0';i++){

        if(str[i-1]==str[i]){
            len++;
        }
        else{
            res[k++]=str[i-1];

            res[k++]=len+'0';

            len=1;
        }
    }
    res[k++]=str[i-1];
    res[k++]=len+'0';
    res[k]='\0';
    printf("%s",res);
}

int main()
{
    char str[100000];
    gets(str);
    Encoding(str);
    return 0;
}
