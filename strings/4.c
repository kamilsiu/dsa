#include<stdio.h>
int main(){
    int ccount=0;
    int vcount = 0;
    int word = 1;
    char A[30] = "Kamil Nissar Kabiri";
    for(int i = 0;A[i]!='\0';i++){
        if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='U'){
            vcount++;
        }
        else if(A[i]>=65&&A[i]<=90||A[i]>=97&&A[i]<=122){
            ccount++;
        }
        else if(A[i]==' '&&A[i-1]!=' '){
            word ++;
        }
    }
    printf("\n number of vowels is : %d \n number of consonants : %d\n number of words are : %d\n",vcount,ccount,word);
}