#pragma once
#include <iostream>


namespace mm{
    class Vector{
        private:
            size_t size;
            size_t capacity;
            char* vector;
        public:
        // constructors and destructor
            Vector();
            Vector(size_t size);
            Vector(const Vector& other);
            ~Vector();
        // getters
            size_t getSize();
            bool operator[](size_t index) const;
        // setters
            void resize();
            bool& operator[](size_t index);
        // insert and erase
            void insert(const size_t index, const bool& element);
            void erase(const size_t index);
            friend std::ostream& operator<<(std::ostream& out, mm::Vector& vector);
    };
    
}