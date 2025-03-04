#include<stdio.h>
#include<stdlib.h>
void insert(int A[],int n){
    int i = n;
    int temp = A[i];
    while(i>1&&temp>A[i/2]){
        A[i]=A[i/2];
        i = i/2;
    }
    A[i]=temp;
}
void Delete(int A[],int n){
    int x,i;
    int val = A[1];
    x = A[n];
    A[1]=A[n];
    A[n]=val;
    i = 1; int j = 2*i;
    while(j<n-1){
        if(A[j]<A[j+1]){
            j +=1;
        }
        if(A[i]<A[j]){
            int temp = A[j];
            A[j]=A[i];
            A[i]=temp;
            i = j;
            j = 2*j;
        }
        else{break;}
    }
}
void createheap(){
    int A[] = {0,10,20,30,25,5,40,35};
    int n = 7;
    int i ;
    for(i = 2;i<=n;i++){
        insert(A,i); 
    }
    printf("\n");
    for(i = 7;i>1;i-- ){
       Delete(A,i);
    }
for(i = 1;i<n;i++){
    printf("%d ",A[i]);
}
}
int main(){
    createheap();
    

}