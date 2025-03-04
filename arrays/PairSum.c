#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[]={6,3,8,10,16,7,5,2,9,14};
    int length = 9;
    int k = 10;
    int *H =(int *)malloc(16*sizeof(int));
    for(int i = 0 ;i<length; i++){
        if(H[k - A[i]]!=0){
            printf("%d + %d = %d\n",i,k-i,k);
        }
        H[A[i]]++;
        
    }

}