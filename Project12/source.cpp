//문맥마다 숫자들을 언제든지 완전히 다르게 출력
#include<iostream>
#include<iomanip>

using namespace std;

class format_guard
{
	decltype(cout.flags()) f{ cout.flags() };
public:
	~format_guard()
	{
		cout.flags(f);
	}
};

template<typename T>
struct scientific_type
{
	T value;
	explicit scientific_type(T val) : value{ val } {}
};
template<typename T>
ostream& operator<<(ostream& os, const scientific_type<T>& w)
{
	format_guard _;
	os << scientific << uppercase << showpos;
	return os << w.value;
}

int main()
{
	{
		format_guard _;
		cout << hex << scientific << showbase << uppercase;
		cout << "Numbers with special formatting:" << endl;
		cout << 0x123abc << endl;
		cout << 0.1223456789 << endl;
	}
	cout << "Same numbers, but noraml formatting again:" << endl;
	cout << 0x123abc << endl;
	cout << 0.123456789 << endl;

	cout << "Mixed formatting: "
		<< 123.0 << " "
		<< scientific_type{ 123.0 } << " "
		<< 123.456 << endl;
}