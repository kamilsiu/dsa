#include<stdio.h>
int main(){
    int A[] = {1,3,20,5,25,100,-10,110,3,4};
    int max = A[0];
    int min = A[0];
    int length = 10;
    for(int i = 0;i<length;i++){
        if(min>A[i]){
            min = A[i];
        }
        else if(max<A[i]){
            max = A[i];
        }
    }
    printf("max : %d \n", max);
    printf("min : %d \n",min);
}