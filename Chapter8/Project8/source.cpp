//std::unique_ptr을 이용한 자원 자동 처리
#include<iostream>
#include<memory>

using namespace std;

class Foo
{
public:
	string name;
	Foo(string n)
		: name{ move(n) }
	{
		cout << "CTOR " << name << endl;
	}
	~Foo() { cout << "DTOR " << name << endl; }
};

void process_item(unique_ptr<Foo> p)
{
	if (!p) { return; }
	cout << "Processing " << p->name << endl;
}

int main()
{
	{
		unique_ptr<Foo> p1{ new Foo{"foo"} };
		auto p2(make_unique<Foo>("bar"));
	}
	process_item(make_unique<Foo>("foo1"));
	auto p1(make_unique<Foo>("foo2"));
	auto p2(make_unique<Foo>("foo3"));
	process_item(move(p1));
	cout << "End of main()" << endl;
}