#include<stdio.h>
#include<stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = 0;  // Initialize front and rear to 0
    q->Q = (int*)malloc(sizeof(int) * q->size);
}

int isFull(struct Queue *q) {
    return (q->rear == q->size - 1);
}

int isEmpty(struct Queue *q) {
    return (q->front == q->rear);
}

void EnqueueatFront(struct Queue *q, int x) {
    if (q->front == 0) {  // Prevent front from going below 0
        printf("No space at front\n");
    } else {
        q->Q[--q->front] = x;
    }
}

void EnqueueatRear(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue Overflow\n");
    } else {
        q->Q[q->rear++] = x;
    }
}

int DequeueatFront(struct Queue *q) {
    int x = -1;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        x = q->Q[q->front++];
    }
    return x;
}

int DequeueatRear(struct Queue *q) {
    int x = -1;
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        x = q->Q[--q->rear];
    }
    return x;
}

void Display(struct Queue q) {
    for (int i = q.front; i < q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    Create(&q,5);
    EnqueueatRear(&q,10);
    EnqueueatRear(&q,20);
    EnqueueatRear(&q,30);
    EnqueueatRear(&q,40);
    EnqueueatRear(&q,50);

    printf("Deleted Element is : %d\n",DequeueatFront(&q));
    printf("Deleted Element is : %d\n",DequeueatFront(&q));
    printf("Deleted Element is : %d\n",DequeueatFront(&q));
    EnqueueatFront(&q,454);
    EnqueueatFront(&q,44);
    EnqueueatFront(&q,4);
    EnqueueatFront(&q,4);
    EnqueueatFront(&q,4);
    Display(q);
}
