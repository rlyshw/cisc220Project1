class BigInt {
public:
	int val;
	BigInt(int i);
	BigInt operator+(const BigInt&);
	BigInt operator*(const BigInt&);
	BigInt operator-(const BigInt&);
	BigInt operator/(const BigInt&);
};
