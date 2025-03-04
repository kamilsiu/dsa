#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*prev;
    int data;
    struct Node*next;
}*first=NULL;
void create(int A[],int n){
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first;
    first->next=first;
    last=first;
    for(int i=1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;
        first->prev=t; // makes this list circular
        last=t;
    }
}
int length(struct Node*p){
    int count =0;
    do{
        count++;
        p=p->next;
    }while(p!=first);
    return count;
}
void Middle(struct Node*first){
    struct Node*q,*p;
    p = q = first;
    while(q){
        q = q->next;
        if(q)q=q->next;
        if(q)p=p->next;
    }
    printf("%d \n",p->data);
}
void Insert(struct Node*p,int pos,int x){
    struct Node*t;
    if(pos<=0||pos>length(p))return;
    if(pos==1){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=first;
        t->prev=first->prev;
        first->prev->next=t;
        first->prev=t;
        first=t;
        return;
    }
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x; 
    int i = 1;
    while(i!=pos-1){
        i++;
        p = p->next;
    }
    t->next=p->next; 
    t->prev=p;
    p->next=t;
}
void Delete(struct Node*p,int pos){
    if(pos<=0||pos>length(p))return;
    if(pos==1){
        first=first->next;
        first->prev=p->prev;
        p->prev->next=first;
        free(p);
    }
    else{
        int i = 0;
        while(i!=pos-1){
            i++;
            p=p->next;
        }
        p->next->prev=p->prev;
        if(p->next)p->prev->next=p->next;
    }
}
void Display(struct Node*p){
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=first);
}

int main(){
    int A[] = {2,4,1,9,19};
    create(A,5);
    Insert(first,2,100);
    Display(first);
    printf("\n");
    Delete(first,3);
    Display(first);
} 