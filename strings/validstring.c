#include<stdio.h>
int valid(char*name){

    for(int i = 0 ;i!='\0';i++){
          if(!(name[i]>=65&&name<=97)&&!(name[i]>=97&&name[i]<=122)&&!(name[i]>=48&&name<=57)){
            return 0;
          }
          return 1;
    }
}
int main(){
    char *name;
    
    name = "Kamil is king";
    int v = valid(name);
    if(v==0)
        printf("Invalid name");
    printf("Name : %s ",name);

}