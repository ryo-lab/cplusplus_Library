#ifndef STRING_H
#define STRING_H

class String
{
public:
	String() {};
	String &operator=(const char*);
	void Print();
	int getSize();
	const char operator[](int);
	void append(String&);

private:
	const char *element;
	int size;
};

#endif // !STRING_H



