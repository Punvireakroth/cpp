#include <iostream>
 
using namespace std;

// Base class
class Name {
   public:
      void setFirst(string f) {
         firstName = f;
      }
      void setLast(string l) {
         lastName = l;
      }
      
   protected:
      string firstName;
      string lastName;
};

// Derived class
class Uchiha: public Name {
   public:
      string displayName() {
         return (firstName + " " + lastName); 
      }
};

int main(void) {
   Uchiha clan;
 
   clan.setFirst("Levi");
   clan.setLast("Uchiha");

   // Print the name of the object.
   cout << "You are: " << clan.displayName() << endl;

   return 0;
}