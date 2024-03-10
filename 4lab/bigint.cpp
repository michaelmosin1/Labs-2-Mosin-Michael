#include "bigint.hpp"
#include "string.hpp"
#include <string.h>


namespace mm
{

	//constructors and destructor

	BigInt::BigInt(){
	_number_of_digits = 0;
	_is_negative = false;
	_digits = "\0";
	}
	BigInt::BigInt(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
	}
	BigInt::BigInt(const mm::string& stroka){
		_digits = stroka;
		_is_negative = false;
		if (_digits[0] == '-'){
			_is_negative = true;
			_digits.remove(0);
		}
		_digits.reverse();
		_number_of_digits = _digits.length();
	}
	BigInt::~BigInt() = default;

	//logical operations

	bool BigInt::operator<(const BigInt& other){
		if (_is_negative && !other._is_negative) return true;
		else if (!_is_negative && other._is_negative) return false;
		else if (!_is_negative && !other._is_negative){
			if (_number_of_digits != other._number_of_digits){
				return (_number_of_digits < other._number_of_digits);
			}
			else{
				size_t i = _number_of_digits;
				while ((_digits[i] == other._digits[i]) && (i > 0)){
					i--;
				}
				return (_digits[i] < other._digits[i]);
			}
		}
		else{
			if (_number_of_digits != other._number_of_digits){
				return (_number_of_digits > other._number_of_digits);
			}
			else{
				size_t i = _number_of_digits;
				while ((_digits[i] == other._digits[i]) && (i > 0)){
					i--;
				}
				return (_digits[i] > other._digits[i]);
			}
		}
	}
	bool BigInt::operator>(const BigInt& other){
		if (_is_negative && !other._is_negative) return false;
		else if (!_is_negative && other._is_negative) return true;
		else if (!_is_negative && !other._is_negative){
			if (_number_of_digits != other._number_of_digits){
				return (_number_of_digits > other._number_of_digits);
			}
			else{
				size_t i = _number_of_digits;
				while ((_digits[i] == other._digits[i]) && (i > 0)){
					i--;
				}
				return (_digits[i] > other._digits[i]);
			}
		}
		else{
			if (_number_of_digits != other._number_of_digits){
				return (_number_of_digits < other._number_of_digits);
			}
			else{
				size_t i = _number_of_digits;
				while ((_digits[i] == other._digits[i]) && (i > 0)){
					i--;
				}
				return (_digits[i] < other._digits[i]);
			}
		}
	}
	bool BigInt::operator==(const BigInt& other){
		if ((_number_of_digits != other._number_of_digits) || (_is_negative != other._is_negative)){
			return false;
		}
		else{
			size_t i = _number_of_digits;
			while ((_digits[i] == other._digits[i]) && (i > 0)){
				i--;
			}
			return (_digits[i] == other._digits[i]);
		}
	}
	bool BigInt::operator!=(const BigInt& other){
		if ((_number_of_digits != other._number_of_digits) || (_is_negative != other._is_negative)){
			return true;
		}
		else{
			size_t i = _number_of_digits;
			while ((_digits[i] == other._digits[i]) && (i > 0)){
				i--;
			}
			return (_digits[i] != other._digits[i]);
		}
	}
	bool BigInt::operator<=(const BigInt& other){
		return ((*this < other) || (*this == other));
	}
	bool BigInt::operator>=(const BigInt& other){
		return ((*this > other) || (*this == other));
	}
	BigInt& BigInt::operator=(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
		return *this;
	}

	//arithmetic operations

	BigInt BigInt::operator+(const BigInt& other){
		BigInt result;
		result+=other;
		return result;
	}
	BigInt& BigInt::operator+=(const BigInt& other){
			BigInt bigger;
			BigInt lesser;
		if (_number_of_digits > other._number_of_digits){
			bigger = *this;
			lesser = other;
		}
		else{
			bigger = other;
			lesser = *this;
		}
		for (size_t i = 0; i < lesser._number_of_digits; i++){
			bigger._digits[i] = to_char(to_int(bigger._digits[i])+to_int(lesser._digits[i]));
			if (to_int(bigger._digits[i]) > 9){
				bigger._digits[i] = to_char(to_int(bigger._digits[i])%10);
				if (i < bigger._number_of_digits-1){
					bigger._digits[i+1]++;
				}
				else{
					bigger._digits+="1";
				}
			}
		}
		*this = bigger;
		return *this;
	}
	BigInt BigInt::operator-(const BigInt& other){
		BigInt result = *this;
		result -= other;
		return result;
	}
	BigInt& BigInt::operator-=(const BigInt& other){
		BigInt bigger;
		BigInt lesser;
		if (*this > other){
			bigger = *this;
			lesser = other;
		}
		else{
			bigger = other;
			lesser = *this;
			bigger._is_negative = true;
		}
		for (size_t i = 0; i < lesser._number_of_digits; i++){
			bigger._digits[i] = to_char(to_int(bigger._digits[i])-to_int(lesser._digits[i]));
			if (to_int(bigger._digits[i]) < 0){
				bigger._digits[i]+=10;
				if (i < bigger._number_of_digits-1){
					bigger._digits[i+1]--;
				}
			}
		}
		size_t i = bigger._number_of_digits-1;
		while ((bigger._digits[i] == '0') && (i > 0)){
			bigger._digits.resize(bigger._number_of_digits);
			bigger._number_of_digits--;
			i--;
		}
		*this = bigger;
		return *this;
	}

	// input-output operations

	std::istream& operator>>(std::istream& in, BigInt& number){
		mm::string buffer;
		in >> buffer;
		number = buffer;
		return in;
	}
	std::ostream& operator<<(std::ostream& out, BigInt& number){
		mm::string digits = number._digits;
		if (number._is_negative) digits+="-";
		digits.reverse();
		return out << digits;
	}
}