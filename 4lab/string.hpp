#pragma once
#include <cstddef>
#include <iostream>


namespace mm{
    class string{
        public:
            char* _massive;
            size_t _length;
            size_t _capacity;
        public:
            string();
            ~string();
            string(const string& other);
            string(const char* c_string);
            string& operator=(const string& other);
            string& operator=(const char* other);
            char* c_str();
            string& operator+=(const string& other);
            string operator+(const string& other);
            bool operator<(const string& other);
            bool operator>(const string& other);
            bool operator==(const string& other);
            char& operator[](size_t index);
            char& operator[](size_t index) const;
            char at(size_t index);
            size_t length();
            size_t find(char symbol);
            void remove(size_t index);
            void reverse();
            void push_back(const char& symbol);
            void resize(size_t size);

            friend std::ostream& operator<<(std::ostream& out, string& string);
            friend std::istream& operator>>(std::istream& in, string& string);
    };
    int to_int(char symbol);
	char to_char(int digit);
}
