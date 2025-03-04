#include<stdio.h>
#include<stdlib.h>
int main(){
    int values[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int i;
    int arr[9] = {0};
    for(i = 0;i<3;i++){
        arr[i] = values[0][i];
    }
    arr[i++] = values[1][2];
    arr[i++] = values[2][2];
    for(int k = 0;k<9;k++){
        printf("%d ",arr[k]);
    }
}