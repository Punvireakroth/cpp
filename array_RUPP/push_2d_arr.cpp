#include <iostream>
using namespace std;
void insert_one_D();


int main (){
   insert_one_D(); 
}

// Insert one D array 
void insert_one_D()
{
    int l = 0;
    int student_M3[3] = {};
    int new_list[3][3] = {};
    int list;
    int num = 0;
    int i, j;
    int display_list[] = {};
    do 
    {
        cout << "Row " << l + 1 << endl;
        for (int i = 0; i <= 2; i++)
        {
            cout << "Number: ";
            cin >> num;
            list = student_M3[i] = num;
            for (j = 0; j <= 0 ; j++)
            {
                new_list[i][j] = list;  
            } 
        }

        for(i=0;i<=2;i++)
	    {
	  	    for(j=0;j<=2;j++)
	  	    {
	  		    cout<<"\t"<<new_list[i][j];
		    }
		cout<<endl;
	    } 
        
        l++;
    }while (l < 3);
    // for (int m = 0; m <= 2; m++)
    //     {
    //         for (int k = 0; k<=2; k++)
    //         {
    //             cout << new_list[k] << " ";
    //         }  
    //         cout << endl;
    //     }
    
}
// Insert 2D array

// void insert_two_D()
// {
//     for (int l = 0; l<=2;l++)
//     {
//         cout << "Row " << l + 1 << endl; 
//         insert_one_D();
//     }
// }