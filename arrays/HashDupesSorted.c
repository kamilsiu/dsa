#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]= {1,3,5,5,7,8,10,10,14,15,15,15,16};
    int length = 13;
    int *H;
    H = (int*)malloc(16*sizeof(int));
    for(int i = 0 ; i<length - 1;i++){
        H[arr[i]]++;
    }
    for(int i = 0;i<16;i++){
        if(H[i]>1){
            printf("%d is repeating for %d times \n",i,H[i]);

        }
    }
    
}