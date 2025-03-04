#include<stdio.h>
#include<stdlib.h>
int main(){
    int A[5];
    int *p;
    int n;
    scanf("%d",&n);
    p = (int *)malloc(n*sizeof(A[0]));
    for(int i = 0 ;i<n;i++){
        printf("%d ",A[i]);
    }
    free(p);
return 0;
}