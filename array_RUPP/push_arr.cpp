#include <iostream>
using namespace std;

int main (){
    string student_M3[3] = {};
    string new_list[] = {};
    string list;
    string name = "";
    for (int i = 0; i <= 2; i++)
    {
        cout << "Name: ";
        cin >> name;
        list = student_M3[i] = name;
        for (int j = 0; j <= 0 ; j++){
            new_list[i] = list;
        } 
    }
    for (int k = 0; k <= 2; k++)
    {
        cout << new_list[k] << " ";
    }
}

