#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*Head;
void Create(int A[],int n){
    int i;
    struct Node*last,*t;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last = Head;
    
    for(int i = 1 ;i<n;i++){
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    last->next = t;
    last = t;

    }
}
void Display(struct Node*p){
    printf("Elements in circular linked list are :\n");
    do{
        printf("%d ",p->data);
        p = p->next;
    }while(p!=Head);
}
void RecursiveDisplay(struct Node*p){
    static int flag = 0;
    if(p!=Head||flag==0){
        flag = 1;
        printf("%d ",p->data);
        RecursiveDisplay(p->next);
    }
    flag = 0;
}
int length(struct Node*p){
    int count = 0;
    do{
        count++; 
        p=p->next;
    }while(p!=Head);
    return count;
}
void Insert(struct Node*p,int pos,int x){
    struct Node*t;
    if(pos<0 ||pos>length(p))
    return;
    if(pos==0){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(Head==NULL){
            Head=t;
            Head->next=Head; 
        }
        else{
            while(p->next!=Head){
                p=p->next;
            }
            p->next=t;
            t->next=Head;
            Head=t;
        }
    }
    else{
        int i;
        while(i<pos-1){
            p = p->next;
        } 
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next=t;
    }
}
void DeleteatBeg(struct Node*p){
    while(p->next !=Head){
        p = p->next;
    }
    p->next=Head->next;
    Head=p->next;
}
void DeleteatIndex(struct Node*p,int pos){
    int i = 0;
    struct Node*q;
    while(i<pos-1){
        i++;
        p = p->next;
    }
    q = p->next; 
    p->next=q->next;
    free(q);
}
void Delete(struct Node*p,int pos){
    struct Node*q=p;
    if(pos<0||pos>length(p))return;
    int i = 1;
    if(pos==1){
        while(p->next!=Head){
            p=p->next;
        }
        if(p==Head){
            free(Head);
        }
        p->next=Head->next;
        free(Head);
        Head=p->next;
    }
    else{
        while(i!=pos-1){
            i++;
            p=p->next;
        }
        q = p->next;
        p->next=q->next;
        free(q);
    }  
}
int main(){
    int A[]={23,4,5,6,2,19};
    Create(A,6);
    Display(Head);
    printf("\n");
    Delete(Head,3);
    Display(Head);


}