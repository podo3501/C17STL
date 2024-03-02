#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

template<typename It>
It remove_multi_whitespace(It it, It end_it)
{
	return unique(it, end_it, [](const auto& a, const auto& b) {
		return isspace(a) && isspace(b); });
}

int main()
{
	string s{ "fooo     bar \t           baz" };
	cout << s << endl;

	s.erase(remove_multi_whitespace(begin(s), end(s)), end(s));
	cout << s << endl;
}