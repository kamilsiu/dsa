#include<stdio.h>
int fib(int n){
    static int first = 0 ,second = 1 , sum ;
    if (n<=1)
        return n;
    for(int i = 1; i<n;i++){
        sum = first + second;
        first = second;
        second = sum;
    }
    return sum;
}
int main(){
    printf("%d ",fib(6));
}