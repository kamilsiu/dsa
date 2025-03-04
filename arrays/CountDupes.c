#include<stdio.h>
int main(){
    int arr[] = {3,6,8,8,10,12,15,15,15,20};
    int length = 10;
    int j = 0;
    for(int i = 0 ;i<length -1;i++){
        if(arr[i]==arr[i+1]){
            j = i+1;
            while(arr[j]==arr[i]){
                j++;
                
            }
            printf("\n%d is appearing %d times",arr[i],j-i);
                i = j;
        }
    }
}