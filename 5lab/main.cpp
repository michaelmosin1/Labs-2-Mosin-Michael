#include "matrix.hpp"


int main(){
    mm::Matrix<int> mat1(3, 3);
    mm::Matrix<int> mat2(3, 3);
    std::cin >> mat1 >> mat2;
    std::cout << std::endl;
    std::cout << mat1 << std::endl;
    std::cout << mat2 << std::endl;
    mat1+=mat2;
    std::cout << mat1 << std::endl;
    std::cout << mat2 << std::endl;
    return 0;
}
