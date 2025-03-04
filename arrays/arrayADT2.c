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
void Append(struct Array *arr,int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
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
void SortInsert(struct Array *arr,int x){
    int i = arr->length - 1;
    if(arr->length == arr->size)
        return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--; 
    }
    arr->A[i+1] = x;
    arr->length++; 
} 
int isSorted(struct Array arr){
    for(int i = 0 ;i<arr.length;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
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
int BinarySearch(struct Array arr,int key,int low ,int high){

    while(high>=low){  
        int mid = (low+high)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}
int RBinarySearch(int a[],int l,int h,int key){
    if(l<=h){
        int mid = (l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<=a[mid]){
            return RBinarySearch(a,l,mid-1,key);
        }
        else{
            return RBinarySearch(a,mid+1,h,key);
        }
    }
}
int Get(struct Array arr ,int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }return -1;
}
void Set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}
int Max(struct Array arr){
    int max = arr.A[0];
    for(int i = 0;i<arr.length;i++){
        if(max<arr.A[i]){
            max=arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr){
    int min = arr.A[0];
    for(int i = 0 ;i<arr.length;i++){
        if(min>arr.A[i]){
            min=arr.A[i];
        }
   
    }
    return min;

}
int Sum(struct Array arr){
    int Total = 0;
    for(int i = 0;i<arr.length;i++){
        Total += arr.A[i];
    }
    return Total;
}
float Average(struct Array arr){

    return (float)(Sum(arr))/arr.length;
}
void Display(struct Array arr){
    printf("\nPrinting the elements :\n");
    for(int i = 0; i<arr.length;i++){
       printf("%d ",arr.A[i]); 
    }
    printf("\n");
}
void Reverse(struct Array *arr){
    int j = arr->length - 1;
    for(int i = 0 ;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}
void BReverse(struct Array *arr){
    int i = 0;
    int *B;
    B = (int *)malloc(arr->length * sizeof(int ));
    for(int j = arr->length -1; j>=0;j--,i++){
        B[i] = arr->A[j];
    } 
    for(int i = 0 ; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}
void Rearrange(struct Array*arr){
    int i = 0,j = arr->length;
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>=0){
            j--;
        }
        if(j>i){
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}
struct Array* merge(struct Array *arr1,struct Array *arr2){
    struct Array *arr3 = (struct Array * )malloc(sizeof(struct Array)); 
    int m = arr1->length ;
    int n  = arr2->length ;
    int i ,j,k;
    i=j=k=0;
    while(i<m && j<n){
        if(arr1->A[i]>arr2->A[j]){
            arr3->A[k++]=arr2->A[j++];
        }
        else{
            arr3->A[k++]=arr1->A[i++];
        }
    }
    for(;i<m;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<n;j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=16;
    return arr3;
}
struct Array* Union(struct Array *arr1,struct Array *arr2){
    struct Array *arr3 = (struct Array * )malloc(sizeof(struct Array)); 
    int m = arr1->length ;
    int n  = arr2->length ;
    int i ,j,k;
    i=j=k=0;
    while(i<m && j<n){
        if(arr1->A[i]>arr2->A[j]){
            arr3->A[k++]=arr2->A[j++];
        }
        else if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
        }
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<m;i++){
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<n;j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length=k ;
    arr3->size=16;
    return arr3;
}
struct Array* Intersection(struct Array *arr1,struct Array *arr2){
struct Array *arr3 = (struct Array * )malloc(sizeof(struct Array)); 
    int m = arr1->length ;
    int n  = arr2->length ;
    int i ,j,k;
    i=j=k=0;
    while(i<m && j<n){
        if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k ;
    arr3->size=16;
    return arr3;
}
struct Array* Difference(struct Array *arr1,struct Array *arr2){
    struct Array *arr3 = (struct Array * )malloc(sizeof(struct Array)); 
    int m = arr1->length ;
    int n  = arr2->length ;
    int i ,j,k;
    i=j=k=0;
    while(i<m && j<n){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }
        else if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(;i<m;i++){
        arr3->A[k++]=arr1->A[i++];
    }
    
    arr3->length=k ;
    arr3->size=16;
    return arr3;
}
int main() {
    struct Array arr1;
    int ch;
    int x, index, key;

    printf("Enter the size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;  // Initialize length as 0

    do {
        printf("\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter the element and index: ");
                scanf("%d%d", &x, &index);
                insert(&arr1, index, x);  // Insert element at index
                break;
            case 2:
                printf("Enter the index of the element you want to delete: ");
                scanf("%d", &index);
                x = delete(&arr1, index);
                printf("Deleted element: %d\n", x);
                break;
            case 3:
                printf("Enter the key element you want to search: ");
                scanf("%d", &key);
                index = LinearSearch(&arr1, key);
                if (index >= 0) {
                    printf("Element found at index: %d\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 4:
                printf("The sum of the elements is: %d\n", Sum(arr1));
                break;
            case 5:
                Display(arr1);
                break;
        }
    } while (ch < 6);

    // Free allocated memory
    free(arr1.A);

    return 0;
}