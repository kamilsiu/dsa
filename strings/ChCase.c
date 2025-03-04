#include<stdio.h>
int main(){
    char sent[] = "welCOme HoMe";
    int i;
    for( i = 0 ; sent[i]!='\0';i++){
        if(sent[i]>='A'&&sent[i]<='Z'){
            sent[i]+=32;
        }
        else if(sent[i]>='a'&&sent[i]<='z'){
            sent[i]-=32;
        }    
    }
     printf("%s",sent);

}