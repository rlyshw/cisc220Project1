#include<iostream>
#include<sstream>
#include"BigInt.h"
#include<bitset>
#include<typeinfo>
using namespace std;

BigInt::BigInt(int i){
	//Creates a 10*1 array that stores each individual digit of the input integer
	this->arr = new int[11]; // int array has to be one larger than our max desired digits
	int iterator = 0;
	long long casti = (long long)i;
	//Loops through each digit of the integer and populates the array
	for(long long j = 10; j <= casti*10; j *= 10){
		arr[iterator] = (i%j)/(j/10);
		iterator++;
	}
	this->val=i;
}

BigInt BigInt::operator+(const BigInt& a){
	int sizeThis=0;
	for(;this->arr[sizeThis]!='\0';++sizeThis);
	
	int sizeA=0;
	for(;a.arr[sizeA]!='\0';++sizeA);
	BigInt newInt = 10;
	cout << newInt<<endl;
	for(int i=0;i<((sizeA-sizeThis>0) ? sizeA : sizeThis);i++){
		
	}
	return newInt;
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
	int size=0;
	for(;a.arr[size]!='\0';++size){
		cout << a.arr[size] << endl;
	};
	size--;
	for(;size>=0;size--){
		out << a.arr[size];
	}
	return out;
}
