#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Stack{
    int top;
    int size;
    int *s;
};
void create (struct Stack*st){
    printf("Enter size : ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));

}
void display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d ",st.s[i]);
    
    }printf("\n"); 
}
void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top]=x;   
    }
}
int pop(struct Stack *st){
    int x= -1;
    if(st->top==-1){
        printf("Stack Underflow");
    }
    else{
        x = st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st,int pos){
    if(st.top-pos+1<0){
        printf("Invalid Position");
        return 0;
    }
    else{
        int x = 0;
        x = st.s[st.top-pos+1];
        return x;
    }
}
bool isEmpty(struct Stack st){
    if(st.top==-1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(struct Stack st){
    if(st.top==st.size-1){
        return true;
    }
    else{
        return false;
    }
}
int StackTop(struct Stack st){
    if(st.top==- 1){
        return -1;
    }
    else{
        return st.s[st.top];
    }
}
int main(){
    struct Stack st;
    create(&st);

    push(&st,10);
    push(&st,20);
    push(&st,20);
    push(&st,20);
    push(&st,20);
    pop(&st);
    printf("\nElement at the top of the stack is %d\n",StackTop(st));
    display(st);

    
}