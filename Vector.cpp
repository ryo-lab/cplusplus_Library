#include "Vector.h"

Vector::Vector(int s, int value)
{
	size = s;
	arr = new int[s]();

	for (int i = 0; i < size; i++) {
		arr[i] = value;
	}
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

