#include<iostream>
#include<fstream>

using namespace std;

class redirect_cout_region
{
	using buftype = decltype(cout.rdbuf());
	ofstream ofs;
	buftype buf_backup;

public:
	explicit redirect_cout_region(const string& filename)
		: ofs(filename), buf_backup(cout.rdbuf(ofs.rdbuf()))
	{}
	redirect_cout_region()
		: ofs{}, buf_backup{ cout.rdbuf(ofs.rdbuf()) }
	{}
	~redirect_cout_region()
	{
		cout.rdbuf(buf_backup);
	}
};

void my_output_heavy_function()
{
	cout << "some output" << endl;
	cout << "this function does really heavy work" << endl;
	cout << "... and lots of it..." << endl;
}

int main()
{
	cout << "Readable from normal stdout" << endl;
	{
		redirect_cout_region _{ "output.txt" };
		cout << "Only visible in output.txt" << endl;
		my_output_heavy_function();
	}

	{
		redirect_cout_region _;
		cout << "This output will completely vanish" << endl;
	}
	
	cout << "Readable from normal stdout again" << endl;
}