#include<iostream>
using namespace std;
class Rectangle{
    private: 
    int length;
    int breadth;
    public:
Rectangle(int l,int b){
    length = l;
    breadth = b;

    }
int area(){
    return length*breadth;
}
int perimeter(){
    int p = 2*(length+breadth);
    return p;
}
};
int main(){
    int l,b;
    cout<<"Enter length  : "<<endl;
    cin>>l;
    cout<<"Enter Breadth : "<<endl;
    cin>>b;

    class Rectangle r = {l,b};
    int ar = r.area();
    int per = r.perimeter();
    cout<<"using class area : "<<ar<<endl<<"using class perimeter : "<<per<<endl;
}

