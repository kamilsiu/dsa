#include<stdio.h>
void merge(int A[],int l,int mid,int high){
    int i,j,k;
    i = l,j= mid+1,k=l;
    int B[100];
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    while(i<=mid){
        B[k++]=A[i++];
    }
    while(j<=high){
        B[k++] = A[j++];
    }
    for(int i = l;i<=high;i++){
        A[i] = B[i];
    }
}
void mergesort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,mid,high);
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
    printf("Before Merge Sort : \n");
    print(A,n);
    printf("\nAfter Merge Sort : \n");
    mergesort(A,0,n-1 );
    print(A,n);
}
