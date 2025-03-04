#include<stdio.h>
void reverse(char name[],int start,int end){
    int i;
    int j;
    for( i = 0 ;name[i]!='\0';i++){
    }
    i-=1;
    for(j=0;j<i;j++,i--){
        char temp = name[i];
        name[i]=name[j];
        name[j]=temp;
    
    }
    
}
int main(){
    char name[]="KamilKabiri";
    int start = 0;
    int end = 10;
    reverse(name,start,end);
    printf("Reversed name is : %s",name);
}