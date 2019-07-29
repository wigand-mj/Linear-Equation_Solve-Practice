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
    string inp;
    cout<<"provide input\n";
    cin >> inp;
    cout<<inp<<"\n";
    cout<<"Thank you";


}

void draw_matrix(vector<int> row,vector<int> column , int size){
cout<<"jup";
    for (int i = 0; i <size ; ++i) {
        cout<<"|"<<row[i];

    }


}




