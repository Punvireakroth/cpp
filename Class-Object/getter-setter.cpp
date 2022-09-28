#include <iostream>
using namespace std;

class Student {
  private:
    // Private attribute
    int score;

  public:
    // Setter
    void setScore(int s) {
      score = s;
    }
    // Getter
    int getScore() {
      return score;
    }
};

int main() {
  Student myObj;
  myObj.setScore(50000);
  cout << myObj.getScore();
  return 0;
}