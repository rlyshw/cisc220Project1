#include<iostream>
#include"BigInt.h"
using namespace std;

template<class T>
BigInt& BigInt::operator =(const T &rhs){
	return *this;
	this->val = &rhs;
}
BigInt::BigInt(int i){
	this->val=i;
}
