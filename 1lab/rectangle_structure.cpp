#include "rectangle.hpp"
#include <iostream>


namespace mm{
    rectangle::rectangle(){}
    rectangle::rectangle(float height, float width){
        if (height > 0 && width > 0){
            _height = height;
            _width = width;
            _is_empty = false;
        }
        else _is_empty = true;
    }
    rectangle::~rectangle(){}
    bool rectangle::is_empty(){
        return _is_empty;
    }
    void rectangle::set_size(float height, float width){
        if (height > 0 && width > 0){
            _height = height;
            _width = width;
            _is_empty = false;
        }
        else _is_empty = true;
    }
    void rectangle::print_out(){
        std::cout 
        << "Your rectangle is " << _height
        << " height and " << _width 
        << " width" << std::endl;
    };
}