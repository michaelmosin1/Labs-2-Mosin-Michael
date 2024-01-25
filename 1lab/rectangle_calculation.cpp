#include "rectangle.hpp"
#include <cmath>


namespace mm{
    float rectangle::diagonal(){
        if (!_is_empty) return pow(pow(_height, 2)+pow(_width, 2), 0.5);
        else return -1;
    }
    float rectangle::perimeter(){
        if (!_is_empty) return (_height+_width)*2;
        else return -1;
    }
    float rectangle::area(){
        if (!_is_empty) return _height*_width;
        else return -1;
    }
}