#include "string.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>


int main(){
    char mas[4] = "str";
    char mas1[4] = "mas";
    mm::string stroka_dva;
    stroka_dva = mas;
    mm::string a;
    mm::string b;
    mm::string stroka;
    mm::string stroka_tri;
    mm::string new_str;
    stroka = mas1;
    std::cin >> stroka_tri;
    new_str = stroka_tri;
    std::cout << new_str << std::endl;
    //a = stroka+stroka_dva;
    b = stroka+stroka_tri;
    std::cout << b << std::endl;
    std::cout << stroka << std::endl;
    b = stroka+stroka_tri; 
    //std::cout << a << std::endl;
    std::cout << b << std::endl;
    try {
        b.at(100);
    } catch (std::exception &e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}