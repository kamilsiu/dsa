#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr){
    printf("\nprinting the elements :\n");
    for(int i = 0; i<arr.length;i++){
       printf("%d ",arr.A[i]); 
    }
}
int main(){
    struct Array arr;
    int n;
    printf("Enter the size of the array ");
    scanf("%d",&arr.size);
    printf("Enter the length of the array ");
    scanf("%d",&n);
    if(n>arr.size){printf("Error ! Length of array exceeds size of array ");
    return -1;}
    arr.A = (int *)malloc(arr.size*(sizeof(int)));
    arr.length = 0;

    printf("Enter all the elements ");
    for(int i = 0;i<n;i++){
        scanf("%d ",&arr.A[i]);
    }
    arr.length = n;
    Display(arr);
}