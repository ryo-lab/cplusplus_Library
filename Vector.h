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
		int& getVal()
		{
			return *p;
		}
		int* getRef()
		{
			return p;
		}
		int &operator=(int *s)
		{
			p = s;
			return *p;
		}
		bool operator!=(iterator s)
		{
			if (*p == s.getVal()) {
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
		iterator operator+(int num)
		{
			p = p + num;
			return *this;
		}
		iterator operator-(int num)
		{
			p = p - num;
			return *this;
		}
		int operator-(iterator s)
		{
			int ref = getRef() - s.getRef();

			return ref;
		}
	private:
		int *p;
	};

	Vector() { size = 0; }
	Vector(int, int = 0);
	Vector(int, int, int);
	Vector(iterator, iterator);
	Vector(int*, int*);
	Vector(const Vector&);
	~Vector();
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
	void erase(iterator, iterator);
	void assign(int, int);
	void assign(int*, int*);
	void assign(iterator, iterator);
	iterator emplace(iterator, int);
	void emplace_back(int);
	//allocator_type get_allocator() const;
	iterator insert(iterator, int);

private:
	int *arr;
	int size;
	iterator original;
};


#endif // !VECTOR_H


