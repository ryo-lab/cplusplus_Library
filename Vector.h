#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
class Vector
{
public:
	class iterator
	{
	public:
		iterator() {}
		int& getRef()
		{
			return *p;
		}
		int &operator=(int *s)
		{
			p = s;
			return *p;
		}
		bool operator!=(iterator s)
		{
			if (*p == s.getRef()) {
				return false;
			}
			else
				return true;
		}
		iterator& operator++()
		{
			p++;
			return *this;
		}
		int& operator*()
		{
			return *p;
		}
	private:
		int *p;
	};

	Vector(){}
	Vector(int, int = 0);
	Vector &operator=(Vector&);
	size_t Size() const;
	int &operator[](const int);
	void push_back(int);
	int pop_back();
	void resize(const int);
	void swap(Vector&);
	bool empty();
	int &front();
	int &back();
	int &at(const int);
	void clear();
	int *data();
	iterator &begin();
	iterator &end();
	

private:
	int *arr;
	int size;
	iterator original;
};


#endif // !VECTOR_H


