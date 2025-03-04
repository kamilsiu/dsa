#include<stdio.h>
int main(){
    char A[] ="python";
    char B[8];
    int j;
    int i ;
    for( i = 0 ;A[i]!='\0';i++){  
    }
    i -=1 ;
    for(j = 0; i>=0;j++,i--){
        B[j]=A[i];
    }
    B[j]='\0';
    
    printf("%s",B);
}