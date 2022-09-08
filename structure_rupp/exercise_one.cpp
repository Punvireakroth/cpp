#include <iostream>
using namespace std;

struct Student{
    int ID, age;
    string name;
    char gender;
}vireakroth;


void display_struct();

int main()
{
   display_struct();
}


void display_struct(){
    cout << "\nInput information" << endl;
    cout << "Name: "<<endl;
    cin >> vireakroth.name;
    cout << "ID: "<<endl;
    cin >> vireakroth.ID;
    cout << "Age: "<<endl;
    cin >> vireakroth.age;
    cout << "gender: "<<endl;
    cin >> vireakroth.gender;
    cout << "\nDisplaying Information." << endl;
    cout << "-------------------------" << endl;


    cout << "ID: " <<vireakroth.name << endl;
    cout <<"Age: " << vireakroth.age << endl;
    cout << "Name: " << vireakroth.ID <<endl;
    cout << "Gender: " << vireakroth.gender;
}