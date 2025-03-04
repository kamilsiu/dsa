#include<stdio.h>
int main(){
    char A[] = "KAMIL";
    char B[] = "MIAKL";
    int H[26] = {0};
    int i ,j;
    for( i = 0 ;A[i]!='\0';i++);
    for( j = 0; B[j]!='\0';j++);
    if(i!=j){
        printf("\n%s and %s are not anagrams",A,B);
    }
    for( i = 0 ; A[i]!='\0';i++){
        H[A[i]-97]++;
    }
 
    for( j = 0 ;B[j]!='\0';j++){
        H[B[j]-97]--;
        if(H[B[j]-97]<0){
            printf("\n%s and %s are not Anagrams",A,B);
            break;
        }
        
    }
    if(B[j]=='\0'){
        printf("\n%s and %s are anagrams",A,B);
    }
}