#include<stdio.h>
struct Matrix{
    int A[10];
    int n; 
};
void set(struct Matrix *m,int i,int j ,int x){
    if(i==j){
        m->A[i-1]=x;
    }
}
int get(struct Matrix m,int i ,int j){
    if(i==j)
    return m.A[i-1];
return 0;

}
void display(struct Matrix m){
    for(int i = 0 ;i<m.n;i++){

    for(int j = 0 ;j<m.n;j++){
        if(i==j){
            printf(" %d",m.A[i-1]);
        }
        else{
            printf(" 0");
        }
    }
    printf("\n");
}
}
int main(){
    struct Matrix m;
    m.n=4;
    set(&m,1,1,2);
    set(&m,2,2,3);
    set(&m,3,3,4);
    set(&m,4,4,5);
    set(&m,5,5,6);
    display(m);


}