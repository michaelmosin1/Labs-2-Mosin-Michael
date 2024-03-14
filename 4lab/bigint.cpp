#include "bigint.hpp"
#include "string.hpp"
#include <string.h>


namespace mm
{

	//constructors and destructor

	BigInt::BigInt(){
	_number_of_digits = 1;
	_is_negative = false;
	_digits = "0";
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
	BigInt::BigInt(const char* c_string){
		mm::string stroka = c_string;
		_digits = stroka;
		_is_negative = false;
		if (_digits[0] == '-'){
			_is_negative = true;
			_digits.remove(0);
		}
		_digits.reverse();
		_number_of_digits = _digits.length();
	}
	// BigInt::BigInt(const int& number){
	// 	int num = number;
	// 	_digits = "\0";
	// 	_is_negative = false;
	// 	_number_of_digits = 0;
	// 	if (num < 0){
	// 		num = -(num);
	// 		_is_negative = true;
	// 	}
	// 	if (num == 0){
	// 		_digits = "0";
	// 		_number_of_digits = 1;
	// 	}
	// 	while (num > 0){
	// 		_digits.push_back(to_char(num % 10));
	// 		_number_of_digits++;
	// 		num/=10;
	// 	}		
	// }
	BigInt::BigInt(const size_t& number){
		size_t num = number;
		_digits = "\0";
		_is_negative = false;
		_number_of_digits = 0;
		if (num == 0){
			_digits = "0";
			_number_of_digits = 1;
		}
		while (num > 0){
			_digits.push_back(to_char(num % 10));
			_number_of_digits++;
			num/=10;
		}		
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

	//arithmetic operations

	BigInt& BigInt::operator=(const BigInt& other){
		_number_of_digits = other._number_of_digits;
		_is_negative = other._is_negative;
		_digits = other._digits;
		return *this;
	}
	BigInt BigInt::operator+(const BigInt& other){
		BigInt result;
		result+=other;
		return result;
	}
	BigInt& BigInt::operator+=(const BigInt& other){
		BigInt firstTerm = *this;
		BigInt secondTerm = other;
		firstTerm._is_negative = false;
		secondTerm._is_negative = false;
		if (firstTerm < secondTerm){
			std::swap(firstTerm, secondTerm);
			firstTerm._is_negative = other._is_negative;
		}
		else{
			firstTerm._is_negative = this->_is_negative;
		}
		while (firstTerm._number_of_digits < secondTerm._number_of_digits){
			firstTerm._number_of_digits++;
			firstTerm._digits.push_back('0');
		}
		while (secondTerm._number_of_digits < firstTerm._number_of_digits){
			secondTerm._number_of_digits++;
			secondTerm._digits.push_back('0');
		}
		if (this->_is_negative == other._is_negative){
			for (size_t i = 0; i < secondTerm._number_of_digits; i++){
				firstTerm._digits[i] = to_char(to_int(firstTerm._digits[i])+to_int(secondTerm._digits[i]));
				if (firstTerm._digits[i] > '9'){
					if (i < firstTerm._number_of_digits-1){
						firstTerm._digits[i]-=10;
						firstTerm._digits[i+1]++;
					}
					else{
						firstTerm._digits[i]-=10;
						firstTerm._digits.push_back('1');
						firstTerm._number_of_digits++;
					}
				}
			}
		}
		if (this->_is_negative != other._is_negative){
			for (size_t i = 0; i < firstTerm._number_of_digits; i++){
				firstTerm._digits[i] = to_char(to_int(firstTerm._digits[i])-to_int(secondTerm._digits[i]));
				if (firstTerm._digits[i] < '0'){
					firstTerm._digits[i]+=10;
					firstTerm._digits[i+1]--;
				}
			}
			while (firstTerm._digits[firstTerm._number_of_digits-1] == '0'){
				firstTerm._number_of_digits--;
				firstTerm._digits.resize(firstTerm._number_of_digits);
			}
		}
		*this = firstTerm;
		return *this;
	}
	BigInt BigInt::operator-(const BigInt& other){
		BigInt result = *this;
		result -= other;
		return result;
	}
	BigInt& BigInt::operator-=(const BigInt& other){
		mm::BigInt minuend = *this;
		mm::BigInt subtract = other;
		minuend._is_negative = false;
		subtract._is_negative = false;
		if (!this->_is_negative && !other._is_negative){
			subtract._is_negative = true;
			minuend+=subtract;
		}
		else if (!this->_is_negative && other._is_negative){
			minuend+=subtract;
		}
		else if (this->_is_negative && !other._is_negative){
			minuend._is_negative = true;
			subtract._is_negative = true;
			minuend+=subtract;
		}
		else{
			minuend._is_negative = true;
			minuend+=subtract;
		}
		*this = minuend;
		return *this;
	}
	BigInt BigInt::operator*(const BigInt& other){
		mm::BigInt result = *this;
		result*=other;
		return result;
	}
	BigInt& BigInt::operator*=(const BigInt& other){
		mm::BigInt first = *this;
		mm::BigInt second = other;
		if ((first == BigInt("0")) || (second == BigInt("0"))){
			*this = "0";
			return *this;
		}
		first._is_negative = false;
		second._is_negative = false;
		if (first < second){
			std::swap(first, second);
		}
		short max_degree = 63;
		for (short i = 0; i < 63; i++){
			if (BigInt(size_t(2)<<i) > second){
				max_degree = i;
				break;
			}
		}
		mm::BigInt massive[static_cast<const short>(max_degree+1)];
		massive[0] = first;
		for (short i = 1; i <= max_degree; i++){
			first+=first;
			massive[i] = first;
			//std::cout << "massive[" << i << "] = " << massive[i] << std::endl;
		}
		second-=mm::BigInt(size_t(1)<<max_degree);
		while (mm::BigInt(size_t(1)<<max_degree) < second){
			first+=massive[max_degree];
			second-=mm::BigInt(size_t(1)<<max_degree);
		}
		for (short i = max_degree; i >= 0; i--){
			if (mm::BigInt(size_t(1)<<i) < second){
				first+=massive[i];
				second-=mm::BigInt(size_t(1)<<i);
			}
		}
		if (second > mm::BigInt("0")){
			first+=massive[0];
			second-=1;
		}
		first._is_negative = !(this->_is_negative == other._is_negative);
		*this = first;
		return *this;
	}

	// input-output operations

	std::istream& operator>>(std::istream& in, BigInt& number){
		mm::string buffer;
		in >> buffer;
		number = buffer;
		return in;
	}
	std::ostream& operator<<(std::ostream& out, BigInt number){
		mm::string digits = number._digits;
		if (number._is_negative) digits+="-";
		digits.reverse();
		return out << digits;
	}
}