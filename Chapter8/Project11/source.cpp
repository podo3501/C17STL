//스마트 포인터를 이용한 이전 API의 자원 처리 간소화
#include<iostream>
#include<memory>

using namespace std;

class Foo
{
public:
	string name;
	Foo(string n)
		: name{ n }
	{
		cout << "CTOR " << name << endl;
	}
	~Foo() { cout << "DTOR " << name << endl; }

public:
	static Foo* create_foo(string s)
	{
		return new Foo{ move(s) };
	}
	static void destroy_foo(Foo* p) { delete p; }
};

static shared_ptr<Foo> make_shared_foo(string s)
{
	return { Foo::create_foo(move(s)), Foo::destroy_foo };
}
static unique_ptr<Foo, void (*)(Foo*)> make_unique_foo(string s)
{
	return { Foo::create_foo(move(s)), Foo::destroy_foo };
}

int main()
{
	auto ps(make_shared_foo("shared Foo instance"));
	auto pu(make_unique_foo("unique Foo instance"));
}

