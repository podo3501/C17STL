//같은 객체의 서로 다른 멤버 변수 공유
#include<iostream>
#include<memory>
#include<string>

using namespace std;

struct person
{
	string name;
	size_t age;
	person(string m, size_t a)
		: name{ move(m) }, age{ a }
	{
		cout << "CTOR " << name << endl;
	}
	~person() { cout << "DTOR " << name << endl; }
};

int main()
{
	shared_ptr<string> shared_name;
	shared_ptr<size_t> shared_age;
	{
		auto sperson(make_shared<person>("John Doe", 30));
		shared_name = shared_ptr<string>(sperson, &sperson->name);
		shared_age = shared_ptr<size_t>(sperson, &sperson->age);
	}
	cout << "name : " << *shared_name << endl
		<< "age: " << *shared_age << endl;
}