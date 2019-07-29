//
// Created by Ronald on 29-7-2019.
//

#include <iostream>
#include <string>
#include <vector>
#include <user_interface.h>
using std::string;
using namespace std;

string user_input();
void draw_matrix(int row,int column , int size);

string user_input() {
    //this function handles the user input for matrix manipulations and returns the matrix after the operation
    /*
     * x for multiplication
     * s for swapping
     * sub for subtraction
     * add for addition
     * div for division
     *
    cin >> inp;
    cout<<inp<<"\n";
    cout<<"Thank you";
*/

}

void draw_matrix(vector<vector<double> > A, vector<double> B , int size){

    for (int j = 0; j <size ; ++j) {
        cout<<" ___ ";
        if(j==size-1)
        {
            cout<<"\n";
        }
    }

    for (int k = 0; k <size ; ++k) {


        for (int i = 0; i < size; ++i) {
            cout << "| " << A[i][k] << " ";
            if (i == size - 1) {
                cout << "|";
            }
        }
        cout<<"\n";
    }

    for (int j = 0; j <size ; ++j) {
        cout<<" ___ ";
        if(j==size-1)
        {
            cout<<"\n";
        }
    }
}




