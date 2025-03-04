#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[] = {1,2,3,5,6,7,9,11,13};
    int l = 1;
    int length = 9;
    int h = 13;
    int *H;
    H = (int *)malloc(12*(sizeof(int)));
    for(int i = 0 ;i<length;i++){
        H[A[i]]++;
    }
    for(int i = 1 ;i<12;i++){
        if(H[i]==0){
            printf("%d ",i);
        }
    }

}