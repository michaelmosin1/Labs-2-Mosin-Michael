#include "string.hpp"
#include <cstddef>
#include <stdexcept>
#include <string.h>


namespace mm{
    string::string(){
        _massive = nullptr;
        _length = 0;
        _capacity = 0;
    }
    string::~string(){
        delete[](_massive);
    }
    string::string(const string& other){
	    _length = other._length;
        _capacity = other._capacity;
	    _massive = new char[_length+1];
	    strcpy(_massive, other._massive);
    }
    string::string(char* c_string){
        _length = strlen(c_string);
        _capacity = _length + 1;
        _massive = new char[_capacity];
        strcpy(_massive, c_string);
    }
    string& string::operator=(const string& other){
        _length = strlen(other._massive);
        _capacity = _length + 1;
        _massive = new char[_capacity];
        strcpy(_massive, other._massive);
        return(*this);
    }
    string& string::operator=(const char* other){
        _length = strlen(other);
        _capacity = _length + 1;
        _massive = new char[_capacity];
        strcpy(_massive, other);
        return(*this);
    }
    const char* string::c_str(){
        return this->_massive;
    }
    string& string::operator+=(const string& other){
        _length += other._length;
        _capacity = _length + 1;
        _massive = static_cast<char*>(realloc(_massive, _capacity));
        strcat(_massive, other._massive);
        return *this;
    }
    string string::operator+(const string& other){
        // char massive[_length+other._length+1];
        // strcpy(massive, _massive);
        // strcat(massive, other._massive);
        // return string(massive);

        //string sum(this->_massive);
        string sum = *this;
        sum+=other;
        return sum;
    }
    bool string::operator<(const string& other){
        return (strcmp(_massive, other._massive) == -1);
    }
    bool string::operator>(const string& other){
        return (strcmp(_massive, other._massive) == 1);
    }
    bool string::operator==(const string& other){
        return (strcmp(_massive, other._massive) == 0);
    }
    char& string::operator[](size_t index){
        return _massive[index];
    }
    char& string::operator[](size_t index) const {
        return _massive[index];
    }
    char string::at(size_t index){
        if ((index >= 0)&&(index<_length)) return _massive[index];
            //std::cerr << "Error! wrong index" << std::endl;
            //return '\0';
            throw std::out_of_range ("string oor");
         
    }
    size_t string::length(){
        return _length;
    }
    size_t string::find(char symbol){
        for (size_t i = 0; i <= _length; i++){
            if (_massive[i] == symbol) return i;
        }
        throw std::invalid_argument("Symbol not found");
    }
    std::ostream& operator<<(std::ostream& out, string& string){
        return out << string.c_str();
    }
    std::istream& operator>>(std::istream& in, string& string){
        char buffer[100];
        in >> buffer;
        string._length = strlen(buffer);
        delete[] string._massive;
        string._massive = new char[string._length+1];
        for (int i = 0; i <= string._length; i++) string._massive[i] = buffer[i];
        return in;
    }
    void string::remove(size_t index){
	    if (index ==_length) return;
	    for (size_t i = 0; i < _length; i++){
	    this[i] = this[i+1];
	    }
	    _massive = static_cast<char*>(realloc(_massive, _length));
	    _length--;
    }
    void string::reverse(){
        for (size_t i = 0; i < _length/2; i++)
            std::swap(_massive[i], _massive[_length-i-1]);
    }
    void string::push_back(const char& symbol){
        _length++;
        _massive = static_cast<char*>(realloc(_massive, _length+1));
        _massive[_length] = symbol;
        std::swap(_massive[_length], _massive[_length-1]);
    }
    void string::resize(size_t size){
        _massive = static_cast<char*>(realloc(_massive, size));
        if (_length > size) {
            _length = size - 1;
            _massive[_length] = '\0';
        }
        _capacity = size;
    }
}
