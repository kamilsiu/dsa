#include<stdio.h>
int main(){
    int arr[] = {1,2,5,9,11,17,21};
    int s = sizeof(arr)/sizeof(arr[0]);
    int prefix[s];
    prefix[0]=arr[0];
    for(int i = 0;i<s;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    for(int i = 0;i<s;i++){
        printf("%d ",prefix[i]);
    }
}