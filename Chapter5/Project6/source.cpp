#include<iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include<functional>

using namespace std;

template<typename Itr>
static void print(Itr it, size_t chars)
{
	copy_n(it, chars, ostream_iterator<char>{cout});
	cout << endl;
}

int main()
{
	const string long_string{
		"Lorem ipsum dolor sit amet, consetetur"
		" sadipscing elitr, sed diam nunumy eirmod" };
	const string needle{ "elitr" };

	auto match1(search(begin(long_string), end(long_string), begin(needle), end(needle)));
	print(match1, 5);

	auto match2(search(begin(long_string), end(long_string), default_searcher(begin(needle), end(needle))));
	print(match2, 5);

	auto match3(search(begin(long_string), end(long_string), boyer_moore_searcher(begin(needle), end(needle))));
	print(match3, 5);

	auto match4(search(begin(long_string), end(long_string), boyer_moore_horspool_searcher(begin(needle), end(needle))));
	print(match4, 5);
}