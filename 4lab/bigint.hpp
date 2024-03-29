#pragma once
#include <iostream>
#include "string.hpp"


namespace mm{
	class BigInt{
		private:
			size_t _number_of_digits;
			mm::string _digits;
			bool _is_negative;
		public:
			BigInt();
			BigInt(const BigInt& other);
			BigInt(const mm::string& stroka);
			BigInt(const char* c_string);
			BigInt(const size_t& number);
			BigInt(const int& number);
			~BigInt();
			BigInt& operator=(const BigInt& other);
			BigInt& operator+=(const BigInt& other);
			BigInt operator+(const BigInt& other);
			BigInt& operator-=(const BigInt& other);
			BigInt operator-(const BigInt& other);
			BigInt& operator*=(const BigInt& other);
			BigInt operator*(const BigInt& other);
			BigInt& operator++();
			BigInt& operator--();
			bool operator<(const BigInt& other);
			bool operator<=(const BigInt& other);
			bool operator==(const BigInt& other);
			bool operator!=(const BigInt& other);
			bool operator>=(const BigInt& other);
			bool operator>(const BigInt& other);

			friend std::ostream& operator<<(std::ostream& out, BigInt number);
			friend std::istream& operator>>(std::istream& in, BigInt& number);
	};
}
