#include <iostream>
#include <string>
#include <vector>
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

//creating linear equation machien object
les machine(1,1);

//declaring (and initializing states for state machine)
string STATE = "INIT"; string nSTATE;
//Function declarations
string user_input();
void draw_matrix(vector<int> row,vector<int> column , int size);


int main(){
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

