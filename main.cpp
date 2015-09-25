#include<iostream>
#include"BigInt.h"
using namespace std;

/* Performance at various sizes:
Our program works for any "BigInts" to be added together that are put into the system from cin but when
directly constructing a BigInt it cannot be anything bigger than the maximum int's value. 
Addition performs at all sizes, within the real time of .01 seconds found by using time ./a.out
Subtraction performs at all sizes, within the same real time as addtion but you cannot subract a bigger number
Multiplication of BigInts is preformed accurately up to the 100 million place.
Division of BigInts does not work as a quotinet cannot be computed by each number in its value.
*/

int main(){
	//BigInt big = 3;
	//BigInt l = 10;
	//BigInt i = 20;
	//BigInt two = 1234567891;
	//cout << two << endl;13086791879324657913
	BigInt a = 12345678;
	BigInt b = 1000000;
	cout << a/b<< endl;
	//cout << four << endl;
	//cout << (l+i) << endl;
	//cout << (l*i) << endl;
	//cout << (l-i) << endl;
	//cout << (i/l)  << endl;
	//cout << big << endl;

   BigInt a = "123456789123456789";
   cout << a*a << endl;
}

