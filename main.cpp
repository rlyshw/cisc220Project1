#include<iostream>
#include"BigInt.h"
using namespace std;


//BigInt operator+(const BigInt& intA, const BigInt& intB){
    //return new BigInt(100);
//}

int main(){
	BigInt b = "123";
	BigInt c = "321";
	cout << b << " " << c << endl;
	cout << b+c << endl;
	BigInt d = 0;
	cin >> d;
	cout << d;
}
