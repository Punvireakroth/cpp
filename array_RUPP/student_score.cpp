#include <iostream>
using namespace std;

int i, j;
int main()
{
    string student_subject_arr[] = {};
    int student_score[] = {};
    string student_subject;
    int student_score;
    string new_list[] = {};
    // Getting subject input from user
    int subject;
    int score;

    cout << "How many subjects did you take" << endl;
    cin >> subject;

    cout << "Enter the score respectively" << endl;
    cin >> score;

    // Var list is for store one value after each loop
    string list;
    for(i = 0; i < subject; i++)
    {
        // Get and push subject 
        cout << "Enter subjects: ";   
        cin >> student_subject;
        list = student_subject_arr[i] = student_subject;

        for (j = 0; j <=0; j++){
            new_list[i] = list;
        }
    }
    
}