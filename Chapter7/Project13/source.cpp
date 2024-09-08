//std::iostream �����κ��� ���� �� �ִ� ���� �߰�
#include<iostream>
#include<fstream>
#include<system_error>
#include<cstring>

using namespace std;

int main()
{
	ifstream f;
	f.exceptions(f.failbit | f.badbit);
	try
	{
		f.open("non_existant.txt");

		int i;
		f >> i;

		cout << "integer has value: " << i << endl;
	}
	catch (ios_base::failure& e)
	{
		cerr << "Caught error: ";
		if (errno)
		{
			char buff[256];
			strerror_s(buff, 100, errno);
			cerr << buff << endl;
		}
		else
		{
			cerr << e.what() << endl;
		}
	}
}