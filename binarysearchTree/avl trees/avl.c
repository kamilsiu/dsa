#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    int height;
    struct Node*rchild;
}*root=NULL;
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void qcreate(struct Queue *q,int size){
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
struct Node* dequeue(struct Queue*q){
    struct Node*x=NULL;
    if(q->front==q->rear){printf("Queue is empty\n");}
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q){
    return q.front == q.rear;
}
int NodeHeight(struct Node*p){
    int hl,hr;
    hl = (p&&p->lchild)?p->lchild->height:0;
    hr = (p&&p->rchild)?p->rchild->height:0;
    return ((hl>hr)?hl:hr)+1;
}
int BalanceFactor(struct Node*p){
    int hl,hr;
    hl = (p&&p->lchild)?p->lchild->height:0;
    hr = (p&&p->rchild)?p->rchild->height:0;
    return hl-hr;
}
struct Node*llRotation(struct Node*p){
    struct Node*pl=p->lchild;
    struct Node*plr=pl->rchild;
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    if(root==p)root = pl;
    return pl;
}
struct Node*lrRotation(struct Node*p){
    struct Node*pl = p->lchild;
    struct Node*plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;
    if(root==p)root = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    return plr;
}
struct Node*rrRotation(struct Node*p){
    struct Node*pr = p->rchild;
    struct Node*prl = pr->lchild;
    p->rchild = prl;
    pr->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root == p)root = pr;
    return pr;
}
struct Node*rlRotation(struct Node*p){
    struct Node*pr = p->rchild;
    struct Node*prl = pr->lchild;
    
//Performing right rotation first on pr
    pr->lchild = prl->rchild;
    prl->rchild = pr;
//Performing left rotation on p
    p->rchild = prl->lchild;
    prl->lchild = p;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);;
    prl->height = NodeHeight(prl);
    if(root == p)root = prl;
    return prl; 
}
struct Node*Rinsert(struct Node*p,int key){
    struct Node*t=NULL;
    if(p == NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->height = 1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(p->data<key){
        p->rchild = Rinsert(p->rchild,key);
    }
    else if(p->data>key){
        p->lchild=Rinsert(p->lchild,key);
    }
    p->height = NodeHeight(p);
 
    if(BalanceFactor(p)==2&&BalanceFactor(p->lchild)==1){
        return llRotation(p);
    }
    else if(BalanceFactor(p)==-2 &&BalanceFactor(p->rchild)==-1){
        return rrRotation(p);
    }
    else if(BalanceFactor(p)==2 &&BalanceFactor(p->lchild)==-1){
        return lrRotation(p);
    }
    else if (BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1){
        return rlRotation(p);
    }

    return p;
}
struct Node*Delete(struct Node*p,int key){

}
void levelorder(struct Node*p){
    struct Queue q;
    qcreate(&q,100);
    printf("%d ",p->data);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p->lchild){
            printf("%d ",p->lchild->data);
            enqueue(&q,p->lchild);
        }
        if(p->rchild){
            printf("%d ",p->rchild->data);
            enqueue(&q,p->rchild);
        }
    }
}
int main(){
    root = Rinsert(root, 30);
    levelorder(root);
    printf("\n");

    Rinsert(root, 10);
    levelorder(root);  
    printf("\n");

    Rinsert(root, 40);
    levelorder(root); 
    printf("\n");

    Rinsert(root, 35);
    levelorder(root); 
    printf("\n");

    Rinsert(root, 32);
    levelorder(root); 
    printf("\n");

    Rinsert(root, 37);
    levelorder(root);  
    printf("\n");

    return 0;
}