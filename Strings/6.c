//Anagram check

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void check_anagram(char str1[],char str2[]){

    if(strlen(str1)!=strlen(str2)){
        printf("Not Anagram\n");
    }
    else{
        int i,hash[26]={0},flag=0;

        for(i=0;i<strlen(str1);i++){
            hash[str1[i]-'a']++;
            hash[str2[i]-'a']--;
        }

        for(i=0;i<26;i++){
            if(hash[i]==1){
                flag=1;
                break;
            }
        }

        (flag==0) ? printf("Anagram") : printf("Not Anagram");
    }
}

int main(){
    char str1[10000],str2[10000];
    gets(str1);
    gets(str2);
    check_anagram(str1,str2);
    return 0;
}
