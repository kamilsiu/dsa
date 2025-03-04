#include<stdio.h>
double e(int x,int n){
    int i ;
    double s = 1;
    double num = 1;
    double den = 1;
    for(i = 1 ;i <n;i++){
        num*=x;
        den*=i;
        s+=num/den;
    }return s;
}
int main(){
    printf("%lf ",e(1,10));
}