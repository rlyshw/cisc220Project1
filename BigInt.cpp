#include<iostream>
#include<sstream>
#include<math.h>
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
	arr[iterator] = 20;
	this->val=i;
}

BigInt BigInt::operator+(const BigInt& a){
	int sizeThis=0;
	for(;this->arr[sizeThis]!=20;++sizeThis);
	
	int sizeA=0;
	for(;a.arr[sizeA]!=20;++sizeA);
	//cout << sizeA << endl;
	BigInt newInt = 10;
	int length = ((sizeA-sizeThis>0)?sizeA:sizeThis)+1;
	newInt.arr = new int[((length<10)?11:length+1)];
	//cout << ((sizeA-sizeThis>0)?sizeA:sizeThis)+1 << endl;
	int i= 0;
	for(;i<length;i++){
		//if(a.arr[i]==20)a.arr[i]=0;
		//cout << this->arr[i] << '+' << a.arr[i] << "=";
		cout << ((a.arr[i]>=20?a.arr[i]%20:a.arr[i]))<<"+"<<
				((this->arr[i]>=20?this->arr[i]%20:this->arr[i])) <<"="<<
				((a.arr[i]>=20?a.arr[i]%20:a.arr[i])+(this->arr[i]>=20?this->arr[i]%20:this->arr[i]))%10 << " ";
		if(((a.arr[i]>=20?a.arr[i]%20:a.arr[i])+(this->arr[i]>=20?this->arr[i]%20:this->arr[i]))>=10){
			newInt.arr[i+1]++;// this is breaking the original value;
		};
		newInt.arr[i] += ((a.arr[i]>=20?a.arr[i]%20:a.arr[i])+(this->arr[i]>=20?this->arr[i]%20:this->arr[i]))%10;
		if(newInt.arr[i]>=10){
			newInt.arr[i+1]++;
			newInt.arr[i] = newInt.arr[i]%10;
		}
		cout << newInt.arr[i] << endl; 
	}
	if(!newInt.arr[i-1]){
		newInt.arr[i-1]=20;
	}else{
		newInt.arr[i]=20;
	}
	cout << endl;
	return newInt;
}

BigInt BigInt::operator*(const BigInt& a){
	
	/*=
	//Needs some unit testing and unsure of the syntax. In this code, how should the 
	//operand that isn't the big int parameter be represented?
	
	BigInt newInt = 10;
	sumArr = new int[10];
	bool addToVal = false;
	
	int aSize = sizeof(a)/sizeof(*a);
	for(int i = 0; i < aSize; i++){
		if(addToVal == true){
			sumArr[i] += (a.arr[i]*newInt.arr[i])*(pow(10, i));
		}
		else if(addToVal == false){
			sumArr[i] = (a.arr[i]*newInt.arr[i])*(pow(10, i));
		}
	}
	
	for(int i = 1; i < (sizeof(sumArr)/sizeof(*sumArr)); i++){
		a.arr[i] = sumArr[i]%10;
		if(sumArr[i]%(pow(10, i+1)) > 9){
			a.arr[i+1] = sumArr[i]/10;
			addToVal = true;
		}
	}*/
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
	for(;a.arr[size]!=20;++size){
	};
	size--;
	for(;size>=0;size--){
		out << a.arr[size];
	}
	return out;
}
