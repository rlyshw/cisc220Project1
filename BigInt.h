class BigInt {
public:
	int val;
	BigInt(int i);
	template<class T>
	BigInt& operator=(const T &rhs);
	BigInt operator+(const BigInt&);
	BigInt operator*(const BigInt&);
	BigInt operator-(const BigInt&);
	BigInt operator/(const BigInt&);
};
