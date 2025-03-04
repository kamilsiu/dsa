#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void Push(int x){
    struct Node*t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)printf("Stack is Full\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node*p;
    int x = -1;
    if(top==NULL)printf("Stack is Empty\n");
    else{
        p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}
int isEmpty(){
    return top==NULL;
}
int isFull(){
    struct Node*t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)return 1;
    free(t);
    return 0;
}
void display(){
    struct Node*t=top;
    while(t!=NULL){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}
int peek(int pos){
    struct Node*p=top;
    for(int i=0;i<pos-1&&p;i++){
        p = p->next;
    }
    if(p!=NULL)return p->data;
    else return -1;
}
int main(){
    Push(10);
    Push(20);
    Push(30);
    display();
    printf("Element is %d ",peek(3));

    int x = pop();printf("\nDeleted Element %d",x);
}