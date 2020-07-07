#include "Vector.h"
using namespace std;
Vector::Vector(int s, int value)
{
	size = s;
	arr = new int[s]();

	for (int i = 0; i < size; i++) {
		arr[i] = value;
	}
}

Vector::Vector(int a, int b, int c)
{
	size = 3;
	arr = new int[Size()]();

	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
}

Vector::Vector(iterator first, iterator last)
{
	size = last.getRef() - first.getRef();
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++, ++first) {
		arr[i] = *first;
	}
}

Vector::Vector(int* first, int* last)
{
	size = last - first;
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++) {
		arr[i] = *(first + i);
	}
}

Vector::Vector(const Vector &v)
{
	size = v.size;
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++) {
		arr[i] = v.arr[i];
	}
}

Vector::~Vector()
{
	size = 0;
	delete[] arr;
	arr = nullptr;
}

Vector & Vector::operator=(Vector &v)
{
	delete[] arr;
	arr = nullptr;
	arr = new int[v.Size()];
	size = v.Size();
	for (unsigned int i = 0; i < v.Size(); i++) {
		arr[i] = v.arr[i];
	}

	return *this;
}





size_t Vector::Size() const
{
	return size;
}

int &Vector::operator[](const int i)
{
	return arr[i];
}

void Vector::push_back(int num)
{
	/*copy array*/
	int *sub = new int[this->Size()]();
	for (unsigned int i = 0; i < this->Size(); i++) {
		sub[i] = arr[i];
	}
	
	/*delete original array*/
	if (Size() > 0) {
		delete[] arr;
		arr = nullptr;
	}
	
	
	/*creat new array*/
	size += 1;
	arr = new int[Size()];
	for (unsigned int i = 0; i < Size() - 1; i++) {//paste original element
		arr[i] = sub[i];
	}
	arr[Size() - 1] = num;

	delete[] sub;
	sub = nullptr;
}

int Vector::pop_back()
{
	int *sub = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++) {
		sub[i] = arr[i];
	}
	if (Size() > 0) {
		delete[] arr;
		arr = nullptr;
	}

	int returnValue = sub[Size() - 1];//get last value
	size--;
	arr = new int[Size()];
	for (unsigned int i = 0; i < Size(); i++) {
		arr[i] = sub[i];
	}
	delete[] sub;
	sub = nullptr;

	return returnValue;
}

void Vector::resize(const int newSize)
{
	/*copy element array to new array*/
	int *sub;
	sub = new int[Size()];
	for (unsigned int i = 0; i < Size(); i++) {
		sub[i] = arr[i];
	}
	delete[] arr;
	int oldSize = Size();

	/*creat new array*/
	arr = new int[newSize]();
	size = newSize;
	for (int i = 0; i < oldSize; i++) {
		arr[i] = sub[i];
	}
	delete[] sub;
	sub = nullptr;
}

void Vector::swap(Vector &v)
{
	Vector sub;

	sub = v;
	v = *this;
	*this = sub;
}

bool Vector::empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

int &Vector::front()
{
	return arr[0];
}

int &Vector::back()
{
	return arr[Size() - 1];
}

int & Vector::at(const int index)
{
	return arr[index];
}

void Vector::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

int * Vector::data()
{
	return arr;
}

Vector::iterator &Vector::begin()
{
	/*iterator it;*/
	original = arr;

	return original;
}

Vector::iterator & Vector::end()
{
	int *sub = arr + Size();
	original = sub;

	return original;
}

void Vector::erase(iterator first, iterator last)
{
	int *sub = new int[Size()]();
	int index = 0;

	for (Vector::iterator it = last + 1; it != end(); ++it) {
		sub[index] = *it;
		index++;
	}
	delete[] arr;
	arr = nullptr;

	size = index;
	arr = new int[Size()]();
	for (unsigned int j = 0; j < Size(); j++) {
		arr[j] = sub[j];
	}
}

void Vector::assign(int s, int val)
{
	size = s;
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++) {
		arr[i] = val;
	}
}

void Vector::assign(int* first, int* last)
{
	size = last - first;
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++) {
		arr[i] = *(first + i);
	}
}

void Vector::assign(iterator first, iterator last)
{
	size = last.getRef() - first.getRef();
	arr = new int[Size()]();

	for (unsigned int i = 0; i < Size(); i++, ++first) {
		arr[i] = *first;
	}
}

Vector::iterator Vector::emplace(iterator location, int val)
{
	int index = location.getRef() - this->begin().getRef();

	
	int *sub;
	sub = new int[Size()]();
	for (unsigned int i = 0; i < Size(); i++) {
		sub[i] = arr[i];
	}
	delete[] arr;
	arr = nullptr;

	size++;
	arr = new int[Size()]();

	bool insert = false;

	for (unsigned int i = 0; i < Size(); i++) {
		if (i == index) {
			arr[i] = val;
			insert = true;
		}
		else if (insert) {
			arr[i] = sub[i - 1];
		}
		else {
			arr[i] = sub[i];
		}
	}

	original = begin() + index;

	return original;
}

void Vector::emplace_back(int num)
{
	/*copy array*/
	int *sub = new int[this->Size()]();
	for (unsigned int i = 0; i < this->Size(); i++) {
		sub[i] = arr[i];
	}

	/*delete original array*/
	if (Size() > 0) {
		delete[] arr;
		arr = nullptr;
	}


	/*creat new array*/
	size += 1;
	arr = new int[Size()];
	for (unsigned int i = 0; i < Size() - 1; i++) {//paste original element
		arr[i] = sub[i];
	}
	arr[Size() - 1] = num;

	delete[] sub;
	sub = nullptr;
}

Vector::iterator Vector::insert(iterator location, int val)
{
	int index = location - begin();
	
	int* sub;
	sub = new int[Size()]();

	for (int i = 0; i < Size(); i++) {
		sub[i] = arr[i];
	}
	delete[] arr;
	arr = nullptr;

	size++;
	arr = new int[Size()]();

	bool insert = false;

	for (int i = 0; i < Size(); i++) {
		if (i == index) {
			arr[i] = val;
			insert = true;
		}
		else if (insert) {
			arr[i] = sub[i - 1];
		}
		else {
			arr[i] = sub[i];
		}
	}

	original = location;
	return original;
}

