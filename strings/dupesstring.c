#include<stdio.h>
#include<stdlib.h>
int main(){
    char n[] = "Finding";

    int H[26]={0};
    for(int i = 0 ;n[i]!='\0';i++){
        H[n[i]-97]+=1;
    }
    for(int i=0;i<26;i++){
        if(H[i]>1){
            printf("duplicate found %c ,it is repeated %d times\n",i+97,H[i]);
        }
    }

}