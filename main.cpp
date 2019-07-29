#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

//creating linear equation machien object
les machine(1,1);

//declaring (and initializing states for state machine)
string STATE = "INIT"; string nSTATE;

vector<double> b;
vector < vector<double>> a(1); //2-D A matrix v[i][j] where i is the column and j is the row

//Function declarations

void set_fixed_vector(vector <vector<double>> &a, vector<double> &b){
    //lets take vars and eqs 2
    int vars = 2; int eqs = 2;
    for (int i=0; i<vars; i++){
        for (int j=0; j<eqs; j++){
            a[i][j] = (rand() % 10) + 1;
        }
    }
    for (int j=0; j<eqs; j++){
        b[j] = (rand() % 10) + 1;
    }


}

string user_input();
void draw_matrix(vector<int> row,vector<int> column , int size);


int main(){
set_fixed_vector(a,b);
vector<int> row;
vector<int> column;
row[0]=1;
row[1]=2;
column[0]=1;
column[1]=2;
    user_input();
//"hello"
    //draw_matrix(row,column,2);

/* 
// STATE Machine
while (true)
{
    if (STATE == "INIT"){
        //do this
        //STATE = next state
    }
    else if (STATE == ...){
        //do this
    }
    ...
    
    else if (STATE == "TRANS"){
        STATE = nSTATE;
    }
    else if (STATE == "EXIT"){
        system("pause");
        break;
    }

}

*/


return 0; }

