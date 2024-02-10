#include "matrix.hpp"
#include <algorithm>


namespace mm{
    matrix::matrix(){
        N_size = 1;
        M_size = 1;
        data = new int*[N_size];
        for (int i = 0; i < N_size; i++)
            data[i] = new int[M_size];
    }
    matrix::matrix(int N, int M){
        if ((N < 1) && (M < 1)) return;
        N_size = N;
        M_size = M;
        data = new int*[N_size];
        for (int i = 0; i < N_size; i++)
            data[i] = new int[M_size];
    }
    matrix::~matrix(){
        for (int i = 0; i < N_size; i++)
            delete[] data[i];
        delete[] data;
    }
    matrix::matrix(const matrix& other){
        N_size = other.N_size;
        M_size = other.M_size;
        is_matrix_empty = false;
        data = new int*[N_size];
        for (int i = 0; i < N_size; i++)
            data[i] = new int[M_size];
        for (int i = 0; i < N_size; i++){
            for (int j = 0; j < M_size; j++){
                data[i][j] = other.data[i][j];
            }
        }
    }
    matrix& matrix::operator=(const matrix& other){
        matrix::~matrix();
        static matrix some_matrix(other.N_size, other.M_size);
        is_matrix_empty = false;
        for (int i = 0; i < N_size; i++){
            for (int j = 0; j < M_size; j++){
                data[i][j] = other.data[i][j];
            }
        }
        //std::copy(**(other.data), *(*(other.data+N_size)+M_size), data);
        return some_matrix;
    }
}

