#include "matrix.hpp"
#include <iostream>


namespace mm{
    void matrix::fill_with_data(){
        std::cout << "Please input elements of matrix\n";
        for (int i = 0; i < N_size; i++){
            for (int j = 0; j < M_size; j++){
                std::cin >> data[i][j];
            }
        }
    }
    void matrix::print(){
        for (int i = 0; i < N_size; i++){
            for (int j = 0; j < M_size; j++){
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}