#include<stdio.h>
int powe(int m,int n){
    if(n==0){
        return 1;
    }
    return powe(m,n-1)*m;
}
int main(){
    int m = 2;
    int n = 5;
    int power = powe(m,n);
    printf("%d ",power);

}