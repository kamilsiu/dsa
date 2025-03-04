#include<stdio.h>
int main(){
    char pl[]="hififfi";
    int H = 0,x= 0;
    for(int i = 0 ; pl[i]!='\0';i++){
        x = 1;
        x = x<<(pl[i]-97);
        if((x&H)>0){
            printf("duplicate found : %c\n",pl[i]);
        }
        else{
            H = x|H;
        }
    }
}