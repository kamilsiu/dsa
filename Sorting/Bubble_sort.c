#include<stdio.h>
void swap(int *x,int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int *A,int n){
    int i , j;
    int flag; 
    for(i = 0;i<n-1;i++){
        flag = 0;
        for(j = 0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]); 
                flag = 1;
            }
        }
        if(flag == 0)break;
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
    printf("Before Sorting : \n");
    print(A,n);
    printf("\nAfter Sorting : \n");
    bubble_sort(A,n);
    print(A,n);
}