#include <iostream>
using namespace std;

// Base class
class Lab {
    public:
        double length;
        double width;
    
    public:
        void set_data (double a, double b)
        {
            width = a;
            length = b;
        }
};

// Derive class one
class Room306 : public Lab{
    // cal area one
    public: 
        double cal_area() {
            return width * length;
        }
};

// Derive class two

class Room307 : public Lab{
    // cal area two
    public:
        double cal_area(){
            return width * length;
        }
};

int main() {
    // obj one
    Room306 obj306;
    double width, length;
    cout << "--------------------------------------" << endl;
    cout << "Input Length: ";
    cin >> length;
    cout << "Input Width: ";
    cin >> width;
    cout << "--------------------------------------" << endl;
    obj306.set_data(length, width);

    cout << "The first room is = " << obj306.cal_area() << endl;

    // obj two
    cout << "--------------------------------------" << endl;
    cout << "Input Length: ";
    cin >> length;
    cout << "Input Width: ";
    cin >> width;
    cout << "--------------------------------------" << endl;
    Room307 obj307;
    obj306.set_data(length, width);

    cout << "The second room is = " << obj306.cal_area() << endl;
    cout << "--------------------------------------" << endl;
    return 0;
}