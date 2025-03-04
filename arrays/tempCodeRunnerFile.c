#include<stdio.h>
#include<stdlib.h>
int main(){
    //Creating two dynamic arrays for resizing
    int *p,*q;
    p = (int*)malloc(5*sizeof(int));
    p [0]=34;p[1]=45;p[2]=45;p[3] = 122;p[4]=2;
    q = (int *)malloc(10*sizeof(int));
    for(int i = 0;i<5;i++){
        q[i]=p[i];//storing elements of P[] in q[]
    }
    free(p);//Deleting p memory from heap
    p=q;//Assigning q address to p
    q=NULL;//Pointing q to NULL
    for(int i = 0;i<10;i++){
        printf("%d ",p[i]);
    } 

}