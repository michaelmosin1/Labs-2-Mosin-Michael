#pragma once
#include <iostream>
#include "string.hpp"


namespace mm
{
class BigInt
{
	private:
		size_t _number_of_digits;
		mm::string _digits;
		bool _is_negative;
	public:
		BigInt();
		BigInt(const char* stroka);
		BigInt(const BigInt& other);
		BigInt(const mm::string& stroka);
		~BigInt();
		BigInt& operator=(const BigInt& other);
		BigInt& operator+=(const BigInt& other);
		BigInt operator+(const BigInt& other);
		BigInt& operator-=(const BigInt& other);
		BigInt operator-(const BigInt& other);
		BigInt& operator*=(const BigInt& other);
		BigInt operator*(const BigInt& other);
		BigInt& operator/=(const BigInt& other);
		BigInt operator/(const BigInt& other);
		void level_out(size_t index);
		BigInt& operator++();
		BigInt& operator--();
		bool operator<(const BigInt& other);
		bool operator<=(const BigInt& other);
		bool operator==(const BigInt& other);
		bool operator!=(const BigInt& other);
		bool operator>=(const BigInt& other);
		bool operator>(const BigInt& other);

		friend int to_int(char symbol);
		friend char to_char(int digit);
		friend std::ostream& operator<<(std::ostream& out, const BigInt& number);
		friend std::istream& operator>>(std::istream& in, const BigInt& number);
};
}
