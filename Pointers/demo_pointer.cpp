#include <iostream>

using namespace std;

int main()
{
    int a=10;
    int *p = &a; // point to address a

    cout<<a<<endl;
    cout<<&a<<endl; // address of a
    cout<<p<<endl; // storing address of a
    cout<<&p<<endl; // address of p 
    cout<<*p<<endl; // p pointing on a 
    return 0;
}