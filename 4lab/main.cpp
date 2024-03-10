#include "bigint.hpp"


int main(){
    mm::string strochka = "-12345678";
    mm::string strochka2 = "12345555";
    mm::BigInt chislo1 = strochka;
    mm::BigInt chislo2 = strochka2;
    std::cout << chislo1 << std::endl;
    std::cout << chislo2 << std::endl;
    chislo1-=chislo2;
    std::cout << chislo1 << std::endl;
    return 0;
}