#include<iostream>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;

template<typename It, typename F>
pair<It, It> gather(It first, It last, It gather_pos, F predicate)
{
	return { stable_partition(first, gather_pos, not_fn(predicate)),
		stable_partition(gather_pos, last, predicate) };
}

template<typename It>
void gather_sort(It first, It last, It gather_pos)
{
	using T = typename std::iterator_traits<It>::value_type;
	stable_sort(first, gather_pos, greater<T>{});
	stable_sort(gather_pos, last, less<T>{});
}

int main()
{
	auto is_a([](char c) { return c == 'a'; });
	string a{ "a_a_a_a_a_a_a_a_a_a_a" };

	auto middle(begin(a) + a.size() / 2);
	gather(begin(a), end(a), middle, is_a);
	cout << a << endl;

	gather(begin(a), end(a), begin(a), is_a);
	cout << a << endl;

	gather(begin(a), end(a), end(a), is_a);
	cout << a << endl;

	gather(begin(a), end(a), middle, is_a);
	cout << a << endl;

	string b{ "_9_2_4_7_3_8_1_6_5_0_" };
	gather_sort(begin(b), end(b), begin(b) + b.size() / 2);
	cout << b << endl;
}