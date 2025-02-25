#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "user_interface.h"
#include "lineq.h"
using std::string;
using namespace std;

void UI::get_Dimensions(int &v, int &e){
    std::cout << "How many variables?" << std::endl;
    std::cin >> v;
    std::cout << "How many equations?" << std::endl;
    std::cin >> e;
}


// printing as a[alpha][beta], b[beta]; beta proportional to vars, alpha porportional to eqs
void UI::draw_matrix(std::vector< std::vector<double> > a, std::vector<double> b, int eqs, int vars){
    //std::vector< std::vector<double> >::iterator it_a = a.begin();
    //std::vector<double>::iterator it_b = b.begin();

    std::cout << std::endl;
    std::cout << "------" << std::endl;

    for (int i = 0; i<vars; i++){
        //printing A:
        std::cout << "(" << i+1 << ")" << '\t';
        std::cout << "[ "; 

        try {
            for (int k = 0; k<eqs; k++){
                std::cout << a[k][i] << " ";
            }
        } catch (const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }

        std::cout << "]";

        std::cout << " ";
        std::cout << "|" << " ";

        //printing b:
        std::cout << "[ ";
        std::cout << b[i];
        std::cout << " ]";
        

        std::cout << std::endl;
    }   std::cout << "------" << std::endl; std::cout << std::endl;

    }




UI::UI(){}
UI::~UI(){}




