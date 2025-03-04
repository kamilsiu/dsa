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
    first->prev=first->next=NULL;
    last = first;
    for(int i = 1;i<n;i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct Node*p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int length(struct Node*p){
    int len =0;
    while(p){
        p = p->next;
        len++;
    }
    return len;
}
void Insertatbeg(struct Node*p,int x){
    struct Node*t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
}
void InsertatPos(struct Node*p,int index,int x){
    int i = 0;
    struct Node*t;
    while(i!=index-1){
        i++;
        p = p->next;
    }
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->prev=p;
    t->next=p->next;
    if(p->next)p->next->prev=t;
    p->next=t; 
}
void Insert(struct Node*p,int pos,int x){
    struct Node*t;
    if(pos<0||pos>length(p))return;
    if(pos==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else{
        int i = 1;
        while(i!=pos-1){
            i++;
            p = p->next;
        }
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next)p->next->prev=t;
        p->next=t;

    }
}
void DeleteatBeg(struct Node*p){
    first=first->next;
    free(p);
    if(first)first->prev=NULL;
}
void DeleteatPos(struct Node*p,int pos){
    int i = 0;
    while(i<pos-1){
        i++;
        p=p->next;
    }
    p->prev->next=p->next;
    if(p->next)p->next->prev=p->prev;
    free(p);
}
int Delete(struct Node*p,int index){
    int x=-1,i=0;
    if(index<0||index>length(p))return-1;
    if(index==0){
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else{
        while(i!=index-1){
            i++;
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node*p){
    struct Node*temp;
    while(p){
        temp = p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL&&p->next==NULL){first=p;
        }
    }
    
}
int main(){
    int A[]={23,5,1,9,19,3};
    create(A,6); 
    display(first);
    Reverse(first);
    display(first);
}