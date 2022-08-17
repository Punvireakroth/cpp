#include <iostream>

using namespace std;
// Function prototype
void insert_two_d(int row, int col);

// Global Variable
int i, j;
int row, col;

int main()
{
    // Call the function
    insert_two_d(row, col);

    return 0;
}



// Function declaration 
void insert_two_d(int row, int col)
{
    cout << "How many ROW and COLUMN you want your 2D array to have? " << endl;
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> col;
    int array[row][col];
    cout << "---------------------------------------------" << endl;
    cout << "Please insert each index of 2D array as you prefer" << endl;

    for (i = 0;i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << endl << "It's row " << i + 1 <<" column " << j + 1 << " = ";
            cin >> array[i][j];
        }
        cout << "----------------------------------------";
    }
    
}