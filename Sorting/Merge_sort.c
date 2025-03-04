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
void mergesort(int A[],int n){
    int p,l,mid,i,h;
    for(p = 2;p<=n;p*=2){
        for(i = 0;p+i-1<=n;i+=p){
            l = i;
            h = p+i-1;
            mid = (l+h)/2;
            merge(A,l,mid,h);
        }
    }
    if(p/2<n){
        merge(A,0,p/2-1,n-1);
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
    mergesort(A,n);
    print(A,n);
}
