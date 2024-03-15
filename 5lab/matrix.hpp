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
            Matrix();
            Matrix(size_t m, size_t n);
            Matrix(const Matrix& other);
            ~Matrix();
            Matrix& operator=(const Matrix& other);
            Matrix operator+(const Matrix& other);
            Matrix& operator+=(const Matrix& other);
            Matrix operator-(const Matrix& other);
            Matrix& operator-=(const Matrix& other);
            Matrix operator*(const Matrix& other);
            Matrix& operator*=(const Matrix& other);
            Matrix operator*(const T& number);
            Matrix& operator*=(const T& number);
            Matrix& operator++(int);
            Matrix& operator--(int);
            T operator[](size_t) const;
            T operator[](size_t);
            double det(const Matrix& A);

            friend std::ostream& operator<<(std::ostream& out, const Matrix& A);
            friend std::istream& operator>>(std::istream& in, Matrix& A);
    };
}