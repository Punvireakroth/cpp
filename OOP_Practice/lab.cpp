
#include <iostream>
// #include "cal_Rec.hpp"
using namespace std;

class Lab {
    public:
        double length;
        double width;
    
    void set_value(){
        cout << "--------------------------------------" << endl;
        cout << "Input Length: ";
        cin >> length;
        cout << "Input Width: ";
        cin >> width;
        cout << "--------------------------------------" << endl;
    }
    double cal_area(){
        return length * width;
    }
};

int main() {
    Lab cal_rec;
    cal_rec.set_value();

    cout << "The area is " << cal_rec.cal_area() << endl;
    return 0;
}