//중복 내용을 심링크로 대체해 폴더 크기를 줄이는 도구 구현
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<filesystem>

using namespace std;
using namespace filesystem;

static size_t hash_from_path(const path& p)
{
	ifstream is{ p.c_str(), ios::in | ios::binary };
	if (!is) { throw errno; }
	string s;
	is.seekg(0, ios::end);
	s.reserve(static_cast<size_t>(is.tellg()));
	is.seekg(0, ios::beg);
	s.assign(istreambuf_iterator<char>{is}, {});
	return hash<string>{}(s);
}
static size_t reduce_dupes(const path& dir)
{
	unordered_map<size_t, path> m;
	size_t count{ 0 };
	for (const auto& entry : recursive_directory_iterator{ dir })
	{
		const path p{ entry.path() };
		if (is_directory(p)) { continue; }
		const auto& [it, success] = m.try_emplace(hash_from_path(p), p);

		if (!success)
		{
			cout << "Removed " << p
				<< " because it is a duplicate of "
				<< it->second << endl;
			remove(p);
			create_symlink(absolute(it->second), p);
			++count;
		}
	}
	return count;
}
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << " <path>" << endl;
		return 1;
	}
	path dir{ argv[1] };
	if (!exists(dir))
	{
		cout << "Path " << dir << " does not exist." << endl;
		return 1;
	}
	const size_t dupes{ reduce_dupes(dir) };
	cout << "Removed " << dupes << " duplicates." << endl;
}
