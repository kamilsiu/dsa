#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue*q,int size){
    q->front=q->rear=-1;
    q->size=size;
    q->Q=(int*)malloc(sizeof(int)*q->size);
}
void Enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int Dequeue(struct Queue*q){
    int x = -1;
    if(q->rear==q->front){
        printf("Queue Empty");
    }
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q){
    int i ;
    for(i = q.front+1;i<q.rear+1;i++){
        printf("%d ",q.Q[i]);
    }
}
int main(){
    struct Queue q;
    Create(&q,7);
    Enqueue(&q,34);
    Enqueue(&q,3);
    Enqueue(&q,23);
    Enqueue(&q,4);
    printf("Deleted Element is : %d\n",Dequeue(&q));
    printf("Deleted Element is : %d\n",Dequeue(&q));
    printf("Deleted Element is : %d\n",Dequeue(&q));
    Enqueue(&q,3);
    Enqueue(&q,8);
    Enqueue(&q,5);
    Enqueue(&q,5);
    Display(q);

}