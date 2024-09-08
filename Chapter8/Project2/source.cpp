//std::chrono를 이용한 절대 시간과 상대 시간 변환
#include<iostream>
#include<iomanip>
#include<chrono>
#include<time.h>

using namespace std;

ostream& operator<<(ostream& os, const chrono::time_point<chrono::system_clock>& t)
{
	const auto tt(chrono::system_clock::to_time_t(t));
	tm tmNew{};
	const auto error(localtime_s(&tmNew, &tt));
	return os << put_time(&tmNew, "%c");
}
using days = chrono::duration<
	chrono::hours::rep,
	ratio_multiply<chrono::hours::period, ratio<24>>>;
constexpr days operator ""_days(unsigned long long h)
{
	return days{ h };
}

int main()
{
	auto now(chrono::system_clock::now());
	cout << "The current date and time is " << now << endl;

	chrono::hours chrono_12h{ 12 };
	cout << "In 12 hours, it will be " << (now + chrono_12h) << endl;

	using namespace chrono_literals;
	cout << "12 hours and 15 minutes ago, it was " << (now - 12h - 15min) << endl
		<< "I week ago, it was " << (now - 7_days) << endl;
}