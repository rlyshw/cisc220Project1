#include<iostream>
#include"BigInt.h"
using namespace std;


//BigInt operator+(const BigInt& intA, const BigInt& intB){
    //return new BigInt(100);
//}

int main(){
	BigInt big = 12345678987654321;
	BigInt l = 10;
	BigInt i = 20;
	cout << (l+i) << endl;
	cout << (l*i) << endl;
	cout << (l-i) << endl;
	cout << (i/l)  << endl;
	cout << big << endl;
}
