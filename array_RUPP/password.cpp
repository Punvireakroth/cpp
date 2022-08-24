#include <iostream>
#include<string.h>

using namespace std;

void checkpw(string &password) {
  int n = password.length();
  bool hasLower = false, hasUpper = false, hasDigit = false;
  for (int i = 0; i < n; i++) {
    if (islower(password[i]))
      hasLower = true;
    if (isupper(password[i]))
      hasUpper = true;
    if (isdigit(password[i]))
      hasDigit = true;
    if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$'){
        cout << "Invalid, This password consist of the special character" << endl;
    }
  }
  // Displaying the strength of password

  cout << "Strength of password you have entered is:-";

  if (hasUpper && hasDigit && hasLower &&
      (n = 8)) // considering a strong must be of length 8

    cout << "This password is Strong" << endl;
  else if ((n < 8 || n > 8)) // More than 8 or less than 8 characters
    cout << "Invalid, This password has more or less than 8 characters" << endl;

  else if (hasLower && hasUpper &&
           (n = 8)) // when at least a lower case or uppercase, BUT not digit
    cout << "Invalid, This password doesn't a digit" << endl;

  else
    cout << "Invalid, This password doesn't an upper letter" << endl;

  if (isdigit(password[0])){
     cout << "You can't have your first character as an integer";
    }

}
int main() {
  cout << "Welcome, lets check your password " << endl;
  cout << "Please enter a password which should contain :- " << endl;
  cout << " * A password must have exactly 8 characters. " << endl;
   cout << " * A password must consist of only digits and letters. " << endl;
  cout << " * A password must always start with a digit. " << endl;
  cout << " * at least one upper letter " << endl;
  string password;
  cout << "Enter password" << endl;
  getline(cin, password);
  checkpw(password);
  return 0;
}