#ifndef lineq_H
#define lineq_H

#include <vector>

class les {

    public:
    
    // Row operation functions; overloaded to use 1-D and 2-D vectors
    void rows_swap(std::vector<double> &v, std::vector<double> order);
    void rows_swap(std::vector< std::vector<double> > &v, std::vector<double> order);

    void rows_multiplicate(std::vector<double> &v, std::vector<double> order);
    void rows_multiplicate(std::vector< std::vector<double> > &v, std::vector<double> order);

    void rows_add(std::vector<double> &v, std::vector<double> order);
    void rows_add(std::vector< std::vector<double>> &v, std::vector<double> order);

    void rows_subtract(std::vector<double> &v, std::vector<double> order);
    void rows_subtract(std::vector< std::vector<double> > &v, std::vector<double> order);

    void rows_divide(std::vector<double> &v, std::vector<double> order);
    void rows_divide(std::vector< std::vector<double> > &v, std::vector<double> order);
    
    
    
    les(int eqs, int vars);
    ~les();

};


#endif