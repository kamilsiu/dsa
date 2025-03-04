#include<iostream>
#include<stdio.h>
using namespace std;
struct Rectangle{
    int length;
    int breadth;
};
void initialise(struct Rectangle*r,int l,int b){
    r->length = l;
    r->breadth = b;

}
int area(struct Rectangle r){
    return r.length*r.breadth;
}
int perimeter(struct Rectangle r){
    int p = 2*(r.length+r.breadth);
    return p;
}
int main(){
    struct Rectangle r ={0,0};
    int l,b;
    cout<<"Enter length : ";
    cin>>l;
    cout<<"Enter Breadth : ";
    cin>>b;
    initialise(&r,l,b);
    int ar = area(r);
    int per = perimeter(r);
    cout<<"area : "<<ar<<endl<<"perimeter : "<<per<<endl;
}