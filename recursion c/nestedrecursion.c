#include<stdio.h>
int nestedrecursion(int n){
    if(n>100){
        return n - 10;
    }

        return nestedrecursion(nestedrecursion(n+11));
    
}
int main(){
    int x = nestedrecursion(95);
    printf("%d ",x);
}