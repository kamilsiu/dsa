#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}
void Enqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full\n");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int Dequeue(struct Queue*q){
    int x = -1;
    if(q->rear==q->front){
        printf("Queue is Empty\n");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue*q){
    if(q->front==q->rear){
        return 0;
    }
    return -1;
}
void Display(struct Queue q){
    int i = q.front+1;
    do{
        printf("%d ",q.Q[i]);
        i = (i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
int main(){
    struct Queue q;
    Create(&q,7);
    Enqueue(&q,23);
    Enqueue(&q,3);
    Enqueue(&q,2);
    Enqueue(&q,33);
    Enqueue(&q,334);
    Enqueue(&q,234);
    printf("Deleted Element is : %d \n",Dequeue(&q));
    Display(q);
}