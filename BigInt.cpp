#include<iostream>
#include<sstream>
#include"BigInt.h"
using namespace std;

BigInt::BigInt(int i){
	// I don't foresee any issues here.
	// We can only bring in int-sized numbers.
	this->val=i;
}

BigInt BigInt::operator+(const BigInt& a){
	// Below is an example of overloaded addition.
	// if we do i+j, this->"whatever" refers to i,
	// a is the second value, j
	// you should be able to see how we could use the 
	// specific instances data structures to do mathy stuff
	return this->val+a.val;
}

BigInt BigInt::operator*(const BigInt& a){
	return this->val*a.val;
}

BigInt BigInt::operator-(const BigInt& a){
	return this->val-a.val;
}

BigInt BigInt::operator/(const BigInt& a){
	if(this->val%a.val!=0)
	return this->val/a.val;
}

ostream& operator<<(ostream &out, const BigInt& a){
	out << a.val;
	return out;
}
