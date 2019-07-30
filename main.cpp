#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // can probably be removed later; currently only used for set_fixed_vectors()
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

int vars = 1; int eqs = 1;

//creating ui object
UI ui;
//creating linear equation machine object
les machine(eqs,vars);

//declaring (and initializing states for state machine)
string STATE = "INIT"; string nSTATE;

vector<double> b;
vector < vector<double>> a(2); //2-D A matrix v[i][j] where i is the column and j is the row






//###################
void set_fixed_vector(vector <vector<double>> &v1, vector<double> &v2){
    //lets take vars and eqs 2
    int vars = 2; int eqs = 2;

    for (int i=0; i<vars; i++){
        for (int j=0; j<eqs; j++){
            (v1[i]).push_back(double((rand() % 10) + 1)); //random integer between 1 and 10, (rand() % 10) + 1
        }
    }

    for (int j=0; j<eqs; j++){
        v2.push_back(double((rand() % 10) + 1));
    }
}
//###################s





int main(){

// STATE Machine
while (true)
{
    if (STATE == "INIT"){
    
    // getting dimensions
    vars=2; eqs=2;
    machine.update_dimensions(eqs, vars);
    //setting fixed vectors a and b for testing
    set_fixed_vector(a,b);
    
    // Setting next State
    STATE = "DRAW";
    }
    else if (STATE == "DRAW"){
        ui.draw_matrix(a, b, 2);
        STATE = "SWAPNDRAw";
    }
    else if (STATE == "SWAPNDRAw"){
        vector<double> order;
        order.push_back(1); order.push_back(2);
        machine.rows_swap(a, order);
        machine.rows_swap(b, order);
        ui.draw_matrix(a, b, 2);
        STATE = "EXIT";
    }
    else if (STATE == "TRANS"){
        STATE = nSTATE;
    }
    else if (STATE == "EXIT"){
        system("pause");
        break;
    }

}



return 0; }

