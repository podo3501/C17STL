//std::cout 동시 사용 동기화
#include<iostream>
#include<thread>
#include<mutex>
#include<sstream>
#include<vector>

using namespace std;

struct pcout : public stringstream
{
	static inline mutex cout_mutex;
	~pcout()
	{
		lock_guard<mutex> l{ cout_mutex };
		cout << rdbuf();
		cout.flush();
	}
};

static void print_cout(int id)
{
	cout << "cout hello from " << id << endl;
}
static void print_pcout(int id)
{
	pcout{} << "pcout hello from " << id << endl;
}

int main()
{
	vector<thread> v;
	for (size_t i{ 0 }; i < 10; ++i)
	{
		v.emplace_back(print_cout, i);
	}
	for (auto& t : v) { t.join(); }
	cout << "================" << endl;
	v.clear();
	for (size_t i{ 0 }; i < 10; ++i)
	{
		v.emplace_back(print_pcout, i);
	}
	for (auto& t : v) { t.join(); }
}