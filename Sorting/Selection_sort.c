#include<stdio.h>
void swap(int*a,int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int A[],int n){
    int i ,j,  k;
    for(i = 0;i<n;i++){
        for(j = k = i;j<n;j++){
            if(A[j]<A[k]){
                k = j;
            }
        }
        swap(&A[i],&A[k]);
    }
}
void print(int A[],int n){
    for(int i = 0 ; i<n;i++){
        printf("%d ",A[i]);
    }
}
int main(){
    int A[] = {10454,12,20,1,5,10,70,13,2,100,54};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before Selection Sort : \n");
    print(A,n);
    printf("\nAfter Selection Sort : \n");
    selection_sort(A,n);
    print(A,n);
}