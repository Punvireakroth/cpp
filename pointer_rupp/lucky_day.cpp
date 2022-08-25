#include <iostream>

using namespace std;

int main()
{
    // Day
    const char* pday1 = "Sunday";
    const char* pday2 = "Monday";
    const char* pday3 = "Tuesday";
    const char* pday4 = "Wednesday";
    const char* pday5 = "Thursday";
    const char* pday6 = "Friday";
    const char* pday7 = "Saturday";
    const char* pmessage = "Your lucky day is: ";


    int choice = 0;
    cout << endl << "Pick a lucky day " << "Enter Number between 1 to 7: ";

    cin >> choice;
    cout << "========================================================="<<endl;
    switch (choice)
    {
    case 1:
        cout << pday1 << " It's a tough day :("<<endl;
        /* code */
        break;
    case 2:
        cout << pday2 << " It's a tough day :("<<endl;
        /* code */
        break;
    case 3:
        cout << pday3 << " It's a tough day :("<<endl;
        /* code */
        break;
    case 4:
        cout << pday4 << " It's a good day :("<<endl;
        /* code */
        break;
    case 5:
        cout << pday5 << " It's a tough day :("<<endl;
        /* code */
        break;
    case 6:
        cout << pday6 << " It's a good day :("<<endl;
        /* code */
        break;
    case 7:
        cout << pday7 << " It's a good day :) "<<endl;
        /* code */
        break;
    
    default:
        cout << "You have invalid input";
        break;
    }

    return 0;
}