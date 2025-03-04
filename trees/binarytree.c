#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
};
struct Node*root=NULL;
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node**)malloc(q->size*sizeof(struct Node*));
}
void enqueue(struct Queue*q,struct Node* x){
    if((q->rear+1)%q->size==q->front)printf("Queue is full\n");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node*dequeue(struct Queue*q){
    struct Node*x=NULL;
    if(q->front==q->rear){printf("Queue is empty\n");}
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q){
    int i = q.front+1;
    do{
        printf("%d ",q.Q[i]->data);
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    printf("\n");
}
int isEmpty(struct Queue q){
    if(q.rear==q.front){
        return 1;
    }
    return 0;
}
int isFull(struct Queue q){
    if((q.rear+1)%q.size==q.front)return 1;
    return 0;
}
void Treecreate(){
    struct Node*p,*t;
    int x;
    struct Queue m;
    create(&m,100);
    printf("\nEnter root value  : ");
    scanf("%d",&x);
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&m,root);
    while(!isEmpty(m)){
        p = dequeue(&m);
        printf("\nEnter left child value of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&m,t);
        }
        printf("\nEnter right child value %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&m,t);
        }
    }

}
void Preorder(struct Node*p){
    if(p){
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }

}
void Inorder(struct Node*p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node*p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void LevelOrder(struct Node*root){
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q)){
        root=dequeue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
}
int count(struct Node*root){
    if(root){
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}
int height(struct Node*root){
    int lheight , rheight = 0; 
    if(root==NULL)return 0;
    lheight = height(root->lchild);
    rheight = height(root->rchild);
    return (lheight>rheight?lheight:rheight+1);
}
int main(){
    Treecreate();
    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    LevelOrder(root);
    printf("\ncount of the number of nodes is : %d ",count(root));
    printf("height of the tree is : %d\n",height(root));
}