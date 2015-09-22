#include<iostream>
using namespace std;

class BigInt {
public:
    int val;
	BigInt(int i);
	friend BigInt operator+(const BigInt &intA, const BigInt& intB);
	//BigInt & operator =(const int &rhs);

};
/*BigInt&  BigInt::operator =(const int &rhs){
	return *this;
}*/

BigInt::BigInt(int i){
	this->val=i;
}

BigInt operator+(const BigInt& intA, const BigInt& intB){
    return new BigInt(100);
}

int main(){
	BigInt* intA = new BigInt(2000000000);
	BigInt* intB = new BigInt(2000000000);
	cout << intA+intB << endl;
}
