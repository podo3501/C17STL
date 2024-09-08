//정규 표현식 라이브러리로 입력 토큰화
#include<iostream>
#include<iterator>
#include<regex>
#include<algorithm>
#include<iomanip>
#include<fstream>

using namespace std;

template<typename InputIt>
void print(InputIt it, InputIt end_it)
{
	while (it != end_it)
	{
		const string link{ *it++ };
		if (it == end_it) { break; }
		const string desc{ *it++ };

		cout << left << setw(28) << desc << " : " << link << endl;
	}
}

int main()
{
	ifstream infile{ "test.html" };
	infile >> noskipws;
	const std::string in{ istream_iterator<char>{infile}, {} };

	const regex link_re{
		"<a href=\"([^\"]*)\"[^<]*>([^<]*)</a>" };
	sregex_token_iterator it{
		begin(in), end(in), link_re, {1, 2} };

	print(it, {});
}
