class BigInt {
public:
	int val;
	BigInt(int);
	template<class T>
	BigInt& operator=(const T &rhs);
};
