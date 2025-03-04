#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct Term{
    int coeff;
    int exp;
};
struct Poly{
    int n;
    struct Term *t;
};
void Create(struct Poly *p){
    printf("Enter number of terms : ");
    scanf("%d",&p->n);
    p->t=(struct Term*)malloc(p->n*sizeof(struct Term));
    printf("Enter terms : \n");
    for(int i = 0 ;i<p->n;i++){
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}
void Display(struct Poly p){
    printf("Displaying  the equation : \n");
    for(int i = 0 ;i<p.n;i++){
        printf("%dx^%d",p.t[i].coeff,p.t[i].exp);
        if(i<p.n-1)printf(" + ");
    }
    printf("\n");
}
struct Poly*add(struct Poly *p1,struct Poly* p2){
    int i=0,j=0,k=0;
    struct Poly*sum = (struct Poly*)malloc(sizeof(struct Poly));
    sum->t = (struct Term*)malloc((p1->n+p2->n)*sizeof(struct Term));

    while(i <p1->n && j < p2->n){
        if(p1->t[i].exp > p2->t[j].exp){
            sum->t[k++] = p1->t[i++];
        }
        else if(p1->t[i].exp < p2->t[j].exp){
            sum->t[k++] = p2->t[j++];
        }
        else{
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;

        }
    }
    for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
    for(;j<p2->n;j++)sum->t[k++]=p2->t[j];
    sum->n=k;
    return sum;
}
int main(){
    struct Poly p1,p2,*p3;
    Create(&p1);
    Create(&p2);
    p3 = add(&p1,&p2);
    Display(*p3);

   

/*
int x;
    int sum = 0;
    for(int i = 0 ;i<p1.n;i++){
        sum = sum + p1.t[i].coeff * (int)pow(x,p1.t[i].exp);

    }
    printf("The sum of polynomials is : %d ",sum);

*/
}