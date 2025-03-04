#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
struct Stack{
    int size;
    int top;
    struct Node**S;
};
void createStack(struct Stack*st,int size){
    st->size=size;
    st->top = -1;
    st->S=(struct Node**)malloc(sizeof(struct Node*));
}
void push(struct Stack*st,struct Node*x){
    if(st->top==st->size-1)
        printf("\nStack Overflow\n");
    else{
        st->top++;
        st->S[st->top]=x;
    }
}
struct Node*pop(struct Stack *st){
    struct Node*x=NULL;
    if(st->top==-1){
        printf("\nStack Underflow");
    }
    else{
        x = st->S[st->top--];
    }
    return x;
}
int StackisEmpty(struct Stack st){
    if(st.top==-1)
        return 1;
    return 0;
}
int StackisFull(struct Stack st){
    return st.top==st.size-1;
}
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
void Treecreate(){
    struct Node*t,*p;
    struct Queue q;
    int x;
    qcreate(&q,100);
    printf("Enter the root node : ");
    scanf("%d",&x);
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter the value of left child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter the value of right child of %d : ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node*)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild =t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }

    }
}

void preorder(struct Node*p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct Node*p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}  
void postorder(struct Node*p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    } 
}
void preiterative(struct Node*p){
    struct Stack st;
    createStack(&st,100);
    while(p!=NULL||!StackisEmpty(st)){
        if(p!=NULL){
            printf("%d ",p->data);
            push(&st,p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            p = p->rchild;
        }
    }
}
void inorderiterative(struct Node*p){
    struct Stack st;
    createStack(&st,100);
    while(p!=NULL||!StackisEmpty(st)){
        if(p!=NULL){
            push(&st,p);
            p = p->lchild;
        }
        else{
            p = pop(&st);
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
} 
void postorderiterative(struct Node*p){
    struct Stack st;
    createStack(&st,100);
    struct Node*lastvisitednode=NULL;
    struct Node*temp=NULL;
    while(p!=NULL||!StackisEmpty(st)){
        if(p!=NULL){
            push(&st,p);
            p = p->lchild;
        }
        else{
            temp = st.S[st.top];
            if(temp->rchild!=NULL&&lastvisitednode!=temp->rchild)//checking if the right node exists and hasn't been visited yet
            {
                p = temp->rchild;
            }
            else{
                printf("%d ",temp->data); 
                lastvisitednode=pop(&st);//pop the node and mark it as visited
                p = NULL;
            }
        }
    }
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
int countNodes(struct Node* root) {
    int x,y;
    if(root){
        return countNodes(root->lchild)+countNodes(root->rchild)+1;
    }
    else return 0;
}
int height(struct Node*p){
    int x ,y;
    if(p!=NULL){
    x = height(p->lchild);
    y = height(p->rchild);
    return (x>y)?x:y+1;
    }
    return 0;
}
int leafnodes(struct Node*p){
    int x ,y;
    if(p!=NULL){
    x = height(p->lchild);
    y = height(p->rchild);
    if (p->lchild==NULL&& p->rchild==NULL)return x+y+1;
    return x+y;
    }
    return 0; 
}
int NwD2(struct Node*p){
    int x,y;
    if(p==NULL)return 0;
    else{
        x = NwD2(p->lchild);
        y = NwD2(p->rchild);
        if(p->lchild&&p->rchild){return x+y+1;}
        else{return x+y;}
    }
}
int NwD2or1(struct Node*p){
    int x,y;
    if(p==NULL)return 0;
    else{
        x = NwD2or1(p->lchild);
        y = NwD2or1(p->rchild);
        if(p->lchild||p->rchild){return x+y+1;}
        else{return x+y;}
    }
}
int NwD1(struct Node*p){
    int x,y;
    if(p!=NULL){
       x = NwD1(p->lchild); 
       y = NwD1(p->rchild);
       if((p->lchild!=NULL)^(p->rchild!=NULL)){
        return x+y+1;
        }
        return x+y;
    }
    return 0;
}
int main(){
    Treecreate();
    printf("\nRecursive Preorder : ");
    preorder(root);
    printf("\nIterative Preorder : ");
    preiterative(root);
    printf("\nRecursive Inorder : ");
    inorder(root);
    printf("\nIterative Inorder : ");
    inorderiterative(root);
    printf("\nRecursive Postorder : ");
    postorder(root);
    printf("\nIterative Postorder : ");
    postorderiterative(root);
    printf("\nLevel Order : ");
    levelorder(root);
    printf("\nThe number of nodes with degree 2 are : %d",NwD2(root));
    printf("\nThe nodes with degree 1 are : %d",NwD1(root));
    printf("\nThe Nodes in the tree are : %d",countNodes(root));
    printf("\nThe height of the tree is : %d",height(root));
    printf("\nThe number of leaf nodes is : %d\n",leafnodes(root));
}