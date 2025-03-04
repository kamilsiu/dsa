#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node{
    int coeff;
    int exp;
    struct Node*next;
}*poly,*poly2;
void create(){
    struct Node*last,*t=NULL;
    int num;
    printf("Enter the number of terms : ");
    scanf("%d",&num);
    printf("Enter the each term with coeff and exponent : ");
    for(int i = 0 ;i<num;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d%d",&t->coeff,&t->exp);
        t->next=NULL;
        if(poly==NULL){
            poly=last=t;
        }
        last->next=t;
        last=t;
    }
}
long eval(struct Node*p,int x){
    long val = 0;
    while(p){
        val=val + p->coeff*pow(x,p->exp);
        p = p->next;
    }
    return val;
}
void Display(struct Node*p){
    while(p){
        printf("%dx^%d + ",p->coeff,p->exp);
        p = p->next;
    }
}
int main(){
    create();
    long x = eval(poly,1);
    printf("The value of this poly is : %ld\n",x);
    Display(poly);


}