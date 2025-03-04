#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
int findmax(int A[],int n){
    int max=INT32_MIN;
    for(int i = 0;i<n;i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}
void count_sort(int A[],int n){
    int max ;
    max = findmax(A,n);
    int *C = (int*)malloc(sizeof(int)*max+1);
    for(int i = 0;i<n;i++){
        C[A[i]]++;
    }
    int i,j;
    i = j = 0;
    while(i<max+1){
        if(C[i]>0){
            A[j++] = i;
            C[i]--;
        }
        else{
            i++; 
        }
    }
}
void print(int A[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
}
int main(){
    int A[] = {1,20,2,30,20,5,5,10,70,123};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before Count Sort : \n");
    print(A,n);
    printf("\nAfter Count Sort : \n");
    count_sort(A,n);
    print(A,n);
}