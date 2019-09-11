#include "lineq.h"
#include <vector>

// define variables once for functions to use
void les::update_dimensions(int e, int v){
    eqs = e; vars = v;
}

//swap function from script
template<typename T>
    void les::swap(T &a, T &b){
        T tmp = a;
        a = b; b = tmp;
    }

// overloading function to except either a vector or an array
void les::rows_swap(std::vector<double> &v, std::vector<double> order){
    swap<double> (v[order[0]-1], v[order[1]-1]);
}
void les::rows_swap(std::vector< std::vector<double> > &v, std::vector<double> order){
    for (int i = 0; i<eqs; i++){
        swap<double> (v[i][order[0]-1], v[i][order[1]-1]);
    }
}
void les::rows_multiplicate(std::vector<double> &v, std::vector<double> order){ //order[0] is the row, order[1] is the second factor
    v[order[0]-1] = v[order[0]-1] * order[1];
}
void les::rows_multiplicate(std::vector< std::vector<double> > &v, std::vector<double> order){ //order[0] is the row, order[1] is the second factor
    for (int i = 0; i<eqs; i++){
        v[i][order[0]-1] = v[i][order[0]-1] * order[1];
    }
}
void les::rows_add(std::vector<double> &v, std::vector<double> order){ //order[0] is the row, order[1] is the to be added row
    v[order[0]-1] = v[order[0]-1] + v[order[1]-1];
}
void les::rows_add(std::vector< std::vector<double> > &v, std::vector<double> order){ //order[0] is the row, order[1] is the to be added row
    for (int i = 0; i<eqs; i++){
        v[i][order[0]-1] = v[i][order[0]-1] + v[i][order[1]-1];
    }
}
void les::rows_subtract(std::vector<double> &v, std::vector<double> order){ //order[0] is the row, order[1] is the to be subtracted row
    v[order[0]-1] = v[order[0]-1] - v[order[1]-1];
}
void les::rows_subtract(std::vector< std::vector<double> > &v, std::vector<double> order){ //order[0] is the row, order[1] is the to be added row
    for (int i = 0; i<eqs; i++){
        v[i][order[0]-1] = v[i][order[0]-1] - v[i][order[1]-1];
    }
}
void les::rows_divide(std::vector<double> &v, std::vector<double> order){ //order[0] is the row, order[1] is the  divisor
    v[order[0]-1] = v[order[0]-1] / order[1];
}
void les::rows_divide(std::vector< std::vector<double> > &v, std::vector<double> order){ //order[0] is the row, order[1] is the divisor
    for (int i = 0; i<eqs; i++){
        v[i][order[0]-1] = v[i][order[0]-1] / order[1];
    }
}



les::les(int e, int va) { eqs = e; vars = va;}
les::~les() {}
