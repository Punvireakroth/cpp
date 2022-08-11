#include <iostream>

int main (){
    int x[5] = {2,3,4,5,8};
    int y[5] = {5,8,2,3,1};

    int z[5];
    for (int i; i <= 4; i++)
    {
        z[i] = x[i] + y[i];
        std::cout << z[i];
    }
}

