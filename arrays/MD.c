#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};
void swap(int*x,int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insert(struct Array *arr,int index,int x){
    if(index>=0 && index <= arr->length){
        for(int i = arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
int delete(struct Array *arr,int index){
    int x = 0;
    if(index >=0 && index<arr->length){
        x = arr->A[index];        
        for(int i = index;i < arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
    }
    arr->length--;
    return x;
    }
    return 0;
}
int Sum(struct Array arr){
    int Total = 0;
    for(int i = 0;i<arr.length;i++){
        Total += arr.A[i];
    }
    return Total;
}

void Display(struct Array arr){
    printf("\nPrinting the elements :\n");
    for(int i = 0; i<arr.length;i++){
       printf("%d ",arr.A[i]); 
    }
    printf("\n");
}
int LinearSearch(struct Array *arr,int key){
    for(int i = 0;i<arr->length;i++){
        if(key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}

int main(){
   struct Array arr1;
   int ch;
   int x,index,key;
   printf("Enter the size of Array : ");
   scanf("%d",&arr1.size);
   arr1.A = (int *)malloc(arr1.size*sizeof(int));
   arr1.length = 0;
do{
   printf("\nMenu\n");
   printf("1. Insert\n");
   printf("2. Delete\n");
   printf("3. Search\n");
   printf("4. Sum\n");
   printf("5. Display\n");
   printf("6. Exit\n");
   printf("Enter your choice : \n");
   scanf("%d",&ch);
   switch (ch)
   {
   case 1:
        printf("Enter the element and index : ");
        scanf("%d%d" ,&index ,&x);
        insert(&arr1 ,index ,x);
        break;
    case 2:
        printf("Enter the index of the element you want to delete : ");
        scanf("%d" ,&index);
        x = delete(&arr1 ,index);
        printf("Deleted element : %d " ,x);
        break;
    case 3:
        printf("Enter the key element you want to search ");
        scanf("%d",&key);
        index = LinearSearch(&arr1,key);
        printf("%d",index);
        break;
    case 4:
        printf("The sum of the elements is : %d ",Sum(arr1));
        
        break;
    case 5:
         Display(arr1);
         break;
 


   }}while(ch<6);
free(arr1.A);
}
