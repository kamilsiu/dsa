#include<stdio.h>
int main(){
    int A[] = {1,2,4,5,6,7,8,9,10};
    int length = 9;
    int i = 0 ,j = length -1;
    int k = 10;
    while(i<j){
        if(A[i]+A[j]==k){
            printf("%d + %d = %d\n",A[i],A[j],k);
            i++;
            j--;
        }
        else if(A[i]+A[j]>k){
            j--;
        }
        else{
            i++;
        }
    }
}