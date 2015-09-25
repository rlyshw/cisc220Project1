#include<iostream>
using namespace std;

class BigInt {
public:
	int val;
	int* arr;
	BigInt();
	BigInt(int);
	BigInt(const char*);
	BigInt operator+(const BigInt&);
	BigInt operator*(const BigInt&);
	BigInt operator-(const BigInt&);
	BigInt operator/(const BigInt&);
	friend istream& operator>>(istream &in, BigInt&);
};
ostream& operator<<(ostream &out, const BigInt&);
//istream& operator>>(istream $in, const BigInt&);
