//공유 객체에 대한 weak 포인터 다루기
#include<iostream>
#include<iomanip>
#include<memory>

using namespace std;

class Foo
{
public:
	int value;
	Foo(int i) : value{ i } {}
	~Foo() { cout << "DTOR Foo " << value << endl; }
};

void weak_ptr_info(const weak_ptr<Foo>& p)
{
	cout << "----------" << boolalpha
		<< endl << "expired: " << p.expired()
		<< endl << "use_count: " << p.use_count()
		<< endl << "content: ";
	if (const auto sp(p.lock()); sp)
	{
		cout << sp->value << endl;
	}
	else
	{
		cout << "<null>" << endl;
	}
}

int main()
{
	weak_ptr<Foo> weak_foo;
	weak_ptr_info(weak_foo);
	{
		auto shared_foo(make_shared<Foo>(1337));
		weak_foo = shared_foo;
		weak_ptr_info(weak_foo);
	}
	weak_ptr_info(weak_foo);
}