#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	const size_t sig_len{ 100 };
	vector<double> as(sig_len);
	vector<int> ds(sig_len);

	auto sin_gen([n{ 0 }]() mutable {
		return 5.0 * sin(n++ * 2.0 * M_PI / 100); });

	generate(begin(as), end(as), sin_gen);
	copy(begin(as), end(as), begin(ds));

	copy(begin(as), end(as), ostream_iterator<double>{cout, " "});
	cout << endl;
	copy(begin(ds), end(ds), ostream_iterator<double>{cout, " "});
	cout << endl;

	cout << inner_product(begin(as), end(as), begin(ds),
		0.0, std::plus<double>{},
		[](double a, double b) {
			return pow(a - b, 2); })
		<< endl;
}