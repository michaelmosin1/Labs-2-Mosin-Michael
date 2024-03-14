#include "string.hpp"
#include <cstddef>
#include <stdexcept>
#include <string.h>


namespace mm{

    // constructors and destructor

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
    string::string(const char* c_string){
        _length = strlen(c_string);
        _capacity = _length + 1;
        _massive = new char[_capacity];
        strcpy(_massive, c_string);
    }

    // copy operations

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

    // getter

    char* string::c_str(){
        return this->_massive;
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

    // logical operations

    bool string::operator<(const string& other){
        return (strcmp(_massive, other._massive) == -1);
    }
    bool string::operator>(const string& other){
        return (strcmp(_massive, other._massive) == 1);
    }
    bool string::operator==(const string& other){
        return (strcmp(_massive, other._massive) == 0);
    }

    // element access operators

    char& string::operator[](size_t index){
        return _massive[index];
    }
    char& string::operator[](size_t index) const {
        return _massive[index];
    }
    char string::at(size_t index){
        if ((index >= 0)&&(index<_length)) return _massive[index];
        throw std::out_of_range ("string oor");
    }

    // string processing

    string& string::operator+=(const string& other){
        _length += other._length;
        _capacity = _length + 1;
        _massive = static_cast<char*>(realloc(_massive, _capacity));
        strcat(_massive, other._massive);
        return *this;
    }
    string string::operator+(const string& other){
        string sum = *this;
        sum+=other;
        return sum;
    }
    void string::reverse(){
        for (size_t i = 0; i < _length/2; i++)
            std::swap(_massive[i], _massive[_length-i-1]);
    }
    void string::push_back(const char& symbol){
        _length++;
        _capacity++;
        _massive = static_cast<char*>(realloc(_massive, _capacity));
        _massive[_length-1] = symbol;
        _massive[_length] = '\0';
    }
    void string::resize(size_t size){
        _massive = static_cast<char*>(realloc(_massive, size+1));
        if (_length > size) {
            _length = size;
            _massive[_length] = '\0';
        }
        _capacity = size + 1;
    }
    void string::remove(size_t index){
	    if (index == _length) return;
	    for (size_t i = index; i < _length; i++){
	    _massive[i] = _massive[i+1];
	    }
        _capacity--;
        _length--;
	    this->resize(_capacity);
    }

    // input-output operators
    
    std::ostream& operator<<(std::ostream& out, string& string){
        return out << string.c_str();
    }
    std::istream& operator>>(std::istream& in, string& string){
        char buffer[10001];
        in >> buffer;
        string._length = strlen(buffer);
        string._capacity = string._length+1;
        delete[] string._massive;
        string._massive = new char[string._capacity];
        for (int i = 0; i <= string._length; i++) string._massive[i] = buffer[i];
        return in;
    }

    // operations involved in string processing

    char to_char(int digit){
		return char(digit+'0');
	}
	int to_int(char symbol){
		return int(symbol-'0');
	}
}
