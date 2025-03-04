#include<iostream>
using namespace std;
template<class T>
class Arithematic{
private:
    T a;
    T b;
public:
    Arithematic(T num1,T num2);
    T add();
    T sub();
};
template<class T>
Arithematic<T>::Arithematic(T num1,T num2){
    this->a=num1;
    this->b=num2;
}
template<class T>
T Arithematic<T>::add(){
    T c;
    c = a+b;
    return c;
}
template<class T>
T Arithematic<T>::sub(){
    T c;
    c = a - b;
    return c;
}
int main(){
    Arithematic<char> ar = {'A','B'};
    cout<<"Addition of the two numbres : "<<(int)ar.add()<<endl;
    cout<<"Subtraction of two numbers is : "<<(int)ar.sub()<<endl;
}