#include "rectangle.hpp"
#include <iostream>


int main(){
    short choose;
    float height;
    float width;
    std::cout << "Please input sizes of rectangle" << std::endl;
    std::cin >> height >> width;
    mm::rectangle rect1;
    rect1.set_size(height, width);
    mm::rectangle rect2(width, height);
    if (rect1.is_empty()){
        std::cerr << "Error. Wrong sizes of rectangle!" << std::endl;
        return 29;
    }
    std::cout << "1)Find an area of rectangle" << std::endl
    << "2)Find a perimeter of rectangle" << std::endl
    << "3)Find a diagonal" << std::endl <<
     "Choose an operation to perform: ";
    std::cin >> choose;
    switch(choose){
        case 1: std::cout << std::endl << rect1.area() << std::endl; break;
        case 2: std::cout << std::endl << rect1.perimeter() << std::endl; break;
        case 3: std::cout << std::endl << rect1.diagonal() << std::endl; break;
        default: std::cerr << "Error, wrong operation code!" << std::endl;
    }
    return 0;
}