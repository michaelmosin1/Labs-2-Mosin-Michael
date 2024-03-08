#include "bigint.hpp"


int main(){
    mm::BigInt chislo1 = "12345678";
    mm::BigInt chislo2 = "12345678";
    chislo1+=chislo2;
    std::cout << chislo1 << std::endl;
    return 0;
}