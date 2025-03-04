#include<stdio.h>
void display(int arr[5][5]){
    for(int i = 0 ;i<5;i++){
        for(int j = 0 ;j<5;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void diagonal_matrix(int arr[5][5]){
    for(int i = 0 ;i<5;i++){
        for(int j = 0;j<5;j++){
            if(i!=j){
                arr[i][j] = 0;
            }
            else{
                printf("Enter the element you want at %d row and %d column : ",i,j);
                scanf("%d",&arr[i][j]);
            }
        }
    }
    display(arr);
}
void new_array(int arr[5][5],int arr1[5]){
    for(int i = 0 ;i<5;i++){
        for(int j= 0 ;j<5;j++){
            if(i==j){
                arr1[i]=arr[i][j];
            }
        }
    }
    printf("\n");
    for(int i = 0 ;i<5;i++){
        printf("%d ",arr1[i]);
    }
}
int main(){
    int arr[5][5];
    int arr1[5];
    diagonal_matrix(arr);
    new_array(arr,arr1);
}