//call_once로 안전하게 초기화 지연
#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

once_flag callflag;

static void once_print()
{
	cout << '!';
}

static void print(size_t x)
{
	std::call_once(callflag, once_print);
	cout << x;
}

int main()
{
	vector<thread> v;
	for (size_t i{ 0 }; i < 10; ++i)
	{
		v.emplace_back(print, i);
	}
	for (auto& t : v) { t.join(); }
	cout << endl;
}