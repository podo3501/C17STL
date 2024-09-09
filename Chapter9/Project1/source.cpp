//표준 알고리즘을 사용해 자동으로 코드 병렬화
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<execution>

using namespace std;

static bool odd(int n) { return n % 2; }

int main()
{
	vector<int> d(50000000);
	mt19937 gen;
	uniform_int_distribution<int> dis(0, 100000);
	auto rand_num([=]() mutable { return dis(gen); });

	generate(execution::par, begin(d), end(d), rand_num);
	sort(execution::par, begin(d), end(d));
	reverse(execution::par, begin(d), end(d));
	auto odds(count_if(execution::par, begin(d), end(d), odd));
	cout << (100.0 * odds / d.size())
		<< "% of the numbers are odd." << endl;
}