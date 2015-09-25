#include<iostream>
#include<sstream>
#include<math.h>
#include"BigInt.h"
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
	
	// these two loops get the size of each operand array(ie num of digits)
	int sizeThis=0;//sidenote: these are of type int, we are limited to nums with 2bil digits
	for(;this->arr[sizeThis]!=20;++sizeThis);
	int sizeA=0;
	for(;a.arr[sizeA]!=20;++sizeA);
	
	// we instantiate a dummy value for our output, we will overwrite this later
	BigInt newInt = 10;
	// length is the size of our final array
	int length = ((sizeA-sizeThis>0)?sizeA:sizeThis)+1;
	// we use a ternary operator to keep the array atleast 11 digits long
	newInt.arr = new int[((length<10)?11:length+1)];
	
	// we need the iterator after the loop exits
	int i= 0;
	// this for loop is going to do digit-by-digit arithemetic with carry
	for(;i<length;i++){
		// this sum line looks like a lot, lets break it down
		// it's really just a.arr[i]+this->arr[i], the ternary operator
		// just makes sure we aren't trying to add in the array terminator(20)
		int sum = ((a.arr[i]>=20?a.arr[i]%20:a.arr[i])+(this->arr[i]>=20?this->arr[i]%20:this->arr[i]));
		
		if(sum>=10){
			// carry out
			newInt.arr[i+1]++;
		};
		
		// no matter if we carried or not, make this value the first digit of the sum
		newInt.arr[i] += sum%10;
		
		// this stops a 10 from entering our digit array
		// if we are at a ten,
		if(newInt.arr[i]>=10){
			// carry it out
			newInt.arr[i+1]++;
			// and set it back to the ones digit
			newInt.arr[i] = newInt.arr[i]%10;
		}
	}
	
	// this conditional takes care of leading zeros
	// we can get leading zeros if the most significant digit didn't carry out
	if(!newInt.arr[i-1]){
		//change leading zero to terminator
		newInt.arr[i-1]=20;
	}else{
		//otherwise put terminator at the logical end of the digit array
		newInt.arr[i]=20;
	}
	// return the final value
	return newInt;
}

BigInt BigInt::operator*(const BigInt& a){

	BigInt out = 0;
	int size = 0;
	for(;a.arr[size]!=20;++size);
	for(int i=0;i<size;i++){
		for(int j=0;j<(a.arr[i]*pow(10,i));j++){
			out = out+*this;
		}
	}
	return out;
	/*int sizeThis=0;//sidenote: these are of type int, we are limited to nums with 2bil digits
	for(;this->arr[sizeThis]!=20;++sizeThis);
	int sizeA=0;
	for(;a.arr[sizeA]!=20;++sizeA);
	
	// we instantiate a dummy value for our output, we will overwrite this later
	BigInt newInt = 10;
	// length is the size of our final array
	int length = ((sizeA-sizeThis>0)?sizeA:sizeThis)+1;
	// we use a ternary operator to keep the array atleast 11 digits long
	newInt.arr = new int[((length<10)?11:length+1)];*/
	
	// int sizeThis = 0;
	// for(;this->num[sizeThis]!= 20; sizeThis++);
	
	
	// BigInt out = 0;
	// int size = 0;
	// for(;a.arr[size]!=20;++size);
	// int i = 0;
	// int j = 0;
	// if(num.sizeThis >= a.arr[size]){
	// 	for(; i<= a.arr[size]; i++){
	// 		for(;j <= num.sizeThis; j++){
	// 			sum = a[i]*num[i];
	// 			sum[] = new BigInt[sum];
	// 				b[][] = new BigInt(sum);
	// 		}
		
			
	// 	}
	
	//for(int i=0;i<size;i++){
	//	for(int j=0;j<(a.arr[i]*pow(10,i));j++){
	//		out = out+*this;	
	//}
	
	//	}
	//}
	//return out;
	/*
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
