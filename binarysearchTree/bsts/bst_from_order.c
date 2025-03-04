#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
struct Stack{
    int top;
    int size;
    struct Node**S;
};
void createStack(struct Stack*st,int size){
    st->size=size;
    st->top = -1;
    st->S=(struct Node**)malloc(st->size*sizeof(struct Node*));
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
        return NULL;
    }
    else{
        x = st->S[st->top--];
    }
    return x;
}
void create_from_pre(int pre[],int pren){
    struct Stack st;
    struct Node*p,*t=NULL;
    int i = 0;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p = root;
    createStack(&st,100);
    while(i<pren){
        if(p->data>pre[i]){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            push(&st,p);
            p = t;
        }
        else{
            while(st.top!=-1&&pre[i]>st.S[st.top]->data){
                p = pop(&st);
            }
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            p = t;
        }
    }
}
void create_from_post(int pot[],int postn){
    struct Stack st;
    struct Node*t,*p=NULL;
    int i = postn-1;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data=pot[i--];
    root->lchild=root->rchild=NULL;
    p = root;
    createStack(&st,100);
    while(i>=0){
        if(pot[i]>p->data){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data=pot[i--];
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            push(&st,p);
            p = t;
        }
        else{
            while(st.top!=-1&&st.S[st.top]->data>pot[i]){
                p = pop(&st);
            }
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = pot[i--];
            t->lchild = t->rchild = NULL;
            p->lchild=t;
            p = t;
        }
    }
}
void inorder(struct Node*p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
int main(){
    int pre[]={30,20,10,15,25,40,50,45};
    int post[]={15,10,20,25,45,50,40,30};
    int pren = sizeof(pre)/sizeof(pre[0]);
   int postn=sizeof(post)/sizeof(post[0]);
//    create_from_pre(pre,pren);
    create_from_post(post,postn);
    printf("inorder traversal : ");
    inorder(root);
}