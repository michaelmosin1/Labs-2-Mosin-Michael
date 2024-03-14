#include "bigint.hpp"


int main(){
    short choose;
    mm::BigInt chislo1;
    mm::BigInt chislo2;
    std::cout << "Please input two numbers:\n";
    std::cin >> chislo1 >> chislo2;
    std::cout << "Please select operation:" << std::endl;
    std::cout << "1)+\t2)-\t3)*\n";
    std::cin >> choose;
    switch (choose){
        case 1:
            chislo1+=chislo2;
            break;
        case 2:
            chislo1-=chislo2;
            break;
        case 3:
            chislo1*=chislo2;
            break;
        default: return 666;
    }
    std::cout << chislo1 << std::endl;
    return 0;
}