#include "matrix.hpp"


int main(){
    size_t n = 0;
    size_t m = 0;
    double x = 0;
    short choose = 0;
    std::cout << "Please, input size of matrix(rows, then columns): " << std::endl;
    std::cin >> n >> m;
    mm::Matrix<int> mat1(n, m);
    mm::Matrix<int> mat2(n, m);
    std::cout << "Please, input elements of your matrix: " << std::endl;
    std::cin >> mat1;
    std::cout << "Please, choose your operation:\n1)+\t3)++\t5)A*B\t7)det(A)\n2)-\t4)--\t6)A*x" << std::endl;
    std::cin >> choose;
    switch (choose) {
    case 1:
        std::cout << "Please, input second matrix with same sizes as the first one" << std::endl;
        std::cin >> mat2;
        std::cout << mat1 + mat2 << std::endl;
        break;
    case 2:
        std::cout << "Please, input second matrix with same sizes as the first one" << std::endl;
        std::cin >> mat2;
        std::cout << mat1 - mat2 << std::endl;
        break;
    case 3:
        mat1++;
        std::cout << mat1 << std::endl;
        break;
    case 4:
        mat1--;
        std::cout << mat1 << std::endl;
        break;
    case 5:
        std::cout << "Please, input second matrix with same sizes as the first one" << std::endl;
        std::cin >> mat2;
        std::cout << mat1 - mat2 << std::endl;
        break;
    case 6:
        std::cout << "Please, input x-multiplier" << std::endl;
        std::cin >> x;
        std::cout << mat1 * x << std::endl;
        break;
    case 7:
        std::cout << mat1.det() << std::endl;
        break;
    default:
        std::cerr << "Error! Wrong parameter of user`s choice" << std::endl;
        break;
    }
    return 0;
}
