//grep과 유사한 텍스트 검색 도구 구현
#include<iostream>
#include<fstream>
#include<regex>
#include<vector>
#include<string>
#include<filesystem>

using namespace std;
using namespace filesystem;

static vector<pair<size_t, string>>
matches(const path& p, const regex& re)
{
	vector<pair<size_t, string>> d;
	ifstream is{ p.c_str() };

	string s;
	for (size_t line{ 1 }; getline(is, s); ++line)
	{
		if (regex_search(begin(s), end(s), re))
		{
			d.emplace_back(line, move(s));
		}
	}
	return d;
}
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " <pattern>" << endl;
		return 1;
	}
	regex pattern;
	try
	{
		pattern = regex{ argv[1] };
	}
	catch (const regex_error& )
	{
		cout << "Invalid regular expression provided." << endl;
		return 1;
	}
	for (const auto& entry : recursive_directory_iterator{ current_path() })
	{
		auto ms(matches(entry.path(), pattern));
		for (const auto& [number, content] : ms)
		{
			cout << entry.path() << ":" << number
				<< " - " << content << endl;
		}
	}
}