#include <iostream>

using namespace std;

// function prototype
void swap(int *a, int *b);


int main()
{
    int a, b;
    cout << "Enter number a: "<< endl;
    cin >> a;
    cout << "Enter number b: "<< endl;
    cin >> b;
    swap(&a, &b);
    cout << "\nAfter swapp your number are" << endl;
    cout << "==============================" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}


void swap(int *a, int *b)
{
    int store = *a;
    *a = *b;
    *b = store;
}