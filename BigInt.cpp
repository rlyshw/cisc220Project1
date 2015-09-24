#include<iostream>
#include<sstream>
#include"BigInt.h"
#include<bitset>
using namespace std;

BigInt::BigInt(int i){
	this->arr = new int[10];
	int iterator = 0;
	for(int j = 10; j <= i*10; j *= 10){
		cout << (i%j)/(j/10) << endl;
		
		iterator++;
	}
	//BigInt test = new BigInt[];
	//cout << (i%100)/10 << endl;
	// I don't foresee any issues here.
	// We can only bring in int-sized numbers.
	this->val=i;
	// BigInt test = new BigInt[];
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
	/*if(this->val%a.val!=0){
		this->(double)val/a.val;
	}
	else{
		this->val/a.val;
	}
	*/
	return this->val;
}

ostream& operator<<(ostream &out, const BigInt& a){
	out << a.val;
	return out;
}
