#include <iostream>
using namespace std;
void insert_one_D();
int user_input();

    int l = 0;
    int student_M3[3] = {};
    int new_list[3] = {};
    int list;
    int num = 0;
    int i, j, k;
    int display_list[3] = {};

int main (){
    user_input();
}


// user input 
int user_input(){
    do 
    {
        cout << "\nRow " << l + 1 << endl;
        for (int i = 0; i <= 2; i++)
        {
            cout << "Number: ";
            cin >> num;
            list = student_M3[i] = num;
            for (j = 0; j <= 0 ; j++)
            {
                new_list[i] = list;   
            } 
            for (k = 0; k<=2; k++){
                display_list[k] = new_list[i];  
            }
	  	    cout<<"\t"<<display_list[i] << " ";

        }
        l++;
    }while (l < 3);
    
}

// Insert one D array 
void insert_one_D()
{
    do 
    {  
        for (int i = 0; i <= 2; i++)
        {
            list = student_M3[i] = num;
            for (j = 0; j <= 0 ; j++)
            {
                new_list[i] = list;  
            } 
            display_list[i] = new_list[i];
        }
        l++;
        
    }while (l < 3);

    for(i=0;i<=2;i++)
	{
	  	cout<<"\t"<<display_list[i] << " ";
	} 
        
}