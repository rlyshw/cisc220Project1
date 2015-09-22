#include <iostream>
using namespace std;


class BigInt{
    public:
        BigInt operator+(const BigInt &intA, const BigInt &intB);
        BigInt operator-(const BigInt &intA, const BigInt &intB);
        BigInt operator*(const BigInt &intA, const BigInt &intB);
        BigInt operator/(const BigInt &intA, const BigInt &intB);
        BigInt& operator=(const BigInt &intA);
};
