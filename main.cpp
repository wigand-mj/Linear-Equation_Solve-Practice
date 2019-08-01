#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // can probably be removed later; currently only used for set_fixed_vectors()
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

// difficulty & level

short difficulty;
short level;

// system dimensions

int vars = 1; int eqs = 1;

//creating ui object
UI ui;
//creating linear equation machine object
les machine(eqs,vars);

//declaring (and initializing states for state machine)
string STATE = "INIT"; string nSTATE;

vector<double> b;
vector < vector<double>> a(4); //2-D A matrix v[i][j] where i is the column and j is the row






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


bool isSolved (std::vector< std::vector<double>> &v1){
    bool ans = true;
    short counter = 0;
    int no_free_variables = vars-eqs;
    int free_counter = 0;

    // columns
    for (int i=0; i<vars; i++){
        for (int j=0; j<eqs; j++){

            if (v1[i][j] == 1){
                counter++;
            } else if (v1[i][j] != 1 && v1[i][j] != 0) {
                ans = false;
                break;
            }
        }
        if (counter > 1){
            ans = false;
            break;
        } counter = 0;
    }

    
    // rows
    for (int j=0; j<eqs; j++){
        for (int i=0; i<vars; i++){

            if (v1[i][j] == 1){
                counter++;
            } else if (v1[i][j] != 1 && v1[i][j] != 0) {
                ans = false;
                break;
            }
        }
        if (counter > 1){
            free_counter++;
            break;
        } counter = 0;
        if (free_counter > no_free_variables){
            ans = false;
            break;
        }
    }

    return ans;
}

// asking for input and working with gien user input
void operation(){
    std::cout << "Which operation do you want to perform?" << std::endl;
    std::cout << "(s)wap" << ((difficulty >= 1) ? (" - (a)dd - (su)btract") : ("")) << ((difficulty == 2) ? (" - (m)ultiplicate - (d)ivide") : ("")) << "   | [(e)xit] | [try again with (n)ew problem]" << std::endl;
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
    } else if (input == "n"){
        nSTATE = "LOAD";
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
    // Setting initial difficulty  & level
    difficulty = 0;
    level = 1;

    // getting dimensions
    vars=2; eqs=2;
    machine.update_dimensions(eqs, vars);
    //setting fixed vectors a and b for testing
    set_fixed_vector(a,b);
    
    // Setting next State
    STATE = "WELCOME";
    } 
    else if (STATE == "WELCOME"){
        std::cout << "------" << std::endl;
        std::cout << "Welcome to the Linear Equation System Solving Practice!" << std::endl;
        std::cout << "You will start at level 1 with only limited tools for solving." << std::endl;
        std::cout << "After time, the exercises will become more sophisticated, but you will also have more tools to your disposal!" << std::endl;
        std::cout << "----" << std::endl;
        std::cout << "How To Play:" << std::endl;
        std::cout << "Enter the what you want to do with your keyboard and press Enter! It's as simple as that!" << std::endl;
        std::cout << "Usually you will receive screen instructions on how to input your actions, so read carefully!" << std::endl;
        
        
        STATE = "LOAD";
    } 
    else if (STATE == "LOAD"){
        // load random exercise depending on difficulty and thus on level
        STATE = "DRAW";
    }
    else if (STATE == "DRAW"){
        std::cout << "-------" << std::endl;
        std::cout << "LEVEL: " << level << std::endl;
        ui.draw_matrix(a, b, eqs, vars);
        STATE = "CHECK";
    }
    else if (STATE == "CHECK"){
        // check if correct and if yes level++ and draw. If level at speciic threshhold, also difficulty++
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

