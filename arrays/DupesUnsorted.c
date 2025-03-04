#include<stdio.h>
int main(){
    int A[]= {8,11,4,8,6,11,11,12,5,3,4};
    int length = 11;
    for(int i = 0 ;i<length-1;i++){
        int count = 1;
        if(A[i]!=-1){
            for(int j = i+1;j<length;j++){
                if(A[i]==A[j]){
                    count++;
                    A[j]=-1;
                }
}
            }
    if(count>1){
    printf("\n%d is repeating %d times ",A[i],count);
       
    } 

}
    
}