#include<iostream>
#include<sstream>
using namespace std;

class BigInt {
public:
	int val;
	BigInt(int i);
	BigInt operator+(const BigInt&);
	BigInt operator*(const BigInt&);
	BigInt operator-(const BigInt&);
	BigInt operator/(const BigInt&);
};
ostream& operator<<(ostream &out, const BigInt&);
