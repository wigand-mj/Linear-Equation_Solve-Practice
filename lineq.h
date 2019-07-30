#ifndef lineq_H
#define lineq_H

#include <vector>

class les {

    int eqs, vars;
    public:

    les(int e, int va);
    ~les();

   
   void update_dimensions(int e, int v);
   
    // swap function from script
    template<typename T>
        void swap(T &a, T &b);


    // Row operation functions; overloaded to use 1-D and 2-D vectors
    // each function takes a vector order (specifying which rows should be operated on)
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
    
    
    
  

};


#endif