#include<iostream>
#include"BigInt.h"
using namespace std;

BigInt::BigInt(int i){
	// we need a constructor it makes it a scalar type
	this->val=i;
}

template<class T>
BigInt& BigInt::operator =(const T &rhs){
	// This is the place where we initialize the value.
	// Think of it as the entry point of our class.
	// This is where we have to scaffold out the datastructure
	return *this;
	this->val = &rhs;
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
	return this->val/a.val;
}
