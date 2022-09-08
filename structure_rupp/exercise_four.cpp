#include <iostream>
using namespace std;

struct Student{
    int ID, age;
    string name;
    char gender;
}vireakroth;

struct Student student[5];

void display_struct(int ID, int age, string name, char gender);

int main()
{
   display_struct(18215, 19, "VireakRoth", 'M');
}


void display_struct(int ID, int age, string name, char gender){
    cout << "\nDisplaying Information." << endl;
    cout << "-------------------------" << endl;
    student[0].ID = ID;
    student[1].age = age;
    student[2].name = name;
    student[3].gender = gender;

    cout << "ID: " <<student[0].ID << endl;
    cout <<"Age: " << student[1].age  << endl;
    cout << "Name: " << student[2].name <<endl;
    cout << "Gender: " << student[3].gender;
}