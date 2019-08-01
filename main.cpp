#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // can probably be removed later; currently only used for set_fixed_vectors()
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

// difficulty level

short difficulty;

// system dimensions

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

// parses string and adds to container (usually vector) inspired from: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
template<typename Container>
    void string_parse(std::string sep, std::string string, Container &container){
        size_t counter = 0;
        std::string characters;
        try{
        while ((counter = string.find(sep)) != std::string::npos){
            characters = string.substr(0, counter);
            container.push_back(stod(characters));
            string.erase(0, counter + sep.length());
            
        }   container.push_back(stod(string));
        }   catch (const std::exception &e) {std::cout << "Error. " << std::endl; std::cout << "Something was wrong with your input. Try again" << std::endl; STATE = "TRANS";}
    }


// asking for input and working with gien user input
void operation(){
    std::cout << "Which operation do you want to perform?" << std::endl;
    std::cout << "(s)wap" << ((difficulty >= 1) ? (" - (a)dd - (su)btract") : ("")) << ((difficulty == 2) ? (" - (m)ultiplicate - (d)ivide") : ("")) << "   | [(e)xit]" << std::endl;
    std::string input;
    std::string op;
    try { std::cin >> input; }
    catch (const std::exception &e) {std::cout << "Error. " << std::endl; std::cout << "Something was wrong with your input. Try again" << std::endl; nSTATE = "OPERATIONS"; STATE = "TRANS";}
    
    if (input == "s"){

        std::cout << "swapping ROW_A and ROW_B [Input: ROWA,ROWB]" << std::endl;
        std::cin >> op;
        std::vector<double> order;
        string_parse(",", op, order);

        machine.rows_swap(a, order); machine.rows_swap(b, order);

        nSTATE = "DRAW";
        STATE = "TRANS";
    } else if (input == "a"){
        if (difficulty>=1){
            std::cout << "adding ROW_A to ROW_B [Input: ROWB,ROWA]" << std::endl;
            std::cin >> op;
            std::vector<double> order; // TODO change so that is does not have to be re-created all the time
            string_parse(",", op, order);

            machine.rows_add(a, order); machine.rows_add(b, order);
            
            nSTATE = "DRAW";
            STATE = "TRANS";
        } else {
            std::cout << "Something was wrong with your input. Try again" << std::endl;
            nSTATE = "DRAW";
            STATE = "TRANS";
          }
    } else if (input == "su"){
        if (difficulty>=1){
            std::cout << "subtracting ROW_A from ROW_B [Input: ROWB,ROWA]" << std::endl;
            std::cin >> op;
            std::vector<double> order;
            string_parse(",", op, order);

            machine.rows_subtract(a, order); machine.rows_subtract(b, order);
            
            nSTATE = "DRAW";
            STATE = "TRANS";
        } else {
            std::cout << "Something was wrong with your input. Try again" << std::endl;
            nSTATE = "DRAW";
            STATE = "TRANS";
          }
    } else if (input == "m"){
        if (difficulty==2){
            std::cout << "multiplicating ROW with factor [Input: ROW,FACTOR]" << std::endl;
            std::cin >> op;
            std::vector<double> order;
            string_parse(",", op, order);

            machine.rows_multiplicate(a, order); machine.rows_multiplicate(b, order);
        
            nSTATE = "DRAW";
            STATE = "TRANS";
        } else {
            std::cout << "Something was wrong with your input. Try again" << std::endl;
            nSTATE = "DRAW";
            STATE = "TRANS";
          }
    } else if (input == "d"){
        if (difficulty==2){
            std::cout << "dividing ROW by divisor [Input: ROW,DIVISOR]" << std::endl;
            std::cin >> op;
            std::vector<double> order;
            string_parse(",", op, order);

            machine.rows_divide(a, order); machine.rows_divide(b, order);
        
            nSTATE = "DRAW";
            STATE = "TRANS";
        } else {
            std::cout << "Something was wrong with your input. Try again" << std::endl;
            nSTATE = "DRAW";
            STATE = "TRANS";
          }
    } else if (input == "e"){
        nSTATE = "EXIT";
        STATE = "TRANS";
    } else if (input == "p"){ //   NEEDS TO BE REMOVED LATER
        if (difficulty<2){
          difficulty++;
        }
    } else if (input == "o"){ //   NEEDS TO BE REMOVED LATER
        if (difficulty>0){
          difficulty--;
        }
    }
    
    
    else {
        std::cout << "Something was wrong with your input. Try again" << std::endl;
        nSTATE = "DRAW";
        STATE = "TRANS";
    }
}





int main(){

// STATE Machine
while (true)
{
    if (STATE == "INIT"){
    // Setting initial difficulty level
    difficulty = 0;

    // getting dimensions
    vars=2; eqs=2;
    machine.update_dimensions(eqs, vars);
    //setting fixed vectors a and b for testing
    set_fixed_vector(a,b);
    
    // Setting next State
    STATE = "DRAW";
    }
    else if (STATE == "DRAW"){
        ui.draw_matrix(a, b, eqs, vars);
        STATE = "OPERATION";
    }
    else if (STATE == "OPERATION"){
        STATE = "DRAW"; // has to be before operation() call because of exit condition
        operation();      
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

