#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node*next;
}*top=NULL;
 
void Push(char x){
    struct Node*t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)printf("Stack is Full\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop(){
    struct Node*p;
    char x = -1;
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
char peek(int pos){
    struct Node*p=top;
    for(int i=0;i<pos-1&&p;i++){
        p = p->next;
    }
    if(p!=NULL)return p->data;
    else return -1;
}
int isBalance(char*exp){
    int i ;
    for(i = 0 ;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')Push(exp[i]);
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(top==NULL)return 0;
            pop();   
        }
    }
    if(top==NULL)return 1;
    else return 0;
}
int main(){
    char *exp = "{()[]";
    printf(" %d ",isBalance(exp));

}