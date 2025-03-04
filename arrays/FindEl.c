#include<stdio.h>
int main(){
    int arr[] = {1,3,4,5,6,7,8,9,10};
    int formulsum = (10 *(10+1))/2;
    int tsum = 0;
    for(int i = 0; i<9;i++){
        tsum+=arr[i];
    }
    if(formulsum>tsum){
        printf("missing element is : %d",formulsum-tsum);
    }
}