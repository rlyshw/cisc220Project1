#include<iostream>
#include"BigInt.h"
using namespace std;

template<class T>
BigInt& BigInt::operator =(const T &rhs){
	// This is the place where we initialize the value.
	// Think of it as the entry point of our class.
	return *this;
	this->val = &rhs;
}


BigInt::BigInt(int i){
	this->val=i;
}
