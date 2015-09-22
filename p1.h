#include <iostream>
using namespace std;


class BigInt{
    public:
        friend BigInt operator+(const BigInt &intA, const BigInt &intB);
        friend BigInt operator-(const BigInt &intA, const BigInt &intB);
        friend BigInt operator*(const BigInt &intA, const BigInt &intB);
        friend BigInt operator/(const BigInt &intA, const BigInt &intB);
        friend BigInt operator=(const BigInt &intA);
}