#pragma once
#include <cstddef>
#include <iostream>


namespace mm{
    template<typename T>
    class Vector{
        private:
            size_t _size;
            size_t _capacity;
            T* _massive;
        public:
        // constructors and destructor
            Vector() = default;
            Vector(size_t size){
                this->_size = size;
                this->_capacity = size;
                this->_massive = new T[size];
            }
            Vector(const Vector& other){
                this->_size = other._size;
                this->_capacity = other._capacity;
                this->_massive = new T[this->_capacity];
                for (size_t i = 0; i < this->_size; i++){
                    this->_massive[i] = other._massive[i];
                }
            }
            ~Vector(){
                delete[] this->_massive;
            }
        // setters and getters
            size_t getSize(){
                return this->_size;
            }
            size_t getCapacity(){
                return this->_capacity;
            }
            T& operator[](size_t index){
                return this->_massive[index];
            }
            T operator[](size_t index) const {
                return this->_massive[index];
            }
            void size_to_fit(){
                if (this->_capacity > this->_size){
                    this->_capacity = this->_size;
                    this->_massive = static_cast<T*>(realloc(this->_massive, this->_capacity));
                }
                return;
            }
        // manipulation with elements
            void push_back(T element){
                this->_size++;
                if (this->_capacity < this->_size){
                    this->_capacity = this->_size << 1;
                    this->_massive = static_cast<T*>(realloc(this->_massive, this->_capacity));
                }
                this->_massive[this->_size - 1] = element;
                return;
            }
            void insert(T element, size_t index){
                this->push_back(element);
                for (size_t i = this->_size - 1; i > index; i--){
                    this->_massive[i] = this->_massive[i - 1];
                }
                this->_massive[index] = element;
                return;
            }
            void erase(size_t index){
                this->_size--;
                for (size_t i = index; i < this->_size; i++){
                    this->_massive[i] = this->_massive[i + 1];
                }
                this->size_to_fit();
                return;
            }
            friend std::ostream& operator<<(std::ostream& out, const Vector& vector){
                for (size_t i = 0; i < vector._size; i++){
                    out << vector._massive[i] << ' '; 
                }
                return out;
            }
    };
    template<>
    class Vector<bool>{
        private:
            size_t _size;
            size_t _capacity;
            unsigned char* _massive;
        public:
        // constructors and destructor
            Vector() = default;
            Vector(size_t size){
                this->_size = size;
                this->_capacity = size / 8;
                if ((this->_size % 8) > 0) this->_capacity++;
                this->_massive = new unsigned char[this->_capacity];
            }
            Vector(const Vector& other){
                this->_size = other._size;
                this->_capacity = other._capacity;
                this->_massive = new unsigned char[this->_capacity];
                for (size_t i = 0; i < this->_capacity; i++){
                    this->_massive[i] = other._massive[i];
                }
            }
            ~Vector(){
                delete[] this->_massive;
            }
        // setters and getters
            size_t getSize(){
                return this->_size;
            }
            size_t getCapacity(){
                return this->_capacity * 8;
            }
            bool operator[](size_t index) const {
                size_t iter = 0;
                while (index >= 8){
                    index -= 8;
                    iter++;
                }
                return (this->_massive[iter] & (1<<(index % 8)));
            }
            void set_value(size_t index, bool element){
                size_t iter = 0;
                while (index >= 8){
                    index -= 8;
                    iter++;
                }
                if (element) this->_massive[iter] = (this->_massive[iter] | (1<<(index % 8)));
                else this->_massive[iter] = (this->_massive[iter] & ~(1<<(index % 8)));
                return;
            }
            void size_to_fit(){
                if (this->_capacity > ((this->_size+7) / 8)){
                    this->_capacity = (this->_size+7) / 8;
                    this->_massive = static_cast<unsigned char*>(realloc(this->_massive, this->_capacity));
                }
                return;
            }
        // manipulation with elements
            void push_back(bool element){
                this->_size++;
                if ((this->_capacity * 8) < this->_size){
                    this->_capacity++;
                    this->_massive = static_cast<unsigned char*>(realloc(this->_massive, this->_capacity));
                }
                set_value(_size - 1, element);
                return;
            }
            void insert(bool element, size_t index){
                this->push_back(element);
                Vector<bool> copy = *this;
                for (size_t i = this->_size - 1; i > index; i--){
                    this->set_value(i, copy[i - 1]);
                }
                this->set_value(index, element);
                return;
            }
            void erase(size_t index){
                Vector<bool> copy = *this;
                this->_size--;
                for (size_t i = index; i < this->_size; i++){
                    this->set_value(i, copy[i + 1]);
                }
                this->size_to_fit();
                return;
            }
            friend std::ostream& operator<<(std::ostream& out, const Vector& vector){
                for (size_t i = 0; i < vector._size; i++){
                    out << vector[i] << ' '; 
                }
                return out;
            }
    };
}