#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    int i;
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next = NULL;
    last = first;

    for(int i = 1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create1(int A[],int n){
    int i;
    struct Node*t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next = NULL;
    last = second;

    for(int i = 1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void ReverseDisplayR(struct Node*p){
    if(p!=NULL){
        ReverseDisplayR(p->next);
        printf("%d ",p->data);
    }
}
void DisplayR(struct Node*p){
    if(p!=NULL){
        printf("%d ",p->data);
        DisplayR(p->next);
    }
}
int count(struct Node*p){
    int count = 0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
}
int add(struct Node*p){
    //Time -> O(n) 
    //Space -> O(1)
    int sum = 0 ; 
    while(p!=0){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int addR(struct Node*p){
    //Time -> O(n)
    //Space ->O(n)
    int sum = 0;
    
    if(p!=NULL){
        return addR(p->next)+p->data;
    }
    else{
        return 0;
    }
}
int maximum(struct Node*p){
    int max = INT_MIN;
    while(p){
        if(p->data>max){
            max = p->data;
        }
        p = p->next;
    }
    return max;

}
int maximumR(struct Node*p){
    int max=0;
    if(p==0)
        return INT_MIN;
    max=maximumR(p->next);
    return max>p->data?max:p->data;
}
struct Node*search(struct Node*p,int key){
    while(p!=NULL){
        if(key==p->data)return p;
        p=p->next;
    }return NULL;
}
struct Node*Rsearch(struct Node*p,int key){
    if(p==0)return NULL;
    else if(key==p->data)return p;
    else return Rsearch(p->next,key);
}
struct Node*isearch(struct Node*p,int key){
    //Improved Search 
    //Bringing the key element to the first node after its found
    struct Node*q=NULL;       
    q=p;
    while(p!=NULL){
        if(key==p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else{
            p = p->next;
        }
    }

}
struct Node*Insertatbeg(struct Node*p,int x){
    p =(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)return NULL;
    else{
        p->data=x;
        p->next=first;
        first=p;
        return p;
    }
}
struct Node*Insertatmid(struct Node*t,int index,int x){
    int i;
    struct Node*p=first;
    if(index<0 || index>count(t)) return NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1&&p;i++){
            p = p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
struct Node*InsertAtLast(struct Node*t,int x){
    struct Node*p=t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;  
    t->next=NULL;
    if(t==NULL)return t;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=t;  
    return t; 
}
void SortedInsert(struct Node*p,int x){
    struct Node*t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else{
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
        t->next=q->next;
        q->next=t;
    }
    }
}
void DeleteAtBeg(struct Node*p){
    int x;
    first=p->next;
    x=p->data;
    free(p);
    printf("\nDeleted Element : %d\n",x);
}
int DeleteAtPosition(struct Node*p,int index){
    struct Node*q;
    int x=-1;
    if(index<1||index>count(p)){
        return -1;
    }
    if(index==1){
    
        x = p->data;
        first=first->next;
        free(p);
        return x;
    }
    else{
    for(int i = 0;i<index-1&&p;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    return x;
    free(p);
    }
}
int isSorted(struct Node*p){
    int x = INT_MIN;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}
void RemoveDuplicates(struct Node*p){
    struct Node*q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}
void RemoveDupes(struct Node*head){
    struct Node*p = head->next;
    struct Node*q = head;
    while(p!=NULL){
        if(p->data!=q->data){
            q = p;
            p = p->next;
        }
        else{
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
}
void Reverse1(struct Node*p){
    //Reversing using Array storing the elements of linked list in array
    // Storing the elements of linked list in array
    //When it reaches last index
    //Copying it into linked list and decrementing 
    int*A;
    struct Node*q=p;
    A = (int*)malloc(count(p)*sizeof(int*));
    int i = 0;
    while(q!=NULL){
        A[i]= q->data;
        q=q->next;
        i++;
    }i--;
    q=p;
    while(q!=NULL){
        q->data=A[i--];
        q = q->next;

    }
}
void Reverse2(struct Node*p){
    //Using Sliding Window
    //Taking the pointers such that at the end of the loop 
    //such that r->next =q ; q->next = p;p->next = NULL
    //and reversing the links
    struct Node*r,*q=NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next =r;//Reversing the links
    }first=q;
}
void Reverse3(struct Node*q,struct Node*p){
    if(p!=NULL){
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
void Concatenation(struct Node*p,struct Node*q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
   
}
void MergeLinkedList(struct Node*first,struct Node*second){
    struct Node*last;
    if(first->data<second->data){
        last=third=first;
        first=first->next;
        last->next=NULL;
    }
    else{
        last=third=second;
        second=second->next;
        last->next=NULL;
    }
    while(first!=NULL&&second!=NULL){
        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else{
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)last->next=first;
    else last->next=second;
}
int isLoop(struct Node*f){
    struct Node*p,*q;
    p = q = f;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q; 
    }while(p&&q&&p!=q);
    if(p==q)return 1;
    else return 0;
}
int main(){
    int A[]= {4,6,9,11,22};
    create(A,5);
    struct Node*t1,*t2;
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    if(isLoop(first)){
    printf("\nlinked list is a loop");}
    else{printf("it is a linear list ");}

}