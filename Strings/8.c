//Run length Decoding

#include<stdio.h>
#include<stdlib.h>

void Decoding(char str[]){

    int i=0,k=0,len,base,j;
    char res[10000];
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z'){
            res[k++]=str[i];
            i++;
        }
        else{
                len=0;
                base=1;
                while(str[i]>='0' && str[i]<='9' && str[i]!='\0'){
                    len=(len*base)+(str[i]-'0');
                    base*=10;
                    i++;
                }


                for(j=0;j<len-1;j++){
                    res[k]=res[k-1];
                    k++;
                }
        }
    }
    res[k]='\0';
    printf("%s",res);
}

int main(){

    char str[10000];
    gets(str);
    Decoding(str);
    return 0;
}
