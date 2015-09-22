#include<iostream>
using namespace std;

class BigInt {
public:
	BigInt operator=(const BigInt &intA);
}
BigInt operator=(const BigInt &myInt){
	return *this;
}

int main(){
	BigInt myInt = 2700000000000;
}
