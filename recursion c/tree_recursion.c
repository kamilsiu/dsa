#include<stdio.h> 
int fun(int n){ 
    if(n>0){
        printf("%d ",n);
        fun(n-1);
        return fun(n-1);   
    }
    }
int main(){
    int a =3; 
    printf("%d ",fun(a));

}