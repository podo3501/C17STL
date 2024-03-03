#include<iostream>
#include<string>
#include<string_view>
#include<sstream>
#include<algorithm>

using namespace std;

int main()
{
	string a{ "a" };
	auto b("b"s);

	string_view c{ "c" };
	auto d{ "d"sv };

	cout << a << ", " << b << endl;
	cout << c << ", " << d << endl;

	cout << a + b << endl;
	cout << a + string{ c } << endl;

	ostringstream o;
	o << a << " " << b << " " << c << " " << d;

	auto concatenated(o.str());
	cout << concatenated << endl;

	transform(begin(concatenated), end(concatenated), begin(concatenated), ::toupper);
	cout << concatenated << endl;
}