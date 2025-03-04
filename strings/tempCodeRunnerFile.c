#include<stdio.h>
void swap(char *a,char*b){
    char temp;
    temp = *a;
    *a=*b;
    *b=temp;
}
void permutations(char s[],int l,int h){
    if(l==h){
        printf("%s ",s);
    }
    else{
        for(int i = l;i<=h;i++){
            swap(&s[l],&s[i]);
            permutations(s,l+l,h);
            swap(&s[l],&s[i]);
        }
    }

}
int main(){
    char s[] = "ABX";
    int i;
    for( i=0;s[i]!='\0';i++);
    permutations(s,0,i-1);
    

}