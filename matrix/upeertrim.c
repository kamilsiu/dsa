#include<stdio.h>
#include<stdlib.h>
// Low triangle matrix using row major formula
struct Matrix{
    int *A;
    int n; 
};
void set(struct Matrix *m,int i,int j ,int x){
    if(i<=j){
        m->A[j*(j-1)/2+i-1]=x;
    }
}
int get(struct Matrix m,int i ,int j){
    if(i<=j)
    return m.A[j*(j-1)/2+i-1];
return 0;

}
void display(struct Matrix m){
    for(int i = 0 ;i<m.n;i++){

    for(int j = 0;j<m.n ;j++){
        if(i<=j){
            printf(" %d",m.A[j*(j-1)/2+i-1]);
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
    int i,j,x;
    printf("Enter the dimensions : ");
    scanf("%d",&m.n);

    m.A=(int*)malloc((m.n*m.n-1)/2*sizeof(int));
    printf("enter all elements : ");
    for(i = 0 ;i<m.n;i++){
        for(j=0;j<m.n;j++){
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    printf("\n\n");
    display(m);


}