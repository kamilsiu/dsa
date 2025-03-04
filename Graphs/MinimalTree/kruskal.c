#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define I INT_MAX
int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
                {2,6,3,7,4,5,7,6,7},
                {25,5,12,10,8,16,14,20,18}};
int included[9]={0};
int t[2][6];
int find(int u){
    int x = u;
    while(set[x]>0){
        x = set[x];
    }
    return x;
}
void Myunion(int u , int v){
    if(set[u]<set[v]){
        set[u]+=set[v];
        set[v] = u;
    }
    else{
        set[v]+=set[u];
        set[u] = v;
    }
}
void kruskal(){
    int i , j , min , k , u , v , e = 9, n = 7;
    i = 0;
    while(i<n-1){
        min = I;
        for(j = 0;j<e;j++){
            if(included[j]==0&&edges[2][j]<min){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if(find(u)!=find(v)){
            t[0][i] = u; 
            t[1][i] = v;
            Myunion(find(u),find(v));
            i++;
        }
        included[k] = 1;
    }
}
int main(){
    kruskal();
    for(int i = 0;i<6;i++){
        printf("(%d , %d)\n",t[0][i],t[1][i]);
    }
}