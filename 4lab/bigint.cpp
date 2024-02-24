#include "bigint.hpp"


namespace mm
{
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
		if (_digits[0] == '-'){
			_is_negative = true;
			_digits.remove(0);
		}
		_digits.reverse();
		_number_of_digits = _digits.length();
	}
	void BigInt::make_equal_sizes(const BigInt& other){
		
	}
	BigInt& BigInt::operator=(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
		return *this;
	}
	BigInt BigInt::operator+(const BigInt& other){
		BigInt result;
		
		return result;
	}
	BigInt& BigInt::operator+=(const BigInt& other){
		if (_number_of_digits < other._number_of_digits){
			_number_of_digits = other._number_of_digits;
			_digits.resize(other._number_of_digits+1);
		}
		for (size_t i = 0; i < _number_of_digits; i++){
			short summ = int(_digits[i] + other._digits[i] - 2*'0');
			_digits[i] = summ % 10 + '0';
			if (summ > 9){
				_digits[i] += 1;
				if (i == _number_of_digits-1){
					_digits.push_back('1');
					_digits.push_back('\0');
				}
			}
			
		}
	}
}