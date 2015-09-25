#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<math.h>
#include"BigInt.h"
using namespace std;

BigInt::BigInt(){
	this->arr = new int[1];
}

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
	//this->val=i;
}
BigInt::BigInt(const char* s){
	int size=0;
	for(;s[size]!='\0';size++);
	this->arr = new int[size+2];
	int i=0;
	for(;i<size;i++){
		this->arr[i]=s[(size-1)-i]-'0';
	}
	this->arr[i] = 20;
}


BigInt BigInt::operator+(const BigInt& a){
	
	// these two loops get the size of each operand array(ie num of digits)
	int sizeThis=0;//sidenote: these are of type int, we are limited to nums with 2bil digits
	for(;this->arr[sizeThis]!=20;++sizeThis);
	int sizeA=0;
	for(;a.arr[sizeA]!=20;++sizeA);
	// we instantiate a dummy value for our output, we will overwrite this later
	BigInt newInt = 0;
	// length is the size of our final array
	int length = ((sizeA-sizeThis>0)?sizeA:sizeThis)+1;
	// we use a ternary operator to keep the array atleast 11 digits long
	delete[] newInt.arr;
	newInt.arr = new int[((length<10)?11:length+1)];
	int i=0;
	for(;i<((length<10)?11:length+1);i++){
		newInt.arr[i]=0;
	}
	newInt.arr[i]=20;
	// we need the iterator after the loop exits
	i= 0;
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
	/* this is the broken addition loopy way
	BigInt out = 0;
	int size = 0;
	for(;a.arr[size]!=20;++size);
	for(int i=0;i<size;i++){
		ostringstream power;
		power << a.arr[i];
		for(int s=0;s<i;s++){
			power << '0';
		}
		int p = atoi(power.str().c_str());
		for(int j=0;j<p;j++){
			out = out+*this;
		}
	}
	return out;*/
	// THIS IS THE MOST RECENT ALMOST-WORKING DIGIT-WISE
	BigInt out = 0;
	int sizeThis = 0;
	int sizeA = 0;
	for(;a.arr[sizeA]!=20;++sizeA);
	for(;this->arr[sizeThis]!=20;++sizeThis);
	
	int smaller = (sizeThis-sizeA)<0?sizeThis:sizeA;
	int bigger  = (sizeA-sizeThis)<0?sizeThis:sizeA;

	ostringstream power;
	power << '1';
	int s=0;
	for(;s<smaller+bigger;s++){
		power << '0';
	}
	BigInt sum = power.str().c_str();
	sum.arr[smaller+bigger]=0;
	for(int i=0;i<smaller;i++){
		BigInt temp = power.str().c_str();
		int tempSize = 0;
		for(;temp.arr[tempSize]!=20;tempSize++);
		temp.arr[tempSize-1]=0;
		int j =0;
		for(;j<bigger;j++){
			int prod;
			prod = (sizeA<sizeThis)?(a.arr[i]*this->arr[j]):(this->arr[i]*a.arr[j]);
			if(prod>=10){
				temp.arr[j+i+1] = prod/10;
			}
			temp.arr[j+i] += prod%10;
		}
		if(!temp.arr[i+j])temp.arr[i]=20;
		else temp.arr[i+j]=20;
		sum = sum+temp;
		delete[] temp.arr;
	}
	return sum;

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
    // these two loops get the size of each operand array(ie num of digits)
    int sizeThis=0;//sidenote: these are of type int, we are limited to nums with 2bil digits
    for(;this->arr[sizeThis]!=20;++sizeThis);
    int sizeA=0;
    for(;a.arr[sizeA]!=20;++sizeA);
    
    // we instantiate a dummy value for our output, we will overwrite this later
    BigInt newInt = 10;
    // length is the size of our final array
    int length = 0;
    if(sizeThis > sizeA){
        length = sizeThis;
    }
    else{
        length = sizeA;
    }
    
    /*
     //NOT WORKING YET
     //if the left opperand has less digits than the right, adds zeros so both have the same amount
     //of digits so there is no invalid array access or early access into the 20 of one of the arrays.
     if(sizeA < sizeThis){
     int x = sizeThis;
     for(; a.arr[x] != 20; x++){
     this->arr[x] = 0;
     }
     this->arr[x + 1] = 20;
     }
     */
    
    
    //Populates dummy array to be used for operation with values from left operand
    for(;sizeThis>=0;sizeThis--){
        newInt.arr[sizeThis] = this->arr[sizeThis];
    }
    
    // we need the iterator after the loop exits
    int i= 0;
    // this for loop is going to do digit-by-digit arithemetic with carry
    for(;i < length;i++){
        int sum = ((newInt.arr[i]>=20?newInt.arr[i]%20:newInt.arr[i])-(a.arr[i]>=20?a.arr[i]%20:a.arr[i]));
        
        //Stops a negative integer from entering the new array and borrows 10 from the next most significant digit.
        if(sum < 0 && newInt.arr[i+1] != 20){
            newInt.arr[i+1] = newInt.arr[i+1] - 1;
            sum += 10;
            newInt.arr[i] = sum;
        };
        
        newInt.arr[i] = sum;
    }
    
    //Loops through the array to find the index of 20 (the terminate value) and then gets rid of all leading zeros
    //after it. Makes the last leading zero the new 20.
    int j = 0;
    for(; newInt.arr[j] != 20; j++);
    j -= 1;
    for(; newInt.arr[j] == 0 && newInt.arr[j-1] == 0; j--);
    newInt.arr[j] = 20;
    
    return newInt;
}

BigInt BigInt::operator/(const BigInt& a){
	BigInt newInt = 10;
	//find the size of what we're dividing
	int sizeThis=0;
	for(;this->arr[sizeThis]!=20;++sizeThis);
	//find the size of what we're dividing by
	int sizeA=0;
	for(;a.arr[sizeA]!=20;++sizeA);
	if (sizeThis > sizeA){
		if (sizeThis%sizeA == 0){
			for (int i =0; i <  sizeThis-sizeA; i++){
				this->arr[i] *i;
			}
		/*	BigInt final = this;
			while (final > 0){
				final = final- a;
				newInt= newInt+ 1;
			}
		*/
		}
		else{
			//double 
		}
	}
	if (sizeThis < sizeA){
		// double
	}
	if (sizeThis == sizeA){
		bool equal = true;
		while (equal==true){
			for (int j = 0; j< sizeThis; j++){
				if (a.arr[j]== this->arr[j]){
					equal = true;
				}
				else{
					equal = false;
				}
			}
			newInt= 1;
		}
	}
	return newInt;
}

ostream& operator<<(ostream &out, const BigInt& a){
	int size=0;
	for(;a.arr[size]!=20;++size);
	/*if(size>6){
		size--;
		int magnitude = size;
		out << a.arr[size] << ".";
		size--;
		for(;size>=magnitude-5;size--){
			out << a.arr[size];
		}
		out << "e" << magnitude;
		return out;
	}*/
	size--;
	for(;size>=0;size--){
		out << a.arr[size];
	}
	return out;
}
istream& operator>>(istream &in, BigInt& a){
	string s;
	in >> s;
	BigInt out = s.c_str();
	a = out;
	return in;
}
