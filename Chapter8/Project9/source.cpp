//std::shared_ptr을 이용한 공유 힙 메모리 자동 처리
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

void f(shared_ptr<Foo> sp)
{
	cout << "f: use counter at " << sp.use_count() << endl;
}

int main()
{
	shared_ptr<Foo> fa;
	{
		cout << "Inner scope begin" << endl;
		shared_ptr<Foo> f1{ new Foo{"foo"} };
		auto f2(make_shared<Foo>("bar"));
		cout << "f1's use counter at " << f1.use_count() << endl;
		fa = f1;
		cout << "f1's use counter at " << f1.use_count() << endl;
	}
	cout << "Back to outer scope" << endl;
	cout << fa.use_count() << endl;

	cout << "first f() call" << endl;
	f(fa);
	cout << "second f() call" << endl;
	f(move(fa));
	cout << "end of main()" << endl;
}