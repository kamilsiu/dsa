#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL;
int findmax(int A[],int n){
    int max=INT32_MIN;
    for(int i = 0;i<n;i++){
        if(A[i]>max){
            max = A[i];
        }
    }
    return max;
}
void InsertAtLast(struct Node**head,int x){
    struct Node*t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;  
    t->next=NULL;
    if(*head==NULL)*head=t;
    else{
    struct Node*p =*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=t;  
    } 
}
int Delete(struct Node**head){
    if (*head == NULL) return -1; // Handle empty list case
    struct Node* p = *head;
    *head = (*head)->next;
    int x = p->data;
    free(p);
    return x;
}
void bucket_sort(int A[],int n){
    int max = findmax(A,n);
    struct Node**bins;
    bins = (struct Node**)malloc(sizeof(struct Node*)*max+1);
    for(int i = 0;i<max+1;i++){
        bins[i] = NULL;
    }
    for(int i = 0;i<n;i++){
        InsertAtLast(&bins[A[i]],A[i]);
    }
    int i ,j;
    i = 0 ,j = 0;
    while(i<max+1){
        while(bins[i]!=NULL){
            A[j++] = Delete(&bins[i]);
        }
        i++;
    }
    free(bins);
}
void print(int A[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",A[i]);
    }
}
int main(){
    int A[] = {1,20,2,30,20,5,5,10,70,123};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Before Count Sort : \n");
    print(A,n);
    printf("\nAfter Count Sort : \n");
    bucket_sort(A,n);
    print(A,n);
}