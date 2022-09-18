#include <iostream>
using namespace std;

int i, j;
int main()
{
    string student_subject_arr[] = {};
    int student_score_arr[] = {};
    string student_subject;
    int student_score;
    string new_list_subject[] = {};
    string new_list_score[] = {};

    // Getting subject input from user
    int subject;

    cout << "How many subjects did you take" << endl;
    cin >> subject;

    

    // Var list is for store one value after each loop
    string subject_list;
    int score_list;
    for(i = 0; i < subject; i++)
    {
        // Get and push subject 
        cout << "Enter subjects: ";   
        cin >> student_subject;
        subject_list = student_subject_arr[i] = student_subject;

        for (j = 0; j <=0; j++){
            new_list_subject[i] = subject_list;
        }

        cout << "Enter Score: ";   
        cin >> student_score;
        score_list = student_score_arr[i] = student_score;

        for (j = 0; j <=0; j++){
            new_list_score[i] = score_list;
        } 
    }
    
}