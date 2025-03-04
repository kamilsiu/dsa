#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node*next;
}*first=NULL;
void sortedInsert(struct Node**H,int key){
    struct Node*t,*q=NULL,*p = *H;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->next=NULL;
    if(*H==NULL){
        *H=t;
    }
    else{
        while(p&&p->data<key){
            q = p;
            p = p->next;
        }
        if(p==first){
            t->next=first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}
int hash(int key){
    return key%10;
}
void insert(struct Node*H[],int key){
    int index = hash(key);
    sortedInsert(&H[index],key);
}
struct Node*search(struct Node* p,int key){
    while(p!=NULL){
        if(p->data==key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int main(){
    struct Node* temp;
    struct Node*HT[10];
    int i = 0;
    for(i = 0;i<10;i++){
        HT[i]=NULL;
    }
    insert(HT,12);
    insert(HT,32);
    insert(HT,82);
    temp = search(HT[hash(12)],12);
    printf("%d ",temp->data);
}