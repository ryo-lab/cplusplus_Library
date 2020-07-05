#include "String.h"
#include<iostream>
using namespace std;

String & String::operator=(const char* characters)
{
	element = characters;

	char current = element[size];

	while (current != '\0') {
		size++;
		current = element[size];
	}

	return *this;
}

void String::Print()
{
	cout << element << endl;
}

int String::getSize()
{
	return size;
}

const char String::operator[](int s)
{
	if (s < size)
		return element[s];
	else {
		cout << "Out of index\n\n";
		return 0;
	}
}

void String::append(String &s)
{

}

