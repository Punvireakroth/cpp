/*
* ITE M3 
* Team 4 
* VireakRoth | Senglay | Siphai | Thary | Ny SopheakTra 
*/

#include <iostream>

using namespace std;

// a ) Write a class 
class House
{
    // field
    public:
        string strType;
    private:
        string strAddress;
        float fltPrice;
    // b ) Write a getter and setter that can read and write to strAddress
    public:
    // Setter
    void setAddress(string a) {
      strAddress = a;
    }
    // Getter
    string getAddress() {
      return strAddress;
    }

    //c Write a property that can read and write to fltPrice 
    public:
    // Setter
    void setPrice(float b) {
      (fltPrice >= 0) ? fltPrice = b : fltPrice = 0; 
    }
    // Getter
    float getPrice() {
      return fltPrice;
    }
    
};

int main(){
    // d) Declare an object
    House hObj;

    string address;
    float price;

    // e ) Prompt user to enter the type and address 
    cout<<"Enter Type"<<endl;
    cin >> hObj.strType;

    cout<<"Enter Address"<<endl;
    cin >> address;
    hObj.setAddress(address);

    cout<<"Enter Price"<<endl;
    cin>>price;
    hObj.setPrice(price);

    // f) Display type and address of the object

    cout << "Type = "<< hObj.strType << ":: Address = " << hObj.getAddress() << ":: Price = " <<  hObj.getPrice() <<endl;
}