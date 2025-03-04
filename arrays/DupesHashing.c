#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[] = {1,11,14,8,5,4,11,8,9,12,13,9};
    int length = 12;
    int *H;
    H = (int *)malloc(15*sizeof(int));
    for(int i = 0 ; i<length;i++){
        H[A[i]]++;
    }
    for(int i=0;i<15;i++){
        if(H[i]>1){
            printf("\n%d is repeating %d times",i,H[i]);
        }
    }
    free(H);
}
