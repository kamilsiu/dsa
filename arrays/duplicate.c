#include<stdio.h>
int main(){
    int arr[] = {1,2,3,6,6,9,20,25,25,25,10};
    int n = 11;
    int lastduplicate = 0;
    for(int i = 0 ;i<n;i++){
        if(arr[i]==arr[i+1]&& arr[i]!=lastduplicate){
            printf("%d ",arr[i]);
            lastduplicate = arr[i];
        }
    }
}