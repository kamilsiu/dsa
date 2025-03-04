#include<stdio.h>
int main(){
    char word [] ="niggin";
    int i,j;
    for( i = 0;i!='\0';i++){
    }i--;
  
    for(j = 0;j<i;j++,i--){
        if(word[i]!=word[j]){
            printf("%s is not a palindrome",word);
            return -1;
        }
    }
   
          printf("%s is a palindrome",word);
          return 0;
    }

   
        
   
        
