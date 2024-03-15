#include "matrix.hpp"


namespace mm{
    template <typename T1, typename T2> class Matrix;
    Matrix<T1, T2>::Matrix(){
        size_m = 0;
        size_n = 0;
        massive = nullptr;
    }
    Matrix<T1, T2>::Matrix(T1 m, T1 n){

    }
    
}