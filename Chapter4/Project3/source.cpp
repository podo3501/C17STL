#include<iostream>
#include<functional>
#include<string>
#include<iterator>
#include<algorithm>

static bool begins_with_a(const std::string& s)
{
	return s.find("a") == 0;
}

static bool ends_with_b(const std::string& s)
{
	return s.rfind("b") == s.length() - 1;
}

template<typename A, typename B, typename F>
auto combine(F binary_func, A a, B b)
{
	return [=](auto param) {
		return binary_func(a(param), b(param)); };
}

using namespace std;

int main()
{
	auto a_xxx_b(combine(
		logical_and<>{},
		begins_with_a, ends_with_b));

	copy_if(istream_iterator<string>{cin}, {},
		ostream_iterator<string>{cout, ", "},
		a_xxx_b);
	cout << endl;
}