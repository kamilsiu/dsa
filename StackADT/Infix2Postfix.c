#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data;
    struct Node*next;
}*top=NULL;
void push(char x){
    struct Node*t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("\nStack overflow\n");
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop(){
    struct Node*t;
    char x = -1;
    if(top==NULL)printf("\nstack underflow\n");
    else{
        t = top;
        top=top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int isOperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')return 0;
    return 1;
}
int outprecedence(char x ){
    if(x=='+'||x=='-')return 1;
    if(x=='*'||x=='/')return 3;
    if(x=='^') return 6;
    if(x=='(') return 7;
    else return 0;
}
int instackprecedence(char x){
    if(x=='+'||x=='-')return 2;
    if(x=='*'||x=='/')return 4;
    if(x=='^') return 5;
    if(x=='(') return -1; 
    else return -1;
}
char stackTop(){
    if(top)return top->data;
    return '#';
}
char *Infix2Postfix(char *infix){
    int i = 0 , j = 0 ;
    char*postfix;
    int len  = strlen(infix);
    postfix = (char * )malloc(sizeof(char)*(len+1));
    push('#');
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(infix[i]==')'){
                while(stackTop()!='('){
                    postfix[j++]=pop();
                }
                pop();
                i++;
            }
            else{
                while(instackprecedence(stackTop())>=outprecedence(infix[i])){
                    postfix[j++]=pop();
                }
                push(infix[i++]);
            }
        }
    }
    while(top&&stackTop()!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[] = "((a+b)*c)-d^e^f";
    char *x = Infix2Postfix(infix);
    printf("%s ",x);
}