#include <iostream>
using namespace std;

struct Student{
    int ID, age;
    string name;
    char gender;
}vireakroth;

int main()
{
    Student vireakroth = {18215, 19, "VireakRoth", 'M'};
    cout<<"ID: "<< vireakroth.ID<<" Name: "<<" Gender: "<<vireakroth.gender<<" Name: "<<vireakroth.name<<" Age: "<<vireakroth.age<<endl;
}