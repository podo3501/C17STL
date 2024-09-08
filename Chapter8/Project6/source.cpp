//Ÿ�Կ� ���� �� ������ std::any�� �̿��� void* ��ü
#include<iostream>
#include<iomanip>
#include<list>
#include<any>
#include<iterator>

using namespace std;
using int_list = list<int>;

void print_anything(const std::any& a)
{
	if (!a.has_value())
	{
		cout << "Nothing." << endl;
	}
	else if (a.type() == typeid(string))
	{
		cout << "It's a string: "
			<< quoted(any_cast<const string&>(a)) << endl;
	}
	else if (a.type() == typeid(int))
	{
		cout << "It's an integer: "
			<< any_cast<int>(a) << endl;
	}
	else if (a.type() == typeid(int_list))
	{
		const auto& l(any_cast<const int_list&>(a));
		cout << "It's a list: ";
		copy(begin(l), end(l), ostream_iterator<int>{cout, ", "});
		cout << endl;
	}
	else
	{
		cout << "Can't handle this item." << endl;
	}
}

int main()
{
	print_anything({});
	print_anything("abc"s);
	print_anything(123);
	print_anything(int_list{ 1, 2, 3 });
	print_anything(any(in_place_type_t<int_list>{}, { 1, 2, 3 }));
}
