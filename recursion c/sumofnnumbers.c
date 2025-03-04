#include<stdio.h>
int sum(int n){

    int i = 0;
    if(n<=0){
        return 0;
    }
    else{
       return sum(n-1)+n;
    }

    i++;
}
int main(){
    int n = 10;
    int a = sum(n);
    printf("%d ",a);

}