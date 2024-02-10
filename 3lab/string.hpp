#ifndef stroki
#define stroki
#include <cstddef>
#include <iostream>


namespace mm{
    class string{
        public:
            char* _massive;
            size_t _length;
        public:
            string();
            ~string();
            string(char* c_string);
            string& operator=(const string& other);
            string& operator=(const char* other);
            string operator+(const string& other);
            string& operator+=(const string& other);
            char operator[](size_t index);
            bool operator<(const string& other);
            bool operator>(const string& other);
            bool operator==(const string& other);
            const char* c_str();
            size_t find(char symbol);
            size_t length();
            char at(size_t index);

            friend std::ostream& operator<<(std::ostream& out, string& string);
            friend std::istream& operator>>(std::istream& in, string& string);
    };
    
    
}

#endif