#include <iostream>
 
using namespace std;

// Base class
class School {
    public:
        string strSchoolName;
    private:
        string strAddress;
    // Property
    public:
      void setAdress(string a) {
         strAddress = a;
      }
      void getHeight() {
         return strAddress;
      }
    // Constructor 
    School(string n, string a) { 
        strSchoolName = n;
        strAddress = a 
    }
}; // end of the base class

// Derived class
class Student: public School {
    public:
        string strStudentName;
    private:
        float fltSchoolFees;
    // Property
    public:
      void setSchoolFees(string f) {
         fltSchoolFees = f;
      }
      void getSchoolFees() {
         return fltSchoolFees;
      }
    
    //Constructor: We must pass 2 parameters schoolname and address to the constructor of the base class
    School(string studentname, float schoolfees, string schoolname, string address) : base(schoolname,address) { 
        strStudentName = studentname;
        fltSchoolFees = schoolfees; 
    }
};
