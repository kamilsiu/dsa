#include<stdio.h>
void reverse(int*nums,int start,int end){
    while(start<end){
        int temp = nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }

}
void rotate(int* nums,int k ,int end ) {
    k = (k % end)+1 ;
    reverse(nums,0,k-1);
    reverse(nums,k,end-1);
    reverse(nums,0,end-1);
}
int main(){
    int arr[]={1,2,3,4,5,6,7 };
    int numsize = sizeof(arr)/sizeof(arr[0]);
    rotate(arr,3,numsize-1);
    for(int i = 0 ;i<numsize;i++){
        printf("%d ",arr[i]);
    }
    
}