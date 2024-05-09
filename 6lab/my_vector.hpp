#pragma once
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
}