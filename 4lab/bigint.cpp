#include "bigint.hpp"
#include "string.hpp"
#include <string.h>


namespace mm
{
	BigInt::BigInt(){
	_number_of_digits = 0;
	_is_negative = false;
	_digits = "\0";
	}
	BigInt::BigInt(const char* stroka){
		_digits = stroka;
		if (_digits[0] == '-'){
			_digits.remove(0);
			_is_negative = true;
			_number_of_digits = strlen(stroka);
		}
		else{
			_is_negative = false;
			_number_of_digits = strlen(stroka)+1;
		}
		for (size_t i = _is_negative; i < _number_of_digits; i++){
			_digits[i] = stroka[i];
		}
	}
	BigInt::BigInt(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
	}
	BigInt::BigInt(const mm::string& stroka){
		_digits = stroka;
		if (_digits[0] == '-'){
			_is_negative = true;
			_digits.remove(0);
		}
		_digits.reverse();
		_number_of_digits = _digits.length();
	}
	BigInt::~BigInt(){}
	BigInt& BigInt::operator=(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
		return *this;
	}
	char to_char(int digit){
		return char(digit+'0');
	}
	int to_int(char symbol){
		return int(symbol-'0');
	}
	void BigInt::level_out(size_t index){
		size_t i = index;
		while((_digits[i] > 9) && (i < _number_of_digits)){
			_digits[i] = _digits[i]%10;
			_digits[i+1]++;
			i++;
		}
		if (_digits[i] > 9){
			_number_of_digits++;
			_digits.resize(_number_of_digits);
			_digits[i+1] = 1;
		}
	}
	BigInt BigInt::operator+(const BigInt& other){
		BigInt result;
		
		return result;
	}
	BigInt& BigInt::operator+=(const BigInt& other){
		if (_number_of_digits < other._number_of_digits){
			_number_of_digits = other._number_of_digits;
			_digits.resize(other._number_of_digits);
		}
		for (size_t i = 0; i < _number_of_digits; i++){
			_digits[i] = to_char(to_int(_digits[i])+to_int(other._digits[i]));
			this->level_out(i);
		}
		return *this;
	}
	std::ostream& operator<<(std::ostream& out, const BigInt& number){
		return out << number._digits;
	}
}