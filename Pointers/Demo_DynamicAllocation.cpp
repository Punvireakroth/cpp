#include <iostream>

using namespace std;

int main()
{
    // int *p = new int[5]; // an array of size 5 will create in heap
    // p[0]=12;
    // p[2]=14;
    // cout<< p[1] << endl;


    // // If we're stop using it
    // delete []p;
    // p = nullptr;

    // -----------------------------------------

    int *p = new int[20];
    
    delete []p;
    p = new int[40];
    


    return 0;
}