#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node*lchild;
    int data;
    struct Node*rchild;
}*root=NULL;
struct Node*Rinsert(struct Node*p,int key){
    struct Node*t;
    if(p==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    else if(key<p->data) p->lchild = Rinsert(p->lchild,key);
    else if(key>p->data) p->rchild = Rinsert(p->rchild,key);
    return p;
} 
void insert(int key){
    struct Node*p=root;
    struct Node*r=NULL,*t;
    if(root==NULL){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        root = t;
        return;
    }
    while(p!=NULL){
        r = p;
        if(key<p->data){
            p = p->lchild;
        }
        else if(key>p->data){
            p = p->rchild;
        }
        else return ;
    }
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild=t->rchild=NULL;
    if(key<r->data)r->lchild=t;
    else r->rchild=t;
}
int Height(struct Node*p){
    int x,y;
    if(p==NULL)return 0;
    if(p){
        x = Height(p->lchild);
        y = Height(p->rchild);
    }
    return ((x>y)?x:y)+1;
}
struct Node*Inpre(struct Node*p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}
struct Node*Insucc(struct Node*p){
    while(p&&p->lchild){
        p = p->lchild;
    }
    return p;
}
struct Node*Delete(struct Node*p,int key){
    struct Node*q;
    if(p==NULL)return NULL;
    if(p->lchild==NULL&&p->rchild==NULL){
        if(p==root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    else if(key < p->data){
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild = Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q = Inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data); 
        }
        else{
            q = Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data); 
        }
    }
    return p;
}
struct Node* Search(int key){
    struct Node*p=root;
    while(p){
        if(key==p->data)return p;
        else if(key<p->data)p = p->lchild;
        else if (key>p->data) p = p->rchild;
    }
    return NULL;
}
struct Node*Rsearch(struct Node*p,int key){
    if(p){
        if(key==p->data) return p;
        else if(key<p->data)return Rsearch(p->lchild,key);
        else return  Rsearch(p->rchild,key);
    }
    return NULL;
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
int main(){
    struct Node*temp;
    insert(10);
    insert(5);
    insert(20);
    insert(40);
    insert(70);
//    Delete(root,10);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    
    temp=Rsearch(root,20);
    if(temp!=NULL){
        printf("\nElement %d is found ",temp->data);
    }
    else{
        printf("\nElement Not found ");
}
}
