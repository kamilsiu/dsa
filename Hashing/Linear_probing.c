#include<stdio.h>
#define Size 10
int hash(int key){
    return key%Size;
}
int probe(int H[],int key){
    int index = hash(key);
    int i = 0;
    while(H[(index+i)%Size]!=0)
        i++;
    return (index+i)%Size;
}
int search(int H[],int key){
    int index = hash(key);
    int i = 0;
    while(H[(index+i)%Size]!=key){
        i++;
    }
    return (index+i)%Size;
}
void insert(int H[],int key){
    int index = hash(key);
    if(H[index]!=0)
        index = probe(H,key);
    H[index] = key;
}
int main(){
    int H[10] = {0};
    insert(H,25);
    insert(H,20);
    insert(H,30);
    int s = (search(H,30));
    printf(" %d ",s);
}