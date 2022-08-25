#include <iostream>

using namespace std;

int main()
{
    long number = 12345;

    long* pnumber;

    pnumber = &number;

    cout<<"Number "<<number<<endl;
    cout<<"pnumber "<<*pnumber<<endl;
    cout<<"pnumber "<<pnumber<<endl;

    return 0;
}