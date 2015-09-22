#include <iostream>
#include <bitset>
#include"p1.h"
using namespace std;

/*Decide how to get data into an instance of your class.
    *Overload +, *, - to combine two bigInts into another bigInt. (Or make a different choice and defend it.)
    *Allow division of bigInts which returns a double, and a different division which returns the integer quotient as a bigInt.
    *Overload << so that cout displays the bigInt well. Do >> for cin to.
    *Give an indication of your performance at various sizes.
    */
    
class BigInt {
        /* We could use the power of tens and vectors to get the values 
        *  so if the user input 321 it would be 1*1 2*10 3*100
        */
        
        // vector<dataType> identifier(numElements);
        //vector<bigInt> input(numElements);
public:
        BigInt operator+(const BigInt &intA, const BigInt &intB);
        BigInt operator-(const BigInt &intA, const BigInt &intB);
        BigInt operator*(const BigInt &intA, const BigInt &intB);
        BigInt operator/(const BigInt &intA, const BigInt &intB);
        BigInt& operator=(const BigInt &intA); 
}

BigInt operator=(const BigInt &myInt){
        
	return *this;
}
