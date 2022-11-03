// #include <iostream>
// using namespace std;

// class Lab{
//     private:
//         double area;
//     friend class friend_Lab;
// };


// class friend_Lab{
//     public:
//         void display() {
//             Lab objLab;
//             cout << "Inter the Area: ";
//             cin >> objLab.area;
//             cout << "The Area is = " << objLab.area;
//         }   
// };



// int main() {
//     friend_Lab obj_friend_lab;
//     obj_friend_lab.display();
//     return 0;
// }




#include <iostream>
using namespace std;

class Lab{
    private:
        int area;
    public:
        friend float set_value();
        float set_value(Lab Room306){
        Room306.area = 100;
}

};
int main(){
    Lab Room306;
    cout << Room306.area;
}