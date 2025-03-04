#include<stdio.h>
void shell_sort(int A[],int n){
    int temp,j;
    for(int gap = n/2;gap>=1;gap/=2){
        for(int i = gap;i<n;i++){
            temp = A[i];
            j = i - gap;
            while(j>=0&&A[j]>temp){
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
    }
}
void print(int A[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]); 
    }
}
int main(){
    int A[] = {10454,12,20,1,5,10,70,13,2,100,54};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before Selection Sort : \n");
    print(A,n);
    printf("\nAfter Selection Sort : \n");
    shell_sort(A,n);
    print(A,n);
}