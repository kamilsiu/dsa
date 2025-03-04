#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*front = NULL,*rear=NULL;
void Enqueue(int x){
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)printf("Queue is Full\n");
    else{
    t->data=x;
    t->next=NULL;
    }
    if(front==NULL){
        front = rear = t;
    }
    else{
        rear->next=t;
        rear=t;
        rear->next=NULL;
    }
}
int Dequeue(){
    int x = -1;
    struct Node*p;
    if(front==NULL)printf("Queue is Empty\n");
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }return x;
}
void Display(){
    struct Node*q;
    q=front;
    while(q){     
        printf("%d ",q->data);
        q=q->next;
   
    }
    printf("\n");
}
int main(){
    Enqueue(4);
    Enqueue(2);
    Enqueue(1);
    Dequeue();
    Enqueue(9);
   // printf("Deleted ELement is : %d\n",Dequeue());
    Display();
}