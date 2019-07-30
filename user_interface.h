//
// Created by Ronald on 29-7-2019.
//

#ifndef user_interface_H
#define user_interface_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;

class UI
{


public:
UI();
~UI();

//function declarations
//void user_input();
void draw_matrix(vector<vector<double> > A, vector<double> B , int size);
void get_Dimensions(int &v, int &e);


};

#endif //CPP_PROJECT_USER_INTERFACE_H
