#include<stdio.h>
void insertion_sort(int A[],int n){
    int j;
    for(int i = 1;i<n;i++){
        j = i-1;
        int x = A[i];
        while(j>-1&&A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = x;
    }
}
void print(int A[],int n){
    for(int i = 0 ; i<n;i++){
        printf("%d ",A[i]);
    }
}
int main(){
    int A[] = {1,20,2,5,10,70,123};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before Insertion Sort : \n");
    print(A,n);
    printf("\nAfter Insertion Sort : \n");
    insertion_sort(A,n);
    print(A,n);
}