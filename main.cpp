#include <iostream>
#include <string>
#include <vector>
#include "lineq.h"
#include "user_interface.h"

using namespace std;
using std::string;

//les machine(1,1);
//Function declarations
string user_input();
void draw_matrix(vector<vector<double> > matrix, int size);


int main(){
    // test code from the webs --> remove
    // An empty vector of vectors. The space
// between the 2 '>' signs is necessary
    vector<vector<double> > v2d;

// If you intend creating many vectors
// of vectors, the following's tidier
    typedef vector<vector<double> > IntMatrix;
    IntMatrix m;

// Now we'll try to create a 3 by 5 "matrix".
// First, create a vector with 5 elements
    vector<double> v2(5, 99);

// Now create a vector of 3 elements.
// Each element is a copy of v2
    vector<vector<double> > v2d2(4,v2);

    user_input();
//"hello"
    //draw_matrix(v2d2,4);
}

