#include<iostream>
using namespace std;

class BigInt {
public:
	BigInt & operator =(const BigInt &intA){
		if(this!=&intA){
			return *this;
		}
	};
};

int main(){
	BigInt myInt = 270;
}
