//상대 경로에서 기준 파일 경로 얻기
#include<iostream>
#include<filesystem>

using namespace std;
using namespace filesystem;

int main()
{
	path p{ "testdir/foobar.txt" };

	cout << "current_path		: " << current_path() << endl
		<< "absolute_path		: " << absolute(p) << endl
		//<< "system_complete	: " << std::filesystem::system_complete(p) << endl
		<< "canonical(p)		: " << canonical(p)
		<< endl;
	cout << path{ "testdir" } / "foobar.txt" << endl;
	//cout << "canonical testdir : "
	//	//<< canonical("foobar.txt", current_path() / "testdir") << endl
	//	<< canonical("foobar.txt") << endl
	//	<< "canonical testdir 2 : "
	//	//<< canonical(p, current_path() / "testdir/..") 
	//	<< endl;
}