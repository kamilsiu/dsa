#include<stdio.h>
int factorial(int n){
    if(n<0){
        return -1;
    }
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
    
}
int main(){
    int n = 14;
    int x = factorial(n);
    printf("%d ",x);
    return 0;
}