#include<stdio.h>
#define Size 10
int hash(int key){
    return key%Size;
}
int probe(int H[],int key){
    int index = hash(key);
    int i = 0;
    while(H[(index+i*i)%Size]!=0)
        i++;
    return (index+i*i)%Size;
}
int search(int H[],int key){
    int index = hash(key);
    int i = 0;
    while(H[(index+i*i)%Size]!=key){ 
        i++;
    }
    return (index+i*i)%Size;
}
void insert(int H[],int key){
    int index = hash(key);
    if(H[index]!=0)
        index = probe(H,key);
    H[index] = key;
}
int main(){
    int H[10] = {0};
    insert(H,23);
    insert(H,43);
    insert(H,13);
    int s = (search(H,13));
    printf(" %d ",s);
}