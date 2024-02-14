#include<iostream>

class num_iterator 
{
	int i{ 0 };
public:
	explicit num_iterator(int position = 0) : i{ position }
	{}
	int operator*() const { return i; }
	num_iterator& operator++()
	{
		++i;
		return *this;
	}
	bool operator!=(const num_iterator& other) const
	{
		return i != other.i;
	}
};

class num_range
{
	int from{ 0 };
	int to{ 0 };
public:
	num_range(int _from, int _to)
		: from{ _from }, to{ _to }
	{}
	num_iterator begin() const { return num_iterator{ from }; }
	num_iterator end() const { return num_iterator{ to }; }
};

int main()
{
	for (int i : num_range{ 100, 110 })
	{
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}