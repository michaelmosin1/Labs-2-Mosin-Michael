#pragma once
#include <iostream>


namespace mm{
    template <typename T>
    class Matrix{
        private:
            size_t size_m;
            size_t size_n;
            T** massive;
        public:
            Matrix(){
                this->size_m = 0;
                this->size_n = 0;
                this->massive = nullptr;
            };
            Matrix(size_t m, size_t n){
                this->size_m = m;
                this->size_n = n;
                this->massive = new T*[size_m];
                for (size_t i = 0; i < size_m; i++){
                    this->massive[i] = new T[size_n];
                }
            };
            Matrix(const Matrix& other){
                this->size_m = other.size_m;
                this->size_n = other.size_n;
                this->massive = new T*[size_m];
                for (size_t i = 0; i < size_m; i++){
                    this->massive[i] = new T[size_n];
                }
                for (size_t i = 0; i < size_m; i++){
                    for (size_t j = 0; j < size_n; j++){
                        this->massive[i][j] = other.massive[i][j];
                    }
                }
            };
            ~Matrix(){
                for (size_t i = 0; i < size_m; i++){
                    delete[] this->massive[i];
                }
                delete[] this->massive;
            };
            Matrix& operator=(const Matrix& other){
                this->size_m = other.size_m;
                this->size_n = other.size_n;
                this->massive = new T*[size_m];
                for (size_t i = 0; i < size_m; i++){
                    this->massive[i] = new T[size_n];
                }
                for (size_t i = 0; i < size_m; i++){
                    for (size_t j = 0; j < size_n; j++){
                        this->massive[i][j] = other.massive[i][j];
                    }
                }
                return *this;
            };
            Matrix operator+(const Matrix& other){
                Matrix result = *this;
                result+=other;
                return result;
            };
            Matrix& operator+=(const Matrix& other){
                if ((this->size_m == other.size_m) && (this->size_m == other.size_n)){
                    for (size_t i = 0; i < this->size_m; i++){
                        for (size_t j = 0; j < this->size_n; j++){
                            this->massive[i][j] += other.massive[i][j];
                        }
                    }
                }
                return *this;
            };
            Matrix operator-(const Matrix& other){
                Matrix result = *this;
                result-=other;
                return result;
            };
            Matrix& operator-=(const Matrix& other){
                if ((this->size_m == other.size_m) && (this->size_m == other.size_n)){
                    for (size_t i = 0; i < size_m; i++){
                        for (size_t j = 0; j < size_n; j++){
                            this->massive[i][j] -= other.massive[i][j];
                        }
                    }
                }
                return *this;
            };
            Matrix operator*(const Matrix& other){
                Matrix result = *this;
                result*=other;
                return result;
            };
            Matrix& operator*=(const Matrix& other){
                if (this->size_n != other.size_m){
                    std::cout << "Error! Can only multiply matrixes when number of first`s strings is equal to number of other`c columns" << std::endl;
                    return *this;
                }
                Matrix result(this->size_m, other.size_n);
                for (size_t i = 0; i < this->size_m; i++){
                    for (size_t j = 0; j < other.size_n; j++){
                        result.massive[i][j] = 0;
                    }
                }
                for (size_t i = 0; i < this->size_m; i++){
                    for (size_t j = 0; j < other.size_n; j++){
                        for (size_t k = 0; k < this->size_n; k++){
                            result.massive[i][j] += (this->massive[i][k]*other.massive[k][j]);
                        }
                    }
                }
                *this = result;
                return *this;
            };
            Matrix operator*(const T& number){
                Matrix result = *this;
                result*=number;
                return result;
            };
            Matrix& operator*=(const T& number){
                for (size_t i = 0; i < size_m; i++){
                    for (size_t j = 0; j < size_n; j++){
                        this->massive[i][j] *= number;
                    }
                }
                return *this;
            };
            Matrix& operator++(int){
                for (size_t i = 0; i < size_m; i++){
                    for (size_t j = 0; j < size_n; j++){
                        this->massive[i][j] += 1;
                    }
                }
                return *this;
            };
            Matrix& operator--(int){
                for (size_t i = 0; i < size_m; i++){
                    for (size_t j = 0; j < size_n; j++){
                        this->massive[i][j] -= 1;
                    }
                }
                return *this;
            };
            T operator[](size_t index) const {
                return this->massive[index];
            };
            T& operator[](size_t index){
                return this->massive[index];
            };
            double det(const Matrix& A){
                return 0;
            };

            friend std::ostream& operator<<(std::ostream& out, const Matrix& A){
                for (size_t i = 0; i < A.size_m; i++){
                    for (size_t j = 0; j < A.size_n; j++){
                        out << A.massive[i][j] << ' ';
                    }
                    out << std::endl;
                }
                return out;
            };
            friend std::istream& operator>>(std::istream& in, Matrix& A){
                for (size_t i = 0; i < A.size_m; i++){
                    for (size_t j = 0; j < A.size_n; j++){
                        in >> A.massive[i][j];
                    }
                }
                return in;
            };
    };
}
