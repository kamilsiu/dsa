#include<stdio.h>
int power(int m,int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return (power(m*m,n/2));
    }
    else{
        return (m*power(m*m,n/2));
    }
}
int main(){
    int m = 2;
    int n = 5;
    int p = power(m,n);
    printf("%d ",p);

}