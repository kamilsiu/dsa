#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
}*front = NULL,*rear=NULL;
void Enqueue(int x){
    struct Node*t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)printf("Queue is Full\n");
    else{
    t->data=x;
    t->next=NULL;
    }
    if(front==NULL){
        front = rear = t;
    }
    else{
        rear->next=t;
        rear=t;
        rear->next=NULL;
    }
}
int Dequeue(){
    int x = -1;
    struct Node*p;
    if(front==NULL)printf("Queue is Empty\n");
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }return x;
}
int isEmpty() {
    return front == NULL;
}
void bfs(int G[][7],int start,int n){
    int i ,j;
    int visited[7]={0};
    i = start;
    printf("%d ",i);
    visited[i] = 1;
    Enqueue(i);
    while(!isEmpty()){
        i = Dequeue();
        for(j = 1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                Enqueue(j);
            }
        }
    }
}
void dfs(int G[][7],int start , int n){
    static int visited [7]={0};
    int j;
    if(visited[start]==0){
        printf("%d ",start);
        visited[start]=1;
    }
    for(j=1;j<n;j++){
        if(G[start][j]==1&&visited[j]==0){
            dfs(G,j,n);
        }
    }
}
int main(){
    int G[7][7]  = {{0,0,0,0,0,0,0},
                    {0,0,1,1,0,0,0},
                    {0,1,0,0,1,0,0},
                    {0,1,0,0,1,0,0},
                    {0,0,1,1,0,1,1},
                    {0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0} 
                    };
        printf("bfs traversal : \n");
        bfs(G,4,7); 
        printf("\ndfs traversal :\n"); 
        dfs(G,4,7);       
}