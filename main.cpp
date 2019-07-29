#include <iostream>
#include <string>
#include <vector>
#include <user_interface.h>

using namespace std;
using std::string;

//Function declarations
string user_input();
void draw_matrix(vector<int> row,vector<int> column , int size);


int main(){
vector<int> row;
vector<int> column;
row[0]=1;
row[1]=2;
    //user_input();
    draw_matrix([2,2],[1,2],2);
}

