#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Term{
    int Coeff;
    int Exp;
};
struct Poly{
    int n;
    struct Term *t;
};
int main(){
    struct Poly p;
    int x;
    printf("Enter the number of polynomials : \n");
    scanf("%d",&p.n); 
    p.t=(struct Term*)malloc(sizeof(struct Term));

    printf("Enter the value of x : \n");
    scanf("%d",&x);

    for(int i = 0 ;i<p.n;i++){
        printf("Enter Term no. %d :",i+1);
        scanf("%d%d",&p.t[i].Coeff,&p.t[i].Exp);
    }
    int sum = 0;
    for(int i = 0 ;i<p.n;i++){
        sum = sum +p.t[i].Coeff * (int)pow(x,p.t[i].Exp);

    }
    printf("The sum of polynomials is : %d ",sum);
}